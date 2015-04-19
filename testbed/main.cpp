#include <QApplication>

#include "MainWindow.h"

int main(int Argc, char** Argv)
{
  QApplication app(Argc, Argv);
  MainWindow window;
  
  window.resize(window.sizeHint());
  window.show();

  return app.exec();
}