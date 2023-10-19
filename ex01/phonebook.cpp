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
std::string Contact::getSecret(){
    return (Secret);
}

std::string Contact::setFname(std::string n){
    Fname = n;
    return (Fname);
}
std::string Contact::setLname(std::string n){
    Lname = n;
    return (Lname);
}
std::string Contact::setPhoneNumber(std::string n){
    number = n;
    return (number);
}
std::string Contact::setSecret(std::string n){
    Secret = n;
    return (Secret);
}

void PhoneBook::addContact() {
    std::string input;
    if (sizeContact == maxContact) {
        std::cout << "Enter contact information:" << std::endl;
        std::cout << "First Name   ?";
        std::getline(std::cin, input);
        contacts[sizeContact % maxContact].setFname(input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        std::cout << "Last Name    ?";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact % maxContact].setLname(input);
        std::cout << "Phone Number ?";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact % maxContact].setPhoneNumber(input);
        std::cout << "Darkest Secret?";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact % maxContact].setSecret(input);
}
    else {
        std::cout << "Enter contact information" << std::endl;
        std::cout << "First Name     ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact].setFname(input);
        std::cout << "Last Name      ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact].setLname(input);
        std::cout << "Phone Number   ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact].setPhoneNumber(input);
        std::cout << "Darkest Secret ? ";
        std::getline(std::cin, input);
        if (!std::cin.good()){exit(0);}
        if (input.length() == 0){std::cout<< "empty input" << std::endl;}
        contacts[sizeContact].setSecret(input);
        sizeContact++;
    }
    std::cout << "---------------------Contact information---------------" << std::endl;
    int j = 1;
    for (int i = 0; i < sizeContact; i++) {
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<< " <<j << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "|First Name        | " << contacts[i].getFname() << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "|Last Name         | " << contacts[i].getLname() << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "|Phone Number      | " << contacts[i].getPhoneNumber() << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "|Darkest Seret     | " << contacts[i].getSecret() << std::endl;
        std::cout << " -------------------------------------------------------------------" << std::endl;
        j++;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << " -------------------------------------------------------------------" << std::endl;
}

int	ft_atoi(std::string str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(s *= -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - 48;
		i++;
	}
	return (n * s);
}

void PhoneBook::SearchContact() {
    std::cout << "================= LIST CONTACTS =================" << std::endl;
    std::cout << std::left <<std::setw(10) <<  "Index" << " | "
              << std::left <<std::setw(10) <<"First Name" << " | "
              << std::left <<std::setw(10) <<"Last Name" << " | "
              << std::left <<std::setw(10) <<"secret" << std::endl;
    std::cout << "=================================================" << std::endl;

    for (int i = 0; i < sizeContact; i++) {
        std::string fnm = contacts[i].getFname();
        std::string lnm = contacts[i].getLname();
        std::string nmbr = contacts[i].getPhoneNumber();

        if (fnm.length() > 10) {
            fnm = fnm.substr(0, 9) + ".";
        }
        if (lnm.length() > 10) {
            lnm = lnm.substr(0, 9) + ".";
        }
        if (nmbr.length() > 10) {
            nmbr = nmbr.substr(0, 9) + ".";
        }

        std::cout << std::left << std::setw(10)  << i + 1 << " | "
                  << std::left << std::setw(10)  << fnm << " | "
                  << std::left << std::setw(10)  << lnm << " | "
                  << std::left << std::setw(10)  << nmbr << std::endl;
    }

    std::cout << "=================================================" << std::endl;

    std::string indx;
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, indx);
    if (!std::cin.good()){exit(0);}
    if (indx.length() == 0){std::cout<< "empty input" << std::endl;}
    index = ft_atoi(indx);
    if (index < 1 || index > sizeContact) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cout << "################# RESULT SEARCH #############" << std::endl;
    std::cout << "First Name  :# " << contacts[index - 1].getFname() << std::endl;
    std::cout << "Last  Name  :# " << contacts[index - 1].getLname() << std::endl;
    std::cout << "Phone Number:# " << contacts[index - 1].getPhoneNumber() << std::endl;
    std::cout << "##############################################" << std::endl;
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
        if (var.length()){std::cout<< "empty input" << std::endl;}
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
