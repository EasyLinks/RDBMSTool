#ifndef EASYLINK_UTILS_CONDITIONAL_LESSTHANCOMPARE_H
#define EASYLINK_UTILS_CONDITIONAL_LESSTHANCOMPARE_H

#include "easylink/utils/TestModule.h"

namespace easylink {
namespace utils {
namespace conditional {

class LessThanCompare : public easylink::utils::TestModule
{
    public:
        LessThanCompare();
        virtual ~LessThanCompare();
    protected:
        bool comparingFunction(data::ContainerA* object, data::ContainerA* key)
        {
            if (object < key)
            {
                return true;
            }
            return false;
        }
    private:
};

} // namespace conditional
} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_CONDITIONAL_LESSTHANCOMPARE_H
