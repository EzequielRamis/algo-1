#include "ejercicios.h"

vector<vector<int>> productoVectorial(vector<int> u, vector<int> v)
{
	vector<vector<int>> res(u.size(), vector<int>(v.size()));
	int i = 0;
	while (i < res.size())
	{
		int j = 0;
		while (j < res[i].size())
		{
			res[i][j] = u[i] * v[j];
			j++;
		}
		i++;
	}
	return res;
}

void trasponer(vector<vector<int>> &m)
{
	vector<vector<int>> p = m;
	int i = 0;
	while (i < m.size())
	{
		int j = 0;
		while (j < m[i].size())
		{
			m[i][j] = p[j][i];
			j++;
		}
		i++;
	}
	return;
}

vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int>> m2)
{
	vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
	int i = 0;
	while (i < m1.size())
	{
		int j = 0;
		while (j < m2[0].size())
		{
			int k = 0, sum = 0;
			while (k < m2.size())
			{
				sum += m1[i][k] * m2[k][j];
				k++;
			}
			res[i][j] = sum;
			j++;
		}
		i++;
	}
	return res;
}

bool vecinosEnRango(vector<vector<int>> m, int i, int j)
{
	return 0 <= i && i < m.size() &&
		   0 <= j && j < m[0].size();
}

int sumaVecinos(vector<vector<int>> m, int i, int j)
{
	int a = i - 1, sum = 0;
	while (a <= i + 1)
	{
		int b = j - 1;
		while (b <= j + 1)
		{
			if (vecinosEnRango(m, a, b))
				sum += m[a][b];
			b++;
		}
		a++;
	}
	return sum;
}

int cantidadVecinos(vector<vector<int>> m, int i, int j)
{
	int a = i - 1, sum = 0;
	while (a <= i + 1)
	{
		int b = j - 1;
		while (b <= j + 1)
		{
			if (vecinosEnRango(m, a, b))
				sum++;
			b++;
		}
		a++;
	}
	return sum;
}

vector<vector<int>> promediar(vector<vector<int>> m)
{
	vector<vector<int>> res(m.size(), vector<int>(m[0].size()));
	int i = 0;
	while (i < m.size())
	{
		int j = 0;
		while (j < m[0].size())
		{
			int promedio = sumaVecinos(m, i, j) / cantidadVecinos(m, i, j);
			res[i][j] = promedio;
			j++;
		}
		i++;
	}
	return res;
}

bool esPico(vector<vector<int>> m, int i, int j)
{
	bool pico = true;
	int a = i - 1;
	while (a <= i + 1)
	{
		int b = j - 1;
		while (b <= j + 1)
		{
			if ((a != i || b != j) &&
				// a,b en rango
				0 <= a && a < m.size() &&
				0 <= b && b < m[0].size())
				if (!(m[i][j] > m[a][b]))
					pico = false;
			b++;
		}
		a++;
	}
	return pico;
}

int contarPicos(vector<vector<int>> m)
{
	int res = 0, i = 0;
	while (i < m.size())
	{
		int j = 0;
		while (j < m[0].size())
		{
			if (esPico(m, i, j))
				res++;
			j++;
		}
		i++;
	}
	return res;
}

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

bool esTriangular(vector<vector<int>> m)
{
	return esTriangularInferior(m) || esTriangularSuperior(m);
}

bool seAmenazan(vector<vector<int>> m, int i1, int j1, int i2, int j2)
{
	return (i1 != i2 || j1 != j2) &&
		   (i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2));
}

bool amenazaAlguna(vector<vector<int>> m, int i1, int j1)
{
	bool existe = false;
	int i2 = 0;
	while (i2 < m.size())
	{
		int j2 = 0;
		while (j2 < m[0].size())
		{
			if (m[i2][j2] == 1 && seAmenazan(m, i1, j1, i2, j2))
				existe = true;
			j2++;
		}
		i2++;
	}
	return existe;
}

bool hayAmenaza(vector<vector<int>> m)
{
	bool existe = false;
	int i = 0;
	while (i < m.size())
	{
		int j = 0;
		while (j < m[0].size())
		{
			if (m[i][j] == 1 && amenazaAlguna(m, i, j))
				existe = true;
			j++;
		}
		i++;
	}
	return existe;
}

int diferenciaDiagonales(vector<vector<int>> m)
{
	int sum1 = 0, sum2 = 0;
	int i = 0;
	while (i < m.size())
	{
		sum1 += m[i][i];
		i++;
	}
	i = 0;
	while (i < m.size())
	{
		sum2 += m[i][m.size() - 1 - i];
		i++;
	}
	return abs(sum1 - sum2);
}