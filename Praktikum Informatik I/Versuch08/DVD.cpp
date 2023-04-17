/*
 * DVD.cpp
 *
 *  Created on: 18.04.2019
 *      Author: 10346416
 */

#include "DVD.h"


// Konstruktor
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
	: Medium(initTitel)
{
	genre=initGenre;
	altersfreigabe=initAltersfreigabe;
}


DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe()const {
	Medium::ausgabe();
	std::cout << "Genre:" << genre<< std::endl;
	std::cout << "Altersfreigabe:" << altersfreigabe<< std::endl;
}

//Vererbung von Medium::ausleihen mit dazu 2 extra Bedingungen:
bool DVD::ausleihen(Person person, Datum ausleihdatum){

	//Erste Bedingung: sind die Altersbeschraenkungen erfuellt?
	Datum alter=person.getGeburtsdatum();

	if ((ausleihdatum - alter) < altersfreigabe*12  ){
		std::cout<< "Die Altersbeschraenkungen sind nicht erfuellt" << std::endl;
	return false;
	}

	//Zweite Bedingung: ueberpruefen ob der DVD ueberhaupt vorhanden ist?? Medium::ausleihen funktion von Medium einfach uebernehmen
	return Medium:: ausleihen(person, ausleihdatum);
}
