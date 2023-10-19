#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <list>

// using namespace std;

class Contact {
private:
    std::string Fname;
    std::string Lname;
    std::string number;
    std::string Secret;

public:
    // Constructor declaration
    // Contact();
    
    std::string getFname();
    std::string getLname();
    std::string getPhoneNumber();
    std::string getSecret();
    // Member function declarations
    std::string setFname(std::string n);
    std::string setLname(std::string n);
    std::string setPhoneNumber(std::string n);
    std::string setSecret(std::string n);
};