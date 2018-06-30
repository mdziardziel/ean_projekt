#include "funkcja1.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Interval.h"
//using namespace std;
using namespace interval_arithmetic;




//funkcja1 B*X^2+A*X -7
//POCHODNA 1 STOPNIA 2*A*X^2-2*B*X+2
//POCHODNA 2 STOPNIA 4*A*X-2*B

long double fx1(long double a, long double b, long double x){
  return b*pow(x,2)+a*x-2;
}

long double fpx1(long double a, long double b, long double x){
  return 2*b*x+a;
}

long double fppx1(long double a, long double b, long double x){
  return 2*b;
}

Interval<long double> ifx1(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return b*x*x+a*x-Interval<long double>::IntRead("2");
}

Interval<long double> ifpx1(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return Interval<long double>::IntRead("2")*b*x+a;
}

Interval<long double> ifppx1(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return Interval<long double>::IntRead("2")*b;
}
