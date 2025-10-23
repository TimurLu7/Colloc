#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Timur\proga\ОС\Kol_Task2\Kol_Task2\Kol_Task2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTask2
{
	TEST_CLASS(UnitTestTask2)
	{
	public:
		
        TEST_METHOD(TestEmptyVector)
        {
            std::vector<int> input = {};
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result.empty());
        }

        TEST_METHOD(TestNoDuplicates)
        {
            std::vector<int> input = { 1, 2, 3, 4, 5 };
            std::vector<int> expected = { 1, 2, 3, 4, 5 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestWithDuplicates)
        {
            std::vector<int> input = { 1, 2, 2, 3, 4, 4, 5, 1 };
            std::vector<int> result = removeDuplicates(input);

            for (int num : input) {
                bool found = std::find(result.begin(), result.end(), num) != result.end();
                Assert::IsTrue(found);
            }
        }

        TEST_METHOD(TestAllDuplicates)
        {
            std::vector<int> input = { 5, 5, 5, 5, 5 };
            std::vector<int> expected = { 5 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestOrderPreservation)
        {
            std::vector<int> input = { 3, 1, 2, 1, 3, 4, 2 };
            std::vector<int> expected = { 3, 1, 2, 4 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestSingleElement)
        {
            std::vector<int> input = { 42 };
            std::vector<int> expected = { 42 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestNegativeNumbers)
        {
            std::vector<int> input = { -1, -2, -1, -3, -2 };
            std::vector<int> expected = { -1, -2, -3 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestMixedNumbers)
        {
            std::vector<int> input = { -5, 0, 10, -5, 0, 20 };
            std::vector<int> expected = { -5, 0, 10, 20 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestLargeNumbers)
        {
            std::vector<int> input = { 1000000, 999999, 1000000, 888888 };
            std::vector<int> expected = { 1000000, 999999, 888888 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestBoundaryValues)
        {
            std::vector<int> input = { INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN };
            std::vector<int> result = removeDuplicates(input);

            Assert::AreEqual(size_t(3), result.size());

            bool hasIntMax = std::find(result.begin(), result.end(), INT_MAX) != result.end();
            bool hasIntMin = std::find(result.begin(), result.end(), INT_MIN) != result.end();
            bool hasZero = std::find(result.begin(), result.end(), 0) != result.end();

            Assert::IsTrue(hasIntMax);
            Assert::IsTrue(hasIntMin);
            Assert::IsTrue(hasZero);
        }

        

        TEST_METHOD(TestConsecutiveDuplicates)
        {
            std::vector<int> input = { 1, 1, 2, 2, 3, 3, 4, 4 };
            std::vector<int> expected = { 1, 2, 3, 4 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestNonConsecutiveDuplicates)
        {
            std::vector<int> input = { 1, 2, 3, 1, 2, 3, 4 };
            std::vector<int> expected = { 1, 2, 3, 4 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(TestZeroDuplicates)
        {
            std::vector<int> input = { 0, 0, 0, 1, 1, 0 };
            std::vector<int> expected = { 0, 1 };
            std::vector<int> result = removeDuplicates(input);
            Assert::IsTrue(result == expected);
        }
    };
}
