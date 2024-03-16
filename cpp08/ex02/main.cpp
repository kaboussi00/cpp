#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::rev_iterator it1 = mstack.rbegin();
    MutantStack<int>::rev_iterator ite1 = mstack.rend();
    ++it;
    --it;
    std::cout << "Iterator :\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    ++it1;
    --it1;
    std::cout << "Reverse Iterator :\n";
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::stack<int> s(mstack);
    return 0;
}
