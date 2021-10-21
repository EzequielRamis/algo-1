#include <iostream>
#include <vector>

using namespace std;

bool esTriangularInferior(vector<vector<int>> m)
{
    int i = 0;
    bool res = true;
    while (i < m.size())
    {
        int j = 0;
        while (j < m.size())
        {
            if (i < j)
                if (m[i][j] != 0)
                    res = false;
            j++;
        }
        i++;
    }
    return res;
}

bool esTriangularSuperior(vector<vector<int>> m)
{
    int i = 0;
    bool res = true;
    while (i < m.size())
    {
        int j = 0;
        while (j < m.size())
        {
            if (i > j)
                if (m[i][j] != 0)
                    res = false;
            j++;
        }
        i++;
    }
    return res;
}

bool esTriangular(const vector<vector<int>> &m)
{
    return esTriangularInferior(m) || esTriangularSuperior(m);
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    int n; // Cantidad de filas y columnas de la matriz
    cin >> n;
    int x;
    int filas = n, columnas = n;
    vector<vector<int>> m(filas, vector<int>(columnas, 0)); // En m leo la matriz

    for (int f = 0; f < filas; ++f)
    {
        for (int c = 0; c < columnas; ++c)
        {
            cin >> x;
            m[f][c] = x;
        }
    }

    bool res = esTriangular(m);
    cout << (res ? "true" : "false");
    return 0;
}
