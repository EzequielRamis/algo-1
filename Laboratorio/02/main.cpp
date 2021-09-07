#include "main.h"
#include <iostream>
using namespace std;

int main()
{
    int ej;
    while (true)
    {
        char retry;
        cout << "Ingrese nº de ejercicio: ";
        cin >> ej;
        switch (ej)
        {
        case 1:
            ej1();
            break;
        case 2:
            ej2();
            break;
        case 3:
            ej3();
            break;
        case 4:
            ej4();
            break;
        case 5:
            ej5();
            break;
        case 6:
            ej6();
            break;
        case 7:
            ej7();
            break;
        case 8:
            ej8();
            break;
        case 9:
            ej9();
            break;
        default:
            cout << "No se encuentra el ejercicio" << endl;
            break;
        }
        cout << "¿Desea elegir otro ejercicio? (s/N): ";
        cin >> retry;
        if (tolower(retry) != 's')
            break;
    }
    return 0;
}

void ej1()
{
    float sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        int nota = -1;
        while (!estaNotaEnRango(nota))
        {
            cout << "Ingrese nota del alumno nº" << i << ": ";
            cin >> nota;
            if (!estaNotaEnRango(nota))
                cout << "La nota está fuera de rango" << endl;
        }
        sum += nota;
    }
    float promedio = sum / 10;
    cout << "Suma de notas totales: " << sum << endl;
    cout << "Promedio de notas: " << promedio << endl;
}

bool estaNotaEnRango(int n)
{
    return 0 <= n && n <= 10;
}

void ej2()
{
    float sum = 0;
    int i = 0;
    int nota = 0;
    while (nota != -1)
    {
        cout << "Ingrese nota del alumno nº" << i + 1 << ": ";
        cin >> nota;
        if (nota != -1)
        {
            if (estaNotaEnRango(nota))
            {
                sum += nota;
                i++;
            }
            else
                cout << "La nota está fuera de rango" << endl;
        }
    }
    float promedio = sum / i;
    cout << "Suma de notas totales: " << sum << endl;
    cout << "Promedio de notas: " << promedio << endl;
}

void ej3()
{
    float sum = 0;
    float i = 0;
    float aprobados = 0;
    int nota = 0;
    while (nota != -1)
    {
        cout << "Ingrese nota del alumno nº" << i + 1 << ": ";
        cin >> nota;
        if (nota != -1)
        {
            if (estaNotaEnRango(nota))
            {
                sum += nota;
                i++;
                if (nota > 6)
                    aprobados++;
            }
            else
                cout << "La nota está fuera de rango" << endl;
        }
    }
    if (i < 6)
        cout << "Error: Registro de notas insuficiente" << endl;
    else
    {
        float promedio = sum / i;
        if (aprobados / i > 2.0 / 3.0)
            cout << "Se puede incrementar el número de plazas en el curso" << endl;
        cout << "Suma de notas totales: " << sum << endl;
        cout << "Promedio de notas: " << promedio << endl;
    }
}

void ej4()
{
    int n = 0;
    while (n != -1)
    {
        cout << "Ingrese número binario: ";
        cin >> n;
        if (esBinario(n))
        {
            int dec = 0;
            int i = 1;
            while (n > 0)
            {
                dec += (n % 10) * i;
                i *= 2;
                n /= 10;
            }
            cout << "Número decimal: " << dec << endl;
        }
        else if (n != -1)
            cout << "Error: No es un número binario" << endl;
    }
}

bool esBinario(int n)
{
    if (n == 0 || n == 1)
        return true;
    int m = n % 10;
    if (m == 0 || m == 1)
        return esBinario(n / 10);
    return false;
}

void ej5()
{
    const float pi = 3.14159;
    float r = 0;
    while (r != -1)
    {
        cout << "Ingrese el radio de un círculo: ";
        cin >> r;
        if (r != -1)
        {
            float d = 2 * r;
            float c = pi * d;
            float a = pi * r * r;
            cout << "Diámetro: " << d << endl;
            cout << "Circunferencia: " << c << endl;
            cout << "Área: " << a << endl;
        }
    }
}

void ej6()
{
    int n = 0;
    while (n != -1)
    {
        cout << "Ingrese un número: ";
        cin >> n;
        if (n != -1)
        {
            int m = triplicarPorValor(n);
            triplicarPorReferencia(n);
            int dif = m - n;
            if (dif == 0)
                cout << "Las dos funciones son equivalentes" << endl;
            else
                cout << "Hay un error en las dos funciones" << endl;
        }
    }
}

int triplicarPorValor(int n)
{
    return 3 * n;
}

void triplicarPorReferencia(int &n)
{
    n *= 3;
}

void ej7()
{
    int n = 0;
    int m = 0;
    while (n != -1 && m != -1)
    {
        cout << "Ingrese un número n: ";
        cin >> n;
        cout << "Ingrese un número m: ";
        cin >> m;
        if (n != -1 && m != -1)
        {
            cout << "Antes:   n = " << n << ", m = " << m << endl;
            swap(n, m);
            cout << "Después: n = " << n << ", m = " << m << endl;
        }
    }
}

void swap(int &n, int &m)
{
    int c = n;
    n = m;
    m = c;
}

void ej8()
{
    int n = 0;
    while (n != -1)
    {
        cout << "Ingrese un número: ";
        cin >> n;
        if (n > 0)
        {
            int pasos = 0;
            collatz_(n, pasos);
            cout << "Pasos: " << pasos << endl;
        }
    }
}

void collatz(int n, int &cantPasos)
{
    if (n != 1)
    {
        cout << n << " ";
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
        cantPasos++;
        collatz(n, cantPasos);
    }
    else
    {
        cout << n << endl;
        cantPasos++;
    }
}

void collatz_(int n, int &cantPasos)
{
    while (n != 1)
    {
        cout << n << " ";
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
        cantPasos++;
    }
    cout << n << endl;
    cantPasos++;
}

void ej9()
{
    int dividendo = 0;
    int divisor = 1;
    while (dividendo != -1 && divisor != -1)
    {
        cout << "Ingrese un dividendo: ";
        cin >> dividendo;
        cout << "Ingrese un divisor: ";
        cin >> divisor;
        if (dividendo != -1 && divisor != -1)
        {
            if (dividendo >= 0 && divisor > 0)
            {
                int cociente = 0, resto;
                division(dividendo, divisor, cociente, resto);
                cout << dividendo << " = " << divisor << " * " << cociente << " + " << resto << endl;
            }
            else
                cout << "Valores ingresados inválidos" << endl;
        }
    }
}

void division(int dividendo, int divisor, int &cociente, int &resto)
{
    cociente = 0;
    while (cociente * divisor <= dividendo)
        cociente++;
    cociente--;
    resto = dividendo - cociente * divisor;
}

void division_(int dividendo, int divisor, int &cociente, int &resto)
{
    if (cociente * divisor <= dividendo)
    {
        cociente++;
        division_(dividendo, divisor, cociente, resto);
    }
    else
    {
        cociente--;
        resto = dividendo - cociente * divisor;
    }
}