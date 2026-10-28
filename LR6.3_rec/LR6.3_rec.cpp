// LR6.3_rec.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 24

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи звичайних рекурсивних функцій (крок керується індексом i)
void Create(int* arr, const int size, const int low, const int high, int i);
void Print(const int* arr, const int size, int i);
int FindMaxEven(const int* arr, const int size, int i, bool& found, int& currentMax);

// Прототипи шаблонів рекурсивних функцій
template <typename T>
void CreateTemplate(T* arr, const int size, const T low, const T high, int i);

template <typename T>
void PrintTemplate(const T* arr, const int size, int i);

template <typename T>
T FindMaxEvenTemplate(const T* arr, const int size, int i, bool& found, T& currentMax);

int main() 
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int size = 10;
    int arr[size];
    bool foundOrdinary = false;
    int maxEven = 0; // Змінна-посилання для накопичення максимуму

    // Рекурсивне створення масиву (починаємо з індексу 0)
    Create(arr, size, -20, 20, 0);

    // Рекурсивне виведення масиву у вигляді рядка
    cout << "Array: ";
    Print(arr, size, 0);

    // Рекурсивний пошук найбільшого парного елемента
    FindMaxEven(arr, size, 0, foundOrdinary, maxEven);

    if (foundOrdinary) 
    {
        cout << "Max even element: " << maxEven << endl;
    }
    else 
    {
        cout << "No even elements found in the array." << endl;
    }

    return 0;
}

// Рекурсивне створення масиву (заміна циклу for)
void Create(int* arr, const int size, const int low, const int high, int i) 
{
    if (i >= size) 
        return; // Умова завершення рекурсії
    arr[i] = low + rand() % (high - low + 1);
    Create(arr, size, low, high, i + 1); // Рекурсивний крок
}

// Рекурсивне виведення масиву
void Print(const int* arr, const int size, int i) 
{
    if (i >= size) 
    {
        cout << endl; // Умова завершення рекурсії
        return;
    }
    cout << setw(4) << arr[i];
    Print(arr, size, i + 1); // Рекурсивний крок
}

// Рекурсивний пошук найбільшого парного елемента
int FindMaxEven(const int* arr, const int size, int i, bool& found, int& currentMax)
{
    if (i >= size) 
        return currentMax; // повернення проміжного результату

    if (arr[i] % 2 == 0) 
    { // Опрацювання елемента на поточному рівні рекурсії
        if (!found) 
        {
            currentMax = arr[i]; // Фіксація першого парного числа
            found = true;
        }
        else if (arr[i] > currentMax) 
        {
            currentMax = arr[i]; // Перевизначення максимуму
        }
    }
    // Рекурсивний виклик для наступного індексу
    return FindMaxEven(arr, size, i + 1, found, currentMax);
}

// Шаблон створення масиву
template <typename T>
void CreateTemplate(T* arr, const int size, const T low, const T high, int i) 
{
    if (i >= size)
        return;
    arr[i] = low + static_cast<T>(rand()) % (high - low + 1);
    CreateTemplate(arr, size, low, high, i + 1);
}

// Шаблон виведення масиву
template <typename T>
void PrintTemplate(const T* arr, const int size, int i) 
{
    if (i >= size) 
    {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    PrintTemplate(arr, size, i + 1);
}

// Шаблон пошуку максимуму
template <typename T>
T FindMaxEvenTemplate(const T* arr, const int size, int i, bool& found, T& currentMax) 
{
    if (i >= size) 
        return currentMax;

    if (static_cast<int>(arr[i]) % 2 == 0) 
    {
        if (!found) {
            currentMax = arr[i];
            found = true;
        }
        else if (arr[i] > currentMax) 
        {
            currentMax = arr[i];
        }
    }
    return FindMaxEvenTemplate(arr, size, i + 1, found, currentMax);
}
