#ifndef IDELETELINK_H
#define IDELETELINK_H

namespace easylink
{
namespace utils
{
class IDeleteLink
{
    public:
        IDeleteLink();
        virtual ~IDeleteLink();
        virtual void link() = 0;
        virtual void deleteLinked() = 0;
    protected:
    private:
};
} // namespace utils
} // namespace easylink

#endif // IDELETELINK_H
