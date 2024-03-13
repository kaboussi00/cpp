#pragma once

template <class T>
void swap(T& a, T& b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <class T>
T min(T a, T b){
    if (a >= b)
        return b;
    return a;
}

template <class T>
T max(T a, T b){
    if (a > b)
        return a;
    return b;
}
