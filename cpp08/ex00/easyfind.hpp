#pragma once

#include <iterator>
#include <iostream>

class not_found : std::exception{
  public :
    const char * what() const throw();
};

const char * not_found::what() const throw(){
  return ("not found");
}

template <typename T>
typename T::iterator easyfind(T &ar, int i){
  typename T::iterator ptr = ar.begin();
  for ( ; ptr < ar.end(); ptr++){
    if (*ptr == i)
      return (ptr);
  }
  throw not_found();
}
