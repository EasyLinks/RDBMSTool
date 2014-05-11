#include "Entry.h"
using namespace easylink::data;
Entry::Entry()
{
    //ctor
}

Entry::~Entry()
{
    for (auto pointer = _fields.begin(); pointer != _fields.end(); ++pointer)
    {
        delete *pointer;
    }
}
