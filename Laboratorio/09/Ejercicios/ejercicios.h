#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

void mostrar_vector(vector<int> &v);
vector<int> construir_vector(int n, string disposicion);

bool hayDuplicados(vector<int> &v);

int ej4_O1(vector<int> v);
void ej4_On(vector<int> &v);
int ej4_On3(vector<int> &v);
int ej4_Onlogn(vector<int> v, int e);

bool aux(vector<int> &vec, int i, int sum);
bool algunSubconjSuma(vector<int> &vec, int sum);

bool busqueda_binaria(vector<int> &s, int x);
