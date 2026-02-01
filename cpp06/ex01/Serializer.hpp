#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstddef>   // uintptr_t not included in cstdint
#include <stdint.h>  // uintptr_t


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