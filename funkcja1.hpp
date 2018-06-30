//Plik: nazwaPliku.hpp
#ifndef funkcja1_hpp
#define funkcja1_hpp

#include "Interval.h"
using namespace interval_arithmetic;

long double fx1(long double a, long double b, long double x);
long double fpx1(long double a, long double b, long double x);
long double fppx1(long double a, long double b, long double x);


Interval<long double> ifx1(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifpx1(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifppx1(Interval<long double> a, Interval<long double> b, Interval<long double> x);

#endif
