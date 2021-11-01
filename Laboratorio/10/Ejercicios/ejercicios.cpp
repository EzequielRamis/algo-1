#include "ejercicios.h"

using namespace std;

void mostrar_vector(vector<int> &v)
{
    string vector = "[";
    if (v.size() > 0)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            vector = vector + to_string(v[i]) + ", ";
        }
    }

    if (v.size() != 0)
    {
        vector = vector + to_string(v[v.size() - 1]) + "]";
    }
    else
    {
        vector = vector + "]";
    }

    cout << vector << endl;
}

vector<int> construir_vector(int n, string disposicion)
{

    vector<int> res;
    srand(time(NULL));
    int numero;

    if (disposicion == "asc")
    {
        for (int i = 0; i < n; i++)
        {
            res.push_back(i);
        }
    }
    else if (disposicion == "desc")
    {
        for (int i = n - 1; i >= 0; i--)
        {
            res.push_back(i);
        }
    }
    else if (disposicion == "azar")
    {
        for (int i = 0; i < n; i++)
        {
            numero = rand() % 100;
            res.push_back(numero);
        }
    }
    else if (disposicion == "iguales")
    {
        numero = rand() % 100;
        for (int i = 0; i < n; i++)
        {
            res.push_back(numero);
        }
    }
    else
    {
        cout << "Dispocisión no válida" << endl;
    }

    return res;
}

int busquedaBinaria(vector<int> v, int x)
{
    int i = 0, j = v.size() - 1, res = -1;
    while (i + 1 < j)
    {
        int k = (i + j) / 2;
        if (x < v[k])
            j = k;
        else
            i = k;
    }
    if (v[i] == x)
        res = i;
    return res;
}

int busquedaJumpSearch(vector<int> v, int x)
{
    int res = -1, len = v.size(), i = 0;
    int step = floor(sqrt(len));
    while (v[min(i, len - 1)] < x)
        i += step;
    int j = min(i, len - 1);
    int k = max(0, i - step);
    while (k < j)
    {
        if (v[j] == x)
            res = j;
        j--;
    }
    return res;
}