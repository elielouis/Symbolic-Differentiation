#ifndef DERIVATIVE_H_INCLUDED
#define DERIVATIVE_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>


struct math_expression
{
    std::string original;
    std::string derivative;
};

bool isValue(std::string in, int pos);
std::string differentiate(std::vector<std::string> function, std::string variable);



#endif // DERIVATIVE_H_INCLUDED
