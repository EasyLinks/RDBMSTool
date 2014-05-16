#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>

static const std::string _NaN = "NaN";
static const std::string _undefined = "undefined";
static const std::string _InfinityP = "+Infinity";
static const std::string _InfinityN = "-Infinity";

class Number
{
    public:
        Number();
        virtual ~Number();
        Number(long double value)
        {
            _value = value;
        }
        bool isNaN()
        {
            return (currentState != normal);
        }
        bool isUndefined()
        {
            return (currentState == undefined);
        }
        long double value()
        {
            if (isNaN()) return 0;
            return float(_value);
        }
        bool operator == (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return false;
            return (value() == another.value());
        }
        bool operator != (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return true;
            return (value() != another.value());
        }
        bool operator > (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return false;
            return (value() > another.value());
        }
        bool operator < (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return false;
            return (value() < another.value());
        }
        bool operator >= (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return false;
            return (value() >= another.value());
        }
        bool operator <= (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return false;
            return (value() <= another.value());
        }
        Number& operator = (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return *this;
            _value = another.value();
            return *this;
        }
        Number operator + (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return Number(_value);
            Number temp = Number(_value + another.value());
            return temp;
        }
        Number operator - (Number& another)
        {
            if ((isNaN()) || (another.isNaN())) return Number(_value);
            Number temp = Number(_value + another.value());
            return temp;
        }
        Number& operator ++ ()
        {
            _value += 1;
            return *this;
        }
        Number& operator -- ()
        {
            _value -= 1;
            return *this;
        }
        Number& operator += (Number& another)
        {
            _value += another.value();
            return *this;
        }
        Number& operator -= (Number& another)
        {
            _value -= another.value();
            return *this;
        }
        Number& operator / (Number& another)
        {

        }
        std::string toString()
        {
            std::stringstream temp;
            switch (currentState)
            {
            case normal:
                temp << _value;
                return temp.str();
            case NaN:
                return std::string(_NaN);
            case undefined:
                return std::string(_undefined);
            case InfinityP:
                return std::string(_InfinityP);
            case InfinityN:
                return std::string(_InfinityN);
            }
        }
    protected:
        enum States {normal, NaN, undefined, InfinityP, InfinityN};
        long double _value;
        States currentState;
    private:
};

#endif // NUMBER_H
