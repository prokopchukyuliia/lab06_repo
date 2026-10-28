// LR6.4_it.cpp
// < Прокопчук Юлія >
// // Лабораторна робота № 6.4
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
    for (int i = 0; i < n; i++)
    {
        // випадкове дійсне число з діапазону [low; high]
        a[i] = low + (high - low) * rand() / RAND_MAX;
    }
}

void PrintArray(const double* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << setw(8) << a[i];
    }
    cout << endl;
}

double SumOddPositions(const double* a, int n)
{
    double sum = 0;
    // номери 1, 3, 5, ... відповідають індексам 0, 2, 4, ...
    for (int i = 0; i < n; i += 2)
    {
        sum += a[i];
    }
    return sum;
}

int FindFirstNegative(const double* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            return i;
    }
    return -1; // від'ємних немає
}

int FindLastNegative(const double* a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
            return i;
    }
    return -1; // від'ємних немає
}

double SumBetweenNegatives(const double* a, int n)
{
    int first = FindFirstNegative(a, n);
    int last = FindLastNegative(a, n);

    // менше двох від'ємних -- між ними нічого немає
    if (first == -1 || first == last)
        return 0;

    double sum = 0;
    for (int i = first + 1; i < last; i++)
    {
        sum += a[i];
    }
    return sum;
}

int RemoveSmallElements(double* a, int n)
{
    int kept = 0; // кількість елементів, що залишаються
    for (int i = 0; i < n; i++)
    {
        if (fabs(a[i]) > 1)
        {
            a[kept] = a[i]; // зсуваємо елемент вліво, порядок зберігається
            kept++;
        }
    }
    return kept;
}

void FillTailWithZeros(double* a, int n, int from)
{
    for (int i = from; i < n; i++)
    {
        a[i] = 0;
    }
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

    cout << "Sum of elements with odd numbers: "
        << SumOddPositions(a, n) << endl;
    cout << "Sum of elements between the first and the last negative: "
        << SumBetweenNegatives(a, n) << endl;

    int kept = RemoveSmallElements(a, n); // стискаємо масив
    FillTailWithZeros(a, n, kept); // хвіст -- нулі

    cout << "Modified array:" << endl;
    PrintArray(a, n);

    delete[] a; // звільняємо пам'ять
    return 0;
}