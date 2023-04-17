#include "Buch.h"


// Konstruktor
Buch::Buch(std::string initTitel, std::string initAutor)
	: Medium(initTitel) // initialiserungsliste
{
	autor=initAutor;
}

Buch::~Buch() // Kann nicht rein Virtuell sein, denn wir objekte von Buch haben
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe()const {
	Medium::ausgabe();
	std::cout << "Autor:" << autor<< std::endl;
}
