#include <iostream>
#include <string>
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    int a;

    std::cout << "Введите число 1: ";
    std::cin >> a;

    int b;

    std::cout << "Введите число 2: ";
    std::cin >> b;

    float c = (a + b) / 2.0f;

    std::cout << "Среднее: " << c << std::endl;

    char d;

    std::cout << "Введите +, -, * или /: ";

    std::cin >> d;

    /*

    float e = 0;

    if (d == '+') {

        e = a + b;

    }

    else if (d == '-') {

        e = a - b;

    }

    else if (d == '*') {

        e = a * b;

    }

    else if (d == '/') {

        if (b == 0) {

            std::cout << "Ошибка!" << std::endl;

            return 1;

        }

        e = (float)a / b;

    }

    else {

        std::cout << "Неверно!" << std::endl;

        return 1;

    }

    std::cout << "Ответ: " << e << std::endl;

    */

    float e = 0;
    switch (d) {
        case '+':
            e = a + b;
            break;
        case '-':
            e = a - b;
            break;
        case '*':
            e = a * b;
            break;
        case '/':
            if (b == 0) {
                std::cout << "Ошибка: на ноль делить нельзя!" << std::endl;
                return 1;
            }
            e = (float)a / b;
            break;
        default:
            std::cout << "Неправильный знак!" << std::endl;
            return 1;
    }

    std::cout << "Ответ: " << e << std::endl;

    return 0;
}
