#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida ( eph_h th, eph_i ti );
bool esMatriz ( vector<vector<dato>> t );
bool vacia ( vector<vector<dato>> t );
bool cantidadCorrectaDeColumnasI ( eph_i ti );
bool cantidadCorrectaDeColumnasH ( eph_h th );
bool hayIndividuosSinHogares ( eph_i ti, eph_h th );
bool hayHogarConCodigo ( eph_h th, dato c);
bool hayHogaresSinIndividuos ( eph_i ti, eph_h th );
bool hayIndividuoConCodigo ( eph_h th, dato c);
bool hayRepetidosI ( eph_i ti);
bool mismoCodusuYComponente ( individuo i1, individuo i2 );
bool hayRepetidosH ( eph_h th);
bool mismoAnioYTrimestre ( eph_i ti, eph_h th );
bool menosDe21MiembrosPorHogar ( eph_h th, eph_i ti );
int cantHabitantes ( hogar h, eph_i ti );
bool esSuHogar ( hogar h, individuo i );
bool cantidadValidaDormitorios ( eph_h th );
bool valoresEnRangoI ( eph_i ti );
bool individuoValido ( individuo i );
bool valoresEnRangoH ( eph_h th );
bool hogarValido ( hogar h );
bool valorRegionValido ( dato r );
bool esCasa ( hogar h );
int ingresos ( hogar h, eph_i ti );
int maxCantHabitacionesEnCasaEnRegion ( eph_h th, dato r );
float proporcionDeCasasConHC ( eph_h th, eph_i ti, dato region );
bool esHogarConPosibleHC ( hogar h, dato region );
bool esHogarConHacinamientoCritico ( hogar h, eph_i );

#endif //SOLUCION_AUXILIARES_H