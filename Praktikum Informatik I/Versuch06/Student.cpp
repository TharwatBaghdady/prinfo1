#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(unsigned int matNr,  string name,  string geburtstag,  string Adrese) :// Konstruktor mit Parameter
matNr(matNr), name(name), geburtstag(geburtstag), Adrese(Adrese) // Initialisierungsliste
{ }

Student::Student() : matNr(0), name(""), geburtstag(""), Adrese("")
{ }

unsigned int Student::getMatNr() const
{
	return this->matNr;
}

 string Student::getName() const
{
	return this->name;
}

 string Student::getgeburtstag() const
{
	return this->geburtstag;
}

 string Student::getAdrese() const
{
	return this->Adrese;
}

void Student::ausgabe() const
{
     cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getgeburtstag() << " wohnhaft in " << this->getAdrese()
              <<  endl;
}
