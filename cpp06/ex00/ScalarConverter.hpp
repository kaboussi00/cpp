#pragma once

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class ScalarConverter{
    private :
        std::string value;
    public :
        ScalarConverter();
        ScalarConverter(std::string value);
        ScalarConverter(ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        static void convert(const std::string& value);
        ~ScalarConverter();
        class NonDisplayed : public std::exception{
            public :
                const char * what() const throw(){
                    return "Non displayable";
                }
        };
        class Impossible : public std::exception{
            public :
                const char * what() const throw(){
                    return "impossible";
                }
        };

};