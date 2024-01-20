#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice(){
	type = "ice";
}

Ice::~Ice(){}

Ice::Ice(Ice const &obj) : type(obj.getType()){
}

Ice & Ice::operator=(Ice const &obj){
	(void)obj;
	return (*this);
}

std::string const &Ice::getType() const{
	return (type);
}

Ice *Ice::clone() const{
	Ice	*ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target){
	std::string target_name = target.getName();
	std::cout << "* shoots an ice bolt at " << target_name <<" *" <<std::endl;
}