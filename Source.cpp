#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву ітераційним способом
void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        r[i] = Low + rand() % (High - Low + 1);
    }
}

// Виведення масиву ітераційним способом
void Print(const int* r, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << r[i];
    }
    cout << endl;
}

// Умова за варіантом 16: додатні та не кратні 4
bool Criterion(int x)
{
    return x > 0 && x % 4 != 0;
}

// Підрахунок кількості ітераційним способом
int Count(const int* r, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
        {
            count++;
        }
    }
    return count;
}

// Обчислення суми ітераційним способом
int Sum(const int* r, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
        {
            sum += r[i];
        }
    }
    return sum;
}

// Заміна елементів на 0 ітераційним способом
void ReplaceWithZero(int* r, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
        {
            r[i] = 0;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int r[n];

    int Low = -19;
    int High = 25;

    Create(r, n, Low, High);
    cout << "Initial array:" << endl;
    Print(r, n);

    cout << "Count = " << Count(r, n) << endl;
    cout << "Sum   = " << Sum(r, n) << endl;

    ReplaceWithZero(r, n);
    cout << "Modified array:" << endl;
    Print(r, n);

    return 0;
}