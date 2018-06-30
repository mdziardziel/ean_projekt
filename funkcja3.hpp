//Plik: nazwaPliku.hpp
#ifndef funkcja3_hpp
#define funkcja3_hpp

#include "Interval.h"
using namespace interval_arithmetic;

long double fx3(long double a, long double b, long double x);
long double fpx3(long double a, long double b, long double x);
long double fppx3(long double a, long double b, long double x);

Interval<long double> ifx3(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifpx3(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifppx3(Interval<long double> a, Interval<long double> b, Interval<long double> x);

#endif
