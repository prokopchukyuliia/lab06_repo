// LR6.2_it.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 24

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив на екран в один рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// шукає і повертає індекс найбільшого елемента, починаючи з позиції start
int IndexOfMax(int* a, const int size, const int start)
{
    int imax = start; // вважаємо першим найбільшим стартовий елемент
    for (int j = start + 1; j < size; j++)
        if (a[j] > a[imax])
            imax = j;
    return imax;
}

// міняє місцями два цілих числа
void Swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

// впорядковує масив за спаданням (метод вибору)
void SortDescending(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)  // i - початок невпорядкованої частини
    {
        int imax = IndexOfMax(a, size, i);
        Swap(a[i], a[imax]); // найбільший ставимо на позицію i
    }
}

int main()
{
    const int n = 10; // кількість елементів
    const int Low = -10; // нижня межа значень
    const int High = 50; // верхня межа значень
    int a[n];

    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    Create(a, n, Low, High);

    cout << "Original array:" << endl;
    Print(a, n);

    SortDescending(a, n);

    cout << "Array sorted in descending order:" << endl;
    Print(a, n);

    return 0;
}
