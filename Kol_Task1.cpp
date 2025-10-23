#include <iostream>
#include <vector>
#include "Factorial.h"

void printFactorials(int n) {
    try {
        std::cout << "Первые " << n << " факториалов: ";

        auto factorials = FactorialCalc::calculateFact(n);

        for (size_t i = 0; i < factorials.size(); i++) {
            std::cout << factorials[i];
            if (i != factorials.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    std::cout << "Введите число n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Овведите неотрицательное целое число" << std::endl;
        return 1;
    }

    printFactorials(n);

    return 0;
}
}
