// Лабораторна робота № 6.2, варіант 12 (рекурсивний спосіб)
// Завдання: написати функцію, яка шукає індекси найбільшого
// та найменшого елементів одновимірного масиву a із n елементів цілого типу.

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// формування масиву випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виведення елементів масиву в рядок
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// пошук індексу найбільшого елемента (першого входження)
// i - індекс поточного елемента, imax - індекс найбільшого серед переглянутих
int IndexOfMax(int* a, const int size, int i, int imax)
{
    if (a[i] > a[imax])
        imax = i;
    if (i < size - 1)
        return IndexOfMax(a, size, i + 1, imax);
    else
        return imax;
}

// пошук індексу найменшого елемента (першого входження)
int IndexOfMin(int* a, const int size, int i, int imin)
{
    if (a[i] < a[imin])
        imin = i;
    if (i < size - 1)
        return IndexOfMin(a, size, i + 1, imin);
    else
        return imin;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 10;
    int a[n];
    const int Low = -10;
    const int High = 10;

    Create(a, n, Low, High, 0);
    cout << "Array:" << endl;
    Print(a, n, 0);

    int imax = IndexOfMax(a, n, 0, 0);
    int imin = IndexOfMin(a, n, 0, 0);

    cout << "Index of max element: " << imax
        << " (value " << a[imax] << ")" << endl;
    cout << "Index of min element:  " << imin
        << " (value " << a[imin] << ")" << endl;

    return 0;
}