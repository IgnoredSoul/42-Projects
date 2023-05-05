
#include <iostream>
#include <string>
#include <stdio.h>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address in memory of the string : " << (void*)&str[0] << std::endl;
    std::cout << "Address of the string using stringPTR : " << stringPTR << std::endl;
    std::cout << "Address of the string using stringREF : " << &stringREF << std::endl;

    std::cout << "String data using stringPTR : " << *stringPTR << std::endl;
    std::cout << "String data using stringREF : " << stringREF << std::endl;
}