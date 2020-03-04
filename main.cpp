#include <iostream>
#include "derivative.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> function;
    function.push_back("1");
    function.push_back("x");
    function.push_back("+");
    function.push_back("x");
    function.push_back("*");
    differentiate(function, "x");
    return 0;
}
