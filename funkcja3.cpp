#include "funkcja3.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Interval.h"
using namespace interval_arithmetic;

using namespace std;

//funkcja3 A*X^3-B*X^2+2*X -7
//POCHODNA 1 STOPNIA 2*A*X^2-2*B*X+2
//POCHODNA 2 STOPNIA 4*A*X-2*B

// 0,9*sin^x-0.5

long double fx3(long double a, long double b, long double x){
  //std::cout<<a*pow(0.9,x)*sin(x)-b;
  return  a*pow(0.9,x)*sin(x)-b;
}

long double fpx3(long double a, long double b, long double x){
  return a*pow(0.9,x)*(cos(x)-0.105361*sin(x));
}

long double fppx3(long double a, long double b, long double x){
  return a*pow(0.9,x)*(-0.98889*sin(x)-0,210722*cos(x));
}

Interval<long double> przyblizenie_potegi(long double liczba, Interval<long double> x){
  long double l = x.a;
  long double r = x.b;
  return Interval<long double>::IntRead(to_string(pow(liczba,r-(r-l))));
}


Interval<long double> ifx3(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return a*przyblizenie_potegi(0.9,x)*ISin(x)-b;
}

Interval<long double> ifpx3(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return a*przyblizenie_potegi(0.9,x)*(ICos(x)-Interval<long double>::IntRead("0.105361")*ISin(x));
}

Interval<long double> ifppx3(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return a*przyblizenie_potegi(0.9,x)*(Interval<long double>::IntRead("-0.98889")*ISin(x)-Interval<long double>::IntRead("0.210722")*ICos(x));
}
