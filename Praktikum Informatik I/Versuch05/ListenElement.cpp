
#include "ListenElement.h"

ListenElement::ListenElement(const Student& pData, ListenElement* const pNext, ListenElement* const pPrev):
    data(pData), next(pNext), prev(pPrev)
{
}

void ListenElement::setData(const Student& pData)
{
    data = pData;
}


void ListenElement::setNext(ListenElement* const pNext)
{
    next = pNext;
}
void ListenElement::setPrev(ListenElement* const pPrev)
{
    prev = pPrev;
}


Student ListenElement::getData() const
{
    return data;
}


ListenElement* ListenElement::getNext() const
{
    return next;
}
ListenElement* ListenElement::getPrev() const
{
    return prev;
}
