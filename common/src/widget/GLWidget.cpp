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
/*  glClearColor(0.0, 0.0, 0.0);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_MULTISAMPLE);*/
}

void 
wid::GLWidget::resizeGL(int Width, int Height)
{
  myView.Resize(Width, Height);
//  int side = qMin(Width, Height);
/*  glViewport((Width - side) / 2, (Height - side) / 2, side, side);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);

  glMatrixMode(GL_MODELVIEW);*/
}

void 
wid::GLWidget::paintGL()
{
  myView.Render();
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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