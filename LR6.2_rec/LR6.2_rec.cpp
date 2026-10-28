// LR6.2_rec.cpp
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
// i - індекс елемента, який заповнюємо зараз (початкове значення 0)
void Create(int* a, const int size, const int Low, const int High, const int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив на екран в один рядок
// i - індекс елемента, який виводимо зараз (початкове значення 0)
void Print(int* a, const int size, const int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// шукає і повертає індекс найбільшого елемента
// j - індекс елемента, який перевіряємо зараз
// imax - індекс найбільшого серед уже переглянутих елементів
int IndexOfMax(int* a, const int size, const int j, const int imax)
{
    if (j == size) // дійшли до кінця - результат готовий
        return imax;
    if (a[j] > a[imax])
        return IndexOfMax(a, size, j + 1, j);
    return IndexOfMax(a, size, j + 1, imax);
}

// міняє місцями два цілих числа
void Swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

// впорядковує масив за спаданням (метод вибору)
// i - початок невпорядкованої частини (початкове значення 0)
void SortDescending(int* a, const int size, const int i)
{
    if (i >= size - 1) // невпорядкована частина має 1 елемент - кінець
        return;
    int imax = IndexOfMax(a, size, i + 1, i);
    Swap(a[i], a[imax]); // найбільший ставимо на позицію i
    SortDescending(a, size, i + 1);
}

int main()
{
    const int n = 10; // кількість елементів
    const int Low = -10; // нижня межа значень
    const int High = 50; // верхня межа значень
    int a[n];

    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    Create(a, n, Low, High, 0);

    cout << "Original array:" << endl;
    Print(a, n, 0);

    SortDescending(a, n, 0);

    cout << "Array sorted in descending order:" << endl;
    Print(a, n, 0);

    return 0;
}
