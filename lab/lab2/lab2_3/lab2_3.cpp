#include <iostream>
#include <clocale>

// Функция для суммы чисел от 1 до n
int sum_to_n(int n = 1) {
    if (n <= 0) return 0;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

// Функция с ссылочными параметрами
void calculate(int a, int b, int& sum_ref, int& mul_ref) {
    sum_ref = a + b;
    mul_ref = a * b;
}

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    
    // массив 2x3
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    
    // Сумма всех чисел массива
    int total = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            total += arr[i][j];
        }
    }
    std::cout << total << std::endl;
    
    // Одномерный массив из сумм столбцов
    int col_sum[3] = {0};
    for (int j = 0; j < 3; j++) {
        col_sum[j] = arr[0][j] + arr[1][j];
    }
    
    // Вывод одномерного массива
    for (int i = 0; i < 3; i++) {
        std::cout << col_sum[i] << " ";
    }
    std::cout << std::endl;
    
    float num = 20.84f;
    
    // Две ссылки на переменную
    float& ref1 = num;
    float& ref2 = num;
    
    // Изменение значения через ссылку
    ref1 = 38.53f;
    
    // Проверка изменений
    std::cout << num << " " << ref1 << " " << ref2 << std::endl;
    
    // Тестирование
    std::cout << sum_to_n(6) << std::endl;   // сумма от 1 до 6
    std::cout << sum_to_n(-6) << std::endl;  // 0
    std::cout << sum_to_n() << std::endl;    // по умолчанию 1
    
    // Тестирование функции с ссылками
    int x = 6, y = 3;
    int sum_result, mul_result;
    calculate(x, y, sum_result, mul_result);
    std::cout << sum_result << " " << mul_result << std::endl;
    
    int k = 1;
    
    // Цикл с внутренней переменной
    for (int i = 0; i < 3; i++) {
        std::cout << k << " ";
        int p = 2;
        std::cout << p << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
