#include "Aanimal.hpp"

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "stdlib.h"

int main()
{{
        Brain brain;

	    std::string ideas[100] = {
		"meowiing...",
		"eating...",
		"sleeping...",
		"thinking....(WHY NOT?!)",
		"scratching...",
		"Getting upset for no reason...",
		"sdjkhdsak",
		"SseDjNunpK",
		"YSWkdwjyIM",
		"JEvDeIUjRs",
		"GWFCKXQLVF",
		"ESZHTEsLUm",
		"ugbWVMwACy",
		"UTQoxqEFUM"};

	for (int i = 0; i < 14; i++){
		brain.setideas(ideas[i], i);
	}

	Aanimal **animals = new Aanimal*[8];

	for (int i = 0; i < 8; i++){
		if (i < 2){
			animals[i] = new Dog;
		} else{
			animals[i] = new Cat;
		}
	}

	for (int i = 0; i < 8; i++){
		if (i == 0){
			std::cout << "-------------------DOG's SOUND--------------------"<< std::endl;
		}else if (i == 2) {
			std::cout << "-------------------CAT's SOUND--------------------"<< std::endl;
		}
		std::cout << "ideaaaaaaaaaaaaaaaaaa -> "<< brain.getideas(i) << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < 8; i++)
		delete animals[i];
	delete[] animals;
    }
	return 0;
}

