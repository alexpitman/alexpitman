#include "widget/ViewWindow.h"

#include <QHBoxLayout>
#include <QTimer>

wid::ViewWindow::ViewWindow()
: myGLWidget(new GLWidget())
{
  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->setSpacing(0);
  mainLayout->setMargin(0);
  mainLayout->addWidget(myGLWidget);
  setLayout(mainLayout);
  
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), myGLWidget, SLOT(animate()));
  timer->start(10);
  
  setWindowTitle(tr("Hello GL"));
}

void 
wid::ViewWindow::keyPressEvent(QKeyEvent* Event)
{
}
