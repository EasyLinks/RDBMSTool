#ifndef EASYLINK_DATA_VIRTUALTABLE_H
#define EASYLINK_DATA_VIRTUALTABLE_H

#include "Binding.h"
#include "ContainerA.h"
#include "Counter.h"

namespace easylink {
namespace data {

class VirtualTable
{
    public:
        VirtualTable();
        virtual ~VirtualTable();
        int emplace(ContainerA* container)
        {
            int temp = _counter.get();
            _connections.insert(container, temp);
            return temp;
        }
        ContainerA* reverse(int index)
        {
            return _connections.getReverse(index);
        }
        int direct(ContainerA* key)
        {
            return _connections.getDirect(key);
        }
        int length()
        {
            return _counter.current();
        }
    protected:
        utils::Binding<ContainerA*, int> _connections;
        Counter _counter;
    private:
};

} // namespace data
} // namespace easylink

#endif // EASYLINK_DATA_VIRTUALTABLE_H
