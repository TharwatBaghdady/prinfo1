#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
using namespace std;

class Student
{
public:
	Student(); // Konstruktor Student
	Student(unsigned int matNr,  string name,  string geburtstag,  string Adrese);
	unsigned int getMatNr() const;
	 string getName() const;
	 string getgeburtstag() const;
	 string getAdrese() const;
	void ausgabe() const;
	unsigned int matNr;
private:

     string name;
     string geburtstag;
     string Adrese;
};

#endif
