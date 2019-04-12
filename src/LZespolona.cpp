#include "LZespolona.hh"
#include <iostream>
#include <math.h>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!                                                                            
 * Realizuje odejmowanie dwoch liczb zespolonych.                              
 * Argumenty:                                                                  
 *    Skl1 - odjemna.                                      
 *    Skl2 - odjemnik.                                         
 * Zwraca:                                                                     
 *    Roznice dwoch skladnikow przekazanych jako parametry.                    
 */


LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!                                                                            
 * Realizuje mnozenie dwoch liczb zespolonych.                                 
 * Argumenty:                                                                  
 *    Skl1 - pierwszy czynnik mnozenia.                                      
 *    Skl2 - drugi czynnik mnozenia.                                         
 * Zwraca:                                                                     
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.                    
 */

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}
/*
Funkcja wykonuje sprzezenie liczby zespolonej, czyli zmiany znaku stojacego przed czescia urojona
*/
LZespolona Sprzezenie (LZespolona Skl1)
{
  LZespolona sprzezenie;
  sprzezenie.im=-Skl1.im;
  sprzezenie.re=Skl1.re;
  return sprzezenie;
}
/*
Funkcja liczy modul liczby zespolonej, czyli pierwiastek z sumy kwadratow wspolczynnikow czesci rzeczywistej i urojonej.
Nastepnie otrzymany modul zostaje podniesiony do kwardatu i zwrocony jako liczba rzeczywsita
*/

double Modul2(LZespolona Skl1)
{
  double modul, modul2;
  modul=sqrt(Skl1.re*Skl1.re+Skl1.im*Skl1.im);
  modul2=pow(modul, 2);
  return modul2;
}

/*!                                                                            
* Realizuje dzielenie dwoch liczb zespolonych.                                
* Argumenty:                                                                   
*    Skl1 - dzielna.                                       
*    Skl2 - dzielnik.                                          
* Zwraca:                                                                      
*    Iloraz dwoch skladnikow przekazanych jako parametry.                     
*/


LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik = (Skl1 * (Sprzezenie(Skl2)))/(Modul2(Skl2));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, double Dzielnik)
{
  LZespolona Wynik;
  Wynik.re = Skl1.re/Dzielnik;
  Wynik.im = Skl1.im/Dzielnik;
  return Wynik;
}
/*!                                                                            
 * Sprawdza czy wartosci dwoch liczb zespolonych sa sobie rowne.                                  
 * Argumenty:                                                                  
 *    Skl1 - pierwsza liczba zespolona.                                      
 *    Skl2 - druga liczba zespolona.                                         
 * Zwraca:                                                                     
 *    wartosc 1 gdy liczby sa rowne.
 *    wartosc 0 gdy liczby sa rozne.                       
 */

int operator == (LZespolona Skl1, LZespolona Skl2)
{
  int odp = 0;
  if((Skl1.re==Skl2.re) && (Skl1.im==Skl2.im))
    odp = 1;
  else
    odp = 0;

  return odp;
}



ostream & operator <<(ostream & StrWyj, LZespolona liczba)
{
  StrWyj<<"("<<liczba.re<<showpos<<liczba.im<<"i)"<<noshowpos;
  return StrWyj;
}

istream& operator >>(istream& StrWej, LZespolona &liczba)
{
  char znak1, znak2, znak3;
  
  StrWej >> znak1; //wczytanie (
  if (StrWej.fail())
  return StrWej;

  if (znak1!='(')
    {
      StrWej.setstate(ios :: failbit);
      return StrWej;
    }
  StrWej >> liczba.re; //wczytanie czesci rzeczywistej
  if(StrWej.fail())
    {
    StrWej.setstate(ios :: failbit);
    return StrWej;
    }
  StrWej >> liczba.im; //wczytanie czesci urojonej
  if(StrWej.fail())
    {
    StrWej.setstate(ios :: failbit);
    return StrWej;
    }
  StrWej >> znak2; //wczytanie 'i'
  if (znak2!='i')
    {
    StrWej.setstate(ios :: failbit);
    return StrWej;
    }
  StrWej >> znak3; //wczytanie )
  if (znak3!=')')
    {
    StrWej.setstate(ios :: failbit);
    return StrWej;
    }
  return StrWej;
}



   
  
