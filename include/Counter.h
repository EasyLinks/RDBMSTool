#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
    public:
        Counter();
        virtual ~Counter();
        int get()
        {
            return i++;
        }
        int current()
        {
            return i;
        }
    protected:
    private:
        int i;
};

#endif // COUNTER_H
