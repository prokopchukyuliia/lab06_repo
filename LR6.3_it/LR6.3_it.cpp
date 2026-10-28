// LR6.3_it.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 24

#include <iostream>
#include <iomanip> 
#include <cstdlib> 
#include <ctime>    

using namespace std;

// Прототипи звичайних  функцій
void Create(int* arr, const int size, const int low, const int high);
void Print(const int* arr, const int size);
int FindMaxEven(const int* arr, const int size, bool& found);

// Прототипи шаблонів функцій для універсального опрацювання
template <typename T>
void CreateTemplate(T* arr, const int size, const T low, const T high);

template <typename T>
void PrintTemplate(const T* arr, const int size);

template <typename T>
T FindMaxEvenTemplate(const T* arr, const int size, bool& found);

int main() {
    // Ініціалізація генератора випадкових чисел від системного часу
    srand(static_cast<unsigned int>(time(nullptr)));

    const int size = 10;
    int arr[size];
    bool foundOrdinary = false;

    // Сформувати масив за допомогою звичайних функцій
    Create(arr, size, -20, 20);

    // Вивести масив на екран у вигляді рядка 
    cout << "Array: ";
    Print(arr, size);

    // Виконати вказані у завданні дії (пошук найбільшого парного)
    int maxEven = FindMaxEven(arr, size, foundOrdinary);

    // Вивести результат відповідно до умов
    if (foundOrdinary) 
    {
        cout << "Max even element: " << maxEven << endl;
    }
    else {
        cout << "No even elements found in the array." << endl;
    }

    return 0;
}

// Заповнення масиву випадковими числами в заданому діапазоні [low, high]
void Create(int* arr, const int size, const int low, const int high) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = low + rand() % (high - low + 1);
    }
}

// Форматне виведення елементів масиву в один рядок
void Print(const int* arr, const int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// Пошук найбільшого з парних елементів
int FindMaxEven(const int* arr, const int size, bool& found) 
{
    int maxEven = 0; // Початкове значення перепишеться першим знайденим парним числом
    found = false;   // Прапорець для відстеження наявності парних елементів

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] % 2 == 0) 
        { // Перевірка на парність
            if (!found) {
                maxEven = arr[i]; // Фіксуємо перше знайдене парне число як максимум
                found = true;
            }
            else if (arr[i] > maxEven) 
            {
                maxEven = arr[i]; // Оновлюємо максимум, якщо поточний елемент більший
            }
        }
    }
    return maxEven; // Повертаємо результат у місце виклику
}

// Реалізація шаблону функції створення масиву
template <typename T>
void CreateTemplate(T* arr, const int size, const T low, const T high) 
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = low + static_cast<T>(rand()) % (high - low + 1);
    }
}

// Реалізація шаблону функції виведення масиву
template <typename T>
void PrintTemplate(const T* arr, const int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// Реалізація шаблону функції пошуку найбільшого парного елемента
template <typename T>
T FindMaxEvenTemplate(const T* arr, const int size, bool& found) 
{
    T maxEven = T();
    found = false;

    for (int i = 0; i < size; i++) 
    {
        // Приведення типу до int для застосування операції залишку %
        if (static_cast<int>(arr[i]) % 2 == 0) 
        {
            if (!found) 
            {
                maxEven = arr[i];
                found = true;
            }
            else if (arr[i] > maxEven) 
            {
                maxEven = arr[i];
            }
        }
    }
    return maxEven;
}
