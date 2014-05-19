#ifndef EASYLINK_UTILS_LINKER_H
#define EASYLINK_UTILS_LINKER_H

#include <Table.h>
#include <Entry.h>
#include <map>

namespace easylink {
namespace utils {

class Linker
{
    public:
        Linker();
        virtual ~Linker();
        void addLink(std::string fromTable, std::string fromField, std::string toTable, std::string toField)
        {
            _relations.writeBuffer("from_table", fromTable);
            _relations.writeBuffer("from_field", fromField);
            _relations.writeBuffer("to_table", toTable);
            _relations.writeBuffer("to_field", toField);
            _relations.flush();

        }
    protected:
        data::Table _relations;
        std::map<data::Entry*, std::map<int, data::Entry*>> _concreteRAM;
        data::Table _concreteROM;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_LINKER_H
