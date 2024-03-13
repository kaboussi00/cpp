#include "Iter.hpp"


void chargeInt(const int &num) {
    std::cout << "Charging integer: " << num << std::endl;
}

void chargeString(const std::string &str) {
    std::cout << "Charging string: " << str << std::endl;
}

void chargeChar(const char &ch) {
    std::cout << "Charging character: " << ch << std::endl;
}

void chargeFloat(const float &num) {
    std::cout << "Charging float: " << num << std::endl;
}

int main() {
    int intArr[] = { 1, 2, 3, 4, 5 };
    std::string strArr[] = { "Hello", "World", "!" };
    char charArr[] = { 'a', 'b', 'c' };
    float floatArr[] = { 1.23f, 4.56f, 7.89f };

    iter(intArr, 5, chargeInt);
    iter(strArr, 3, chargeString);
    iter(charArr, 3, chargeChar);
    iter(floatArr, 3, chargeFloat);

    return 0;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
