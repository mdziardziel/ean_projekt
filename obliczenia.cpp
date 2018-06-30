//Plik: nazwaPliku.cpp

#include "obliczenia.hpp"
#include "funkcja1.hpp"
#include "funkcja2.hpp"
#include "funkcja3.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

long double nr_funkcji;

// dane[1] = parametr a
// dane[2] = parametr b
// dane[3] = ograniczenie 1
// dane[4] = ograniczenie 2
// dane[5] = przedział lewy
// dane[6] = przedział prawy
// dane[7] = liczba kroków

int funkcja_initial(long double * dane,long double * wyniki);

void oblicz( long double * dane, long double * wyniki, int *ile_wierszy)
{
    nr_funkcji = dane[0];
    *ile_wierszy = funkcja_initial(dane, wyniki);
}

long double fx(long double a, long double b, long double x){
  switch((int)nr_funkcji){
    case 1: return fx1(a,b,x); break;
    case 2: return fx2(a,b,x); break;
    case 3: return fx3(a,b,x); break;
    default: return fx1(a,b,x); break;
  }
}

long double fpx(long double a, long double b, long double x){
  switch((int)nr_funkcji){
    case 1: return fpx1(a,b,x); break;
    case 2: return fpx2(a,b,x); break;
    case 3: return fpx3(a,b,x); break;
    default: return fpx1(a,b,x); break;
  }
}

long double fppx(long double a, long double b, long double x){
  switch((int)nr_funkcji){
    case 1: return fppx1(a,b,x); break;
    case 2: return fppx2(a,b,x); break;
    case 3: return fppx3(a,b,x); break;
    default: return fppx1(a,b,x); break;
  }
}

long double ux(long double a, long double b, long double x){
  return fx(a,b,x)/fpx(a,b,x);
}

long double upx(long double a, long double b, long double x){
  return 1 -fppx(a,b,x)/fpx(a,b,x)*ux(a,b,x);
}

long double x_nowe(long double a, long double b, long double x){
  return x - ux(a,b,x)/upx(a,b,x);
}


int funkcja(long double * dane,long double x, int w, long double * wyniki){
  long double a = dane[1], b = dane[2], o1 = dane[3], o2 = dane[4], k = dane[7];
  long double xn = x_nowe(a,b,x);
  wyniki[w] = xn;
  if(x == xn || abs(fx(a,b,x)) <= o1 || abs(x-xn)<= o2 || w + 1 == k){
    return w+1;
  }
  return funkcja(dane,xn,w+1, wyniki);
}

int funkcja_initial(long double * dane,long double * wyniki){
  long double a = dane[1], b = dane[2], pl = dane[5], pp = dane[6], w1 = dane[8], w2 = dane[9];
  std::cout<<fx(a,b,pl)<<" "<<fx(a,b,pp)<<endl;
  if(fx(a,b,pl)*fx(a,b,pp)<=0 || w1 == 1){
    if(fx(a,b,pp)*fppx(a,b,pp)>0){
      wyniki[0] = pp;
      return funkcja(dane, pp, 1, wyniki);
    }else if(fx(a,b,pl)*fppx(a,b,pl) > 0 || dane[9]){
      wyniki[0] = pl;
      return funkcja(dane, pl, 1, wyniki);
    }else{
      wyniki[0] = 503;
      return 1;
    }
  }else{
    wyniki[0] = 404;
    return 1;
  }
}
