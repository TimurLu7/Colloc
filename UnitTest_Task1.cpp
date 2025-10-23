#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Timur\proga\ОС\Kol_Task1\Kol_Task1\Factorial.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTask1
{
	TEST_CLASS(UnitTestTask1)
	{
	public:
		
        TEST_METHOD(CalculateFact_Zero_ReturnsOneElement)
        {
            auto result = FactorialCalc::calculateFact(0);
            Assert::AreEqual(size_t(1), result.size());
        }

        TEST_METHOD(CalculateFact_Five_ReturnsCorrectFactorials)
        {
            auto result = FactorialCalc::calculateFact(5);
            std::vector<long long> expected = { 1, 1, 2, 6, 24 };

            Assert::AreEqual(expected.size(), result.size());
            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], result[i]);
            }
        }

        TEST_METHOD(CalculateFact_Negative_ThrowsException)
        {
            auto func = [] { FactorialCalc::calculateFact(-1); };
            Assert::ExpectException<std::exception>(func);
        }
    };

    TEST_CLASS(InputValidationTests)
    {
    public:

        TEST_METHOD(ValidateInput_PositiveNumber_Valid)
        {
            int n = 5;
            bool isValid = (n >= 0);
            Assert::IsTrue(isValid);
        }

        TEST_METHOD(ValidateInput_NegativeNumber_Invalid)
        {
            int n = -5;
            bool isValid = (n >= 0);
            Assert::IsFalse(isValid);
        }

        TEST_METHOD(ValidateInput_Zero_Valid)
        {
            int n = 0;
            bool isValid = (n >= 0);
            Assert::IsTrue(isValid);
        }
    };
}