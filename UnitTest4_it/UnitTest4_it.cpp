#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.4_it/LR6.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IterativeTests
{
    TEST_CLASS(ArrayTests)
    {
    public:
        // сума елементів з непарними номерами
        TEST_METHOD(SumOddPositions_FiveElements)
        {
            double a[] = { 1, 2, 3, 4, 5 };
            Assert::AreEqual(9.0, SumOddPositions(a, 5), 1e-9); // 1+3+5
        }
        TEST_METHOD(SumOddPositions_SixElements)
        {
            double a[] = { 1, 2, 3, 4, 5, 6 };
            Assert::AreEqual(9.0, SumOddPositions(a, 6), 1e-9); // 1+3+5
        }
        TEST_METHOD(SumOddPositions_OneElement)
        {
            double a[] = { 7.5 };
            Assert::AreEqual(7.5, SumOddPositions(a, 1), 1e-9);
        }
        TEST_METHOD(SumOddPositions_NegativeValues)
        {
            double a[] = { -1.5, 10, -2.5, 10 };
            Assert::AreEqual(-4.0, SumOddPositions(a, 4), 1e-9);
        }

        // пошук від'ємних
        TEST_METHOD(FindFirstNegative_Found)
        {
            double a[] = { 1, -2, 3, -4 };
            Assert::AreEqual(1, FindFirstNegative(a, 4));
        }
        TEST_METHOD(FindFirstNegative_AtTheStart)
        {
            double a[] = { -1, 2, 3 };
            Assert::AreEqual(0, FindFirstNegative(a, 3));
        }
        TEST_METHOD(FindLastNegative_Found)
        {
            double a[] = { 1, -2, 3, -4, 5 };
            Assert::AreEqual(3, FindLastNegative(a, 5));
        }
        TEST_METHOD(FindLastNegative_AtTheEnd)
        {
            double a[] = { 1, 2, -3 };
            Assert::AreEqual(2, FindLastNegative(a, 3));
        }
        TEST_METHOD(FindNegative_NotFound)
        {
            double a[] = { 1, 2, 3 };
            Assert::AreEqual(-1, FindFirstNegative(a, 3));
            Assert::AreEqual(-1, FindLastNegative(a, 3));
        }
        TEST_METHOD(FindNegative_ZeroIsNotNegative)
        {
            double a[] = { 0, 0, 0 };
            Assert::AreEqual(-1, FindFirstNegative(a, 3));
            Assert::AreEqual(-1, FindLastNegative(a, 3));
        }

        // сума між першим і останнім від'ємними 
        TEST_METHOD(SumBetweenNegatives_Normal)
        {
            double a[] = { 1, -2, 3, 4, -5, 6 };
            Assert::AreEqual(7.0, SumBetweenNegatives(a, 6), 1e-9); // 3+4
        }
        TEST_METHOD(SumBetweenNegatives_NegativesAtEdges)
        {
            double a[] = { -1, 2, 3, 4, -5 };
            Assert::AreEqual(9.0, SumBetweenNegatives(a, 5), 1e-9); // 2+3+4
        }
        TEST_METHOD(SumBetweenNegatives_MoreThanTwoNegatives)
        {
            double a[] = { 5, -1, 2, -3, 4, -5, 6 };
            Assert::AreEqual(3.0, SumBetweenNegatives(a, 7), 1e-9); // 2+(-3)+4
        }
        TEST_METHOD(SumBetweenNegatives_NoNegatives)
        {
            double a[] = { 1, 2, 3 };
            Assert::AreEqual(0.0, SumBetweenNegatives(a, 3), 1e-9);
        }
        TEST_METHOD(SumBetweenNegatives_OneNegative)
        {
            double a[] = { 1, -2, 3 };
            Assert::AreEqual(0.0, SumBetweenNegatives(a, 3), 1e-9);
        }
        TEST_METHOD(SumBetweenNegatives_AdjacentNegatives)
        {
            double a[] = { 1, -2, -3, 4 };
            Assert::AreEqual(0.0, SumBetweenNegatives(a, 4), 1e-9);
        }

        // стиснення масиву
        TEST_METHOD(RemoveSmallElements_ReturnsCount)
        {
            double a[] = { 0.5, 2, -1, 3, -0.3, 1, -4 };
            Assert::AreEqual(3, RemoveSmallElements(a, 7));
        }
        TEST_METHOD(RemoveSmallElements_KeepsOrder)
        {
            double a[] = { 0.5, 2, -1, 3, -0.3, 1, -4 };
            RemoveSmallElements(a, 7);
            Assert::AreEqual(2.0, a[0], 1e-9);
            Assert::AreEqual(3.0, a[1], 1e-9);
            Assert::AreEqual(-4.0, a[2], 1e-9);
        }
        TEST_METHOD(RemoveSmallElements_BoundaryOne)
        {
            // |1| і |-1| не перевищують одиницю -- видаляються
            double a[] = { 1, -1, 1.01, -1.01 };
            Assert::AreEqual(2, RemoveSmallElements(a, 4));
            Assert::AreEqual(1.01, a[0], 1e-9);
            Assert::AreEqual(-1.01, a[1], 1e-9);
        }
        TEST_METHOD(RemoveSmallElements_AllSmall)
        {
            double a[] = { 0.1, -1, 1 };
            Assert::AreEqual(0, RemoveSmallElements(a, 3));
        }
        TEST_METHOD(RemoveSmallElements_NoneSmall)
        {
            double a[] = { 2, -3, 4 };
            Assert::AreEqual(3, RemoveSmallElements(a, 3));
            Assert::AreEqual(2.0, a[0], 1e-9);
            Assert::AreEqual(-3.0, a[1], 1e-9);
            Assert::AreEqual(4.0, a[2], 1e-9);
        }
        TEST_METHOD(FillTailWithZeros_Works)
        {
            double a[] = { 2, 3, -4, 9, 9, 9, 9 };
            FillTailWithZeros(a, 7, 3);
            Assert::AreEqual(2.0, a[0], 1e-9);
            Assert::AreEqual(3.0, a[1], 1e-9);
            Assert::AreEqual(-4.0, a[2], 1e-9);
            for (int i = 3; i < 7; i++)
                Assert::AreEqual(0.0, a[i], 1e-9);
        }
        TEST_METHOD(FillTailWithZeros_NothingToFill)
        {
            double a[] = { 2, 3, 4 };
            FillTailWithZeros(a, 3, 3);
            Assert::AreEqual(4.0, a[2], 1e-9);
        }
        TEST_METHOD(Compress_FullScenario)
        {
            double a[] = { 0.5, 2, -1, 3, -0.3, 1, -4 };
            int kept = RemoveSmallElements(a, 7);
            FillTailWithZeros(a, 7, kept);
            double expected[] = { 2, 3, -4, 0, 0, 0, 0 };
            for (int i = 0; i < 7; i++)
                Assert::AreEqual(expected[i], a[i], 1e-9);
        }
        TEST_METHOD(Compress_AllSmallGivesAllZeros)
        {
            double a[] = { 0.1, -0.5, 1 };
            int kept = RemoveSmallElements(a, 3);
            FillTailWithZeros(a, 3, kept);
            for (int i = 0; i < 3; i++)
                Assert::AreEqual(0.0, a[i], 1e-9);
        }

        //створення і заповнення
        TEST_METHOD(FillArray_InRange)
        {
            double* a = new double[100];
            FillArray(a, 100, -5.0, 5.0);
            for (int i = 0; i < 100; i++)
                Assert::IsTrue(a[i] >= -5.0 && a[i] <= 5.0);
            delete[] a;
        }

    };
}
