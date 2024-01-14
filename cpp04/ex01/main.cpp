#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{{
    Brain brain;

    std::string ideas[100] = {"meowiing...",
    "eating...",
    "sleeping...",
    "thinking....(WHY NOT?!)",
    "scratching...",
    "Getting upset for no reason...",
    "sdjkhdsak",
    "SseDjNunpK",
    "GWFCKXQLVF",
    "YSWkdwjyIM",
    "JEvDeIUjRs",
    "ESZHTEsLUm",
    "ugbWVMwACy",
    "UTQoxqEFUM"};
    for (int i = 0; i < 14; i++){
        brain.setideas(i, ideas[i]);
    }

    Animal **animals = new Animal*[4];

    for (int i = 0; i < 4; i++){
        if (i < 2){
            animals[i] = new Dog;
        } else{
            animals[i] = new Cat;
        }
    }

    for (int i = 0; i < 4; i++){
        if (i == 0){
            std::cout << "-------------------DOG's SOUND--------------------"<< std::endl;
        }else if (i == 2) {
            std::cout << "-------------------CAT's SOUND--------------------"<< std::endl;
        }
        std::cout << brain.getideas(i)<< std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    delete[] animals;
    }
}