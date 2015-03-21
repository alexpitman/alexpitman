#ifndef __WID_VIEW_WINDOW_H
#define __WID_VIEW_WINDOW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewWindow
// Inheritance    : QWidget
// Description    : View window holder
//
///////////////////////////////////////////////////////////////////////////////

#include <QWidget>

#include "widget/Dll.h"

namespace vwr
{
  class ViewHandler;
}

namespace wid
{
  class GLWidget;

  class Dll_wid ViewWindow : public QWidget
  {
    Q_OBJECT

  public:
   
    ViewWindow();

    vwr::ViewHandler* Handler();
    
  protected:

    void keyPressEvent(QKeyEvent* Event);
    
  private:

    GLWidget* myGLWidget;

  };
}

#endif
