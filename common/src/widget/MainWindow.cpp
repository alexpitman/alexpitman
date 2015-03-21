#include "widget/MainWindow.h"

#include "widget/ViewWindow.h"

#include "viewer/ViewHandler.h"

#include "voxel/Factory.h"
#include "voxel/Triangulate.h"

#include "import/ImportObjFile.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"

#include <QApplication>
#include <QErrorMessage>
#include <QFileDialog>
#include <QMenuBar>

wid::MainWindow::MainWindow()
: myViewWindow(new ViewWindow())
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
    
    addAction(tr("&Terrain"));
    connect(action, SIGNAL(triggered()), this, SLOT(createTerrain()));
    
    addAction(tr("&Sphere"));
    connect(action, SIGNAL(triggered()), this, SLOT(createSphere()));
    
    addAction(tr("&Planet"));
    connect(action, SIGNAL(triggered()), this, SLOT(createPlanet()));
  }
}
#include <iostream>
void wid::MainWindow::import()
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

void wid::MainWindow::createPointSet()
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

void wid::MainWindow::createFacetNetwork()
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

void wid::MainWindow::createTerrain()
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

void wid::MainWindow::createSphere()
{
  std::unique_ptr<vxl::SubBlock<64>> ptr(vxl::Factory::GenerateSphere<64>());
  auto blockModelRep = vxl::Triangulate::SubBlock(*ptr);
  myViewWindow->Handler()->SceneController()->AddObject(blockModelRep);
}
  
void wid::MainWindow::createPlanet()
{
  std::unique_ptr<vxl::SubBlock<64>> ptr(vxl::Factory::GeneratePlanet<64>(20.0f));
  auto blockModelRep = vxl::Triangulate::SubBlock(*ptr);
  myViewWindow->Handler()->SceneController()->AddObject(blockModelRep);
}