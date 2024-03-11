#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){
}

Base * generate(void){
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();}
        return NULL;
}

void identify(Base *p){
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);
    if (a != NULL){
        std::cout << "A" << std::endl;
    }
    else if (b != NULL){
        std::cout << "B" << std::endl;
    }
    else if (c != NULL){
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p){
    try{
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &ex){
        try{
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(std::exception &ex){
            try{
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(std::exception &ex){
                std::cout << "not :A B C" <<  std::endl;
            }
        }
    }
}

Base::~Base(){

}