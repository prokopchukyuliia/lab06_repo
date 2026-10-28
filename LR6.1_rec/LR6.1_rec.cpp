// LR6.1_rec.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Формує масив випадковими числами з діапазону [Low; High]; i - індекс поточного елемента
void Create(int* t, const int size, const int Low, const int High, int i)
{
    t[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(t, size, Low, High, i + 1);
}

// Виводить масив в один рядок; кожен елемент займає 4 позиції
void Print(int* t, const int size, int i)
{
    cout << setw(4) << t[i];
    if (i < size - 1)
        Print(t, size, i + 1);
    else
        cout << endl;
}

// Повертає кількість елементів (від i-го до кінця), що задовольняють критерій
// всі, крім: додатних або кратних 5, тобто НЕ (додатний АБО кратний 5)
int Count(int* t, const int size, int i)
{
    if (i < size)
        return (!(t[i] > 0 || t[i] % 5 == 0) ? 1 : 0) + Count(t, size, i + 1);
    else
        return 0;
}

// Повертає суму елементів, що задовольняють критерій (від i-го до кінця)
int Sum(int* t, const int size, int i)
{
    if (i < size)
        return (!(t[i] > 0 || t[i] % 5 == 0) ? t[i] : 0) + Sum(t, size, i + 1);
    else
        return 0; 
}

// Замінює нулями елементи, що задовольняють критерій
void ReplaceWithZero(int* t, const int size, int i)
{
    if (!(t[i] > 0 || t[i] % 5 == 0))
        t[i] = 0;
    if (i < size - 1)
        ReplaceWithZero(t, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 22; // кількість елементів масиву
    int t[n]; 

    const int Low = -20; // нижня межа діапазону
    const int High = 37; // верхня межа діапазону

    Create(t, n, Low, High, 0); 
    cout << "Initial array:" << endl;
    Print(t, n, 0);

    // кількість і суму обчислюємо до заміни, інакше всі потрібні елементи вже будуть нулями
    int k = Count(t, n, 0);
    int s = Sum(t, n, 0);
    cout << "Count = " << k << endl;
    cout << "Sum   = " << s << endl;

    ReplaceWithZero(t, n, 0);
    cout << "Modified array:" << endl;
    Print(t, n, 0);

    return 0;
}