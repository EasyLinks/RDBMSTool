#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <iostream>
#include <sstream>
#include <IContainer.h>
#include <IObject.h>
#include <Utility.h>
#include <DataWrap.h>


template <typename Type>
class Container : public IContainer
{
public:
    Container()
    {
        _data = new Type;
        *(Type*)_data = Type();
    }
    virtual ~Container() {}
    Container& operator=(const Container& other);
    virtual std::string toString()
    {
        std::stringstream stringBuffer;
        if (_data)
        {
            stringBuffer << *(Type*)_data;
        }
        return stringBuffer.str();
    }
    virtual IContainer* distinguishData(std::string value)
    {
        std::stringstream sstream;
        sstream << value;
        sstream >> *(Type*)_data;
        return this;
    }
    virtual IContainer* setData(easylink::data::DataWrap value)
    {
        if (value.getType() == &typeid(Type))
        {
            _data = value.getData();
        }
        return this;
    }
    virtual IContainer* duplicate()
    {
        auto temp = new Container<Type>();
        temp->setData(*(Type*)getData());
        return temp;
    }
    virtual void copyData(void* to)
    {
        *(Type*)to = *(Type*)getData();
    }
    virtual const std::type_info* getType()
    {
        return (const std::type_info*)&typeid(Type);
    }
    virtual bool compare(IContainer& another)
    {
        if (getType() == another.getType())
        {
            return *(Type*)_data == *(Type*)another.getData();
        }
        else
        {
            return false;
        }
    }
    virtual bool lessThan(IContainer& another)
    {
        if (getType() == another.getType())
        {
            return *(Type*)_data < *(Type*)another.getData();
        }
        else
        {
            return false;
        }
    }
    virtual bool greaterThan(IContainer& another)
    {
        if (getType() == another.getType())
        {
            return *(Type*)_data > *(Type*)another.getData();
        }
        else
        {
            return false;
        }
    }
    virtual bool lessEquality(IContainer& another)
    {
        if (getType() == another.getType())
        {
            return *(Type*)_data <= *(Type*)another.getData();
        }
        else
        {
            return false;
        }
    }
    virtual bool greaterEquality(IContainer& another)
    {
        if (getType() == another.getType())
        {
            return *(Type*)_data >= *(Type*)another.getData();
        }
        else
        {
            return false;
        }
    }
protected:
private:
};

#endif // CONTAINER_H
