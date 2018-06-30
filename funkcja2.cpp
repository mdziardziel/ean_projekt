#include "funkcja2.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Interval.h"
using namespace interval_arithmetic;

using namespace std;

//funkcja2 A*X^3-B*X^2+2*X -7
//POCHODNA 1 STOPNIA 2*A*X^2-2*B*X+2
//POCHODNA 2 STOPNIA 4*A*X-2*B

long double fx2(long double a, long double b, long double x){
  return a+b*sin(x);
}

long double fpx2(long double a, long double b, long double x){
  return b*cos(x);
}

long double fppx2(long double a, long double b, long double x){
  return -b*sin(x);
}

Interval<long double> ifx2(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return a+b*ISin(x);
}

Interval<long double> ifpx2(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return b*ICos(x);
}

Interval<long double> ifppx2(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return Interval<long double>::IntRead("-1")*b*ISin(x);
}
