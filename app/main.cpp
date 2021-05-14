// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "Prostopadloscian.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"

using namespace std;
/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

#define DL_BOKU 50

void ZapisWspolrzednychDoStrumienia(ostream &StrmWy, Prostopadloscian pros)
{
       StrmWy << pros;
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian pros)
{
       ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              cerr << "🙁  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
                   << "🙁  nie powiodla sie." << endl;
              return false;
       }

       ZapisWspolrzednychDoStrumienia(StrmPlikowy, pros);
       StrmPlikowy << pros[0] << endl;
       StrmPlikowy << pros[1];
       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}

int main()
{
       Wektor3D x;
       char wybor;
  
       Prostopadloscian Pr;        // To tylko przykladowe definicje zmiennej
       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku prostokata

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("prostopadloscian.dat", PzG::RR_Ciagly, 2);
       //
       //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy x,y,z.
       //
       Lacze.ZmienTrybRys(PzG::TR_3D);

       // Ustawienie zakresow poszczegolnych osi
       Lacze.UstawZakresY(-155, 155);
       Lacze.UstawZakresX(-155, 155);
       Lacze.UstawZakresZ(-155, 155);

     
       double kat;
       char os;
       Macierz3x3 pow;
       while (wybor != 'k')
       {
              cout << "MENU GLOWNE:" << endl;
              cout << "-----------------" << endl;
              cout << "o - obrot o zadany kat" << endl;
              cout << "g - powtorz obrot" << endl;
              cout << "t - wypisz macierz" << endl;
              cout << "p - przesuniecie prostokata o zadany wektor" << endl;
              cout << "w - wyswietlanie wspolrzednych wierzcholkow" << endl;
              cout << "r - rysowanie prostokata" << endl;
              cout << "m - wyswietl menu" << endl;
              cout << "k - koniec programu" << endl;
              cout << "Twoj wybor:";
              cin >> wybor;

              switch (wybor)
              {

              case 'o':
              {
                     Macierz3x3 mac;
                     while (1)
                     {
                            cin >> os;
                            if (os == '.')
                                   break;

                            cin >> kat;
                            if (os == 'x')
                                   mac = mac * mac_obr_x(kat);
                            if (os == 'y')
                                   mac = mac * mac_obr_y(kat);
                            if (os == 'z')
                                   mac = mac * mac_obr_z(kat);
                     }
                     pow = mac;
                     Pr.obrot(mac);
                     break;
              }
                 case 't':
                    cout<<pow;
                     break;
              case 'g':
                     Pr.obrot(pow);
                     break;
              case 'p':
                     cout << "Podaj wektor:" << endl;
                     cin >> x;
                     Pr.Translacja(x);
                     break;

              case 'w':
                     cout << Pr;
                     break;

              case 'r':
                     ZapisWspolrzednychDoPliku("prostopadloscian.dat", Pr);
                     Lacze.Rysuj();
                     break;

              case 'm':
                     cout << "MENU GLOWNE:" << endl;
                     cout << "-----------------" << endl;
                     cout << "o - obrot o zadany kat" << endl;
                     cout << "p - przesuniecie prostokata o zadany wektor" << endl;
                     cout << "w - wyswietlanie wspolrzednych wierzcholkow" << endl;
                     cout << "m - wyswietl menu" << endl;
                     cout << "k - koniec programu" << endl;
                     cout << "Twoj wybor:";
                     break;

              default:
                     break;
              }
       }
}