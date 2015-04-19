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
    
  void import();
    
  // Create menu
  void createPointSet();
  void createFacetNetwork();
  
  // Voxel menu
  void createTerrain();
  void createSphere();
  void createPlanet();
  void create2DTerrain();
    
private:

  wid::ViewWindow* myViewWindow;
};

#endif
