#include "auxiliares.h"
#include "definiciones.h"
#include "ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

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

int maxCantHabitRegion(eph_h th, int region) {
    int max = 0;
    for (int i = 0; i < th.size(); i++) {
        //chequear si debe ser casa o no
        if (th[i][REGION] == region && th[i][IV2] > max)
            max = th[i][IV2];
    }
    return max;
}

bool esHogarValido(hogar h, int region) {
    return esCasa(h) && h[REGION] == region && h[MAS_500] == 0;
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti) {
    return cantHabitantes(h, ti) > 3 * h[II2];
}

int cantHogaresValidos(eph_h th, int region) {
    int sum = 0;
    for (int i = 0; i < th.size(); i++)
        if (esHogarValido(th[i], region))
            sum++;
    return sum;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region) {
    int sum = 0;
    for (int i = 0; i < th.size(); i++)
        if (esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti))
            sum++;
    return sum;
}

float proporcionDeCasasConHC(eph_h th, eph_i ti, int region) {
    float proporcion = 0;
    if (cantHogaresValidos(th, region) > 0)
        proporcion = float(cantHogaresValidosConHC(th, ti, region) / cantHogaresValidos(th, region));
    return proporcion;
}

float proporcionTeleworking(eph_h th, eph_i ti) {
    if (cantIndividuosQueTrabajan(th, ti) > 0)
        return float(cantIndividuosTrabajandoEnSuVivienda(th, ti)) / float(cantIndividuosQueTrabajan(th, ti));
    return 0;
}

int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti) {
    int sum = 0;
    for (int i = 0; i < ti.size(); i++)
        if (trabaja(ti[i]) && trabajaEnSuVivienda(ti[i], th) && individuoEnHogarValido(ti[i], th))
            sum++;
    return sum;
}

int cantIndividuosQueTrabajan(eph_h th, eph_i ti) {
    int sum = 0;
    for (int i = 0; i < ti.size(); i++)
        if (trabaja(ti[i]) && individuoEnHogarValido(ti[i], th))
            sum++;
    return sum;
}
bool trabajaEnSuVivienda(individuo i, eph_h th) {
    return realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i, th);
}

bool individuoEnHogarValido(individuo i, eph_h th) {
    return esDeCiudadGrande(i, th) && suHogarEsCasaODepartamento(i, th);
}

bool trabaja(individuo i) {
    return i[ESTADO] == 1;
}

bool esDeCiudadGrande(individuo i, eph_h th) {
    bool res = false;
    for (int h = 0; h < th.size(); h++)
        if (esSuHogar(th[h], i) && th[h][MAS_500] == 1)
            res = true;
    return res;
}

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th) {
    bool res = false;
    for (int h = 0; h < th.size(); h++)
        if (esSuHogar(th[h], i) && tieneEspaciosReservadosParaElTrabajo(th[h]))
            res = true;
    return res;
}

bool suHogarEsCasaODepartamento(individuo i, eph_h th) {
    bool res = false;
    for (int h = 0; h < th.size(); h++)
        if (esSuHogar(th[h], i) && esCasaODepartamento(th[h]))
            res = true;
    return res;
}

bool esCasaODepartamento(hogar h) {
    return h[IV1] == 1 || h[IV1] == 2;
}

bool realizaSusTareasEnEsteHogar(individuo i) {
    return i[PP04G] == 6;
}

bool tieneEspaciosReservadosParaElTrabajo(hogar h) {
    return h[II3] == 1;
}

bool tieneCasaPropia(hogar h) {
    return h[II7] == 1;
}

bool tieneCasaChica(hogar h, eph_i ti) {
    return cantHabitantes(h, ti) - 2 > h[II2];
}

void selectionSortPorCODUSU(vector<hogar> &regionales) {
    for (int j = 0; j < regionales.size(); j++) {
        int min = j;
        for (int k = j; k < regionales.size(); k++) {
            if (regionales[min][HOGCODUSU] > regionales[k][HOGCODUSU])
                min = k;
        }
        // swap
        hogar tmp = regionales[j];
        regionales[j] = regionales[min];
        regionales[min] = tmp;
    }
}

void ordenarHogaresRegionYCODUSU(eph_h &th) {
    // agrupamos hogares por region
    vector<vector<hogar>> regiones(6, vector<hogar>(0));
    for (int h = 0; h < th.size(); h++) {
        if (th[h][REGION] == 1)
            regiones[0].push_back(th[h]);
        else
            regiones[th[h][REGION] - 39].push_back(th[h]);
    }

    for (int i = 0; i < regiones.size(); i++)
        selectionSortPorCODUSU(regiones[i]);

    // combinamos los vectores regionales en &th
    int k = 0;
    for (int i = 0; i < regiones.size(); i++)
        for (int j = 0; j < regiones[i].size(); j++) {
            th[k] = regiones[i][j];
            k++;
        }
}

