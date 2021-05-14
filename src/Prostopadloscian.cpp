#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian()
{

     Punk[1][0] += 100;

    Punk[2][1] += 100;

    Punk[3][0] += 100;
    Punk[3][1] += 100;

    Punk[4][1] += 100;
    Punk[4][2] += 100;

    Punk[5][0] += 100;
    Punk[5][1] += 100;
    Punk[5][2] += 100;

    Punk[6][2] += 100;

    Punk[7][0] += 100;
    Punk[7][2] += 100;
}

Prostopadloscian::Prostopadloscian(Wektor3D start, double wys, double szer, double dlug)
{
    for (int i = 0; i < ROZM_P; i++)
    {
        Punk[i] = start;
    }

    Punk[1][0] += dlug;

    Punk[2][1] += szer;

    Punk[3][0] += dlug;
    Punk[3][1] += szer;

    Punk[4][1] += szer;
    Punk[4][2] += wys;

    Punk[5][0] += dlug;
    Punk[5][1] += szer;
    Punk[5][2] += wys;

    Punk[6][2] += wys;

    Punk[7][0] += dlug;
    Punk[7][2] += wys;
}

const Wektor3D Prostopadloscian::operator[](int index) const
{
    if (index > ROZM_P || index < 0)
    {
        cerr << "Indeks poza skala" << endl;
        exit(1);
    }
    return Punk[index];
}

Wektor3D &Prostopadloscian::operator[](int index)
{
    if (index > ROZM_P || index < 0)
    {
        cerr << "Indeks poza skala" << endl;
        exit(1);
    }
    return Punk[index];
}

std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr)
{
    for (int i = 0; i < ROZM_P; i++)
    {
        Strm << Pr[i] << endl;
        if((i+1)%2==0)
               Strm << endl;
    }
    return Strm;
}

void Prostopadloscian::Translacja(Wektor3D arg)
{
    *this = *this + arg;
}

Prostopadloscian Prostopadloscian::operator*(Macierz3x3 arg)
{
    Prostopadloscian Wynik;
    for (int i = 0; i < ROZM_P; i++)
    {
        Wynik[i] = arg * Punk[i];
    }
    return Wynik;
}

void Prostopadloscian::obrot(Macierz3x3 Mac)
{

    *this = *this * Mac;
}

Prostopadloscian Prostopadloscian::operator+(Wektor3D arg)
{
    Prostopadloscian Wynik;
    for (int i = 0; i < ROZM_P; i++)
    {
        Wynik[i] = Punk[i] + arg;
    }
    return Wynik;
}

Prostopadloscian Prostopadloscian::operator-(Wektor3D arg)
{
    Prostopadloscian Wynik;
    for (int i = 0; i < ROZM_P; i++)
    {
        Wynik[i] = Punk[i] - arg;
    }
    return Wynik;
}

