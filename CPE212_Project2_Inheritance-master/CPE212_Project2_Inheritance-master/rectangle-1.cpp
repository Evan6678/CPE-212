#include "rectangle.h"

Rectangle::Rectangle()
{
  l = 0.0;
  w = 0.0;
}
Rectangle::Rectangle(double ll, double ww, int rr, int gg, int bb)
:Shape(rr, gg, bb)
{
  l = ll;
  w = ww;
}

double Rectangle::area() const
{
  return w*l;
}

double Rectangle::perimeter() const
{
  return 2 * (l+w);
}
