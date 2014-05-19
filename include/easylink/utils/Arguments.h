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
        template <typename Type>
        std::vector<data::ContainerA> get(std::string name)
        {
            std::vector<data::ContainerA> result = std::vector<data::ContainerA>();
            for (auto iter = _values.begin(); iter != _values.end(); ++iter)
            {
                if ((std::get<0>(*iter) == name) && (std::get<1>(*iter)->getType() == &typeid(Type)))
                {
                    result.push_back(*std::get<1>(*iter));
                }
            }
            return result;
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
        Arguments& operator = (Arguments& another)
        {
            auto targetNames = another.names();
            for (auto iter = targetNames.begin(); iter != targetNames.end(); ++iter)
            {
                //_values.emplace(*iter, another.get(*iter));
            }
        }
    protected:
        std::multimap<std::string, data::ContainerA*> _values;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_ARGUMENTS_H
