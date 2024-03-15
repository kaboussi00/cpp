#include "Span.hpp"

Span::Span(){
  n = 0;
}

Span::Span(unsigned int x){
  n = x;
}

Span::Span(Span const &obj){
  if (this != &obj)
    *this = obj;
}

Span const &Span::operator=(const Span &obj){
  if (this != &obj)
    this->n = obj.n;
  return *this;
}

const char * Span::non_valid::what () const throw(){
  return ("non_valid");
}

void Span::addNumber(int nbr){
  if (lst.size() < n)
    lst.push_back(nbr);
  else
    throw non_valid();
}

int Span::shortestSpan()
{
  int min = 2147483647;
  if (lst.size() < 2)
    throw non_valid();
  for (unsigned int i = 0;i < lst.size(); i++)
  {
    for (unsigned int j = i + 1; j < lst.size(); j++)
    {
      if (min > abs(lst[i] - lst[j]))
        min = abs(lst[i] - lst[j]);
    }
  }
  return (min);
}

int Span::longestSpan()
{
  int max = -2147483648;
  if (lst.size() < 2)
    throw non_valid();
  for (unsigned int i = 0;i < lst.size(); i++)
  {
    for (unsigned int j = i + 1; j < lst.size(); j++)
    {
      if (max < abs(lst[i] - lst[j]))
        max = abs(lst[i] - lst[j]);
    }
  }
  return (max);
}

void Span::addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (end - begin + lst.size() > n)
        throw non_valid();
    std::vector<int>::iterator it;
    it = lst.begin();
    std::copy(begin, end , std::inserter(lst, it));
}

Span::~Span(){
}
