//Plik: nazwaPliku.cpp

#include "Iobliczenia.hpp"
#include "funkcja1.hpp"
#include "funkcja2.hpp"
#include "funkcja3.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Interval.h"
using namespace interval_arithmetic;
using namespace std;
long double nr_ifunkcji;

// dane[1] = parametr a
// dane[2] = parametr b
// dane[3] = ograniczenie 1
// dane[4] = ograniczenie 2
// dane[5] = przedział lewy
// dane[6] = przedział prawy
// dane[7] = liczba kroków

int ifunkcja_initial(string * dane,string * wyniki);

void ioblicz(string * dane, string * wyniki, int *ile_wierszy)
{
    nr_ifunkcji = stold(dane[0]);
    *ile_wierszy = ifunkcja_initial(dane, wyniki);
}

Interval<long double> ifx(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  switch((int)nr_ifunkcji){
    case 1: return ifx1(a,b,x); break;
    case 2: return ifx2(a,b,x); break;
    case 3: return ifx3(a,b,x); break;
    default: return ifx1(a,b,x); break;
  }
}

Interval<long double> ifpx(Interval<long double>a, Interval<long double> b, Interval<long double> x){
  switch((int)nr_ifunkcji){
    case 1: return ifpx1(a,b,x); break;
    case 2: return ifpx2(a,b,x); break;
    case 3: return ifpx3(a,b,x); break;
    default: return ifpx1(a,b,x); break;
  }
}

Interval<long double> ifppx(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  switch((int)nr_ifunkcji){
    case 1: return ifppx1(a,b,x); break;
    case 2: return ifppx2(a,b,x); break;
    case 3: return ifppx3(a,b,x); break;
    default: return ifppx1(a,b,x); break;
  }
}

Interval<long double> iux(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return ifx(a,b,x)/ifpx(a,b,x);
}

Interval<long double> iupx(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return Interval<long double>::IntRead("1") -ifppx(a,b,x)/ifpx(a,b,x)*iux(a,b,x);
}

Interval<long double> ix_nowe(Interval<long double> a, Interval<long double> b, Interval<long double> x){
  return x - iux(a,b,x)/iupx(a,b,x);
}


int ifunkcja(string * dane, Interval<long double> x, int w, string * wyniki){
  Interval<long double> a = Interval<long double>::IntRead(dane[1]), b = Interval<long double>::IntRead(dane[2]),
        o1 = Interval<long double>::IntRead(dane[3]), o2 = Interval<long double>::IntRead(dane[4]);
  string k = dane[7];
  Interval<long double> xn = ix_nowe(a,b,x);
  string tmp1, tmp2;
  xn.IEndsToStrings(tmp1, tmp2);
  wyniki[w] = tmp1 + " " + tmp2;
  if((x.a == xn.a && x.b == xn.b) || abs(ifx(a,b,x).a) <= o1.a || abs((x-xn).a)<= o2.a || to_string(w + 1) == k){
    return w+1;
  }
  return ifunkcja(dane,xn,w+1, wyniki);
}

int ifunkcja_initial(string * dane,string * wyniki){
  Interval<long double> a = Interval<long double>::IntRead(dane[1]), b = Interval<long double>::IntRead(dane[2]),
        pl = Interval<long double>::IntRead(dane[5]), pp = Interval<long double>::IntRead(dane[6]);
  string  w1 = dane[8], w2 = dane[9];
  if((ifx(a,b,pl)*ifx(a,b,pp)).b<=0 || w1 == "1"){
    if((ifx(a,b,pp)*ifppx(a,b,pp)).a>0){
      string tmp1, tmp2;
      pp.IEndsToStrings(tmp1, tmp2);
      wyniki[0] = tmp1 + " " + tmp2;
      return ifunkcja(dane, pp, 1, wyniki);
    }else if((ifx(a,b,pl)*ifppx(a,b,pl)).a > 0 || w2 == "1"){
      string tmp1, tmp2;
      pl.IEndsToStrings(tmp1, tmp2);
      wyniki[0] = tmp1 + " " + tmp2;
      return ifunkcja(dane, pl, 1, wyniki);
    }else{
      wyniki[0] = "błąd 503 - funkcja i druga pochodna różne znaki "+ to_string(ifx(a,b,pl).a) + " oraz " + to_string(ifppx(a,b,pl).a);
      return 1;
    }
  }else{
    wyniki[0] = "błąd 404 - krańce przedziałów ten sam znak " + to_string(ifx(a,b,pl).b) + " oraz " + to_string(ifx(a,b,pp).b);
    return 1;
  }
}
