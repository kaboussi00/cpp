#include "rpn.hpp"

int evaluateRPN(const std::string& exp)
{
    std::stack<int> s;
    for (size_t i = 0 ; i < exp.size(); i++)
    {
        if (exp[i] == ' ')
            continue;
        else if (std::isdigit(exp[i]))
            s.push(exp[i] - '0');
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if (s.size() < 2)
                throw std::runtime_error("Error: Invalid expression");
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (exp[i] == '+')
                s.push(a + b);
            else if (exp[i] == '-')
                s.push(a - b);
            else if (exp[i] == '*')
                s.push(a * b);
            else if (exp[i] == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
                s.push(a / b);
            }
        }
        else
            throw std::runtime_error("Error: Invalid exp");
    }
    if (s.size() != 1)
        throw std::runtime_error("Error: Invalid exp");
    return s.top();
}