#include "widget/MainWindow.h"

#include "widget/ViewWindow.h"

#include "viewer/ViewHandler.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"

#include <QApplication>
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