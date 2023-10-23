#include "phonebook.hpp"

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

PhoneBook::PhoneBook(){
    maxContact = 8;
    sizeContact = 0;
};

void PhoneBook::addContact() {
    int index = sizeContact % maxContact;
    std::string input;
        std::cout << "Enter contact information" << std::endl;
        std::cout << "First Name     ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        while (true){
            if (input.length() == 0){std::cout<< "empty input" << std::endl;}
            else{
                contacts[index].setFname(input);
                break;
            }
            std::getline(std::cin, input);
            if (!std::cin.good()){exit(0);}
        }
        std::cout << "Last Name      ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        while (true){
            if (input.length() == 0){std::cout<< "empty input" << std::endl;}
            else{
                contacts[index].setLname(input);
                break;
            }
            std::getline(std::cin, input);
            if (!std::cin.good()){exit(0);}
        }
        std::cout << "Phone Number   ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        while (true){
            if (input.length() == 0){std::cout<< "empty input" << std::endl;}
            else{
                contacts[index].setPhoneNumber(input);
                break;
            }
            std::getline(std::cin, input);
            if (!std::cin.good()){exit(0);}
        }
        std::cout << "Nick name      ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
         while (true){
            if (input.length() == 0){std::cout<< "empty input" << std::endl;}
            else{
                contacts[index].setNickname(input);
                break;
            }
            std::getline(std::cin, input);
            if (!std::cin.good()){exit(0);}
        }
        std::cout << "Darkest Secret ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
         while (true){
            if (input.length() == 0){std::cout<< "empty input" << std::endl;}
            else{
                contacts[index].setSecret(input);
                break;
            }
            std::getline(std::cin, input);
            if (!std::cin.good()){exit(0);}
        }
        sizeContact++;
}

int	ft_atoi(std::string str)
{
	int		i;
	int		s;
	long	n;

	s = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(s *= -1);
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
        return(0);
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
	if ((str[i] < 48 || str[i] > 57) && str[i])
    {
		std :: cout << "invalid index!!zz" << std::endl;
        return(0);
    }
	return (n * s);
}

void PhoneBook::SearchContact() {
    std::cout << "========================== LIST CONTACTS ==============================" << std::endl;
    std::cout  <<std::setw(10) <<  "Index" << " | "
               <<std::setw(10) <<"First Name" << " | "
               <<std::setw(10) <<"Last Name" << " | "
               <<std::setw(10) <<"Number Phone" << std::endl;
    std::cout << "=======================================================================" << std::endl;

    int size = sizeContact;
    if (size > 8) {
        size = 8;
    }
    for (int i = 0; i < size; i++) {
        std::string fnm = contacts[i].getFname();
        std::string lnm = contacts[i].getLname();
        std::string nmbr = contacts[i].getPhoneNumber();
        std::string nckn = contacts[i].getNickname();
        std::string scrt = contacts[i].getSecret();

        if (fnm.length() > 10) {
            fnm = fnm.substr(0, 9) + ".";
        }
        if (lnm.length() > 10) {
            lnm = lnm.substr(0, 9) + ".";
        }
        if (nmbr.length() > 10) {
            nmbr = nmbr.substr(0, 9) + ".";
        }

        std::cout << std::setw(10)  << i + 1 << " | "
                 << std::setw(10)  << fnm << " | "
                 << std::setw(10)  << lnm << " | "
                 << std::setw(10)  << nmbr << std::endl;
    }

    std::cout << "=======================================================================" << std::endl;

    std::string indx;
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, indx);
    if (!std::cin.good()){exit(0);}
    index = ft_atoi(indx);
    while (true){
        if (indx.length() == 0){std::cout<< "empty index" << std::endl;}
        else{
            break;
        }
        std::getline(std::cin, indx);
        index = ft_atoi(indx);
        if (!std::cin.good()){exit(0);}
    }
    if (!index)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    if(index ){
        if (index < 1 || index > sizeContact) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "################# RESULT SEARCH #############" << std::endl;
    std::cout << "First Name     :# " << contacts[index - 1].getFname() << std::endl;
    std::cout << "Last  Name     :# " << contacts[index - 1].getLname() << std::endl;
    std::cout << "Nick  Name     :# " << contacts[index - 1].getNickname() << std::endl;
    std::cout << "Darket Secret  :# " << contacts[index - 1].getSecret() << std::endl;
    std::cout << "Phone Number   :# " << contacts[index - 1].getPhoneNumber() << std::endl;
    std::cout << "##############################################" << std::endl;
    
    }
}

int main(){
    std::string var;
    Contact cn;
    PhoneBook pn;
    while (true)
    {
        std::getline(std::cin, var);
        if (!std::cin.good()) {
        return(0);}
        if (var == "ADD")
            pn.addContact();
        else if (var == "SEARCH")
            pn.SearchContact();
        else if (var == "EXIT")
            exit(0);
        else
            std::cout<<"DID YOU MEAN (ADD || SEARCH || EXIT) ??"<<std::endl;
    }
}
