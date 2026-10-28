#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.3_rec/LR6.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest_Recursive)
    {
    public:
        // Перевірка звичайної рекурсивної функції на пошук максимуму
        TEST_METHOD(TestFindMaxEvenOrdinary)
        {
            const int size = 6;
            int a[size] = { 11, 22, 33, 44, 5, 6 };
            bool found = false;
            int maxVal = 0;

            FindMaxEven(a, size, 0, found, maxVal);

            Assert::IsTrue(found);
            Assert::AreEqual(44, maxVal);
        }

        // Перевірка рекурсії у випадку відсутності парних елементів
        TEST_METHOD(TestFindMaxEvenNoEvens)
        {
            const int size = 4;
            int a[size] = { 1, 7, 9, 13 };
            bool found = false;
            int maxVal = 0;

            FindMaxEven(a, size, 0, found, maxVal);

            Assert::IsFalse(found);
        }

        // Перевірка рекурсивного шаблону для типу int (від'ємні значення)
        TEST_METHOD(TestFindMaxEvenTemplateInt)
        {
            const int size = 4;
            int a[size] = { -2, -10, -4, -8 };
            bool found = false;
            int maxVal = 0;

            FindMaxEvenTemplate<int>(a, size, 0, found, maxVal);

            Assert::IsTrue(found);
            Assert::AreEqual(-2, maxVal);
        }
    };
}
