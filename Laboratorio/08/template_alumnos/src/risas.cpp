#include <string>
#include <vector>
#include "risas.h"
#include <iostream>
#include <fstream>

using namespace std;

/* Utiles */
vector<char> leerDatos(string s)
{
    vector<char> vec;
    ifstream file;
    char val;

    file.open(s, ifstream::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> val;
            vec.push_back(val);
        }
    }
    file.close();
    return vec;
}

int leerLargoReal(string filename)
{
    int largo = -1;
    ifstream file;
    file.open(filename, ifstream::in);
    if (file.is_open())
        file >> largo;
    file.close();
    return largo;
}
/* Utiles */

/* RESOLUCION ALUMNOS */
int risaMasLarga(vector<char> s)
{
    int len = s.size();
    if (len == 0)
        return 0;
    int i = 0;
    int risaMax;
    int risa;
    if (s[i] == 'a' || s[i] == 'h')
    {
        risaMax = 1;
        risa = 1;
    }
    else
    {
        risaMax = 0;
        risa = 0;
    }
    while (i < len - 1)
    {
        if ((s[i] == 'a' && s[i + 1] == 'h') || (s[i] == 'h' && s[i + 1] == 'a'))
            risa++;
        else
        {
            if (risa > risaMax)
                risaMax = risa;
            if (s[i + 1] == 'a' || s[i + 1] == 'h')
                risa = 1;
            else
                risa = 0;
        }
        i++;
    }
    return risaMax;
}
/* RESOLUCION ALUMNOS */
