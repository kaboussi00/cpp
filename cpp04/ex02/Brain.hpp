#pragma once

#include <iostream>

class Brain{
    private:
        std::string ideas[100];
    public :
        Brain();
        Brain(std::string name);
        Brain(const Brain &obj);
        Brain &operator=(const Brain &obj);
        void setideas(std::string idea, int i);
        std::string getideas(int i);
        ~Brain();
};
