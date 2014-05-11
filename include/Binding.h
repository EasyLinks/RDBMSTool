#ifndef BINDING_H
#define BINDING_H

#include <map>

namespace easylink
{
namespace utils
{
template <typename T, typename H> class Binding
{
    public:
        Binding(){}
        virtual ~Binding(){}
        void insert(T from, H to)
        {
            _direct.emplace(from, to);
            _reverse.emplace(to, from);
        }
        void removeDirect(T key)
        {
            try
            {
                removeReverse(getDirect(key));
                _direct.erase(key);
            }
            catch(...){}
        }
        void removeReverse(H key)
        {
            try
            {
                removeDirect(getReverse(key));
                _reverse.erase(key);
            }
            catch(...){}
        }
        H getDirect(T key)
        {
            try
            {
                return _direct.at(key);
            }
            catch(...)
            {
                return H();
            }
        }
        T getReverse(H key)
        {
            try
            {
                return _reverse.at(key);
            }
            catch (...)
            {
                return T();
            }
        }
        void clear()
        {
            _direct.clear();
            _reverse.clear();
        }
    protected:
    private:
        std::map<T, H> _direct;
        std::map<H, T> _reverse;
};
}
}

#endif // BINDING_H
