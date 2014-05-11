#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <stdlib.h>


class Utility
{
public:
    Utility();
    virtual ~Utility();
    template <typename T> static void* copy(T value)
    {
        T* temp = new T;
        *temp = value;
        return (void*)temp;
    }

    static void* rawCopy(void* value, unsigned int size)
    {
        void* temp = (void*)malloc(size);
        for (unsigned int i = 0; i < size; ++i)
        {
            *((char*)temp + i) = *((char*)value + i);
        }
        return temp;
    }

    template <typename T> static T Type()
    {
        return *(new T);
    }

protected:
private:
};

class Error
{
    public:
        static const int NO_ERROR = 0;
        static const int MULTIPLE_INITIALIZATION = 1;
        static const int INCORRECT_TYPE_PASSED = 2;
        static const int NOT_INITIALIZED = 3;
    protected:
    private:
};

#endif // UTILITY_H
