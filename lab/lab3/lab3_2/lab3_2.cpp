#include <iostream>
using namespace std;

// 1. Функция суммы элементов массива
int summArray(int* nach, int* kon) {
    int summa = 0;
    for (int* pntr = nach; pntr != kon; pntr++) {
        summa += *pntr;
    }
    return summa;
}

// 3. Функции суммы и разности
int sum(int a, int b) {
    return a + b;
}

int raz(int a, int b) {
    return a - b;
}

// 4, 5. Функция, возвращающая указатель на функцию
int (*sum_or_raz(char x))(int, int) {
    if (x == '+') return sum;
    else if (x == '-') return raz;
    else return nullptr; // на случай других символов
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    // 2. Проверка функции суммы массива
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Сумма массива: " << summArray(array, array + size) << endl;
    
    // 6. Проверка функций с указателями на функции
    char operation;
    cout << "Введите операцию (+ или -): ";
    cin >> operation;
    
    // Получаем указатель на функцию
    int (*funcPtr)(int, int) = sum_or_raz(operation);
    
    if (funcPtr != nullptr) {
        // Вызываем функцию через указатель
        int result = funcPtr(10, 3);
        cout << "Результат: " << result << endl;
    } else {
        cout << "Неверная операция!" << endl;
    }
    
    // 7, 8. Динамический указатель
    float* dynamicPtr = new float(3.14f);
    cout << "Динамическая переменная: " << *dynamicPtr << endl;
    
    // Освобождаем память
    delete dynamicPtr;
    
    return 0;
}
