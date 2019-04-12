#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */



LZespolona Oblicz (WyrazenieZesp WyrZ)
{
  LZespolona Wynik;
  switch(WyrZ.Op)
    {
     case Op_Dodaj:
     Wynik = WyrZ.Arg1+WyrZ.Arg2;
     break;
     case Op_Odejmij:
     Wynik = WyrZ.Arg1-WyrZ.Arg2;
     break;
     case Op_Mnoz:
     Wynik = WyrZ.Arg1*WyrZ.Arg2;
     break;
     case Op_Dziel:
     Wynik = WyrZ.Arg1/WyrZ.Arg2;
     break;
    }
    return Wynik;
}


ostream & operator <<(ostream & StrWyj, WyrazenieZesp WyrZ){
  StrWyj << WyrZ.Arg1;
  if(WyrZ.Op == Op_Dodaj)
    StrWyj << " + " ; // Znak operatora
  else if(WyrZ.Op == Op_Odejmij)
    StrWyj << " - " ; // Znak operatora
  else if(WyrZ.Op == Op_Mnoz)
    StrWyj << " * " ; // Znak operatora
  else if(WyrZ.Op == Op_Dziel)
    StrWyj << " / " ; // Znak operatora
  StrWyj << WyrZ.Arg2;
  StrWyj << " =" << endl;
  return StrWyj;
}

istream& operator >> (istream& StrWej, WyrazenieZesp WyrZ)
{
  StrWej >> WyrZ.Arg1;
  if (StrWej.fail())
    return StrWej;
  cout << WyrZ.Op;
  if(WyrZ.Op == '+')             //sprawdzenie znaku operacji
    WyrZ.Op = Op_Dodaj;
  else if(WyrZ.Op == '-')
    WyrZ.Op = Op_Odejmij;
  else if(WyrZ.Op == '*')
    WyrZ.Op = Op_Mnoz;
  if(WyrZ.Op == '/')
    WyrZ.Op = Op_Dziel;
  StrWej >> WyrZ.Arg2;

  return StrWej;
  
}
