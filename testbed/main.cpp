#include <iostream>

#include <QApplication>

#include "widget/ViewWindow.h"

#include "export/ExportImage.h"

#include "geometry/Point.h"

#include "system/InputStream.h"
#include "import/ImportObjFile.h"

int main(int Argc, char** Argv)
{
  geo::Point3D p(0, 1, 2);

  std::cout << "Hello Cake!" << std::endl;
  std::cout << p.X() << " " << p.Y() << " " << p.Z() << std::endl;

  img::Image image(10, 10);
  
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      image(i, j) = att::Colour(i/10.0f, j/10.0f, 0.0f);
    }
  }
  
  ept::ExportImage::Png(image, "test.png");
  
  QApplication app(Argc, Argv);
  wid::ViewWindow window;
  
  window.resize(window.sizeHint());
  window.show();

  return app.exec();
}