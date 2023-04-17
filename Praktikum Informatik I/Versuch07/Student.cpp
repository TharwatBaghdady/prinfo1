#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string geburtsdatum, std::string adrese) :
matNr(matNr), name(name), geburtsdatum(geburtsdatum), adrese(adrese)
{ }

Student::Student() : matNr(0), name(""), geburtsdatum(""), adrese("")
{ }

unsigned int Student::getMatNr() const
{
	return this->matNr;
}

std::string Student::getName() const
{
	return this->name;
}

std::string Student::getgeburtsdatum() const
{
	return this->geburtsdatum;
}

std::string Student::getadrese() const
{
	return this->adrese;
}

void Student::ausgabe() const
{
    std::cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getgeburtsdatum() << " wohnhaft in " << this->getadrese()
              << std::endl;
}

void Student::ausgabe(std::ostream& ostr) const
{
    ostr << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getgeburtsdatum() << " wohnhaft in " << this->getadrese()
              << std::endl;
}

bool Student::operator == (const Student& student) const
{
	if(matNr == student.getMatNr())
	{
		return true;
	}
	return false;
}

bool Student::operator < (const Student& student) const{
	if (matNr < student.matNr)
	{
		return true;
	}
	return false;

}

bool Student::operator > (const Student& student) const{
	if (matNr > student.matNr)
	{
		return true;
	}
	return false;

}

