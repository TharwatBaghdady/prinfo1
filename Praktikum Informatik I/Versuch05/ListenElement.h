#ifndef _ListenElement_H_
#define _ListenElement_H_

#include "Student.h"

class ListenElement
{
private:
	Student data;
    ListenElement* next;
    ListenElement* prev;

public:
    ListenElement(const Student& pData, ListenElement* const pNext,ListenElement* const pPrev);

    void setData(const Student& pData);
    void setNext(ListenElement* const pNext);
    void setPrev(ListenElement* const pPrev);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;
};

#endif
