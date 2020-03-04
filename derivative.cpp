#include "derivative.h"

int values_size=11;
char values[] = "1234567890.";



std::string differentiate(std::vector<std::string> function, std::string variable)
{
    std::vector<math_expression> stack;
    for(int i = 0; i<function.size(); i++)
    {
        if(isValue(function[i], 0))
        {
            math_expression expr;
            expr.original = function[i];
            expr.derivative = "0";
            stack.push_back(expr);

        }
        else if(function[i] == variable)
        {
            math_expression expr;
            expr.original = function[i];
            expr.derivative = "1";
            stack.push_back(expr);
        }
        else
        {
            if(function[i]=="+")
            {
                math_expression expr1, expr2;
                expr1 = stack.back();
                stack.pop_back();
                expr2 = stack.back();
                stack.pop_back();

                math_expression newexpr;

                newexpr.derivative = expr1.derivative + "+" + expr2.derivative;
                newexpr.original = expr1.original + "+" + expr2.original;

                stack.push_back(newexpr);
            }
            else if(function[i]=="*")
            {
                math_expression expr1, expr2;
                expr1 = stack.back();
                stack.pop_back();
                expr2 = stack.back();
                stack.pop_back();

                math_expression newexpr;
                newexpr.derivative = expr1.derivative + "*" + expr2.original + "+" + expr1.original + "*" + expr2.derivative;
                newexpr.original = expr1.original + "*" + expr2.original;

                stack.push_back(newexpr);


            }

        }

    }
    std::cout<<stack.back().derivative;
}


bool isValue(std::string in, int pos)
{
    if(in[pos]=='+' or in[pos]=='-')
    {
        if(in.size()>pos+1)
        {
            if(isValue(in, pos+1))
                return true;
        }
    }
    for(int i=0;i<values_size;i++)
    {
        if(in[pos]==values[i])
            return true;
    }
    return false;
}
