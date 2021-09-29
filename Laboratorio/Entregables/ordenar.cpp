#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r)
{
    int s = v.size();
    int i = l - 1;
    int res = l;
    while (i < r)
    {
        int k = i + 1;
        if (v[k] < v[res])
            res = k;
        i++;
    }
    return res;
}

void ordenar1(vector<int> &v)
{
    int i = 0;
    int s = v.size();
    while (i < s)
    {
        int j = indiceMinSubsec(v, i, s - 1);
        swap(v[i], v[j]);
        i++;
    }
}

int main()
{
    /* No hace falta modificar el main */

    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v; // En v leo el vector
    while (i < n)
    {
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);

    // Imprimo el vector resultado
    i = 0;
    while (i < v.size())
    {
        cout << v[i] << " ";
        i++;
    }

    return 0;
}
