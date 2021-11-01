#include "ejercicios.h"

using namespace std;

int main()
{
    int n = 100;
    int hasta = 100000;
    int paso = 10;
    ofstream fout;
    fout.open("datos.csv");
    fout << "n\t"
         << "tiempo" << endl;
    for (n; n <= hasta; n *= paso)
    {
        vector<int> v = construir_vector(n, "asc");
        int numero = rand() % n;
        double t0 = clock();
        int res = busquedaJumpSearch(v, numero);
        double t1 = clock();
        printf("%d %d\n", numero, res);
        double tiempo = (t1 - t0) / CLOCKS_PER_SEC;
        fout << n << "\t" << tiempo << endl;
    }
    fout.close();
    return 0;
}