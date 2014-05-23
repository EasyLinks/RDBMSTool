#ifndef CONTAINERA_H
#define CONTAINERA_H

#include <IContainer.h>
#include <Container.h>
#include <typeinfo>
#include <stdio.h>

namespace easylink
{
namespace data
{
class ContainerA
{
public:
    ContainerA();
    template <typename DataType> explicit ContainerA(DataType value, bool restricted = false)
    {
        __initialized__ = bool(true);
        __restricted__ = restricted;
        _container = new Container<DataType>;
        _container->setData(value);
        _type = &typeid(DataType);
    }
    virtual ~ContainerA();
    IContainer* operator*()
    {
        return _container;
    }
    void* getData()
    {
        if (__initialized__)
        {
            return _container->getData();
        }
        else
        {
            return nullptr;
        }
    }
    template <typename T> IContainer* setData(T value, bool restricted = false)
    {
        if (&typeid(T) != _type)
        {
            if (isRestricted() == false)
            {
                if (__initialized__)
                {
                    delete _container;
                }
                _container = new Container<T>;
                __initialized__ = true;
                _type = &typeid(T);
            }
        }
        else
        {
            if (__initialized__ == false)
            {
                _container = new Container<T>;
                __initialized__ = true;
            }
        }
        if (restricted)
        {
            restrict();
        }
        return _container->setData(easylink::data::DataWrap(value));
    }
    void clear()
    {
        if (isInitialized())
        {
            delete _container;
            __initialized__ = false;
        }
    }
    void setRawData(IContainer* data)
    {
        if (__initialized__)
        {
            delete _container;
        }
        _container = data->duplicate();
        _type = data->getType();
        __initialized__ = true;
    }
    const std::type_info* getType()
    {
        return _container->getType();
    }
    template <typename NewType> void setType()
    {
        if (__initialized__)
        {
            delete _container;
        }
        _container = new Container<NewType>;
        __initialized__ = true;
        _type = &typeid(NewType);
        restrict();
    }
    void setType(const std::type_info* type)
    {
        _type = type;
        restrict();
    }
    virtual IContainer* duplicate()
    {
        return _container->duplicate();
    }
    virtual void copyData(void* to)
    {
        _container->copyData(to);
    }
    std::string toString()
    {
        return _container->toString();
    }
    void restrict()
    {
        __restricted__ = true;
    }
    void unrestrict()
    {
        __restricted__ = false;
    }
    bool isRestricted()
    {
        return __restricted__;
    }
    bool isInitialized()
    {
        return __initialized__;
    }
    ContainerA& assign(ContainerA& another)
    {
        _container = another.duplicate();
        __initialized__ = another.isInitialized();
        __restricted__ = another.isRestricted();
        _type = another.getType();
        return *this;
    }
    bool operator == (ContainerA& another)
    {
        return compare(another);
    }
    bool operator != (ContainerA& another)
    {
        return (compare(another)?false:true);
    }
    bool operator < (ContainerA& another)
    {
        return lessThan(another);
    }
    bool operator > (ContainerA& another)
    {
        return greaterThan(another);
    }
    bool operator <= (ContainerA& another)
    {
        return lessEquality(another);
    }
    bool operator >= (ContainerA& another)
    {
        return greaterEquality(another);
    }
    bool compare(ContainerA& another)
    {
        return _container->compare(*another.duplicate());
    }
    bool lessThan(ContainerA& another)
    {
        return _container->lessThan(*another.duplicate());
    }
    bool greaterThan(ContainerA& another)
    {
        return _container->greaterThan(*another.duplicate());
    }
    bool lessEquality(ContainerA& another)
    {
        return _container->lessEquality(*another.duplicate());
    }
    bool greaterEquality(ContainerA& another)
    {
        return _container->greaterEquality(*another.duplicate());
    }
    void update(ContainerA& another)
    {
        if (getType() == another.getType())
        {
            _container = another.duplicate();
            __initialized__ = another.isInitialized();
        }
    }
    /*ContainerA operator = (ContainerA another)
    {
        _container = another.duplicate();
        __initialized__ = another.isInitialized();
        __restricted__ = another.isRestricted();
        _type = another.getType();
        return *this;
    }*/
    ContainerA* duplicateA()
    {
        ContainerA* temp = new ContainerA;
        temp->setRawData(_container->duplicate());
        temp->setType(getType());
        if (isRestricted() == false)
        {
            temp->unrestrict();
        }
        return temp;
    }
protected:
private:
    const std::type_info* _type;
    IContainer* _container;
    bool __initialized__;
    bool __restricted__;
};
}
}
#endif // CONTAINERA_H
