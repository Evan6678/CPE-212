#ifndef SHAPE_H
#define SHAPE_H

#include "color.h"
#include <iostream>       //debugging with cout

using namespace std;

class Shape
{
private:

  Color c;                    //color object

public:
  Shape();                    //default Constructor

  Shape(int r,int g,int b);   //overload Constructor

  Color getColor() const;     //retuns value of Color

  virtual double area() const;        //returns default area

  virtual double perimeter() const;   //returns default perimeter

};

#endif
