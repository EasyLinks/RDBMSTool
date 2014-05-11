#include "Container.h"
/*
template <typename T> Container<T>::Container()
{
    //ctor
}

template <typename T> Container<T>::~Container()
{
    //dtor
}

template <typename T> Container<T>::Container(const Container& other)
{
    //copy ctor
}*/

template <typename T> Container<T>& Container<T>::operator=(const Container<T>& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
