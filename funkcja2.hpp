//Plik: nazwaPliku.hpp
#ifndef funkcja2_hpp
#define funkcja2_hpp

#include "Interval.h"
using namespace interval_arithmetic;

long double fx2(long double a, long double b, long double x);
long double fpx2(long double a, long double b, long double x);
long double fppx2(long double a, long double b, long double x);

Interval<long double> ifx2(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifpx2(Interval<long double> a, Interval<long double> b, Interval<long double> x);
Interval<long double> ifppx2(Interval<long double> a, Interval<long double> b, Interval<long double> x);

#endif
