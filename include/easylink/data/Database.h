#ifndef EASYLINK_DATA_DATABASE_H
#define EASYLINK_DATA_DATABASE_H

#include "Table.h"
#include "easylink/data/VirtualTable.h"
#include "Binding.h"
#include <map>
#include <tuple>
#include <easylink/utils/Linker.h>

namespace easylink
{
namespace data
{

class Database
{
public:
    Database();
    virtual ~Database();
    void createTable(std::string name)
    {
        Table* temp = new Table;
        _tables.emplace(name, temp);
    }
    void dropTable(std::string name)
    {
        try
        {
            _tables.erase(name);
        }
        catch (...)
        {
            std::cout << "Exception at dropTable(std::string)" << std::endl;
        }
    }
    template <typename T>
    void createField(std::string table, std::string field)
    {
        try
        {
            _tables.at(table)->addField<T>(field);
        }
        catch (...)
        {
            std::cout << "Exception at createField(std::string, std::string)" << std::endl;
        }
    }
    template <typename T>
    void writeBuffer(std::string table, std::string field, T data)
    {
        try
        {
            _tables.at(table)->writeBuffer(field, data);
        }
        catch (...)
        {
            std::cout << "Exception at writeBuffer(std::string, std::string, T)" << std::endl;
        }
    }
    std::string readBuffer(std::string table, std::string field)
    {
        try
        {
            return _tables.at(table)->readBuffer(field);
        }
        catch (...)
        {
            std::cout << "Exception at readBuffer(std::string, std::string)" << std::endl;
            return std::string();
        }
    }
    template <typename T>
    void update(std::string table, std::string field, T value)
    {
        try
        {
            _tables.at(table)->update(field, value);
        }
        catch (...)
        {
            std::cout << "Exception at update(std::string, std::string, T)" << std::endl;
        }
    }
    void flush(std::string table)
    {
        try
        {
            _tables.at(table)->flush();
        }
        catch (...)
        {
            std::cout << "Exception at flush(std::string)" << std::endl;
        }
    }
    std::string getString(std::string table, std::string field, int index)
    {
        try
        {
            return _tables.at(table)->getValue(field, index);
        }
        catch(...)
        {
            std::cout << "Exception at getString(std::string, std::string, int)" << std::endl;
            return std::string();
        }
    }
    std::string getString(Table& table, std::string field, int index)
    {
        return table.getValue(field, index);
    }
    template <typename T>
    int findFirst(std::string table, std::string field, T value)
    {
        ContainerA temp = ContainerA(value);
        try
        {
            return _tables.at(table)->findFirst(field, temp);
        }
        catch (...)
        {
            std::cout << "Exception at findFirst(std::string, std::string, T)" << std::endl;
            return -1;
        }
    }
    template <typename T>
    int findLast(std::string table, std::string field, T value)
    {
        ContainerA temp = ContainerA(value);
        try
        {
            return _tables.at(table)->findLast(field, temp);
        }
        catch (...)
        {
            std::cout << "Exception at findLast(std::string, std::string, T)" << std::endl;
            return -1;
        }
    }
    template <typename T>
    std::vector<int> findAll(std::string table, std::string field, T value)
    {
        ContainerA temp = ContainerA(value);
        try
        {
            return _tables.at(table)->findAll(field, temp);
        }
        catch (...)
        {
            std::cout << "Exception at findAll(std::string, std::string, T)" << std::endl;
            return std::vector<int>();
        }
    }
    Table* getReference(std::string table)
    {
        try
        {
            return _tables.at(table);
        }
        catch (...)
        {
            return nullptr;
        }
    }
protected:
    std::map<std::string, Table*> _tables;
    utils::Linker _relations;
private:
};

} // namespace data
} // namespace easylink

#endif // EASYLINK_DATA_DATABASE_H
