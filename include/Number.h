#ifndef NUMBER_H
#define NUMBER_H


class Number
{
    public:
        static const std::string _NaN = "NaN";
        static const std::string _undefined = "undefined";
        static const std::string _InfinityP = "+Infinity";
        static const std::string _InfinityN = "-Infinity";
        Number();
        virtual ~Number();
        bool isNaN()
        {
            return (currentState != normal);
        }
        bool isUndefined()
        {
            return (currentState == undefined);
        }
        auto value() -> decltype(_value)
        {
            return float(_value);
        }
        Number& operator == (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            return (value() == another.value());
        }
        Number& operator != (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return true;
            return (value() != another.value());
        }
        Number& operator > (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            return (value() > another.value());
        }
        Number& operator < (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            return (value() < another.value());
        }
        Number& operator >= (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            return (value() >= another.value());
        }
        Number& operator <= (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            return (value() <= another.value());
        }
        Number& operator = (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return *this;
            _value = another.value();
            return *this;
        }
        Number& operator + (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            Number temp = Number();
            temp = _value += another.value();
            return *this;
        }
        Number& operator - (Number& another)
        {
            if ((isNaN) || (another.isNaN())) return false;
            Number temp = Number();
            temp = *this;
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
            _value
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
