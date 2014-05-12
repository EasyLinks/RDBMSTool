#ifndef EASYLINK_UTILS_OBSERVER_H
#define EASYLINK_UTILS_OBSERVER_H

#include <easylink/utils/Arguments.h>
#include <easylink/data/Database.h>
#include <Table.h>
#include <string>
#include <map>

namespace easylink {
namespace utils {

class Observer
{
    public:
        Observer();
        virtual ~Observer();
        void createDatabase(std::string database)
        {
            data::Database* temp = new data::Database;
            _databases.emplace(database, temp);
        }
        data::Database* getDatabase()
        {
            return _database;
        }
        data::Table* getTable()
        {
            return _table;
        }
        bool connect(std::string database, Arguments& auth)
        {
            data::Database* temp;
            if ((temp = getDatabase(database)) != nullptr)
            {
                setDatabase(temp);
                return true;
            }
            return false;
        }
        bool selectTable(std::string table)
        {
            data::Table* temp;
            if ((temp = getTable(table)) != nullptr)
            {
                setTable(temp);
                return true;
            }
            return false;
        }
        data::Database* getDatabase(std::string name)
        {
            try
            {
                return _databases.at(name);
            }
            catch (...)
            {
                return nullptr;
            }
        }
        data::Table* getTable(std::string name)
        {
            try
            {
                return _database->getReference(name);
            }
            catch (...)
            {
                return nullptr;
            }
        }
        void setDatabase(data::Database& database)
        {
            _database = &database;
        }
        void setDatabase(data::Database* database)
        {
            _database = database;
        }
        void setTable(data::Table& table)
        {
            _table = &table;
        }
        void setTable(data::Table* table)
        {
            _table = table;
        }
    protected:
        std::map<std::string, data::Database*> _databases;
        data::Database* _database;
        data::Table* _table;
        std::string key;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_OBSERVER_H
