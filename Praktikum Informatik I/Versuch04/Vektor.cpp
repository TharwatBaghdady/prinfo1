//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einfuehrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <cmath>
#define PI 3.1415926

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Diese Funktion rechent den Bertarg vom eingegebenen Vektor
 * @return gibt Skalar an
 */
double Vektor::laenge() const // Vektor normieren
{
    return sqrt(x*x + y*y + z*z);
}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
	std::cout << "X-Komponente: " << x << std::endl;
	std::cout << "Y-Komponente: " << y << std::endl;
	std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Diese Funktion suptrahiert einen Vektor von dem anderen
 * @param input ist der Vektor, mit dem Subtrahiert wird
 * @return gibt wieder einen Vektor an, welcher das Ergebnis diese Subtraktion ist.
 */
Vektor Vektor::sub(const Vektor &input) const
{
	return Vektor(x - input.x, y - input.y, z - input.z);
}


/**
 * @brief Diese Funktion rechnet das Skalarprodukt von 2 Vektoren
 * @param input ist der Vektor, welche mit dem mit Aufruf dieser Funktion eingegebenem Vektor multipliziert wird
 * @return gibt Skalar an
 */
double Vektor::skalarProd(const Vektor &input) const
{
	double result = (x*input.x)+(y*input.y)+(z*input.z);
	return result;
}

/**
 * @brief Diese Funktion rechnet Winkel, die sich zwischen 2 Vektoren befindet
 * @param input ist ein der beiden Vektoren
 * @return gibt die gesuchte Winkel in Grad an
 */
double Vektor::winkel(const Vektor& input) const
{
    double bertag1 = laenge(); // Betrag vom 1.Vektor wird berechnet
    double bertag2 = input.laenge(); // Betrag vom 2.Vektor wird berechnet
    double skalar = this->skalarProd(input); // Skalarprodukt von 1. und 2. Vektoren wird berchnet, wir haben this Zeiger benutzt, um Call by Reference benutzen zu können.

	return acos((skalar)/(bertag2*bertag1))*(180/PI);
}

/**
 * @brief Diese Funktion besorgt fuer Rotierung eines Vektors um Z-Achse um bestimmte winkel
 * @param rad ist die Winkel, um die der Vektor rotiert wird
 */
void Vektor::rotiereUmZ(double rad){

	double temp = x;
	x = cos(rad) * x - sin(rad) * y;
	y = sin(rad) * temp + cos(rad) * y;
}

