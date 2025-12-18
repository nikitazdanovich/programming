#include <iostream>
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n;
    while (true) {
        std::cout << "Введите положительное число: ";
        std::cin >> n;
        if (n > 0) {
            break;
        }
        std::cout << "Попробуйте еще раз." << std::endl;
    }
    
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
        std::cout << i;
        if (i < n) {
            std::cout << " + ";
        }
    }
    std::cout << " = " << s << std::endl;
    
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " 
              << arr[4] << " " << arr[5] << " " << arr[6] << " " << arr[7] << " " 
              << arr[8] << " " << arr[9] << std::endl;
    
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            sum += arr[i];
        }
    }
    std::cout << sum << std::endl;
    
    return 0;
}