void ordenarIndividuosRegionYCODUSU(eph_i &ti, eph_h &th) {
    // bubble sort
    int len = ti.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            // si no se cumple el predicado estanOrdenadosPorCodusuDeHogarYComponente se hace un swap
            if (!(suHogarEstaAntes(ti[j], ti[j + 1], th) ||
                  (vivenJuntos(ti[j], ti[j + 1]) && ti[j][COMPONENTE] < ti[j + 1][COMPONENTE]))) {
                individuo tmp = ti[j];
                ti[j] = ti[j + 1];
                ti[j + 1] = tmp;
            }
        }
    }
}

bool suHogarEstaAntes(individuo i1, individuo i2, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++) {
        for (int j = 0; j < th.size(); j++) {
            if (esSuHogar(th[i], i1) && esSuHogar(th[j], i2) && hogarEstaAntes(th[i], th[j], th))
                res = true;
        }
    }
    return res;
}

bool vivenJuntos(individuo i1, individuo i2) {
    return i1[INDCODUSU] == i2[INDCODUSU];
}

bool hogarEstaAntes(hogar h1, hogar h2, eph_h th) {
    bool res = false;
    for (int i = 0; i < th.size(); i++) {
        for (int j = i + 1; j < th.size(); j++) {
            if (th[i] == h1 && th[j] == h2)
                res = true;
        }
    }
    return res;
}

// vector de ingresos del primer test
// 0, 35, 26, 27, 30, 0, 180, 1, 20, 25

// vector de ingresos del primer test ordenado
// 0, 0, 1, 20, 25, 26, 27, 30, 35, 180

/*  j
    |
    v
i ->    00  00  01  20  25  26  27  30  35  180
    00                                         
    00  00                                     
    01  01  01                                 
    20  20  20  19                             
    25  25  25  24  05                               
    26  26  26  25  06  01                     
    27  27  27  26  07  02  01                 
    30  30  30  29  10  05  04  03             
    35  35  35  34  15  10  09  08  05         
    180 180 180 179 160 155 154 153 150 145   
*/

// vector de ingresos esperado test
// 25, 35, 20, 30

// vector de ingresos esperado test ordenado
// 20, 25, 30, 35

// vector de ingresos del segundo test
// 0, 30, 26, 27, 30, 0, 3, 1, 20, 24, 0

// vector de ingresos del segundo test ordenado
// 0, 0, 0, 1, 3, 20, 24, 26, 27, 30, 30

/*  j
    |
    v
i ->    00  00  00  01  03  20  24  26  27  30  30
    00
    00  00
    00  00  00
    01  00  00  00
    03  03  03  03  02
    20  20  20  20  19  17
    24  24  24  24  23  21  04
    26  26  26  26  25  23  06  02
    27  27  27  27  26  24  07  03  01  
    30  30  30  30  29  27  10  06  04  03
    30  30  30  30  29  27  10  06  04  03  00 
*/

// vector de ingresos esperado test
// 24, 27, 30

// vector de ingresos esperado test ordenado
// 24, 27, 30

//      ((hogar x, hogar y), diferencia)
typedef pair<pair<hogar, hogar>, int> puntoDiferenciaIngresos;
typedef vector<puntoDiferenciaIngresos> puntosDiferenciaIngresos;

int diferenciaDeIngresos(hogar h1, hogar h2, eph_i ti) {
    return abs(ingresos(h1, ti) - ingresos(h2, ti));
}

int indiceGrupoConDif(vector<puntosDiferenciaIngresos> &r, puntoDiferenciaIngresos p) {
    int res = -1;
    for (int i = 0; i < r.size(); i++)
        if (r[i][0].second == p.second)
            res = i;
    return res;
}

vector<puntosDiferenciaIngresos> agruparPorDiferencia(puntosDiferenciaIngresos ps) {
    vector<puntosDiferenciaIngresos> res;
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i].second != 0) {
            int j = indiceGrupoConDif(res, ps[i]);
            if (j != -1)
                res[j].push_back(ps[i]);
            else
                res.push_back({ps[i]});
        }
    }
    return res;
}

