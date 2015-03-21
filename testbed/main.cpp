#include <iostream>

#include <QApplication>

#include "widget/ViewWindow.h"

#include "export/ExportImage.h"

#include "geometry/Point.h"

#include "numeric/Fractal.h"
#include "numeric/Noise.h"
#include "numeric/Random.h"

#include "system/InputStream.h"
#include "import/ImportObjFile.h"

int main(int Argc, char** Argv)
{
  geo::Point3D p(0, 1, 2);

  std::cout << "Hello Cake!" << std::endl;
  std::cout << p.X() << " " << p.Y() << " " << p.Z() << std::endl;
/*
  {
    img::Image image(10, 10);
    
    for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < 10; ++j)
      {
        image(i, j) = att::Colour(i/10.0f, j/10.0f, 0.0f);
      }
    }
    
    ept::ExportImage::Png(image, "test.png");
  }
*/
/*
  {
    int width = 1024;
    int height = 256;
    img::Image image(width, height);
    img::Image fbmImage(width, height);
    
    num::Gradient gradient;
    gradient.setGradient(0, 0, 0, 1);
    
    num::Fractal fbm(num::FractalTypes::FBM, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC);
    fbm.setNumOctaves(6);
    fbm.setFrequency(2.0f);
    
    num::ScaleOffset scaleOffset(0.5f, 0.0f);
    scaleOffset.setSource(&fbm);
    
    num::ScaleDomain scaleDomain;
    scaleDomain.setSource(&scaleOffset);
    scaleDomain.setYScale(0.0f);
    
    num::TranslateDomain translateDomain;
    translateDomain.setSource(&gradient);
    translateDomain.setYAxisSource(&scaleDomain);
    
    for (int x = 0; x < width; ++x)
    {
      const float pX = x / float(width);
    
      for (int y = 0; y < height; ++y)
      {
        const float pY = y / float(height);
      
        if (translateDomain.get(pX, pY) > 0.5f)
        {
          image(x, y) = att::Colour::BlackColour();
        }
        else
        {
          image(x, y) = att::Colour::WhiteColour();
        }
      }
    }
    
    ept::ExportImage::Png(image, "test2.png");
    ept::ExportImage::Png(fbmImage, "test3.png");
  }
*/
  QApplication app(Argc, Argv);
  wid::ViewWindow window;
  
  window.resize(window.sizeHint());
  window.show();

  return app.exec();
}