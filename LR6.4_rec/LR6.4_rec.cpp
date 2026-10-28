// LR6.4_rec.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 24

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillArray(double* a, int n, double low, double high)
{
    if (n == 0) // база рекурсії: заповнювати нічого
        return;
    FillArray(a, n - 1, low, high); // спочатку перші n-1 елементів
    a[n - 1] = low + (high - low) * rand() / RAND_MAX; // потім останній
}

void PrintArray(const double* a, int n)
{
    if (n == 0) // база рекурсії
        return;
    PrintArray(a, n - 1); // спочатку перші n-1 елементів
    cout << fixed << setprecision(2) << setw(8) << a[n - 1];
}

void PrintNewLine()
{
    cout << endl;
}

double SumOddPositions(const double* a, int n)
{
    if (n <= 0) // база рекурсії
        return 0;
    // елемент a[n-1] має номер n; додаємо його, якщо n непарне
    if (n % 2 == 1)
        return a[n - 1] + SumOddPositions(a, n - 1);
    return SumOddPositions(a, n - 1);
}

int FindFirstNegative(const double* a, int n, int i)
{
    if (i >= n) // дійшли до кінця -- від'ємних немає
        return -1;
    if (a[i] < 0)
        return i;
    return FindFirstNegative(a, n, i + 1); // шукаємо далі
}

int FindLastNegative(const double* a, int n)
{
    if (n == 0) // від'ємних немає
        return -1;
    if (a[n - 1] < 0)
        return n - 1;
    return FindLastNegative(a, n - 1); // шукаємо в меншій частині
}

double SumRange(const double* a, int left, int right)
{
    if (left >= right) // порожній проміжок
        return 0;
    return a[left] + SumRange(a, left + 1, right);
}

double SumBetweenNegatives(const double* a, int n)
{
    int first = FindFirstNegative(a, n, 0);
    int last = FindLastNegative(a, n);

    // менше двох від'ємних -- між ними нічого немає
    if (first == -1 || first == last)
        return 0;
    return SumRange(a, first + 1, last);
}

int RemoveSmallElements(double* a, int n)
{
    if (n == 0) // база рекурсії
        return 0;
    int kept = RemoveSmallElements(a, n - 1); // обробляємо перші n-1 елементів
    if (fabs(a[n - 1]) > 1)
    {
        a[kept] = a[n - 1]; // зсуваємо елемент вліво, порядок зберігається
        return kept + 1;
    }
    return kept;
}

void FillTailWithZeros(double* a, int n, int from)
{
    if (n <= from) // хвіст закінчився
        return;
    a[n - 1] = 0;
    FillTailWithZeros(a, n - 1, from);
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // ініціалізація генератора

    int n;
    cout << "Enter n: ";
    cin >> n;
    while (n <= 0) // розмір має бути додатним
    {
        cout << "n must be positive. Enter n again: ";
        cin >> n;
    }

    double* a = new double[n]; // динамічний масив з n дійсних чисел
    FillArray(a, n, -5.0, 5.0);

    cout << "Original array:" << endl;
    PrintArray(a, n);
    PrintNewLine();

    cout << "Sum of elements with odd numbers: "
        << SumOddPositions(a, n) << endl;
    cout << "Sum of elements between the first and the last negative: "
        << SumBetweenNegatives(a, n) << endl;

    int kept = RemoveSmallElements(a, n); // стискаємо масив
    FillTailWithZeros(a, n, kept); // хвіст -- нулі

    cout << "Modified array:" << endl;
    PrintArray(a, n);
    PrintNewLine();

    delete[] a; // звільняємо пам'ять
    return 0;
}
