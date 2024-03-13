#pragma once

#include <iostream>

template<typename T>
void iter(T* array, int len, void (*f)(const T &a)){
    if (!array)
        return;
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

template<typename T>
void iter(T* array, int len, void (*f)(T &a)){
    if (!array)
        return;
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}