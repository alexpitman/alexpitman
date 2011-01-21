///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : QGLWidget
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "widget/GLWidget.h"

wid::GLWidget::GLWidget(QWidget* Parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), Parent),
  myView()
{
}

wid::GLWidget::~GLWidget()
{
}

QSize 
wid::GLWidget::minimumSizeHint() const
{
  return QSize(50, 50);
}

QSize 
wid::GLWidget::sizeHint() const
{
  return QSize(400, 400);
}

void 
wid::GLWidget::initializeGL()
{
  myView.GLInitialise();
}

void 
wid::GLWidget::resizeGL(int Width, int Height)
{
  myView.Resize(Width, Height);
}

void 
wid::GLWidget::paintGL()
{
  myView.Render();
}

void
wid::GLWidget::animate()
{
  myView.Animate();
  repaint();
}

void 
wid::GLWidget::mousePressEvent(QMouseEvent* Event)
{
  

  //lastPos = event->pos();
}

void 
wid::GLWidget::mouseMoveEvent(QMouseEvent *Event)
{
/*     int dx = event->x() - lastPos.x();
     int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton) {
         setXRotation(xRot + 8 * dy);
         setYRotation(yRot + 8 * dx);
     } else if (event->buttons() & Qt::RightButton) {
         setXRotation(xRot + 8 * dy);
         setZRotation(zRot + 8 * dx);
     }
     lastPos = event->pos();*/
}