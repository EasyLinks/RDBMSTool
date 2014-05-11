#include "ContainerA.h"

#include <iostream>

easylink::data::ContainerA::ContainerA()
{
    __initialized__ = bool(false);
    __restricted__ = bool(false);
}

easylink::data::ContainerA::~ContainerA()
{
    if (__initialized__)
    {
        delete _container;
    }
}
