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
    std::cout << "Калькулятор факториалов " << std::endl;

    printFactorials(0);
    printFactorials(1);
    printFactorials(5);
    printFactorials(10);

    return 0;
}