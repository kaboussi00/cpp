#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <list>
#include "contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int maxContact;
        int sizeContact;
    public:
        // constractor declaration
        PhoneBook(){
            maxContact = 8;
            sizeContact = 0;
        };
    
        //function mumbers
        void addContact();     
        void SearchContact();
};
