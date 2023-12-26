#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <list>

class Contact {
private:
    std::string Fname;
    std::string Lname;
    std::string number;
    std::string nickname;
    std::string Secret;

public:
    std::string getFname();
    std::string getLname();
    std::string getPhoneNumber();
    std::string getNickname();
    std::string getSecret();
    void setFname(std::string n);
    void setLname(std::string n);
    void setPhoneNumber(std::string n);
    void setNickname(std::string n);
    void setSecret(std::string n);
};