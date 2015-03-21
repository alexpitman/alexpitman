#include "widget/MainWindow.h"

#include "widget/ViewWindow.h"

#include <QApplication>
#include <QMenuBar>

wid::MainWindow::MainWindow()
: myViewWindow(new ViewWindow())
{
  setCentralWidget(myViewWindow);
  setWindowTitle(tr("Application"));
  
  QMenu* menu;
  QAction* action;
  
  auto addMenu = [&](const QString& Name)
    {
      menu = menuBar()->addMenu(Name);
    };
  auto addAction = [&](const QString& Name)
    {
      action = menu->addAction(Name);
    };
  
  // File menu.
  {
    addMenu(tr("&File"));

    addAction(tr("&Quit"));
    connect(action, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
  }
}

