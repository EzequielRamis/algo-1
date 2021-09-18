#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores()
{
	cout << "El módulo vectores fue cargado correctamente" << endl;
}

//Ejercicio
bool divide(vector<int> v, int a)
{
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
	int i = 0;
	while (i < v.size())
	{
		if (v[i] % a != 0)
			return false;
		i++;
	}
	return true;
}

//Ejercicio
int mayor(vector<int> v)
{
	// Dado un vector v, devuelve el valor maximo encontrado.
	int may = -1, i = 0;
	while (i < v.size())
	{
		if (v[i] > may)
			may = v[i];
		i++;
	}
	return may;
}

//Ejercicio
vector<int> reverso(vector<int> v)
{
	// Dado un vector v, devuelve el reverso.
	vector<int> rev;
	int i = v.size() - 1;
	while (i >= 0)
	{
		rev.push_back(v[i]);
		i--;
	}
	return rev;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k)
{
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
	vector<int> rot;
	int i = 0;
	while (i < v.size())
	{
		int p = (i + k) % v.size();
		rot.push_back(v[p]);
		i++;
	}
	return rot;
}

//Ejercicio
bool esPrimo(int n)
{
	int d = 2;
	while (d < n)
	{
		if (n % d == 0)
			return false;
		d++;
	}
	return true;
}

vector<int> factoresPrimos(int n)
{
	//que dado un entero devuelve un vector con los factores primos del mismo
	vector<int> facts;
	int p = 2;
	while (n > 1)
	{
		if (esPrimo(p) && n % p == 0)
		{
			facts.push_back(p);
			n /= p;
		}
		else
			p++;
	}
	return facts;
}

//Ejercicio
void mostrarVector(vector<int> v)
{
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	int i = 0;
	int s = v.size();
	cout << "[";
	while (i < s - 1)
	{
		cout << v[i] << ", ";
		i++;
	}
	if (i == s - 1)
		cout << v[i];
	cout << "]" << endl;
}
