#include "Span.hpp"

int main()
{
try{
Span sp = Span(20);
std::vector<int> ar;
ar.push_back(1);
ar.push_back(20);
ar.push_back(4);
ar.push_back(99);
sp.addNumber(6);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.addManyNumber(ar.begin(), ar.end());
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}
catch(std::exception &e){
  std::cout << e.what() << std::endl;
}
return 0;
}