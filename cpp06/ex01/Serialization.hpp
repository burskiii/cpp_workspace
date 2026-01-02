#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>

#include "Data.hpp"

class Serializer {

    public:

        static Data* deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);

    private:

        Serializer();
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
};

#endif