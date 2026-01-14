#include <iostream>
#include <stdexcept> 
#include <ctime>
using namespace std;

class BirthYearException : public std::exception {
private:
public:
    enum ErrorCode {
        TOO_OLD,
        FUTURE_YEAR,
        NEGATIVE_YEAR,
        INVALID_VALUE
    };
    ErrorCode code;
    BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case TOO_OLD:
            return "Введённый год слишком старый для реального года рождения";
        case FUTURE_YEAR:
            return "Введённый год ещё не наступил";
        case NEGATIVE_YEAR:
            return "Год рождения не может быть отрицательным";
        case INVALID_VALUE:
            return "Некорректное значение года";
        default:
            return "Неизвестная ошибка при вводе года рождения";
        }
    }
};

string numberToText(int n) {
    if (n == 1) return "Один";
    else if (n == 2) return "Два";
    else if (n == 3) return "Три";
    else throw invalid_argument("Некорректное значение");
}

int getCurrentYear() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        cout << "Введите число от 1 до 3: ";
        int num;
        cin >> num;
        cout << "Вы ввели: " << numberToText(num) << "\n";
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << "\n";
    }

    try {
        cout << "\nВведите ваш год рождения: ";
        int birthYear;
        cin >> birthYear;
        
        int currentYear = getCurrentYear();
        
        if (birthYear < 0) {
            throw BirthYearException(BirthYearException::NEGATIVE_YEAR);
        }
        else if (birthYear < 1850) {
            throw BirthYearException(BirthYearException::TOO_OLD);
        }
        else if (birthYear > currentYear) {
            throw BirthYearException(BirthYearException::FUTURE_YEAR);
        }
        else if (birthYear == 0) {
            throw BirthYearException(BirthYearException::INVALID_VALUE);
        }
        else {
            cout << "Спасибо! Ваш возраст: " << (currentYear - birthYear) << " лет\n";
        }
    }
    catch (const BirthYearException& e) {
        cout << "Ошибка: " << e.what() << "\n";
    }
    catch (const exception& e) {
        cout << "Произошла ошибка: " << e.what() << "\n";
    }

    return 0;
}
