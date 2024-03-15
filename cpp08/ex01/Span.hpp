#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

class Span{
  private: 
    unsigned int n;
    std::vector<int> lst;

  public:
    Span();
    Span(unsigned int x);
    Span(Span const &obj);
    Span const &operator = (const Span &other);
    class non_valid : public std::exception{
      public :
      const char * what () const throw();
    };
    void addNumber(int nbr);
    int shortestSpan();
    int longestSpan();
    void addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    ~Span();
};