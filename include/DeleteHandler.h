#ifndef DELETEHANDLER_H
#define DELETEHANDLER_H

namespace easylink
{
namespace utils
{
class DeleteHandler
{
    public:
        DeleteHandler();
        virtual ~DeleteHandler();
        bool state()
        {
            return __deletion_state__;
        }
        void beginDelete()
        {
            __deletion_state__ = true;
        }
    protected:
    private:
        bool __deletion_state__;
};
}
}
#endif // DELETEHANDLER_H
