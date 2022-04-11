#include "RightAngled.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

bool Init(Triangle& f)
{
    double d1 = f.get_a();
    double d2 = f.get_b();
    double d3 = f.get_c();

    if(f.get_b() > d1)
    {
        d1 = f.get_b();
        d2 = f.get_a();
    }
    if(f.get_c() > d1)
    {
        d1 = f.get_c();
        d2 = f.get_a();
        d3 = f.get_b();
    }

    if ((d1*d1) == (d2*d2 + d3*d3))
    {
        return true;
    }
    else
    {
        cout << "Sides don't make right angled triangle!" << endl;
        return false;
    }
}

RightAngled::RightAngled() {
    area = 0;
}

RightAngled::RightAngled(double f) {
    area = f;
}

RightAngled::RightAngled(RightAngled& f) {
    triangle = f.triangle;
    area = f.area;
}

RightAngled& RightAngled::operator = (const RightAngled& f) {
    triangle = f.triangle;
    area = f.area;
    return *this;
}

istream& operator >> (istream& in, RightAngled& f)
{
    do
    {
        cin >> f.triangle;
    }
    while(!Init(f.triangle));
    return in;
}

ostream& operator << (ostream& out, const RightAngled& a)
{
    out << string(a);
    return out;
}

RightAngled::operator string () const
{
    stringstream f;
    f << triangle;
    return f.str();
}

void RightAngled::area_calculate(Triangle& t)
{
    double p = t.perimeter() / 2;
    double s1 = t.get_a();
    double s2 = t.get_b();
    double s3 = t.get_c();
    
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}

Triangle RightAngled::get_triangle()
{
    return triangle;
};

double RightAngled::get_area()
{
    area_calculate(triangle);
    return area;
}

void Read(RightAngled& f)
{
    cin >> f;
}

void Display(RightAngled& f)
{
    Display(f.triangle);
    cout << "Area: " << f.get_area() << endl;
}
