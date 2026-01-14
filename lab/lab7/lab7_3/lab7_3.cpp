#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

int main() {
    double radius;
    std::cout << "Введите радиус окружности: ";
    std::cin >> radius;
    
    double length = 2 * M_PI * radius;
    std::cout << "Длина окружности: " << std::fixed << std::setprecision(3) 
              << length << std::endl;
    
    std::string filename = "textfile.txt";
    
    while (true) {
        std::string input;
        std::cout << "\nВведите строку (или read/erase/exit): ";
        std::cin >> input;
        
        if (input == "exit") {
            std::cout << "Выход из программы" << std::endl;
            break;
        }
        else if (input == "read") {
            std::ifstream file(filename);
            if (file.is_open()) {
                std::cout << "Содержимое файла:" << std::endl;
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            } else {
                std::cout << "Файл пуст или не существует" << std::endl;
            }
        }
        else if (input == "erase") {
            std::ofstream file(filename, std::ios::trunc);
            file.close();
            std::cout << "Файл очищен" << std::endl;
        }
        else {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << input << std::endl;
                std::cout << "Строка записана в файл" << std::endl;
                file.close();
            }
        }
    }
    
    return 0;
}
