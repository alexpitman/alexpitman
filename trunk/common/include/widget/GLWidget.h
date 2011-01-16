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

#include "viewer/View.H"

namespace wid
{
  class GLWidget : public QGLWidget
  {
  //  Q_OBJECT
    
  public:
    GLWidget(QWidget* Parent = NULL);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    
  protected:
    
    void initializeGL();
    void paintGL();
    void resizeGL(int Width, int Height);
    void mousePressEvent(QMouseEvent* Event);
    void mouseMoveEvent(QMouseEvent* Event);
    
  private:

    vwr::View myView;
    
  };
}

#endif
