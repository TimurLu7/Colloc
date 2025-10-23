#include <vector>
#include <unordered_set>
#include <iostream>
#include <stdexcept>

std::vector<int> removeDuplicates(const std::vector<int>& input) {
    if (input.empty()) {
        std::cout << "передан пустой вектор" << std::endl;
        return std::vector<int>(); 
    }
    std::vector<int> result;
    std::unordered_set<int> set;
    try {
        for (int num : input) {
            if (set.find(num) == set.end()) {
                set.insert(num);
                result.push_back(num);
            }
        }

        if (result.empty()) {
            std::cout << "все элементы были дубликатами" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка при обработке данных: " << e.what() << std::endl;
        throw;
    }


    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    try {
        std::vector<int> numbers;
        int n;
        std::cout << "Введите количество элементов: ";
        std::cin >> n;

        if (std::cin.fail()) {
            throw std::runtime_error("Ошибка: введено не число");
        }

        if (n < 0) {
            throw std::runtime_error("Ошибка: количество элементов не может быть отрицательным");
        }

        if (n == 0) {
            std::cout << "Введен пустой массив" << std::endl;
        }

        std::cout << "Введите " << n << " чисел: ";
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;

            if (std::cin.fail()) {
                throw std::runtime_error("Ошибка: введено не число");
            }
            numbers.push_back(num);
        }
        std::vector<int> result = removeDuplicates(numbers);

        std::cout << "Массив без дубликатов: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}