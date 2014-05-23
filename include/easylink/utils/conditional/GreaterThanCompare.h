#ifndef EASYLINK_UTILS_CONDITIONAL_GREATERTHANCOMPARE_H
#define EASYLINK_UTILS_CONDITIONAL_GREATERTHANCOMPARE_H

namespace easylink {
namespace utils {
namespace conditional {

class GreaterThanCompare : public easylink::utils::TestModule
{
    public:
        GreaterThanCompare();
        virtual ~GreaterThanCompare();
    protected:
        bool comparingFunction(data::ContainerA* object, data::ContainerA* key)
        {
            if (object > key)
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


#endif // EASYLINK_UTILS_CONDITIONAL_GREATERTHANCOMPARE_H
