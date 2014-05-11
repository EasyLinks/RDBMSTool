#ifndef EASYLINK_UTILS_OBSERVER_H
#define EASYLINK_UTILS_OBSERVER_H

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
        bool connect(std::string database);
        {
            try
            {
                setDatabase(_)
            }
        }
        void setDatabase(data::Database* database)
        {
            _database = database;
        }
    protected:
        std::map<std::string, data::Database*> _databases;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_OBSERVER_H
