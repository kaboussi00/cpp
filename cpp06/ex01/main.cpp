#include "Serializer.hpp"

int main() {
    Data data;
    data.value1 = 42;
    data.value2 = 3.14;
    data.value3 = ' ';

    Data* origin = &data;

    uintptr_t serializedValue = Serializer::serialize(origin);

    std::cout << serializedValue << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serializedValue);

    std::cout << deserializedPtr->value1 << std::endl;
    std::cout << deserializedPtr->value2 << std::endl;
    std::cout << deserializedPtr->value3 << std::endl;

    if (origin == deserializedPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    // std::cout << data.value2 << std::endl;

    return 0;
}