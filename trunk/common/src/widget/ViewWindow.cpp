///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewWindow
// Inheritance    : QWidget
// Desctription   : View window holder
//
///////////////////////////////////////////////////////////////////////////////

#include "widget/ViewWindow.h"

#include <QHBoxLayout>

wid::ViewWindow::ViewWindow()
: myGLWidget(new GLWidget())
{
  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addWidget(myGLWidget);
  setLayout(mainLayout);

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
