#include <iostream>
#include "BazaTestu.hh"

using namespace std;

int main(int argc, char **argv)
{
  LZespolona odpowiedz;
  
  struct Statystyka
  {
    double PoprawneOdp=0.0;
    double IloscWszystkichOdp=0.0;
    double BledneOdp=0.0;
  };
  
  Statystyka stat;
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
     cout << "Podaj wynik operacji: ";
     cout<<(WyrZ_PytanieTestowe);
    
    LZespolona wynik = Oblicz(WyrZ_PytanieTestowe);
    if(cin.fail()){
      cin.clear();
      cin.ignore(50, '\n');
    };
    
    cin>> odpowiedz;
      if (!cin.fail())
    {
    cout<<"Twoja odpowiedz: "<<odpowiedz<<endl;
    }
    else
      {
      
	for(int i=1; i<3 && cin.fail(); ++i)
	  {
	    cout<<"Niepoprawne wprowadzenie liczby zespolonej. Ilosc prob: "<<3-i<<endl;
	    cin.clear();
	    cin.ignore(50, '\n');
	    cin>>odpowiedz;
	    //cout<<"Twoja odpowiedz: "<<odpowiedz<<endl;
	  }
       
      }
    if (wynik == odpowiedz)
      {
	cout << "Prawidlowy wynik !" << endl;
	++stat.PoprawneOdp;
	++stat.IloscWszystkichOdp;
      }
    else
      {
	cout << "Nieprawidlowy wynik"<<endl;
	++stat.BledneOdp;
	++stat.IloscWszystkichOdp;
      }
    cout <<"Poprawny wynik to: "<< (Oblicz(WyrZ_PytanieTestowe))<<endl;
    cout << endl;
        
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  cout<<"Statystyka"<<endl;
  cout<<"Prawidlowe odpowiedzi: "<<stat.PoprawneOdp<<endl;
  cout<<"Bledne odpowiedzi: "<<stat.BledneOdp<<endl;
  cout<<"Wynik procentowy: "<<(stat.PoprawneOdp/stat.IloscWszystkichOdp)*100<<"%"<<endl;

  LZespolona licz;
  
  {
    licz.re = 3;
    licz.im = 2;
  }
  
}
