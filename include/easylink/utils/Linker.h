#ifndef EASYLINK_UTILS_LINKER_H
#define EASYLINK_UTILS_LINKER_H

namespace easylink {
namespace utils {

class Linker
{
    public:
        Linker();
        virtual ~Linker();
        void addDependency(std::string fromTable, std::string fromField, std::string toTable, std::string toTable)
        {
            std::vector<std::tuple<std::string, std::string>> current;
            try
            {
                current = _relations.at(toTable);
            }
            catch (...)
            {
                _relations.emplace(toTable, std::vector<std::tuple<std::string, std::string>>);
                current = _relations.at(toTable);
            }
            current.push_back()
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
                return _relations.at(table)->at(field);
            }
            catch (...)
            {
                return std::map<std::string, std::string>();
            }
        }
    protected:
        std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> _relations;
        std::map<data::ContainerA*, data::ContainerA*> _concrete;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_LINKER_H
