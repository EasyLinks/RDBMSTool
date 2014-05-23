#ifndef EASYLINK_UTILS_CONDITIONAL_LESSEQUALITYCOMPARE_H
#define EASYLINK_UTILS_CONDITIONAL_LESSEQUALITYCOMPARE_H

namespace easylink {
namespace utils {
namespace conditional {

class LessEqualityCompare : public easylink::utils::TestModule
{
    public:
        LessEqualityCompare();
        virtual ~LessEqualityCompare();
    protected:
        bool comparingFunction(data::ContainerA* object, data::ContainerA* key)
        {
            if (object <= key)
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

#endif // EASYLINK_UTILS_CONDITIONAL_LESSEQUALITYCOMPARE_H
