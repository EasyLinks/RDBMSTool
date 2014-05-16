#ifndef TABLE_H
#define TABLE_H

#include <Line.h>
#include <Entry.h>
#include <easylink/data/VirtualTable.h>
#include "easylink/utils/TestModule.h"

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
        Entry* temp = new Entry();
        for (int i = 0; i < _indices.length(); ++i)
        {
            temp->addUntypedField();
            temp->assign(i, _indices.reverse(i));
        }
        _lines.push_back(temp);
        _header.clear();
    }
    template <typename T> void writeBuffer(std::string name, T data)
    {
        _header.setData(name, data);
    }
    std::string readBuffer(std::string field)
    {
        return _header.toString(field);
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
    int findFirst(std::string field, ContainerA& key)
    {
        int index = getIndex(field);
        for(int i = 0; i < _lines.size(); ++i)
        {
            if (_lines.at(i)->get(index)->compare(key))
            {
                return i;
            }
        }
        return -1;
    }
    Entry* findLast(std::string field, ContainerA& key, utils::TestModule* condition = nullptr)
    {
        int index = getIndex(field);
        for(int i = _lines.size(); i > 0; --i)
        {
            if (_lines.at(i)->get(index)->compare(key))
            {
                return _lines.at(i);
            }
        }
        return nullptr;
    }
    std::vector<int> findAll(std::string field, ContainerA& key)
    {
        int index = getIndex(field);
        std::vector<int> result = std::vector<int>();
        for(int i = 0; i < _lines.size(); i++)
        {
            if (_lines.at(i)->get(index)->compare(key))
            {
                result.push_back(i);
            }
        }
        return result;
    }
    void loadSelf(std::string path, unsigned int offset)
    {
        // Avialiable only when loadSelf methods are implemented for ContainerA, Line, Entry and Container<T> classes.
    }
    int length()
    {
        return _lines.size();
    }
protected:
    Line _header;
    std::vector<Entry*> _lines;
    easylink::data::VirtualTable _indices;
private:
};
}
}

#endif // TABLE_H
