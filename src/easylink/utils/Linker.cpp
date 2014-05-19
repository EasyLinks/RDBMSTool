#include "easylink/utils/Linker.h"

namespace easylink {
namespace utils {

Linker::Linker()
{
    //_relations = data::Table();
    _relations.addField<int>("id");
    _relations.addField<std::string>("from_table");
    _relations.addField<std::string>("from_field");
    _relations.addField<std::string>("to_table");
    _relations.addField<std::string>("to_field");
    //_concreteROM = data::Table();
    _concreteROM.addField<int>("id");
    _concreteROM.addField<uint64_t>("from");
    _concreteROM.addField<uint64_t>("to");
}

Linker::~Linker()
{
    //dtor
}

} // namespace utils
} // namespace easylink
