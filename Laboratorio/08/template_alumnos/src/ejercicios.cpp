#include "ejercicios.h"
#include <bits/stdc++.h>

/* Para compilar */

using namespace std;

vector<string> split(string s, char delim)
{
	vector<string> v;
	string buf;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == delim)
		{
			if (buf.size() > 0)
				v.push_back(buf);
			buf.clear();
		}
		else
		{
			buf.push_back(s[i]);
		}
	}
	if (buf.size() > 0)
		v.push_back(buf);
	return v;
}

string darVueltaPalabra(string s)
{
	string res;
	vector<string> palabras = split(s, ' ');
	for (int i = palabras.size() - 1; i >= 0; i--)
	{
		string palabra = palabras[i];
		for (int j = 0; j < palabra.size(); j++)
		{
			res.push_back(palabra[j]);
		}
		if (i != 0)
		{
			res.push_back(' ');
		}
	}
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2)
{
	vector<int> indices;
	bool estaOrdenado = true;
	int j = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		while (j < s2.size() && s2[j] != s1[i])
		{
			j++;
		}
		indices.push_back(j);
		j++;
	}
	for (int i = 1; i < indices.size(); i++)
	{
		if (!(indices[i - 1] < indices[i] && indices[i] < s2.size()))
			estaOrdenado = false;
	}
	return estaOrdenado && indices.size() == s1.size();
}

int apariciones(string s, char e)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == e)
			sum++;
	return sum;
}

bool esAnagrama(string a, string b)
{
	if (a.size() != b.size())
		return false;
	if (a.size() == 0)
		return true;
	int i = 0;
	while (i < a.size() && apariciones(a, a[i]) == apariciones(b, a[i]))
	{
		i++;
	}
	return i == a.size();
}

bool perteneceAnteriores(vector<vector<string>> v, string e)
{
	bool res = false;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j] == e)
				res = true;
	return res;
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string>> agruparAnagramas(vector<string> v)
{
	vector<vector<string>> res;
	for (int i = 0; i < v.size(); i++)
	{
		vector<string> grp;
		for (int j = i; j < v.size(); j++)
			if (!perteneceAnteriores(res, v[j]) && esAnagrama(v[j], v[i]))
				grp.push_back(v[j]);
		if (grp.size() > 0)
			res.push_back(grp);
	}
	return res;
}

string reverso(string s)
{
	string rev;
	for (int i = s.size() - 1; i >= 0; i--)
		rev.push_back(s[i]);
	return rev;
}

bool esPalindromo(string s)
{
	return reverso(s) == s;
}

bool tieneRepetidos(string s)
{
	bool repetidos = false;
	for (int i = 0; i < s.size(); i++)
	{
		int r = apariciones(s, s[i]);
		if (r > 1)
			repetidos = true;
	}
	return repetidos;
}

string rotar(string s, int j)
{
	string rot(s);
	for (int i = 0; i < s.size(); i++)
	{
		int p = (i + j) % s.size();
		rot[p] = s[i];
	}
	return rot;
}

// no se puede usar substring
string darVueltaK(string s, int k)
{
	string res;
	int i = 0;
	while (i < s.size())
	{
		int j = 0;
		string buf;
		while (i + j < s.size() && j < k)
		{
			buf.push_back(s[i + j]);
			j++;
		}
		string rev = reverso(buf);
		for (int l = 0; l < rev.size(); l++)
		{
			res.push_back(rev[l]);
		}
		i += j;
	}
	return res;
}

string abueloLaino(string s)
{
	string res = "S";
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'i')
			res = "N";
	return res;
}

int cantidadDeFelicitaciones(vector<string> v)
{
	int res = 0;
	char prefijo = ' ';
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j] == 'D' || v[i][j] == 'R')
			{
				if ((prefijo == 'D' && v[i][j] == 'R') || (prefijo == 'R' && v[i][j] == 'D'))
				{
					res++;
					prefijo = ' ';
				}
				else
					prefijo = v[i][j];
			}
	return res;
}

void middleMove(string &s, int i, bool end)
{
	int n = s.size();
	if (!(1 <= i && i <= n))
		return;
	i--;
	char tmp = s[i];
	if (end)
	{
		for (int j = i; j < n - 1; j++)
			s[j] = s[j + 1];
		s[n - 1] = tmp;
	}
	else
	{
		for (int j = i; j > 0; j--)
			s[j] = s[j - 1];
		s[0] = tmp;
	}
	return;
}

int middleOut(string s, string t)
{
	if (!esAnagrama(s, t))
		return -1;
	int res = 0;
	sort(s.begin(), s.end());
	return res;
}
