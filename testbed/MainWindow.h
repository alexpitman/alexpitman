#ifndef __TST_MAIN_WINDOW_H
#define __TST_MAIN_WINDOW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : MainWindow
// Inheritance    : QMainWindow
// Description    : Main application window for the test application
//
///////////////////////////////////////////////////////////////////////////////

#include <QMainWindow>

#include "widget/ViewWindow.h"

namespace wid
{
  class ViewWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
   
  MainWindow();
    
private slots:
    
  // File menu
  void import();
    
  // Create menu
  void createPointSet();
  void createFacetNetwork();
  
  // Voxel menu
  void createTerrain();
  void createSphere();
  void createPlanet();
  void create2DTerrain();
    
  // Shader menu
  void testShader();
  
  void zoom();
  
private:

  void buildMenu();
  void buildToolBar();

  wid::ViewWindow* myViewWindow;
};

#endif
