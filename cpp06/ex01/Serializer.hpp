#pragma once

#include <iostream>
#include <cstdint>

struct Data {
    int value1;
    double value2;
    char value3;
};

class Serializer {
private:
    Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();
};
