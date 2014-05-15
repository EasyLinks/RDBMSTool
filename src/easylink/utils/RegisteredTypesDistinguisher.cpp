#include "easylink/utils/RegisteredTypesDistinguisher.h"

namespace easylink {
namespace utils {

RegisteredTypesDistinguisher::RegisteredTypesDistinguisher()
{
    //ctor
}

RegisteredTypesDistinguisher::~RegisteredTypesDistinguisher()
{
    for (auto iter = _registeredTypes.begin(); iter != _registeredTypes.end(); ++iter)
    {
        delete std::get<1>(*iter);
    }
}

} // namespace utils
} // namespace easylink
