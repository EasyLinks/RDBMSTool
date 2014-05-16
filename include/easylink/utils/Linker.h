#ifndef EASYLINK_UTILS_LINKER_H
#define EASYLINK_UTILS_LINKER_H

#include <easylink/data/Database.h>
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
    protected:
        data::Table _relations;
        std::map<data::Entry*, std::map<int, data::Entry*>> _concreteRAM;
        data::Table _concreteROM;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_LINKER_H
