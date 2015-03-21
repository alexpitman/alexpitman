#ifndef __WID_GLWIDGET_H
#define __WID_GLWIDGET_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : QGLWidget
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include <QGLWidget>
#include <QKeyEvent>

#include "widget/Dll.h"

#include "viewer/View.h"

namespace wid
{
  class Dll_wid GLWidget : public QGLWidget
  {
    Q_OBJECT
    
  public:
    GLWidget(QWidget* Parent = nullptr);
    ~GLWidget();

    vwr::ViewHandler* Handler() { return myView.Handler(); }

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    
  public slots:
    void animate();
    
  protected:
    
    void initializeGL();
    void paintGL();
    void resizeGL(int Width, int Height);
    
    void mousePressEvent(QMouseEvent* Event);
    void mouseReleaseEvent(QMouseEvent* Event);
    void mouseMoveEvent(QMouseEvent* Event);
    void keyPressEvent(QKeyEvent* Event);
    void keyReleaseEvent(QKeyEvent* Event);
    
  private:

    void handleMouse(QMouseEvent* Event);
  
    vwr::View myView;
    
  };
}

#endif
