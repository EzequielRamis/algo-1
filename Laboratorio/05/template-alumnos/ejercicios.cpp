#include "ejercicios.h"

// Ejercicio 1
bool existePico(vector<int> v)
{
	int s = v.size();
	bool res = false;
	int i = 1;
	while (i < s - 1)
	{
		if (v[i] > v[i - 1] && v[i] > v[i + 1])
			res = true;
		i++;
	}
	return res;
}

// Ejercicio 2
int mcd(int m, int n)
{
	int a = m, b = n;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

// Ejercicio 3
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

// Ejercicio 4
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

// Ejercicio 5
void ordenar2(vector<int> &v)
{
	int i = 0;
	int j = 0;
	int k = v.size() - 1;
	while (j <= k)
	{
		if (v[j] == 2)
		{
			swap(v[j], v[k]);
			k--;
		}
		else if (v[j] == 0)
		{
			swap(v[i], v[j]);
			i++;
			j++;
		}
		else
			j++;
	}
}

// Ejercicio 6
tuple<int, int> division(int n, int d)
{
	int q = 0, r = n - 1;
	while (n != q * d + r)
	{
		if (n > q * d)
			q++;
		if (n < q * d + r)
			r--;
	}
	return make_tuple(q, r);
}
