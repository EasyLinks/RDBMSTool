#include "easylink/utils/Arguments.h"

namespace easylink {
namespace utils {

Arguments::Arguments()
{
    //ctor
}

Arguments::~Arguments()
{
    for (auto iter = _values.begin(); iter != _values.end(); iter++)
    {
        delete std::get<1>(*iter);
    }
}

} // namespace utils
} // namespace easylink
