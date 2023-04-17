/*
 * Magazin.cpp
 *
 *  Created on: 18.04.2019
 *      Author: 10346416
 */

#include "Magazin.h"


// Konstruktor
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
	: Medium(initTitel)
{
	sparte=initSparte;
	erscheinungsdatum=initDatumAusgabe;
}



Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe()const {
	Medium::ausgabe();
	std::cout << "Erscheinungsdatum:" << erscheinungsdatum<< std::endl;
	std::cout << "Sparte:" << sparte<< std::endl;
}


//Vererbung von Medium::ausleihen mit dazu 2 extra Bedingungen:
bool Magazin::ausleihen(Person person, Datum ausleihdatum){

	//Erste Bedingung: handelt es sich um die neueste Ausgabe?

	if (ausleihdatum - erscheinungsdatum < 1){ // z.B [18.06.2018 (Ausleihdatum) - 01.05.2018 (Erscheinungsdatum)] ergibt 1 zurück
												// DIE AUSGABE IST EINE GANZE ZAHL VON MONATEN
		std::cout<< "Es handelt sich um die neueste Ausgabe" << std::endl;
	return false;
	}

	//Zweite Bedingung: überprüfen ob der Magazin vorhanden ist?? Medium::ausleihen funktion von medium einfach übernehmen
	return Medium:: ausleihen(person, ausleihdatum);
}
