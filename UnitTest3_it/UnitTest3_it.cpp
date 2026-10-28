#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.3_it/LR6.3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest_Iterative)
    {
    public:
        // Перевірка звичайної ітераційної функції на масиві з парними числами
        TEST_METHOD(TestFindMaxEvenOrdinary)
        {
            const int size = 6;
            int a[size] = { 3, -4, 8, 5, 2, 7 };
            bool found = false;
            int expected = 8; // Парні: -4, 8, 2. Максимум: 8
            int actual = FindMaxEven(a, size, found);

            Assert::IsTrue(found);
            Assert::AreEqual(expected, actual);
        }

        // Перевірка випадку, коли парних чисел немає взагалі
        TEST_METHOD(TestFindMaxEvenNoEvens)
        {
            const int size = 4;
            int a[size] = { 1, 3, 5, 7 };
            bool found = true;
            FindMaxEven(a, size, found);

            Assert::IsFalse(found); // Прапорець має скинутися в false
        }

        // Перевірка шаблону функції для типу int
        TEST_METHOD(TestFindMaxEvenTemplateInt)
        {
            const int size = 5;
            int a[size] = { -12, -6, -2, -4, -11 };
            bool found = false;
            int expected = -2; // Максимальне з від'ємних парних
            int actual = FindMaxEvenTemplate<int>(a, size, found);

            Assert::IsTrue(found);
            Assert::AreEqual(expected, actual);
        }

        // Перевірка шаблону функції для типу long
        TEST_METHOD(TestFindMaxEvenTemplateLong)
        {
            const int size = 4;
            long a[size] = { 14L, 55L, 26L, 11L };
            bool found = false;
            long expected = 26L;
            long actual = FindMaxEvenTemplate<long>(a, size, found);

            Assert::IsTrue(found);
            Assert::AreEqual(expected, actual);
        }
    };
}
