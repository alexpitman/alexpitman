///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewWindow
// Inheritance    : QWidget
// Desctription   : View window holder
//
///////////////////////////////////////////////////////////////////////////////

#include "widget/ViewWindow.h"

#include <QHBoxLayout>
#include <QTimer>

wid::ViewWindow::ViewWindow()
: myGLWidget(new GLWidget())
{
  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addWidget(myGLWidget);
  setLayout(mainLayout);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), myGLWidget, SLOT(animate()));
  timer->start(10);
  
  setWindowTitle(tr("Hello GL"));
}

wid::ViewWindow::~ViewWindow()
{
  delete myGLWidget;
}

void 
wid::ViewWindow::keyPressEvent(QKeyEvent* Event)
{
}
