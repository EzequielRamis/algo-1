#include "auxiliares.h"
#include "definiciones.h"
#include "ejercicios.h"
#include "gtest/gtest.h"

bool esMatriz(vector<vector<dato>> t) {
    bool res = true;
    int len = t.size();
    for (int i = 0; i < len - 1; i++)
        if (t[i].size() != t[i + 1].size())
            res = false;
    return res;
}

bool individuoEnTabla(individuo ind, eph_i ti) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++)
        if (ind == ti[i])
            res = true;
    return res;
}

bool hogarEnTabla(hogar h, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++)
        if (h == th[i])
            res = true;
    return res;
}

bool vacia(vector<vector<dato>> t) {
    return t.size() == 0;
}

bool cantidadCorrectaDeColumnas(vector<vector<dato>> t, int col) {
    bool res = true;
    for (int i = 0; i < t.size(); i++)
        if (t[i].size() != col)
            res = false;
    return res;
}

bool hayIndividuosSinHogares(eph_i ti, eph_h th) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++)
        if (!hayHogarConCodigo(th, ti[i][INDCODUSU]))
            res = true;
    return res;
}

bool hayHogarConCodigo(eph_h th, int c) {
    bool res = false;
    for (int i = 0; i < th.size(); i++)
        if (th[i][HOGCODUSU] == c)
            res = true;
    return res;
}

bool hayHogaresSinIndividuos(eph_i ti, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++)
        if (!hayIndividuoConCodigo(ti, ti[i][HOGCODUSU]))
            res = true;
    return res;
}

bool hayIndividuoConCodigo(eph_i ti, int c) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++)
        if (ti[i][INDCODUSU] == c)
            res = true;
    return res;
}

bool hayRepetidosI(eph_i ti) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++)
        for (int j = 0; j < ti.size(); j++)
            if (i != j && mismoCodusuYComponente(ti[i], ti[j]))
                res = true;
    return res;
}

bool mismoCodusuYComponente(individuo i1, individuo i2) {
    return i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE];
}

bool hayRepetidosH(eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++)
        for (int j = 0; j < th.size(); j++)
            if (i != j && th[i][HOGCODUSU] == th[j][HOGCODUSU])
                res = true;
    return res;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th) {
    bool res = true;
    int anio = ti[0][INDANIO];
    int trimestre = ti[0][INDTRIMESTRE];
    for (int i = 0; i < ti.size(); i++)
        if (ti[i][INDANIO] != anio || ti[i][INDTRIMESTRE] != trimestre)
            res = false;
    for (int i = 0; i < th.size(); i++)
        if (th[i][HOGANIO] != anio || th[i][HOGTRIMESTRE] != trimestre)
            res = false;
    return res;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti) {
    bool res = true;
    for (int i = 0; i < th.size(); i++)
        if (cantHabitantes(th[i], ti) >= 21)
            res = false;
    return res;
}

int cantHabitantes(hogar h, eph_i ti) {
    int sum = 0;
    for (int k = 0; k < ti.size(); k++)
        if (esSuHogar(h, ti[k]))
            sum++;
    return sum;
}

bool esSuHogar(hogar h, individuo i) {
    return h[HOGCODUSU] == i[INDCODUSU];
}

bool cantidadValidaDormitorios(eph_h th) {
    bool res = true;
    for (int i = 0; i < th.size(); i++)
        if (th[i][IV2] < th[i][II2])
            res = false;
    return res;
}

bool valoresEnRangoI(eph_i ti) {
    bool res = true;
    for (int i = 0; i < ti.size(); i++)
        if (!individuoValido(ti[i]))
            res = false;
    return res;
}

bool individuoValido(individuo i) {
    return (
        i[INDCODUSU] > 0 &&
        i[COMPONENTE] > 0 &&
        (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4) &&
        (0 < i[CH4] && i[CH4] <= 2) &&
        i[CH6] >= 0 &&
        (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
        (-1 <= i[ESTADO] && i[ESTADO] <= 1) &&
        (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4) &&
        (i[p47T] >= 0 || i[p47T] == -1) &&
        (0 <= i[PP04G] && i[PP04G] <= 10));
}

bool valoresEnRangoH(eph_h th) {
    bool res = true;
    for (int i = 0; i < th.size(); i++)
        if (!hogarValido(th[i]))
            res = false;
    return res;
}

bool hogarValido(hogar h) {
    return (
        h[HOGCODUSU] > 0 &&
        (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) &&
        (0 < h[II7] && h[II7] <= 3) &&
        valorRegionValido(h[REGION]) &&
        (h[MAS_500] == 0 || h[MAS_500] == 1) &&
        (0 < h[IV1] && h[IV1] <= 5) &&
        0 < h[IV2] && h[II2] >= 1 &&
        (h[II3] = 1 || h[II3] == 2));
}

bool valorRegionValido(int r) {
    return r == 1 || (40 <= r && r <= 44);
}

bool esCasa(hogar h) {
    return h[IV1] == 1;
}

int ingresos(hogar h, eph_i ti) {
    int sum = 0;
    for (int i = 0; i < ti.size(); i++)
        if (esSuHogar(h, ti[i]) && ti[i][p47T] > -1)
            sum += ti[i][p47T];
    return sum;
}