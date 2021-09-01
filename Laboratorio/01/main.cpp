#include "main.h"
#include <iostream>
using namespace std;

int main()
{
    int q = false;
    while (!q)
    {
        int n;
        cout << "Ingrese número: ";
        cin >> n;
        if (n < 0)
            q = true;
        else
            cout << sumaDivisores(n) << endl;
    }
    return 0;
}

int f(int x, int y)
{
    return x > y ? x + y : x * y;
}

// Ejericio 4
bool esPrimo(int n)
{
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

// Ejericio 5
int fibonacci(int n)
{
    return n == 0 ? 0 : n + fibonacci(n - 1);
}

int fibonacci_(int n)
{
    int fib = 0;
    for (int i = 1; i <= n; i++)
        fib += i;
    return fib;
}

// Ejericio 6
int sumaImpares(int n)
{
    if (n == 1)
        return 0;
    int m = n - 1;
    return m % 2 == 1 ? m + sumaImpares(m) : sumaImpares(m);
}

int sumaImpares_(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i += 2)
        sum += i;
    return sum;
}

// Ejericio 7
int sumaDivisores(int n)
{
    return divisoresHasta(n, n);
}

int divisoresHasta(int d, int n)
{
    if (d == 1)
        return 1;
    return n % d == 0 ? d + divisoresHasta(d - 1, n) : divisoresHasta(d - 1, n);
}

int sumaDivisores_(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            sum += i;
    return sum;
}