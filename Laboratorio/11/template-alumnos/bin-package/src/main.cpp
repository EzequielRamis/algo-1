#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void swap(vector<int> &v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void insertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            swap(arr, j - 1, j);
}

void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i; j < arr.size(); j++)
            if (arr[j] < arr[min])
                min = j;
        swap(arr, i, min);
    }
}

void ordenar(vector<int> &items) {
    insertionSort(items);
}

int bestFit(int W, vector<int> &items) {
    multiset<int> restos;
    for (int i = 0; i < (int)items.size(); ++i) {
        restos.insert(W);
    }
    int res = 0;
    for (int i = 0; i < (int)items.size(); ++i) {
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if (restoAct == W) {
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

int main() {
    int N, W, aux;

    //Se levantan los items y la capacidad del contenedor
    cout << "Se levantan los items y la capacidad del contenedor";
    ifstream bpp("BPP.in");
    bpp >> N >> W;
    vector<int> items;
    for (int i = 0; i < N; ++i) {
        bpp >> aux;
        items.push_back(aux);
    }
    bpp.close();
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

    return 0;
}
