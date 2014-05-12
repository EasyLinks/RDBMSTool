#ifndef EASYLINK_UTILS_ARGUMENTS_H
#define EASYLINK_UTILS_ARGUMENTS_H

#include <ContainerA.h>
#include <vector>
#include <map>
#include <string>

namespace easylink {
namespace utils {

class Arguments
{
    public:
        Arguments();
        virtual ~Arguments();
        template <typename T>
        void set(std::string name, T value)
        {
            data::ContainerA* temp = new data::ContainerA;
            temp->setData(value);
            _values.emplace(name, temp);
        }
        data::ContainerA get(std::string name)
        {
            try
            {
                return *_values.at(name);
            }
            catch (...)
            {
                return data::ContainerA();
            }
        }
        std::vector<std::string> names()
        {
            std::vector<std::string> temp = std::vector<std::string>();
            for (auto iter = _values.begin(); iter != _values.end(); iter++)
            {
                temp.push_back(std::get<0>(*iter));
            }
            return temp;
        }
    protected:
        std::map<std::string, data::ContainerA*> _values;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_ARGUMENTS_H
