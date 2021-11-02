#include "anagramas.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string palabra, palabra2;
    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
    cin >> palabra;

    ifstream dicci("ingles.dic");
    vector<string> listaPalabras;
    string word;
    while (getline(dicci, word)) {
        listaPalabras.push_back(word);
    }
    int cantidadAnagrama = 0;
    for (int i = 0; i < listaPalabras.size(); ++i) {
        if (esAnagrama(listaPalabras[i], palabra)) {
            cout << "Son anagramas: " << listaPalabras[i] << " y " << palabra << endl;
            cantidadAnagrama++;
        }
    }
    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;
    return 0;
}

bool esAnagrama(string p1, string p2) {
    // CAMBIAR AQUI QUE IMPLEMENTACION USAR
    return esAnagrama1(p1, p2);
}

bool esAnagrama1(string p1, string p2) {
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa ordenar
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
}

bool esAnagrama2(string p1, string p2) {
    //COMPLETAR
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa el mapeo de letras a números primos. Utilizar charToPrimo()
    int res1 = 1, res2 = 1;
    for (int i = 0; i < p1.size(); i++)
        res1 *= charToPrimo(p1[i]);
    for (int j = 0; j < p2.size(); j++)
        res2 *= charToPrimo(p2[j]);
    return res1 == res2;
}

void ordenarString(string &palabra) {
    //COMPLETAR
    //Asumir que palabra solo contiene letras minusculas de a-z (sin enie). Implementar cualquier algoritmo

    //Voy a usar counting sort
    vector<char> abc(26, 0);
    for (int i = 0; i < palabra.size(); i++) {
        int pos = posicionEnAlfabeto(palabra[i]);
        abc[pos]++;
    }
    int k = 0;
    for (int j = 0; j < abc.size(); j++)
        while (abc[j] > 0) {
            // alphabet position to ascii
            palabra[k] = (char)j + 'a';
            k++;
            abc[j]--;
        }
}

int charToPrimo(char c) {
    //COMPLETAR
    //Dado una letra minuscula de a-z (sin enie) devolver el numero primo correspondiente.
    switch (c) {
    case 'a':
        return 2;
    case 'b':
        return 3;
    case 'c':
        return 5;
    case 'd':
        return 7;
    case 'e':
        return 11;
    case 'f':
        return 13;
    case 'g':
        return 17;
    case 'h':
        return 19;
    case 'i':
        return 23;
    case 'j':
        return 29;
    case 'k':
        return 31;
    case 'l':
        return 37;
    case 'm':
        return 41;
    case 'n':
        return 43;
    case 'o':
        return 47;
    case 'p':
        return 53;
    case 'q':
        return 59;
    case 'r':
        return 61;
    case 's':
        return 67;
    case 't':
        return 71;
    case 'u':
        return 73;
    case 'v':
        return 79;
    case 'w':
        return 83;
    case 'x':
        return 89;
    case 'y':
        return 97;
    case 'z':
        return 101;
    default:
        return 1;
    }
}

int posicionEnAlfabeto(char c) {
    return c - 'a';
}
