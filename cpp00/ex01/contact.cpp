
#include "contact.hpp"

std::string Contact::getFname(){
    return (Fname);
}
std::string Contact::getLname(){
    return (Lname);
}
std::string Contact::getPhoneNumber(){
    return (number);
}
std::string Contact::getNickname(){
    return (number);
}
std::string Contact::getSecret(){
    return (Secret);
}

void Contact::setFname(std::string n){
    Fname = n;
}
void Contact::setLname(std::string n){
    Lname = n;
}
void Contact::setPhoneNumber(std::string n){
    number = n;
}
void Contact::setNickname(std::string n){
    number = n;
}
void Contact::setSecret(std::string n){
    Secret = n;
}