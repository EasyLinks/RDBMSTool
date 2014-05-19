#ifndef TABLE_H
#define TABLE_H

#include <Line.h>
#include <Entry.h>
#include <easylink/data/VirtualTable.h>
#include "easylink/utils/TestModule.h"
#include "easylink/utils/Arguments.h"

namespace easylink
{
namespace data
{
class Table
{
public:
    Table();
    virtual ~Table();
    template <typename T> void addField(std::string name)
    {
        if (_lines.begin() == _lines.end())
        {
            _header.addField<T>(name);
            _indices.emplace(_header.getReference(name));
        }
    }
    void flush()
    {
        if (validate())
        {
            Entry* temp = new Entry();
            for (int i = 0; i < _indices.length(); ++i)
            {
                temp->addUntypedField();
                temp->assign(i, _indices.reverse(i));
            }
            _lines.push_back(temp);
            _header.clear();
        }
    }
    template <typename T> void writeBuffer(std::string name, T data)
    {
        _header.setData(name, data);
    }
    std::string readBuffer(std::string field)
    {
        return _header.toString(field);
    }
    ContainerA* getBuffer(std::string field)
    {
        return _header.getReference(field);
    }
    Entry* getLine(unsigned int number)
    {
        if (number < _lines.size())
        {
            return _lines.at(number)->duplicate();
        }
        return nullptr;
    }
    std::string getValue(std::string name, int pos)
    {
        std::string returnValue;
        try
        {
            Entry* current = _lines.at(pos);
            returnValue = current->toString(getIndex(name));
        }
        catch (...)
        {
            returnValue = std::string();
            std::cout << "Oops... Exception thrown!" << std::endl;
        }
        return returnValue;
    }
    ContainerA get(std::string name, int pos)
    {
        ContainerA returnValue;
        try
        {
            Entry* current = _lines.at(pos);
            returnValue.assign(*current->get(getIndex(name)));
        }
        catch (...)
        {
            returnValue = ContainerA();
        }
        return returnValue;
    }
    ContainerA* getReference(std::string name, int pos)
    {
        try
        {
            Entry* current = _lines.at(pos);
            return current->get(getIndex(name));
        }
        catch (...)
        {
            return nullptr;
        }
    }
    int getIndex(std::string name)
    {
        return _indices.direct(_header.getReference(name));
    }
    template <typename T>
    void update(std::string name, int index, T updateValue)
    {
        ContainerA* temp = getReference(name, index);
        if (temp != nullptr)
        {
            ContainerA upd = ContainerA(updateValue);
            temp->update(upd);
        }
    }
    Entry* findFirst(std::string field, ContainerA& key, utils::TestModule* condition)
    {
        int index = getIndex(field);
        for(unsigned int i = 0; i < _lines.size(); ++i)
        {
            if (condition->checkCondition(_lines.at(i)->get(index), &key));
            {
                return _lines.at(i);
            }
        }
        return nullptr;
    }
    Entry* findLast(std::string field, ContainerA& key, utils::TestModule* condition = nullptr)
    {
        int index = getIndex(field);
        for(int i = _lines.size(); i > 0; --i)
        {
            if (condition->checkCondition(_lines.at(i)->get(index), &key));
            {
                return _lines.at(i);
            }
        }
        return nullptr;
    }
    std::vector<Entry*> findAll(std::string field, ContainerA& key, utils::TestModule* condition)
    {
        int index = getIndex(field);
        std::vector<Entry*> result = std::vector<Entry*>();
        for(unsigned int i = 0; i < _lines.size(); i++)
        {
            if (condition->checkCondition(_lines.at(i)->get(index), &key));
            {
                result.push_back(_lines.at(i));
            }
        }
        return result;
    }
    bool validate()
    {
        std::vector<data::ContainerA> required = _attributes.get<std::string>("required");
        std::vector<data::ContainerA> counters = _attributes.get<std::string>("counter");
        for (auto iter = required.begin(); iter != required.end(); ++iter)
        {
            if (getBuffer(iter->toString())->isInitialized() == false) return false;
        }
        for (auto iter = counters.begin(); iter != counters.end(); ++iter)
        {
            if (getBuffer(iter->toString())->isInitialized() == true) return false;
        }
        return true;
    }
    void setAttributes(utils::Arguments attributes)
    {
        _attributes = attributes;
    }
    int length()
    {
        return _lines.size();
    }
protected:
    Line _header;
    std::vector<Entry*> _lines;
    easylink::data::VirtualTable _indices;
    easylink::utils::Arguments _attributes;
private:
};
}
}

#endif // TABLE_H
