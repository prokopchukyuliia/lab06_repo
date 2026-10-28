#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include "../LR6.1_rec/LR6.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
    TEST_CLASS(UnitTestRec)
    {
    public:

        // Критерій: підходять елементи, які НЕ (додатні АБО кратні 5).
        // Перевіряємо його через Count на масивах з одного елемента
        TEST_METHOD(Count_Criterion_SingleElement)
        {
            int a[1];
            a[0] = -1;  Assert::AreEqual(1, Count(a, 1, 0)); // від'ємне, не кратне 5
            a[0] = -19; Assert::AreEqual(1, Count(a, 1, 0));
            a[0] = 1;   Assert::AreEqual(0, Count(a, 1, 0)); // додатне
            a[0] = 37;  Assert::AreEqual(0, Count(a, 1, 0));
            a[0] = 0;   Assert::AreEqual(0, Count(a, 1, 0)); // 0 кратний 5
            a[0] = -5;  Assert::AreEqual(0, Count(a, 1, 0)); // кратне 5
            a[0] = -20; Assert::AreEqual(0, Count(a, 1, 0));
        }

        // Масив: підходять -1, -2, -7, -3
        TEST_METHOD(Count_MixedArray)
        {
            int t[10] = { -1, 5, -2, 0, 8, -5, -7, 10, -10, -3 };
            Assert::AreEqual(4, Count(t, 10, 0));
        }

        TEST_METHOD(Count_NoElementsMatch)
        {
            int t[5] = { 1, 2, 3, 0, -5 };
            Assert::AreEqual(0, Count(t, 5, 0));
        }

        TEST_METHOD(Count_AllElementsMatch)
        {
            int t[4] = { -1, -2, -3, -4 };
            Assert::AreEqual(4, Count(t, 4, 0));
        }

        TEST_METHOD(Sum_MixedArray)
        {
            int t[10] = { -1, 5, -2, 0, 8, -5, -7, 10, -10, -3 };
            Assert::AreEqual(-13, Sum(t, 10, 0));      // -1 - 2 - 7 - 3
        }

        TEST_METHOD(Sum_NoElementsMatch)
        {
            int t[5] = { 1, 2, 3, 0, -5 };
            Assert::AreEqual(0, Sum(t, 5, 0));
        }

        TEST_METHOD(Sum_AllElementsMatch)
        {
            int t[4] = { -1, -2, -3, -4 };
            Assert::AreEqual(-10, Sum(t, 4, 0));
        }

        TEST_METHOD(ReplaceWithZero_MixedArray)
        {
            int t[10] = { -1, 5, -2, 0, 8, -5, -7, 10, -10, -3 };
            int expected[10] = { 0, 5, 0, 0, 8, -5, 0, 10, -10, 0 };
            ReplaceWithZero(t, 10, 0);
            for (int i = 0; i < 10; i++)
                Assert::AreEqual(expected[i], t[i]);
        }

        // Після заміни жоден елемент не повинен задовольняти критерій
        TEST_METHOD(ReplaceWithZero_ThenCountIsZero)
        {
            int t[10] = { -1, 5, -2, 0, 8, -5, -7, 10, -10, -3 };
            ReplaceWithZero(t, 10, 0);
            Assert::AreEqual(0, Count(t, 10, 0));
        }

        // Усі згенеровані елементи мають належати діапазону [-20; 37]
        TEST_METHOD(Create_ElementsInRange)
        {
            const int n = 22;
            int t[n];
            srand(12345);
            for (int k = 0; k < 100; k++)
            {
                Create(t, n, -20, 37, 0);
                for (int i = 0; i < n; i++)
                {
                    Assert::IsTrue(t[i] >= -20);
                    Assert::IsTrue(t[i] <= 37);
                }
            }
        }
    };
}
