#ifndef ENTRY_H
#define ENTRY_H

#include <ContainerA.h>
#include <Line.h>

namespace easylink
{
namespace data
{
class Entry
{
    public:
        Entry();
        virtual ~Entry();
        template <typename T> void addField()
        {
            ContainerA* temp = new ContainerA;
            temp->setType<T>();
            _fields.push_back(temp);
        }
        void addUntypedField()
        {
            ContainerA* temp = new ContainerA;
            _fields.push_back(temp);
        }
        std::string toString(int number)
        {
            try
            {
                return _fields.at(number)->toString();
            }
            catch (...)
            {
                return std::string();
            }
        }
        void assign(int index, ContainerA* value)
        {
            try
            {
                _fields.at(index)->assign(*value);
            }
            catch (...) {}
        }
        void erase(int index)
        {
            try
            {
                _fields.at(index)->clear();
            }
            catch (...) {}
        }
        ContainerA* get(int index)
        {
            try
            {
                return _fields.at(index);
            }
            catch (...)
            {
                return nullptr;
            }
        }
        Entry duplicate()
        {
            Entry temp = Entry();
            for (unsigned int i = 0; i < _fields.size(); ++i)
            {
                temp.addUntypedField();
                temp.assign(i, temp.get(i));
            }
            return temp;
        }
    protected:
        std::vector<ContainerA*> _fields;
    private:
};
} // namespace data
} // namespace easylink
#endif // ENTRY_H
