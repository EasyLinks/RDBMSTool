#ifndef DELETELINK_H
#define DELETELINK_H

#include <DeleteHandler.h>
#include <iostream>

namespace easylink
{
namespace utils
{
template <typename StoredType>
class DeleteLink
{
    public:
        DeleteLink(StoredType* passedLink, DeleteHandler* handler)
        {
            std::cout << "DeleteLink [ctor] at " << this << std::endl;
            handle(handler);
            link(passedLink);
        }
        DeleteLink()
        {
            std::cout << "DeleteLink [ctor] at " << this << std::endl;
            _link = nullptr;
            _handler = nullptr;
        }
        DeleteLink(const DeleteLink& another)
        {
            link(another.getLink());
            handle(another.getHandler());
        }
        virtual ~DeleteLink()
        {
            std::cout << "DeleteLink [dtor] at " << this << std::endl;
            if ((_link != nullptr) && (_handler->state() == true))
            {
                std::cout << " Destroying data at " << _link << std::endl;
                deleteLinked();
            }
        }
        virtual void handle(DeleteHandler* handler)
        {
            _handler = handler;
        }
        virtual void link(StoredType* link)
        {
            if (_link == nullptr)
            {
                std::cout << " Linked to: " << link << std::endl;
                _link = link;
            }
        }
        DeleteHandler* getHandler() const
        {
            return _handler;
        }
        StoredType* getLink() const
        {
            return _link;
        }
        virtual void deleteLinked()
        {
            delete _link;
        }
    protected:
        StoredType* _link;
        DeleteHandler* _handler;
    private:
};
} // namespace utils
} // namespace easylink

#endif // DELETELINK_H
