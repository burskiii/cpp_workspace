#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data originalData;
    originalData.n = 42;
    originalData.str = "Hello, Serialization!";

    // Serialize the address of originalData
    uintptr_t raw = Serializer::serialize(&originalData);

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Verify that the deserialized pointer matches the original pointer
    if (deserializedData == &originalData)
    {
        std::cout << "Serialization and Deserialization successful!" << std::endl;
        std::cout << "Original Data: n = " << originalData.n << ", str = " << originalData.str << std::endl;
        std::cout << "Deserialized Data: n = " << deserializedData->n << ", str = " << deserializedData->str << std::endl;
    }
    else
    {
        std::cout << "Error: Deserialized pointer does not match the original pointer." << std::endl;
    }

    std::cout << "original:     " << &originalData << std::endl;
    std::cout << "serialized:   " << raw << std::endl; //uintptr_t, print as integer, as decimal format, it is still the address
    std::cout << "deserialized: " << Serializer::deserialize(raw) << std::endl; //using reinterpret_cast<Data*> to conver back to Data* pointer, which was the decimal format.


    return 0;
}