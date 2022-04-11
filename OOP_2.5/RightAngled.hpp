#pragma once
#include <string>
#include <iostream>
#include "Triangle.hpp"

using namespace std;

class RightAngled
{
private:
    Triangle triangle;
    double area;
public:
    RightAngled();
    RightAngled(double);
    RightAngled(RightAngled&);
    RightAngled& operator = (const RightAngled&);
    
    operator string() const;
    friend ostream& operator << (ostream&, const RightAngled&);
    friend istream& operator >> (istream&, RightAngled&);
    
    friend void Read(RightAngled&);
    friend void Display(RightAngled&);
    friend bool Init(Triangle&);

    
    void set_triangle(Triangle triangle) { this->triangle = triangle; };
    void set_area(double value) { area = value; };
    Triangle get_triangle();
    double get_area();

    void area_calculate(Triangle&);
};
