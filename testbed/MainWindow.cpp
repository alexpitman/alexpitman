#include "MainWindow.h"

#include "widget/ViewWindow.h"

#include "viewer/ViewHandler.h"

#include "voxel/Factory.h"
#include "voxel/Triangulate.h"

#include "import/ImportObjFile.h"

#include "export/ExportImage.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"

#include <QApplication>
#include <QErrorMessage>
#include <QFileDialog>
#include <QMenuBar>

MainWindow::MainWindow()
: myViewWindow(new wid::ViewWindow())
{
  setCentralWidget(myViewWindow);
  setWindowTitle(tr("Application"));
  
  QMenu* menu;
  QAction* action;
  
  auto addMenu = [&](const QString& Name)
    {
      menu = menuBar()->addMenu(Name);
    };
  auto addAction = [&](const QString& Name)
    {
      action = menu->addAction(Name);
    };
  
  // File menu.
  {
    addMenu(tr("&File"));

    addAction(tr("&Import"));
    connect(action, SIGNAL(triggered()), this, SLOT(import()));

    addAction(tr("&Quit"));
    connect(action, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
  }
  
  // Create menu.
  {
    addMenu(tr("&Create"));
    
    addAction(tr("&Point set"));
    connect(action, SIGNAL(triggered()), this, SLOT(createPointSet()));
    
    addAction(tr("&Facet network"));
    connect(action, SIGNAL(triggered()), this, SLOT(createFacetNetwork()));
  } 

  // Voxel menu
  {
    addMenu(tr("&Voxel"));
    
    addAction(tr("&Terrain"));
    connect(action, SIGNAL(triggered()), this, SLOT(createTerrain()));
    
    addAction(tr("&Sphere"));
    connect(action, SIGNAL(triggered()), this, SLOT(createSphere()));
    
    addAction(tr("&Planet"));
    connect(action, SIGNAL(triggered()), this, SLOT(createPlanet()));
    
    addAction(tr("Terrain &2D"));
    connect(action, SIGNAL(triggered()), this, SLOT(create2DTerrain()));
  }
}

void MainWindow::import()
{
  auto fileName = QFileDialog::getOpenFileName(
    this, tr("Import"), "", tr("Obj files (*.obj)"));
  
  if (fileName.isEmpty()) return;
  
  try
  {
    auto name = fileName.toUtf8();
    auto f = imp::ImportObjFile::Import(name.constData());
    myViewWindow->Handler()->SceneController()->AddObject(f);
  }
  catch (const std::exception& e)
  {
    auto error = new QErrorMessage(this);
    error->showMessage(tr("Failed to import file") + "\n" + QString(e.what()));
  }
}

void MainWindow::createPointSet()
{
  geo::Point3D points[] = {
    geo::Point3D(-1, -1,  1),
    geo::Point3D(-1,  1,  1),
    geo::Point3D( 1,  1,  1),
    geo::Point3D( 1, -1,  1),
  };
  
  auto p = std::make_shared<obj::PointSet>(points, points+4);
  myViewWindow->Handler()->SceneController()->AddObject(p);
}

void MainWindow::createFacetNetwork()
{
  geo::Point3D points[] = {
    geo::Point3D(-1, -1,  1),
    geo::Point3D(-1,  1,  1),
    geo::Point3D( 1,  1,  1),
    geo::Point3D( 1, -1,  1),
  };
  
  tpo::Triple facets[] = {
    tpo::Triple(0, 2, 1),
    tpo::Triple(0, 3, 2),
  };

  auto f = std::make_shared<obj::FacetNetwork>(points, points+4, facets, facets+2);
  myViewWindow->Handler()->SceneController()->AddObject(f);
}

void MainWindow::createTerrain()
{
  vxl::TerrainDescriptor descriptor(false);
  
  const int tileCountX = 2;
  const int tileCountY = 2;
  
  for (int x = 0; x < tileCountX; ++x)
  {
    for (int y = 0; y < tileCountY; ++y)
    {
      auto terrainTile = vxl::Triangulate::Terrain<64>(descriptor, geo::Vector3D(x, y, 0));
      myViewWindow->Handler()->SceneController()->AddObject(terrainTile);
    }
  }
}

void MainWindow::createSphere()
{
  std::unique_ptr<vxl::SubBlock<64>> ptr(vxl::Factory::GenerateSphere<64>());
  auto blockModelRep = vxl::Triangulate::SubBlock(*ptr);
  myViewWindow->Handler()->SceneController()->AddObject(blockModelRep);
}
  
void MainWindow::createPlanet()
{
  std::unique_ptr<vxl::SubBlock<64>> ptr(vxl::Factory::GeneratePlanet<64>(20.0f));
  auto blockModelRep = vxl::Triangulate::SubBlock(*ptr);
  myViewWindow->Handler()->SceneController()->AddObject(blockModelRep);
}

void MainWindow::create2DTerrain()
{
  auto fileName = QFileDialog::getSaveFileName(
    this, tr("Export"), "", tr("PNG files (*.png)"));
  
  if (fileName.isEmpty()) return;

  int width = 1024;
  int height = 256;
  img::Image image(width, height);
  
  num::Gradient gradient;
  gradient.setGradient(0, 0, 0, 1);
  
  num::Fractal fbm(num::FractalTypes::FBM, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC);
  fbm.setNumOctaves(6);
  fbm.setFrequency(2.0f);
  
  num::ScaleOffset scaleOffset(0.5f, 0.0f);
  scaleOffset.setSource(&fbm);
  
  num::ScaleDomain scaleDomain;
  scaleDomain.setSource(&scaleOffset);
  scaleDomain.setYScale(0.0f);
  
  num::TranslateDomain translateDomain;
  translateDomain.setSource(&gradient);
  translateDomain.setYAxisSource(&scaleDomain);
  
  for (int x = 0; x < width; ++x)
  {
    const float pX = x / float(width);
  
    for (int y = 0; y < height; ++y)
    {
      const float pY = y / float(height);
    
      if (translateDomain.get(pX, pY) > 0.5f)
      {
        image(x, y) = att::Colour::BlackColour();
      }
      else
      {
        image(x, y) = att::Colour::WhiteColour();
      }
    }
  }
  
  ept::ExportImage::Png(image, fileName.toUtf8().constData());
}