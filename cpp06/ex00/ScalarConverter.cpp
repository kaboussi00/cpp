#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(std::string a){
    value = a;
}

ScalarConverter::ScalarConverter(ScalarConverter &obj){
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj){
    if (this != &obj)
        this->value = obj.value;
    return (*this);
}

void ScalarConverter::convert(const std::string & value){
    int intval;
    float floatval;
    double doubleval;
    int i = 0;
    // convert into char
    try{
        if (value.size() == 1 && !isdigit(value[0])){
            std::cout << "char: '" << value[0] << "'"  << std::endl;
        }
        else{
        intval = std::stoi(value);  
        floatval = std::stof(value); 
        i = 0;
        if ((intval < 0 || intval > 255) || floatval - intval != 0){
            throw Impossible();}
        if (!isprint(intval))
            throw NonDisplayed();
        std::cout<<"char: '"<<static_cast<char>(intval)<<"'"<<std::endl;
        }
    }
    catch(NonDisplayed &ex){
        std::cout << "char :" <<ex.what()<< std::endl;
    }
    catch(std::exception& ex){
        std::cout << "char :impossible" << std::endl;
    }

    // convert into int
    try{
            intval = std::stoi(value);
            std::cout << "int: " << intval << std::endl;
    }
    catch(std::exception &ex){
        if (value.size() == 1 && !isdigit(value[0]))
            std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
    }
    // convert into float
    try{
            floatval = std::stof(value);
            intval = std::stoi(value);
            std::cout << "float: " <<  floatval;
            if (floatval - intval == 0)
                std::cout << ".0f";
            else
                std::cout << "f";
            std::cout << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "float: nanf" << std::endl;
    }
    // convert into double
    try{
            doubleval = std::stod(value);
            intval = std::stoi(value);
            std::cout << "double: " << doubleval;
            if (doubleval - intval == 0)
                std::cout << ".0";
            std::cout << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "double: nan"  << std::endl;}
}

ScalarConverter::~ScalarConverter(){
}
