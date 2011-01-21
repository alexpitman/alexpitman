#ifndef __WID_VIEW_WINDOW_H
#define __WID_VIEW_WINDOW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewWindow
// Inheritance    : QWidget
// Desctription   : View window holder
//
///////////////////////////////////////////////////////////////////////////////

#include <QWidget>

#include "widget/GLWidget.h"

namespace wid
{
  class ViewWindow : public QWidget
  {
    Q_OBJECT

  public:
   
    ViewWindow();
    ~ViewWindow();

  protected:

    void keyPressEvent(QKeyEvent* Event);

  private:

    GLWidget* myGLWidget;

  };
}

#endif
