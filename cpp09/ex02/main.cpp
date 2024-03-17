#include "sort.hpp"

int main(int argc, char* argv[])
{
    if (argc <= 1)
        return 0;
    std::vector<int> v;
    std::string ret;
    try
    {
        for (int i = 1; i < argc; i++)
        {
            ret += argv[i];
            if (i != argc - 1)
                ret += ' ';
        }
        v = split(ret, ' ');
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    std::deque<int> d(v.begin(), v.end());
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    v = sort_vector(v);
    clock_t end = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(5) << static_cast<float>(end - start) << "\n";

    // std::cout << "Before: ";
    // for (size_t i = 0; i < d.size(); i++)
    //     std::cout << d[i] << " ";
    // std::cout << std::endl;

    start = clock();
    d = sort_deque(d);
    end = clock();

    // std::cout << "After:  ";
    // for (size_t i = 0; i < d.size(); i++)
    //     std::cout << d[i] << " ";
    // std::cout << std::endl;

    std::cout << "Time to process a range of " << d.size() << " elements with std::deque: ";
    std::cout << std::fixed << std::setprecision(5) << static_cast<float>(end - start) << "\n";

    return 0;
}