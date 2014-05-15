#ifndef EASYLINK_UTILS_LINKER_H
#define EASYLINK_UTILS_LINKER_H

#include <easylink/data/Database.h>
#include <string>
#include <map>

namespace easylink {
namespace utils {

class Linker
{
    public:
        Linker();
        virtual ~Linker();
        void addDependency(std::string fromTable, std::string fromField, std::string toTable, std::string toField)
        {
            std::map<std::string, std::map<std::string, std::string>> current;
            try
            {
                current = _relations.at(toTable);
            }
            catch (...)
            {
                _relations.emplace(toTable, std::map<std::string, std::map<std::string, std::string>>());
                current = _relations.at(toTable);
            }
            try
            {
                current.at(toField).emplace(fromTable, fromField);
            }
            catch (...)
            {
                current.emplace(toField, std::map<std::string, std::string>());
                current.at(toField).emplace(fromTable, fromField);
            }
        }
        std::map<std::string, std::map<std::string, std::string>> getDependencies(std::string table)
        {
            try
            {
                return _relations.at(table);
            }
            catch (...)
            {
                return std::map<std::string, std::map<std::string, std::string>>();
            }
        }
        std::map<std::string, std::string> getFieldDependencies(std::string table, std::string field)
        {
            try
            {
                return _relations.at(table).at(field);
            }
            catch (...)
            {
                return std::map<std::string, std::string>();
            }
        }
        void addConcrete(std::string table, std::string field, int index)
        {

        }
    protected:
        std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> _relations;
        std::map<std::pair<data::Entry*, int>, std::map<std::pair<std::string, std::string>, std::pair<data::Entry*, int>>> _concreteRAM;
        std::map<std::tuple<std::string, int, int>, std::map<std::pair<std::string, std::string>, std::tuple<std::string, int, int>>> _concreteROM;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_LINKER_H
