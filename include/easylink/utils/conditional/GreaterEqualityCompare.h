#ifndef EASYLINK_UTILS_CONDITIONAL_GREATEREQUALITYCOMPARE_H
#define EASYLINK_UTILS_CONDITIONAL_GREATEREQUALITYCOMPARE_H

namespace easylink {
namespace utils {
namespace conditional {

class GreaterEqualityCompare : public easylink::utils::TestModule
{
    public:
        GreaterEqualityCompare();
        virtual ~GreaterEqualityCompare();
    protected:
        bool comparingFunction(data::ContainerA* object, data::ContainerA* key)
        {
            if (object >= key)
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

#endif // EASYLINK_UTILS_CONDITIONAL_GREATEREQUALITYCOMPARE_H
