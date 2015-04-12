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
    
  void createPointSet();
  void createFacetNetwork();
  void createTerrain();
  void createSphere();
  void createPlanet();
    
private:

  wid::ViewWindow* myViewWindow;
};

#endif
