#ifndef EASYLINK_UTILS_REGISTEREDTYPESDISTINGUISHER_H
#define EASYLINK_UTILS_REGISTEREDTYPESDISTINGUISHER_H

#include "IContainer.h"
#include "ContainerA.h"

namespace easylink {
namespace utils {

class RegisteredTypesDistinguisher
{
    public:
        RegisteredTypesDistinguisher();
        virtual ~RegisteredTypesDistinguisher();
        void registerType(std::string signature, IContainer* prototype)
        {
            _registeredTypes.emplace(signature, prototype);
        }
        IContainer* populate(std::string signature)
        {
            try
            {
                return _registeredTypes.at(signature)->duplicate();
            }
            catch (...)
            {
                return nullptr;
            }
        }
        IContainer* populate(std::string signature, std::string data)
        {
            IContainer* temp = populate(signature);
            temp->setData(data);
            return temp;
        }
        std::string toString(IContainer* data)
        {
            std::stringstream temp;
            for (auto iter = _registeredTypes.begin(); iter != _registeredTypes.end(); ++iter)
            {
                if (data->compare(*std::get<1>(*iter)))
                {
                    temp << std::get<0>(*iter) << ":" << data->toString();
                    return temp.str();
                }
            }
            return std::string();
        }
        void write(data::ContainerA& data)
        {

        }
    protected:
        std::map<std::string, IContainer*> _registeredTypes;
    private:
};

} // namespace utils
} // namespace easylink

#endif // EASYLINK_UTILS_REGISTEREDTYPESDISTINGUISHER_H
