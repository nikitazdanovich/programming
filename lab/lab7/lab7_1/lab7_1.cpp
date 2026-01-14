#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    if (str.length() >= 3) {
        std::string sub = str.substr(1, 3);
        std::cout << "Подстрока: " << sub << std::endl;
    } else {
        std::cout << "Слишком короткая строка" << std::endl;
    }

    size_t pos = str.find('a');
    if (pos != std::string::npos) {
        std::cout << "Позиция 'a': " << pos << std::endl;
    } else {
        std::cout << "Символа a не найдено" << std::endl;
    }
    
    return 0;
}
