#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores()
{
	interseccion();
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

vector<int> leerVector(string nombreArchivo)
{
	vector<int> res;
	int e;
	ifstream fin;
	fin.open(nombreArchivo, ios::in);
	while (!fin.eof())
	{
		fin >> e;
		res.push_back(e);
	}
	fin.close();
	return res;
}

void guardarVector(vector<int> v, string nombreArchivo)
{
	ofstream fout;
	fout.open(nombreArchivo);
	int i = 0;
	int s = v.size();
	fout << "[";
	while (i < s - 1)
	{
		fout << v[i] << ", ";
		i++;
	}
	if (i == s - 1)
		fout << v[i];
	fout << "]" << endl;
	fout.close();
}

int sumatoria(vector<int> v, int j, int k)
{
	int sum = 0;
	if (j > k)
		return 0;
	while (j <= k)
	{
		sum += v[j];
		j++;
	}
	return sum;
}

int elementoMedio(vector<int> v)
{
	int i = 0, s = v.size(), izq, der;
	while (i < s - 1)
	{
		izq = sumatoria(v, 0, i);
		der = sumatoria(v, i + 1, s - 1);
		if (izq > der)
			return v[i];
		i++;
	}
	return v[s - 1];
}

int apariciones(vector<int> v, int e)
{
	int i = 0, s = 0;
	while (i < v.size())
	{
		if (v[i] == e)
			s++;
		i++;
	}
	return s;
}

void cantApariciones(string nombreArchivo)
{
	vector<int> v = leerVector(nombreArchivo);
	vector<int> w(mayor(v));
	ofstream fout;
	fout.open(nombreArchivo + ".out");
	int i = 0;
	while (i < w.size())
	{
		int e = i + 1;
		int s = apariciones(v, e);
		if (s > 0)
			fout << e << " " << s << endl;
		i++;
	}
	fout.close();
}

int apariciones(vector<string> v, string e)
{
	int i = 0, s = 0;
	while (i < v.size())
	{
		if (v[i] == e)
			s++;
		i++;
	}
	return s;
}

vector<string> leerVectorPalabra(string nombreArchivo)
{
	vector<string> res;
	string e;
	ifstream fin;
	fin.open(nombreArchivo, ios::in);
	while (!fin.eof())
	{
		fin >> e;
		res.push_back(e);
	}
	fin.close();
	return res;
}

void cantAparicionesDePalabra(string nombreArchivo, string palabra)
{
	vector<string> v = leerVectorPalabra(nombreArchivo);
	int s = apariciones(v, palabra);
	cout << s << endl;
}

void guardarVector(vector<float> v, string nombreArchivo)
{
	ofstream fout;
	fout.open(nombreArchivo);
	int i = 0;
	int s = v.size();
	fout << "[";
	while (i < s - 1)
	{
		fout << v[i] << ", ";
		i++;
	}
	if (i == s - 1)
		fout << v[i];
	fout << "]" << endl;
	fout.close();
}

void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut)
{
	vector<int> v = leerVector(nombreArchivoIn1);
	vector<int> w = leerVector(nombreArchivoIn2);
	vector<float> z;
	int s = min(v.size(), w.size());
	int i = 0;
	while (i < s)
	{
		float p = (v[i] + w[i]) / 2.0;
		z.push_back(p);
		i++;
	}
	guardarVector(z, nombreArchivoOut);
}

int minimo(vector<int> v, int i, int j)
{
	// Dado un vector v y un rango i<j, devuelve el indice del valor minimo encontrado.
	int min = j - 1;
	if (i > j || j > v.size())
		return min;
	while (i < j)
	{
		if (v[i] < v[min])
			min = i;
		i++;
	}
	return min;
}

void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut)
{
	vector<int> v = leerVector(nombreArchivoIn1);
	vector<int> w = leerVector(nombreArchivoIn2);
	int i = 0;
	while (i < w.size())
	{
		v.push_back(w[i]);
		i++;
	}
	i = 0;
	int s = v.size();
	while (i < s - 1)
	{
		int jMin = i;
		int j = i + 1;
		while (j < s)
		{
			if (v[j] < v[jMin])
				jMin = j;
			j++;
		}
		swap(v[i], v[jMin]);
		i++;
	}
	guardarVector(v, nombreArchivoOut);
}

vector<int> interseccion()
{
	string f1, f2;
	cin >> f1 >> f2;
	vector<int> v = leerVector(f1);
	vector<int> w = leerVector(f2);
	vector<int> z;
	int i = 0;
	while (i < v.size())
	{
		if (apariciones(w, v[i]) > 0)
			z.push_back(v[i]);
		i++;
	}
	mostrarVector(z);
	return z;
}