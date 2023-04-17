

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium
{
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch(); // beim L�schen von Medium wird Buch nicht automatisch gel�scht und deswegen ist der Destruktor virtuell

	void ausgabe() const;


private:
	std::string autor;

};

#endif /* BUCH_H_ */
