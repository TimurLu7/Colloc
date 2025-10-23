#pragma once
#include <vector>
#include <stdexcept>

class FactorialCalc {
public:
    static std::vector<long long> calculateFact(int n) {
        if (n < 0) {
            throw std::invalid_argument("����� ������ ���� ����������� (n >= 0)");
        }

        if (n > 20) {
            throw std::overflow_error("������� ������� n! �������� 20 ��� ���� long long");
        }

        std::vector<long long> result;
        long long factorial = 1;
        result.push_back(factorial);

        for (int i = 1; i < n; i++) {
            factorial *= i;
            result.push_back(factorial);
        }

        return result;
    }
};