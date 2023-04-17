/*
 * Magazin.h
 *
 *  Created on: 18.04.2019
 *      Author: 10346416
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin : public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();

	void ausgabe() const;

	bool ausleihen(Person person, Datum ausleihdatum);

private:
	Datum erscheinungsdatum;
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
