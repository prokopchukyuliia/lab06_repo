// LR6.1_it.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Формує масив випадковими числами з діапазону [Low; High]
void Create(int* t, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        t[i] = Low + rand() % (High - Low + 1);
}

// Виводить масив в один рядок
void Print(int* t, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << t[i];
    cout << endl;
}

// Повертає кількість елементів, що задовольняють критерій
// всі, крім: додатних або кратних 5, тобто НЕ (додатний АБО кратний 5)
int Count(int* t, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (!(t[i] > 0 || t[i] % 5 == 0))
            k++;
    return k;
}

// Повертає суму елементів, що задовольняють критерій
int Sum(int* t, const int size)
{
    int s = 0; 
    for (int i = 0; i < size; i++)
        if (!(t[i] > 0 || t[i] % 5 == 0))
            s += t[i];
    return s;
}

// Замінює нулями елементи, що задовольняють критерій
void ReplaceWithZero(int* t, const int size)
{
    for (int i = 0; i < size; i++)
        if (!(t[i] > 0 || t[i] % 5 == 0))
            t[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 22; // кількість елементів масиву
    int t[n]; // одновимірний масив t

    const int Low = -20; // нижня межа діапазону
    const int High = 37; // верхня межа діапазону

    Create(t, n, Low, High);
    cout << "Initial array:" << endl;
    Print(t, n);

    // кількість і суму обчислюємо ДО заміни, інакше всі потрібні елементи вже будуть нулями
    int k = Count(t, n);
    int s = Sum(t, n);
    cout << "Count = " << k << endl;
    cout << "Sum   = " << s << endl;

    ReplaceWithZero(t, n);
    cout << "Modified array:" << endl;
    Print(t, n);

    return 0;
}