#ifndef __WID_MAIN_WINDOW_H
#define __WID_MAIN_WINDOW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : MainWindow
// Inheritance    : QMainWindow
// Description    : Main application window
//
///////////////////////////////////////////////////////////////////////////////

#include <QMainWindow>

#include "widget/Dll.h"
#include "widget/ViewWindow.h"

namespace wid
{
  class ViewWindow;

  class Dll_wid MainWindow : public QMainWindow
  {
    Q_OBJECT

  public:
   
    MainWindow();
    
  private:

    ViewWindow* myViewWindow;

  };
}

#endif
