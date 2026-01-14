#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string name;
    std::cout << "Введите ваше имя: ";
    std::cin >> name;
    
    std::regex namePattern("^[A-Z][a-z]{1,31}$");
    
    if (std::regex_match(name, namePattern)) {
        std::cout << "Имя корректно: " << name << std::endl;
    } else {
        std::cout << "Имя некорректно!" << std::endl;
        std::cout << "Имя должно быть от 2 до 32 символов, начинаться с заглавной буквы и содержать только буквы." << std::endl;
    }

    std::string text = "Контакты: support@company.com, manager@gmail.com, "
                      "info@mail.ru и test@test.org для связи.";
    
    std::cout << "\nEmail-адреса в тексте:" << std::endl;
    
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    
    auto begin = std::sregex_iterator(text.begin(), text.end(), emailPattern);
    auto end = std::sregex_iterator();
    
    int count = 0;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::cout << ++count << ". " << match.str() << std::endl;
    }
    
    if (count == 0) {
        std::cout << "Адреса не найдены" << std::endl;
    }
    
    return 0;
}
