#ifndef EASYLINK_UTILS_TESTMODULE_H
#define EASYLINK_UTILS_TESTMODULE_H

#include <ContainerA.h>

namespace easylink {
namespace utils {

class TestModule
{
    public:
        TestModule();
        virtual ~TestModule();
        virtual bool checkCondition(data::ContainerA& object, data::ContainerA& key)
        {
            return comparingFunction(&object, &key);
        }
        virtual bool checkCondition(data::ContainerA* object, data::ContainerA* key)
        {
            return comparingFunction(object, key);
        }
    protected:
        virtual bool comparingFunction(data::ContainerA* object, data::ContainerA* key) = 0;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_TESTMODULE_H
