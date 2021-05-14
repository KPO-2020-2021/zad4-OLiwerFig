#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#define ROZM_P 8
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostopadloscian {

  Wektor3D Punk[ROZM_P];
 
  Macierz3x3 Mac;
public:
  
  Prostopadloscian();
  
  Prostopadloscian(Wektor3D start, double wys, double szer, double dlug);
 
  const Wektor3D operator[](int index) const;
  
  Wektor3D &operator[](int index);

  Prostopadloscian operator+(Wektor3D arg);

  Prostopadloscian operator-(Wektor3D arg);
 
  void Translacja(Wektor3D arg); 

  Prostopadloscian operator *(Macierz3x3 arg);
  
  void obrot(Macierz3x3 Mac);
 
};



std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr
                          );


#endif
