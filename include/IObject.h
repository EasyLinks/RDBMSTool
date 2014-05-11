#ifndef IOBJECT_H
#define IOBJECT_H

#include <string>
#include <map>

class IObject
{
    public:
        IObject();
        virtual ~IObject();
        IObject(const IObject& other);
        IObject& operator=(const IObject& other);
        IObject* getParent() { return _parent; }
        void setParent(IObject& val)
        {
            _parent = &val;
        }
        IObject& getChild(std::string name)
        {
            return *_children[name];
        }
        IObject& setChild(std::string name, IObject& value)
        {
            _children[name] = &value;
            return *_children[name];
        }
        virtual std::string toString()
        {
            return std::string("[object Object]");
        }
    protected:
        IObject* _parent;
        std::map<std::string, IObject*> _children;
    private:
};

#endif // IOBJECT_H
