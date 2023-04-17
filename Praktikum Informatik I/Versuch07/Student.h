#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <ostream>

class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string geburtsdatum, std::string adrese);
	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getgeburtsdatum() const;
	std::string getadrese() const;
	void ausgabe() const;
	void ausgabe(std::ostream& ostr) const;
	bool operator ==(const Student& student) const;
	bool operator < (const Student& student) const;
	bool operator > (const Student& student) const;
    unsigned int matNr;


private:

    std::string name;
    std::string geburtsdatum;
    std::string adrese;
};

#endif
