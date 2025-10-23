#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Timur\proga\ОС\Kol_Task3\Kol_Task3\Kol_Task3.cpp"
#include "vector"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTask3
{
	TEST_CLASS(UnitTestTask3)
	{
	public:
		
        TEST_METHOD(TestReverseNormalList)
        {
            Node* head = create({ 1, 2, 3, 4, 5 });
            std::vector<int> expected = { 5, 4, 3, 2, 1 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected);

        }

        TEST_METHOD(TestReverseSingleElement)
        {
            Node* head = create({ 42 });
            std::vector<int> expected = { 42 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected);
        }

        TEST_METHOD(TestReverseEmptyList)
        {
            Node* head = nullptr;

            Node* reversed = reverse(head);

            Assert::IsNull(reversed);
        }

        TEST_METHOD(TestReverseTwoElements)
        {
            Node* head = create({ 1, 2 });
            std::vector<int> expected = { 2, 1 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected);

        }

        TEST_METHOD(TestReverseThreeElements)
        {
            Node* head = create({ 1, 2, 3 });
            std::vector<int> expected = { 3, 2, 1 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected);
        }

        TEST_METHOD(TestReverseListWithDuplicates)
        {
            Node* head = create({ 1, 2, 2, 3, 3, 3 });
            std::vector<int> expected = { 3, 3, 3, 2, 2, 1 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected);
        }

        TEST_METHOD(TestReverseNegativeNumbers)
        {
            Node* head = create({ -5, -4, -3, -2, -1 });
            std::vector<int> expected = { -1, -2, -3, -4, -5 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected, L"Список с отрицательными числами неправильно развернут");

        }

        TEST_METHOD(TestReverseMixedNumbers)
        {
            Node* head = create({ -2, -1, 0, 1, 2 });
            std::vector<int> expected = { 2, 1, 0, -1, -2 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected, L"Список со смешанными числами неправильно развернут");
        }

        TEST_METHOD(TestReverseZeroElements)
        {
            Node* head = create({ 0, 0, 0 });
            std::vector<int> expected = { 0, 0, 0 };

            Node* reversed = reverse(head);
            std::vector<int> actual = listToVector(reversed);

            Assert::IsTrue(actual == expected, L"Список с нулями неправильно развернут");

        }
    };
}
