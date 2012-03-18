#include <iostream>

#include <QApplication>

#include "widget/ViewWindow.h"

#include "geometry/Point.h"

#include "system/InputStream.h"
#include "import/ImportObjFile.h"

int main(int Argc, char** Argv)
{
  geo::Point3D p(0, 1, 2);

  std::cout << "Hello Cake!" << std::endl;
  std::cout << p.X() << " " << p.Y() << " " << p.Z() << std::endl;

  QApplication app(Argc, Argv);
  wid::ViewWindow window;
  
  window.resize(window.sizeHint());
  window.show();

  return app.exec();
}