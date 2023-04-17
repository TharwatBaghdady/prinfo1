

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD : public Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	void ausgabe() const;

	bool ausleihen(Person person, Datum ausleihdatum);

private:
	std::string genre;
	int altersfreigabe;
};

#endif /* DVD_H_ */
