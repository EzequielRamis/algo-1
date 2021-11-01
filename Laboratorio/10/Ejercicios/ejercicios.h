#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

void mostrar_vector(vector<int> &v);
vector<int> construir_vector(int n, string disposicion);

bool aux(vector<int> &vec, int i, int sum);
bool algunSubconjSuma(vector<int> &vec, int sum);

int busquedaBinaria(vector<int> v, int x);
int busquedaJumpSearch(vector<int> v, int x);
