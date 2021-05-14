#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "Prostopadloscian.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
TEST_CASE("test wektora kostruktor")
{
    Vector<3> tmp; 
    CHECK(tmp[0]== 0);
    CHECK(tmp[1]== 0); 
}

TEST_CASE("test wektora kostruktor parametycznego")
{
    double wek[]={2,3};
    Vector<3> tmp(wek);
    CHECK(tmp[0]== 2); 
    CHECK(tmp[1]== 3); 
} 

TEST_CASE("test wektora +")
{
    double wek[]={2,3}; 
    Vector<3> tmp(wek); 
    Vector<3> tmp2(wek); 
    tmp2 = tmp2 + tmp; 
    CHECK(tmp2[0]== 4); 
    CHECK(tmp2[1]== 6); 
}

TEST_CASE("sprawdzenie []") 
{
    double wek[]={2,3}; 
    Vector<3> tmp(wek); 
    WARN_THROWS(tmp[10]); 
}

TEST_CASE("wektor - wyswietlanie standard") 
{
    double wek[]={2,3}; 
    Vector<3> tmp(wek); 
    std::ostringstream out; 
    out <<tmp; 
    CHECK( "2 3 2 " == out.str() ); 
}

TEST_CASE("wektor - wczytywanie standard") 
{ 
    Vector<3> tmp;
    std::istringstream in("3 4"); 
    in >> tmp; 
    std::ostringstream out; 
    out <<tmp;
    CHECK( "3 4 0 " == out.str() ); 
} 

TEST_CASE("test wektora ==") 
{ 
    Vector<3> tmp,tmp2; 
    CHECK( tmp==tmp2 );
}




TEST_CASE("test macierzy kostruktor")
{ 
    Matrix<3> tmp;
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    CHECK(tmp(i,j)== 1.0); 
}

TEST_CASE("test macierzy kostruktor parametycznego")
{
    double x[3][3]={{1,1},{1,1}};
    Matrix<3> tmp(x);
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    CHECK(tmp(i,j)== 1);
}

TEST_CASE("test wektora *")
{
    Matrix<3> tmp;
    double wek[]={2,3};
    Vector<3> tmp2(wek);
    tmp2 = tmp * tmp2;
    CHECK(tmp2[0]== 2.0);
    CHECK(tmp2[1]== 3.0);
} 

TEST_CASE("sprawdzenie ()")
{
    Matrix<3> tmp;
    WARN_THROWS(tmp(12,31));
}





TEST_CASE("test prostokata kostruktor parametycznego")
{

    Prostopadloscian tmp;
    CHECK(tmp[0][0]== 30);
    CHECK(tmp[0][1]== 20);
}

TEST_CASE("prostokata - wyswietlanie standard") 
{

    Prostopadloscian tmp;
    std::ostringstream out;
    out <<tmp; 
    CHECK( "30 20 \n230 20 \n230 120 \n30 120 \n" == out.str() ); 
}

TEST_CASE("test prostokata kostruktor parametycznego")
{

    Prostopadloscian tmp;
    double wek2[]={10,10};
  tmp=tmp+wek2;
    CHECK(tmp[0][0]== 10);
    CHECK(tmp[0][1]== 10); 
     CHECK(tmp[0][2]== 10); 
}

