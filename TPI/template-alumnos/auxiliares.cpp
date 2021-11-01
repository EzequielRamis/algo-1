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
    for (int i = 0; i < ti.size(); i++) {
        if (ind == ti[i])
            res = true;
    }
    return res;
}

bool hogarEnTabla(hogar h, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++) {
        if (h == th[i])
            res = true;
    }
    return res;
}

bool vacia(vector<vector<dato>> t) {
    return t.size() == 0;
}

bool cantidadCorrectaDeColumnasI(eph_i ti) {
    bool res = true;
    for (int i = 0; i < ti.size(); i++)
        if (individuoEnTabla(ti[i], ti) && ti[i].size() != FILAS_INDIVIDUO)
            res = false;
    return res;
}

bool cantidadCorrectaDeColumnasH(eph_h th) {
    bool res = true;
    for (int i = 0; i < th.size(); i++)
        if (hogarEnTabla(th[i], th) && th[i].size() != FILAS_HOGAR)
            res = false;
    return res;
}

bool hayIndividuosSinHogares(eph_i ti, eph_h th) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++)
        if (individuoEnTabla(ti[i], ti))
            if (!hayHogarConCodigo(th, ti[i][INDCODUSU]))
                res = true;
    return res;
}

bool hayHogarConCodigo(eph_h th, int c) {
    bool res = false;
    for (int i = 0; i < th.size(); i++) {
        if (hogarEnTabla(th[i], th) && th[i][HOGCODUSU] == c)
            res = true;
    }
    return res;
}

bool hayHogaresSinIndividuos(eph_i ti, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++)
        if (hogarEnTabla(th[i], th))
            if (!hayIndividuoConCodigo(ti, ti[i][HOGCODUSU]))
                res = true;
    return res;
}

bool hayIndividuoConCodigo(eph_i ti, int c) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++) {
        if (hogarEnTabla(ti[i], ti) && ti[i][INDCODUSU] == c)
            res = true;
    }
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

bool mismoAnoYTrimestre;