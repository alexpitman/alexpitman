///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : QGLWidget
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "widget/GLWidget.h"

#include "input/Key.h"
#include "input/Mouse.h"

#include <iostream>

wid::GLWidget::GLWidget(QWidget* Parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), Parent),
  myView()
{
  setFocusPolicy(Qt::StrongFocus);
  setMouseTracking(true);
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
  handleMouse(Event);
}

void 
wid::GLWidget::mouseReleaseEvent(QMouseEvent* Event)
{
  handleMouse(Event);
}

void 
wid::GLWidget::mouseMoveEvent(QMouseEvent *Event)
{
  handleMouse(Event);
}

void 
wid::GLWidget::keyPressEvent(QKeyEvent* Event)
{
  myView.KeyPress( in::Key(Event->key(), Event->modifiers()) );
}

void 
wid::GLWidget::keyReleaseEvent(QKeyEvent* Event)
{
  myView.KeyRelease( in::Key(Event->key(), Event->modifiers()) );
}

void
wid::GLWidget::handleMouse(QMouseEvent* Event)
{
  Qt::MouseButtons mb = Event->buttons();

  myView.Mouse( in::Mouse(Event->x(), Event->y(), mb & Qt::LeftButton, mb & Qt::RightButton, mb & Qt::MiddleButton) );
}
