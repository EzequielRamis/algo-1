#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida(eph_h th, eph_i ti) {
    if (!vacia(th) && !vacia(ti) &&
        cantidadCorrectaDeColumnas(ti, FILAS_INDIVIDUO) &&
        cantidadCorrectaDeColumnas(th, FILAS_HOGAR)) {
        return (
            !hayIndividuosSinHogares(ti, th) && !hayHogaresSinIndividuos(ti, th) &&
            !hayRepetidosI(ti) && !hayRepetidosH(th) &&
            mismoAnioYTrimestre(ti, th) &&
            menosDe21MiembrosPorHogar(th, ti) &&
            cantidadValidaDormitorios(th) &&
            valoresEnRangoI(ti) && valoresEnRangoH(th));
    }
    return false;
}

// Implementacion Problema 2
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    int maxHab = maxCantHabitRegion(th, region);
    vector<int> res(maxHab, 0);
    for (int i = 0; i < th.size(); i++)
        if (esCasa(th[i]) && th[i][REGION] == region)
            res[th[i][IV2] - 1]++;
    return res;
}

// Implementacion Problema 3
vector<pair<int, float>> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {

    vector<pair<int, float>> resp = {make_pair(1, 0),
                                     make_pair(40, 0),
                                     make_pair(41, 0),
                                     make_pair(42, 0),
                                     make_pair(43, 0),
                                     make_pair(44, 0)};
    for (int i = 0; i < resp.size(); i++)
        resp[i].second = proporcionDeCasasConHC(th, ti, resp[i].first);
    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}

// Implementacion Problema 5
int costoSubsidioMejora(eph_h th, eph_i ti, int monto) {
    int res = 0;
    for (int i = 0; i < th.size(); i++)
        if (tieneCasaPropia(th[i]) && tieneCasaChica(th[i], ti))
            res += monto;
    return res;
}

// Implementacion Problema 6
join_hi generarJoin(eph_h th, eph_i ti) {
    join_hi resp;
    for (int i = 0; i < ti.size(); i++) {
        int j = 0;
        while (j < th.size() && th[j][HOGCODUSU] != ti[i][INDCODUSU])
            j++;
        individuo ind = ti[i];
        hogar hog = th[j];
        resp.push_back(make_pair(hog, ind));
    }
    return resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU(eph_h &th, eph_i &ti) {
    ordenarHogaresRegionYCODUSU(th);
    ordenarIndividuosRegionYCODUSU(ti, th);
}

// Implementacion Problema 8
vector<hogar> muestraHomogenea(eph_h &th, eph_i &ti) {
    hogar h = {};
    vector<hogar> resp = {h};

    // TODO

    return resp;
}

// Implementacion Problema 9
void corregirRegion(eph_h &th, eph_i ti) {

    // TODO

    return;
}

// Implementacion Problema 10
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias) {
    vector<int> resp = {};

    // TODO

    return resp;
}

// Implementacion Problema 11
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair<eph_h, eph_i> resp = make_pair(rth, rti);

    // TODO

    return resp;
}