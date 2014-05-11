#ifndef DATAWRAP_H
#define DATAWRAP_H

#include <typeinfo>

namespace easylink
{
    namespace data
    {

        class DataWrap
        {
            public:
                DataWrap();
                template <typename DataType> DataWrap(DataType data)
                {
                    _data = new DataType;
                    *(DataType*)_data = data;
                    _type = &typeid(DataType);
                }
                virtual ~DataWrap(){}
                auto getData() -> void*
                {
                    return _data;
                }
                auto getType() -> const std::type_info*
                {
                    return _type;
                }
            protected:
            private:
                void* _data;
                const std::type_info* _type;
        };
    }
}
#endif // DATAWRAP_H
