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
        int numero = rand() % 100;
        double t0 = clock();
        ej4_Onlogn(v, numero);
        double t1 = clock();
        double tiempo = (t1 - t0) / CLOCKS_PER_SEC;
        fout << n << "\t" << tiempo << endl;
    }
    fout.close();
    return 0;
}