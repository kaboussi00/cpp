#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Cure::Cure(){
	type = "cure";
}

Cure::~Cure(){}

Cure::Cure(Cure const &obj){
	type = obj.getType();
}

Cure &Cure::operator=(Cure const &obj){
	(void)obj;
	return (*this);
}

std::string const &Cure::getType() const{
	return (type);
}

Cure *Cure::clone() const{
	Cure	*ret = new Cure;
	return (ret);
}

void Cure::use(ICharacter& target){
	std::string target_name = target.getName();
	std::cout << "* heals " << target_name << "\'s wounds *" << std::endl;
}