#ifndef LINE_H
#define LINE_H

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <IContainer.h>
#include <Container.h>
#include <ContainerA.h>
#include <DeleteLink.h>
#include <DeleteHandler.h>
#include <Binding.h>

#include <iostream>

namespace easylink
{
namespace data
{
class Line
{
    public:
        Line();
        virtual ~Line()
        {
            for (auto p = _fields.begin(); p != _fields.end(); ++p)
            {
                delete std::get<1>(*p);
            }
        }
        ContainerA* getReference(std::string name)
        {
            try
            {
                return _fields.at(name);
            }
            catch (...)
            {
                return nullptr;
            }
        }
        template <typename ContainerType> void addField(std::string name)
        {
            ContainerA* temp = new ContainerA;
            temp->setType<ContainerType>();
            _fields.emplace(name, temp);
        }
        void deleteField(std::string name)
        {
            try
            {
                delete _fields.at(name);
                _fields.erase(name);
            }
            catch (...) {}
        }
        template <typename T> int setData(std::string name, T data)
        {
            try
            {
                _fields.at(name)->setData<T>(data);
            }
            catch (...)
            {
                return 1;
            }
            return 0;
        }
        const std::type_info* getType(std::string name)
        {
            try
            {
                return _fields.at(name)->getType();
            }
            catch (...)
            {
                return nullptr;
            }
        }
        std::string toString(std::string name)
        {
            try
            {
                return _fields.at(name)->toString();
            }
            catch (...) {}
            return std::string();
        }
        std::vector<std::string> valueStrings()
        {
            std::vector<std::string> result = std::vector<std::string>();
            for (auto p = _fields.begin(); p != _fields.end(); ++p)
            {
                result.push_back(std::get<1>(*p)->toString());
            }
            return result;
        }
        std::vector<std::string> nameStrings()
        {
            std::vector<std::string> result = std::vector<std::string>();
            for (auto p = _fields.begin(); p != _fields.end(); ++p)
            {
                result.push_back(std::get<0>(*p));
            }
            return result;
        }
        void clear()
        {
            for (auto iter = _fields.begin(); iter != _fields.end(); ++iter)
            {
                std::get<1>(*iter)->clear();
            }
        }
    protected:
        std::map<std::string, ContainerA*> _fields;
        int current;
    private:
};
}
}

#endif // LINE_H
