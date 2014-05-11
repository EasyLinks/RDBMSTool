#include "IObject.h"

#include <iostream>

IObject::IObject()
{
    //ctor
}

IObject::~IObject()
{
    //dtor
}

IObject::IObject(const IObject& other)
{
    //copy ctor
}

IObject& IObject::operator=(const IObject& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
