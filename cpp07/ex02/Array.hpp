#pragma once

#include <iostream>

template <class T>
class Array{
    private :
        T* element;
        unsigned int n;
        
    public :

        Array (){
            std::cout << "C default\n"; 
            element = NULL;
            n = 0;
        }
    
        Array (unsigned int x){
            std::cout << "C param" << std::endl; 
            n = x;
            element = new T[n];
            for (unsigned int i = 0; i < n ; i++){
                element[i] = T();
            }
        }
    
        Array(const Array& obj) {
        std::cout << "Copy constructor" << std::endl;
        n = obj.n;
        element = new T[n];
        for (unsigned int i = 0; i < n; i++) {
            element[i] = obj.element[i];}
        }
    
        Array& operator=(Array const &obj){
            std::cout << "C assignement" << std::endl; 
            if (this != &obj){
                if (element)
                    delete[] element;
                this->element = new T[n];
                this->n = obj.n;
                for(int i = 0; i < obj.n ; i++){
                    element[i] = obj.element[i];
                }
            }
            return (*this);
        }
    
        T& operator[](unsigned int i){
                if (i >= n || i < 0)
                    throw std::out_of_range("out of range");

            return (element[i]);
        }
        unsigned int size(void){
            return n;
        }
    
        ~Array(){
            delete[] element;
            std::cout << "C destructor" << std::endl;
        }
};
