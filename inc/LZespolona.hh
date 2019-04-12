#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

void Wyswietl (LZespolona arg);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator - (LZespolona Skl1, LZespolona Skl2); 

LZespolona operator * (LZespolona Skl1, LZespolona Skl2);

LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

LZespolona operator / (LZespolona Skl1, double Dzielnik);

LZespolona Sprzezenie (LZespolona Skl1);

double  Modul2(LZespolona Skl1);

int operator == (LZespolona Skl1, LZespolona Skl2);

ostream & operator <<(ostream & StrWyj, LZespolona liczba);

istream& operator >>(istream& StrWej, LZespolona &liczba);

#endif
