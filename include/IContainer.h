#ifndef ICONTAINER_H
#define ICONTAINER_H

#include <typeinfo>
#include <IObject.h>
#include <DataWrap.h>

class IContainer : public IObject
{
public:
    IContainer();
    virtual ~IContainer();
    void* getData()
    {
        return _data;
    }
    virtual bool compare(IContainer& another) = 0;
    virtual bool lessThan(IContainer& another) = 0;
    virtual bool greaterThan(IContainer& another) = 0;
    virtual bool lessEquality(IContainer& another) = 0;
    virtual bool greaterEquality(IContainer& another) = 0;
    virtual std::string toString() = 0;
    virtual IContainer* distinguishData(std::string value) = 0;
    virtual IContainer* setData(easylink::data::DataWrap value) = 0;
    virtual const std::type_info* getType() = 0;
    virtual IContainer* duplicate() = 0;
    virtual void copyData(void* to) = 0;
protected:
    void* _data;
private:
};

#endif // ICONTAINER_H
