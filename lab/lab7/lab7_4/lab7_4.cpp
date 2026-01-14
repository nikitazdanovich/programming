#include <iostream>
#include <vector>
#include <map>
#include <string>

void printVector(const std::vector<float>& vec) {
    std::cout << "Вектор: ";
    for (float num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

class Settings {
private:
    static std::map<std::string, std::string> data;

public:
    static void Add(const std::string& key, const std::string& value) {
        data[key] = value;
    }
    
    static std::string Get(const std::string& key) {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return "Ключ не найден";
    }
    
    static void Print() {
        std::cout << "Настройки:" << std::endl;
        for (const auto& pair : data) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }
    }
};

std::map<std::string, std::string> Settings::data;

int main() {
    std::vector<float> numbers;
    
    numbers.push_back(1.5f);
    numbers.push_back(2.5f);
    numbers.push_back(3.5f);
    numbers.push_back(4.5f);
    numbers.push_back(5.5f);
    
    printVector(numbers);

    auto it = numbers.begin() + 3;
    numbers.insert(it, 3.75f);
    
    printVector(numbers);
    
    numbers.pop_back();
    
    printVector(numbers);
    
    std::cout << "\n";
    
    /*
    Settings settings;
    settings.Add("Язык", "Русский");
    settings.Add("Тема", "Тёмная");
    settings.Add("Громкость", "75");
    
    std::cout << "Язык: " << settings.Get("Язык") << std::endl;
    std::cout << "Тема: " << settings.Get("Тема") << std::endl;
    std::cout << "Несуществующий: " << settings.Get("Разрешение") << std::endl;
    
    settings.Print();
    */
    
    Settings::Add("Язык", "Английский");
    Settings::Add("Тема", "Светлая");
    Settings::Add("Громкость", "50");
    
    std::cout << "Язык: " << Settings::Get("Язык") << std::endl;
    std::cout << "Тема: " << Settings::Get("Тема") << std::endl;
    std::cout << "Несуществующий: " << Settings::Get("Яркость") << std::endl;
    
    Settings::Print();
    
    return 0;
}
