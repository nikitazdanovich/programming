#include <iostream>
#include <string>

int main()
{
    int a = 150;
    float b = 15.933f;
    unsigned char c = 250;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << (int)c << std::endl;

    int day1 = 31;
    std::string month1 = "марта";
    int year1 = 2006;
    std::cout << "Моя дата рождения: " 
              << day1 << " " 
              << month1 << " " 
              << year1 << " года" << std::endl;
    const float d = 2.3f;
    const std::string e = "WINDOWS";
    std::cout << d << " " << e << std::endl;
    return 0;
}
