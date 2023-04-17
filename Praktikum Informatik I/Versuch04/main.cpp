//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.1415927

int main()
{

    // Ausdruck-funktion
	Vektor vektor1(1,2,3);
	Vektor vektor2(4,5,6);


	vektor1.ausgabe();
	vektor2.ausgabe();
	 cout<<""<< endl;

	 cout <<" 1- Die Leange des 1.Vektors ist "<< vektor1.laenge()<< endl;
	 cout <<"    Die Leange des 2.Vektors ist "<< vektor2.laenge()<< endl;
	 cout<<""<< endl;

	// Subtarhtionsfunktion
	vektor1.sub(vektor2);
	vektor2.sub(vektor1);

	 cout <<"2- Die Subtraktion des 1. Vektors von 2. ist "<<  endl;
	vektor1.sub(vektor2).ausgabe();
	 cout <<"   Die Subtraktion des 2. Vektors von 1. ist "<< endl;
	vektor2.sub(vektor1).ausgabe();
	 cout<<""<< endl;

	// Skalarprodukt

	 cout <<"3- Das Skalarprodukt vom 1. und 2.Vektor ist "<< vektor1.skalarProd(vektor2) <<  endl;
	 cout<<""<< endl;

	// Winkel zwischen den 2 Vektoren
	double der_winkel = vektor1.winkel(vektor2);
	 cout <<"4- Die gesuchte Winkel in Grad betraegt "<< der_winkel <<  endl;
	 cout<<""<< endl;

	// Rotierung um Z-Achse
	double rad;
	 cout << "5- Geben Sie bitte die radiante Winkel, um die die Vektoren um Z-Achse rotiert wird: ";
	 cin >> rad;
	vektor1.rotiereUmZ(rad);
	vektor2.rotiereUmZ(rad);

	// Aufgabe 4.6.2, Berechnung der Distanz und Winkel

	Vektor erde (6371,0,0);
	Vektor mensch(6371.5574,0,0);
	Vektor  entfernung_vektor = mensch.sub(erde);
	double winkel_rad = 0.00000001; // Winkel, um die das Radius von der Erde rotiert wird = Winkel von einem Schritt.
	double winkelRad = 0;
	double entfernung = 0;
	int schritte = 0;

	while(erde.skalarProd(entfernung_vektor) >= 0)
	// Alternativ
	//while(entfernung_vektor.winkel(erde) <= 90)
	{
		erde.rotiereUmZ(winkel_rad);
		entfernung_vektor = mensch.sub(erde); // Vektor zwischen dem Mensch und dem aktuellen Punkt.
		entfernung = entfernung_vektor.laenge();
		winkelRad += winkel_rad; // Winkel in Rad
		schritte++;
	}

	double winkelGrad = 0;
	winkelGrad = (winkelRad * 180) / PI; // Winkel in Grad umgerchnet.
	double hoch = (mensch.laenge() - 6371)*1000; //erde subtrahieren dann km in m umwandeln

	 cout<<""<< endl;
	 cout<<"6- Aufgabe der Distanz und Winkel: "<< endl;
	 cout<<""<< endl;
	 cout<<"Sie koennen "<< entfernung <<" Km weit sehen."<< endl;
	 cout<<"Sie sind "<< hoch <<" Meter hoch."<< endl;
	 cout<<"Der Winkel betraegt "<< winkelGrad <<" Grad."<< endl;
	 cout<<"Anzahl Schritte : "<< schritte << endl;

    return 0;

}
