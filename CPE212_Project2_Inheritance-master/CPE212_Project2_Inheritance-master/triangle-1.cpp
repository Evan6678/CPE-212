#include "triangle.h"

Triangle::Triangle()
{
  a = 0;
  b = 0;
  c = 0;
}

Triangle::Triangle(double aaa, double bbb, double ccc, int rr, int gg, int bb)
:Shape(rr, gg, bb)
{
  a = aaa;
  b = bbb;
  c = ccc;
}

double Triangle:: area() const
{
  return (a + b + c)/2;
}

double Triangle::perimeter() const
{
  return (a + b + c);
}