eph_h quitarDuplicados(eph_h v) {
    int len = v.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (v[j][HOGCODUSU] > v[j + 1][HOGCODUSU]) {
                hogar tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
    eph_h res = {v[0]};
    for (int i = 1; i < v.size(); i++)
        if (v[i - 1][HOGCODUSU] != v[i][HOGCODUSU])
            res.push_back(v[i]);
    return res;
}

eph_h muestraHomogeneaCruda(eph_h th, eph_i ti) {
    puntosDiferenciaIngresos puntos;
    for (int i = 0; i < th.size(); i++)
        for (int j = i + 1; j < th.size(); j++) {
            int d = diferenciaDeIngresos(th[i], th[j], ti);
            puntos.push_back(make_pair(make_pair(th[i], th[j]), d));
        }
    vector<puntosDiferenciaIngresos> agrupadosPorDiferencia = agruparPorDiferencia(puntos);
    for (int i = 0; i < agrupadosPorDiferencia.size(); i++) {
        puntosDiferenciaIngresos p = agrupadosPorDiferencia[i];
        puntosDiferenciaIngresos escalonadaMasLarga;
        for (int j = 0; j < p.size(); j++) {
            puntosDiferenciaIngresos escalonadaAComparar = {p[j]};
            for (int k = j + 1; k < p.size(); k++) {
                int len = escalonadaAComparar.size();
                puntoDiferenciaIngresos ultimo = escalonadaAComparar[len - 1];
                int ingresoAnterior = ingresos(ultimo.first.second, ti);
                int ingresoActual = ingresos(p[k].first.first, ti);
                if (ingresoAnterior == ingresoActual) {
                    escalonadaAComparar.push_back(p[k]);
                }
            }
            if (escalonadaAComparar.size() > escalonadaMasLarga.size())
                escalonadaMasLarga = escalonadaAComparar;
        }
        agrupadosPorDiferencia[i] = escalonadaMasLarga;
    }
    eph_h muestraMasLarga;
    for (int i = 0; i < agrupadosPorDiferencia.size(); i++) {
        eph_h hogaresAgrupados;
        int len = agrupadosPorDiferencia[i].size();
        for (int j = 0; j < len; j++) {
            hogaresAgrupados.push_back(agrupadosPorDiferencia[i][j].first.first);
            hogaresAgrupados.push_back(agrupadosPorDiferencia[i][j].first.second);
        }
        hogaresAgrupados = quitarDuplicados(hogaresAgrupados);
        if (hogaresAgrupados.size() > muestraMasLarga.size())
            muestraMasLarga = hogaresAgrupados;
    }
    return muestraMasLarga;
}

void ordenarPorIngreso(vector<hogar> &v, eph_i ti) {
    int len = v.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (ingresos(v[j], ti) > ingresos(v[j + 1], ti)) {
                hogar tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

bool cumpleEstaCondicion(pair<int, dato> busquedaJ, individuo i) {
    bool res = false;
    int item = busquedaJ.first;
    if (i[item] == busquedaJ.second)
        res = true;
    return res;
}

bool cumpleCadaCondicion(vector<pair<int, dato>> busqueda, individuo i) {
    bool res = true;
    for (int j = 0; j < busqueda.size(); j++) {
        if (!cumpleEstaCondicion(busqueda[j], i))
            res = false;
    }
    return res;
}

bool hayIndividuoCumpleCondicionEnHogar(hogar h, vector<pair<int, dato>> busqueda, eph_i ti) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++) {
        if (esSuHogar(h, ti[i]) && cumpleCadaCondicion(busqueda, ti[i]))
            res = true;
    }
    return res;
}

bool hayIndividuoNoCumpleCondicionEnHogar(hogar h, vector<pair<int, dato>> busqueda, eph_i ti) {
    bool res = false;
    for (int i = 0; i < ti.size(); i++) {
        if (esSuHogar(h, ti[i]) && !cumpleCadaCondicion(busqueda, ti[i]))
            res = true;
    }
    return res;
}

eph_h hogaresRes(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_h res;
    for (int j = 0; j < th.size(); j++) {
        if (hayIndividuoCumpleCondicionEnHogar(th[j], busqueda, ti))
            res.push_back(th[j]);
    }
    return res;
}

eph_i individuosRes(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_i res;
    for (int j = 0; j < ti.size(); j++) {
        if (cumpleCadaCondicion(busqueda, ti[j]))
            res.push_back(ti[j]);
    }
    return res;
}

void individuosEnEncuesta(eph_i &ti, vector<pair<int, dato>> busqueda) {
    eph_i tiFinal;
    for (int j = 0; j < ti.size(); j++) {
        if (!cumpleCadaCondicion(busqueda, ti[j]))
            tiFinal.push_back(ti[j]);
    }
    ti = tiFinal;
}

void hogaresEnEncuesta(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_h thFinal;
    for (int j = 0; j < th.size(); j++) {
        if (hayIndividuoNoCumpleCondicionEnHogar(th[j], busqueda, ti))
            thFinal.push_back(th[j]);
    }
    th = thFinal;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair<int, int> centro, eph_h th) {
    int sum = 0;
    for (int i = 0; i < th.size(); i++)
        if (hogarEnAnillo(distDesde, distHasta, centro, th[i]))
            sum++;
    return sum;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair<int, int> centro, hogar h) {
    float d = distanciaEuclidiana(centro, h[HOGLATITUD], h[HOGLONGITUD]);
    return float(distDesde) < d && d <= float(distHasta);
};

float distanciaEuclidiana(pair<int, int> centro, int latitud, int longitud) {
    return sqrt(pow(centro.first - latitud, 2) + pow(centro.second - longitud, 2));
}