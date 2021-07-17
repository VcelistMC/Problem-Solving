#include <iostream>
int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    if(str1 == str2)
        std::cout << "-1";
    else
        std::cout << (str1.length() > str2.length()? str1.length() : str2.length());
}