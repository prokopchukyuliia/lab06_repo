#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.2_it/LR6.2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// перевіряє, що масив впорядковано за спаданням
static bool IsDescending(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
        if (a[i] < a[i + 1])
            return false;
    return true;
}

// перевіряє, що два масиви містять однакові елементи (з урахуванням повторів)
static bool SameElements(int* a, int* b, const int size)
{
    int* x = new int[size];
    int* y = new int[size];
    for (int i = 0; i < size; i++) { x[i] = a[i]; y[i] = b[i]; }
    // простий підрахунок: для кожного елемента з x шукаємо пару в y
    bool ok = true;
    for (int i = 0; i < size && ok; i++)
    {
        bool found = false;
        for (int j = 0; j < size; j++)
            if (x[i] == y[j]) { y[j] = INT_MIN; found = true; break; }
        ok = found;
    }
    delete[] x;
    delete[] y;
    return ok;
}

namespace LR62IterTests
{
    TEST_CLASS(CreateTests)
    {
    public:
        TEST_METHOD(ValuesInRange)
        {
            const int n = 1000;
            int a[n];
            Create(a, n, -10, 50);
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= -10);
                Assert::IsTrue(a[i] <= 50);
            }
        }

        TEST_METHOD(SingleValueRange)
        {
            // коли Low == High, усі елементи мають бути однаковими
            const int n = 20;
            int a[n];
            Create(a, n, 7, 7);
            for (int i = 0; i < n; i++)
                Assert::AreEqual(7, a[i]);
        }

        TEST_METHOD(NegativeRange)
        {
            const int n = 200;
            int a[n];
            Create(a, n, -30, -20);
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= -30);
                Assert::IsTrue(a[i] <= -20);
            }
        }
    };

    TEST_CLASS(IndexOfMaxTests)
    {
    public:
        TEST_METHOD(MaxInMiddle)
        {
            int a[] = { 3, 8, 1, 5 };
            Assert::AreEqual(1, IndexOfMax(a, 4, 0));
        }

        TEST_METHOD(MaxAtStart)
        {
            int a[] = { 9, 2, 4, 1 };
            Assert::AreEqual(0, IndexOfMax(a, 4, 0));
        }

        TEST_METHOD(MaxAtEnd)
        {
            int a[] = { 1, 2, 3, 10 };
            Assert::AreEqual(3, IndexOfMax(a, 4, 0));
        }

        TEST_METHOD(SearchFromStartIgnoresEarlierElements)
        {
            // найбільший (100) стоїть до start - він не повинен враховуватись
            int a[] = { 100, 3, 7, 5 };
            Assert::AreEqual(2, IndexOfMax(a, 4, 1));
        }

        TEST_METHOD(StartIsLastIndex)
        {
            int a[] = { 5, 6, 7 };
            Assert::AreEqual(2, IndexOfMax(a, 3, 2));
        }

        TEST_METHOD(AllNegative)
        {
            int a[] = { -5, -2, -9, -3 };
            Assert::AreEqual(1, IndexOfMax(a, 4, 0));
        }

        TEST_METHOD(DuplicateMaxReturnsFirst)
        {
            int a[] = { 4, 9, 2, 9 };
            Assert::AreEqual(1, IndexOfMax(a, 4, 0));
        }
    };

    TEST_CLASS(SwapTests)
    {
    public:
        TEST_METHOD(SwapDifferent)
        {
            int x = 3, y = 8;
            Swap(x, y);
            Assert::AreEqual(8, x);
            Assert::AreEqual(3, y);
        }

        TEST_METHOD(SwapEqual)
        {
            int x = 5, y = 5;
            Swap(x, y);
            Assert::AreEqual(5, x);
            Assert::AreEqual(5, y);
        }

        TEST_METHOD(SwapNegative)
        {
            int x = -4, y = 6;
            Swap(x, y);
            Assert::AreEqual(6, x);
            Assert::AreEqual(-4, y);
        }

        TEST_METHOD(SwapArrayElements)
        {
            int a[] = { 1, 2, 3 };
            Swap(a[0], a[2]);
            Assert::AreEqual(3, a[0]);
            Assert::AreEqual(2, a[1]);
            Assert::AreEqual(1, a[2]);
        }
    };

    TEST_CLASS(SortDescendingTests)
    {
    public:
        TEST_METHOD(ArbitraryArray)
        {
            int a[] = { 3, -1, 8, 0, 5 };
            int expected[] = { 8, 5, 3, 0, -1 };
            SortDescending(a, 5);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(AlreadyDescending)
        {
            int a[] = { 9, 7, 5, 3, 1 };
            int expected[] = { 9, 7, 5, 3, 1 };
            SortDescending(a, 5);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(AscendingInput)
        {
            int a[] = { 1, 2, 3, 4, 5 };
            int expected[] = { 5, 4, 3, 2, 1 };
            SortDescending(a, 5);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(AllEqual)
        {
            int a[] = { 4, 4, 4, 4 };
            SortDescending(a, 4);
            for (int i = 0; i < 4; i++)
                Assert::AreEqual(4, a[i]);
        }

        TEST_METHOD(WithDuplicates)
        {
            int a[] = { 2, 7, 2, 7, 5 };
            int expected[] = { 7, 7, 5, 2, 2 };
            SortDescending(a, 5);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(AllNegative)
        {
            int a[] = { -3, -10, -1, -7 };
            int expected[] = { -1, -3, -7, -10 };
            SortDescending(a, 4);
            for (int i = 0; i < 4; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(SingleElement)
        {
            int a[] = { 42 };
            SortDescending(a, 1);
            Assert::AreEqual(42, a[0]);
        }

        TEST_METHOD(TwoElements)
        {
            int a[] = { 1, 2 };
            SortDescending(a, 2);
            Assert::AreEqual(2, a[0]);
            Assert::AreEqual(1, a[1]);
        }

        TEST_METHOD(RandomArraysAreSortedAndKeepElements)
        {
            // комплексна перевірка: Create + SortDescending на випадкових даних
            const int n = 10;
            for (int test = 0; test < 100; test++)
            {
                int a[n], copy[n];
                Create(a, n, -10, 50);
                for (int i = 0; i < n; i++) copy[i] = a[i];

                SortDescending(a, n);

                Assert::IsTrue(IsDescending(a, n));
                Assert::IsTrue(SameElements(a, copy, n));
            }
        }
    };
}