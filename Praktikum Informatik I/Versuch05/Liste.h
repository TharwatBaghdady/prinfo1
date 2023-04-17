#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"


class List
{
private:
    ListenElement* front;                                        // Zeiger auf das erste Listenelement
    ListenElement* back;                                        // Zeiger auf das letzte Listenelement
public:
    List();                                                 // Konstruktor mit Zeigerinitialisierung
    void pushBack(const Student &pData);
    void pushFront(const Student &pData);
    bool loeschen(const unsigned int mat_nummer); // um ein Element von der Liste zu loeschen
    bool popFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;

    bool empty() const;                           // testet, ob die Liste leer ist oder nicht

};

#endif /*LISTE_H_*/
