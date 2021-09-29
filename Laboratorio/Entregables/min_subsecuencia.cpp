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

int main()
{
  /* No hace falta modificar el main */
  // Leo las entradas
  int n; //Longitud del vector a rotar
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

  int l, r;
  cin >> l >> r;
  // Calculo el minimo
  int min = indiceMinSubsec(v, l, r);

  // Impimo salida
  cout << min;

  return 0;
}
