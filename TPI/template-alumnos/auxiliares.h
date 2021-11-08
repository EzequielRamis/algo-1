#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
#include <vector>

#endif //SOLUCION_AUXILIARES_H

bool esMatriz(vector<vector<dato>> t);
bool sonIguales(vector<dato> v1, vector<dato> v2);
bool individuoEnTabla(individuo ind, eph_i ti);
bool hogarEnTabla(hogar h, eph_h th);
bool vacia(vector<vector<dato>> t);
bool cantidadCorrectaDeColumnas(vector<vector<dato>> t, int col);
bool hayIndividuosSinHogares(eph_i ti, eph_h th);
bool hayHogarConCodigo(eph_h th, int c);
bool hayHogaresSinIndividuos(eph_i ti, eph_h th);
bool hayIndividuoConCodigo(eph_i ti, int c);
bool hayRepetidosI(eph_i ti);
bool mismoCodusuYComponente(individuo i1, individuo i2);
bool hayRepetidosH(eph_h th);
bool mismoAnioYTrimestre(eph_i ti, eph_h th);
bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);
int cantHabitantes(hogar h, eph_i ti);
bool esSuHogar(hogar h, individuo i);
bool cantidadValidaDormitorios(eph_h th);
bool valoresEnRangoI(eph_i ti);
bool individuoValido(individuo i);
bool valoresEnRangoH(eph_h th);
bool hogarValido(hogar h);
bool valorRegionValido(int r);
bool esCasa(hogar h);
int ingresos(hogar h, eph_i ti);

int maxCantHabitRegion(eph_h th, int region);

bool esHogarValido(hogar h, int region);
bool hogarConHacinamientoCritico(hogar h, eph_i ti);
int cantHogaresValidos(eph_h th, int region);
int cantHogaresValidosConHC(eph_h th, eph_i ti, int region);
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);

float proporcionTeleworking(eph_h th, eph_i ti);
int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti);
int cantIndividuosQueTrabajan(eph_h th, eph_i ti);
bool trabajaEnSuVivienda(individuo i, eph_h th);
bool individuoEnHogarValido(individuo i, eph_h th);
bool trabaja(individuo i);
int anio(eph_i ti);
int trimestre(eph_i ti);
bool esDeCiudadGrande(individuo i, eph_h th);
bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th);
bool suHogarEsCasaODepartamento(individuo i, eph_h th);
bool esCasaODepartamento(hogar h);
bool realizaSusTareasEnEsteHogar(individuo i);
bool tieneEspaciosReservadosParaElTrabajo(hogar h);

bool tieneCasaPropia(hogar h);
bool tieneCasaChica(hogar h, eph_i ti);

void ordenarHogaresRegionYCODUSU(eph_h &th);
void ordenarIndividuosRegionYCODUSU(eph_i &ti, eph_h &th);
bool vivenJuntos(individuo i1, individuo i2);
bool hogarEstaAntes(hogar h1, hogar h2, eph_h th);
bool suHogarEstaAntes(individuo i1, individuo i2, eph_h th);

int diferenciaMasRecurrente(eph_h th, eph_i ti);
bool estaEnDifs(vector<pair<int, int>> difs, int n);
eph_h muestraHomogeneaCruda(eph_h th, eph_i ti);
void ordenarPorIngreso(vector<hogar> &v, eph_i ti);

bool cumpleEstaCondicion(pair<int, dato> busquedaJ, individuo i);
bool cumpleCadaCondicion(vector<pair<int, dato>> busqueda, individuo i);
bool hayIndividuoCumpleCondicionEnHogar(hogar h, vector<pair<int, dato>> busqueda, eph_i ti);
bool hayIndividuoNoCumpleCondicionEnHogar(hogar h, vector<pair<int, dato>> busqueda, eph_i ti);
eph_h hogaresRes(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda);
eph_i individuosRes(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda);
void individuosEnEncuesta(eph_i &ti, vector<pair<int, dato>> busqueda);
void hogaresEnEncuesta(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda);