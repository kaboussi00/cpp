#pragma once

#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{ 
public:
    MutantStack(){

    };
    MutantStack(MutantStack const &obj) : std::stack<T>(obj){

    };
    MutantStack const &operator=(MutantStack const &other){
        this->c = other.c;
    return (*this);
    }; 
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;
    iterator begin(){
        return (this->c.begin());
    };
    iterator end(){
        return (this->c.end());
    };
    rev_iterator rbegin(){
        return (this->c.rbegin());
    };
    rev_iterator rend(){
        return (this->c.rend());
    };
    ~MutantStack(){

    };
};
