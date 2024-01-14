#pragma once

#include <iostream>

class Brain{
    private:
        std::string ideas[100];
    public :
        Brain();
        Brain(const Brain &obj);
        Brain &operator=(const Brain &obj);
        std::string getideas(int i);
        void setideas(int i, std::string ideas);
        ~Brain();
};
