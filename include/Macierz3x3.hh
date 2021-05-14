#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include <cmath>
#include "matrix.hh"

/*!
 * \brief Klasa Macierz3x3 ma być instancją szablonu Macierz<>
 *
 *  Zdefiniowanie nowego typu Macierz3x3.
 *  Jest to trójwymiarowa tablica o trzech polach.
 *  Zawiera ona informacje o danych współrzędnych trójwymiarowej 
 *  macierzy. Przeciążenie operatora zapewnia nam odwołanie się do
 *  pól macierzy.
 */
typedef Matrix<3>  Macierz3x3;


Macierz3x3 mac_obr_x(double kat);
Macierz3x3 mac_obr_y(double kat);
Macierz3x3 mac_obr_z(double kat);
#endif
