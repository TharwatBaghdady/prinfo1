 /**
 * @file List.cpp
 * content: linked list data structure
 */

#include "Liste.h"

List::List(): front(nullptr), back(nullptr)
{
}


/**
 * @brief Die Funktion fuegt ein Element am Ende der Liste hinzu
 * @param pData ist das Element, welches am Ende der Liste hinzugefuegt werden soll
 *@return void
 */

void List::pushBack(const Student &pData)
{
	ListenElement* neuesElement = new ListenElement(pData, nullptr,nullptr);

	    if (front == nullptr)                              // liste leer?!
	    {
	        front = neuesElement;
	        back = neuesElement;
	    }
	    else
	    {
	        back->setNext(neuesElement);
	        neuesElement->setPrev(back);
	        back = neuesElement;
	    }

}


/**
 * @brief popFront loescht ein Element vom Anfang der Liste.
 *
 *
 * @param
 * @return bool
 */
bool List::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthaelt nur ein Listenelement
    {
        delete front;                                        // Listenelement loeschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        delete cursor;
    }
    return true;

}

/**
 * @brief ausgabe content from first to last element.
 *
 * ausgabes to cout.
 *
 * @return void
 */
void List::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr) // Ausgabe in Reihenfolge vom Anfang
    {
        cursor->getData().ausgabe();

        cursor = cursor->getNext();
    }

}
/**
 * @brief Die Funktion gibt die Elemente in umgekehrter Reihenfolge
 *
 * @return void
 */
void List::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	 while (cursor != nullptr) // Ausgabe in Reihenfolge vom Ende, auch am Anfang gibt es nullptr
	    {
	        cursor->getData().ausgabe();

	        cursor = cursor->getPrev();
	    }
	}

/**
 * @brief Diese Funktion loescht ein Element
 *
 * @param mat_nummer ist Matrik-N, welches geloescht werden soll
 * @return true wenn das gesuchte Element schon gefunden und dann geloescht wird, false wenn das gesuchte Element nicht gefunden
 */
bool List::loeschen(const unsigned int mat_nummer)
{
	ListenElement* cursor = front;
	    while(cursor->getData().getMatNr()!=mat_nummer) // Alle Elemente mit dem Eingegeben vergleichen
	    {
	    	if(cursor==nullptr) // Wir habe das Ende erreicht, Element wurde nicht gefunden
	    	{
	    		return false;
	    	}
	    	cursor=cursor->getNext();
	    }
	    if(front==back) // Es geht um nur ein Element
	    {
	    	front=back=nullptr;
	    }
	    else if(cursor==back) //Element ist back
	    {
	    	cursor->getPrev()->setNext(cursor->getNext());
	    	back=cursor->getPrev();
	    }
	    else if(cursor==front)  //Element ist front
	    {
			cursor->getNext()->setPrev(cursor->getPrev());
			front=cursor->getNext();
	    }
	    else
	    {
	    	cursor->getPrev()->setNext(cursor->getNext());
	    	cursor->getNext()->setPrev(cursor->getPrev());
	    }
	    delete cursor;
	    return true;
	}



/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::pushFront(const Student &pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr,nullptr);

    if (back == nullptr)                                       // ist die liste leer??
    {
        back = neuesElement;
        front = neuesElement;
    }
    else
    {
    	neuesElement->setNext(front);
        front->setPrev(neuesElement);

        front = neuesElement;
    }


}

/**
 * @brief Diese Funktion testet, ob die Liste leer ist oder nicht
 * @return true wenn die Liste leer, sonst false
 */
bool List::empty() const
{
	return (front==nullptr); //true wenn die Liste leer ist

	}
