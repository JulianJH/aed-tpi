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
float proporcionTeleworking ( eph_h th , eph_i ti );
int cantIndividuosTrabajandoEnSuVivienda ( eph_h th , eph_i ti );
int cantidadDeIndividuosQueTrabajan ( eph_h th , eph_i ti );
bool trabajaEnSuVivienda ( individuo i , eph_h th );
bool individuoEnHogarValido ( individuo i , eph_h th );
int trimestre ( eph_i ti );
bool esDeCiudadGrande ( hogar h );
bool suHogarTieneEspaciosReservadosParaElTrabajo ( individuo i , eph_h th );
bool tieneEspaciosReservadosParaElTrabajo ( hogar h );
bool realizaSusTareasEnEsteHogar ( individuo i );
bool esCasaODepartamento ( hogar h );
bool trabaja ( individuo i );
bool tieneCasaPropia ( hogar h );
bool tieneCasaChica ( hogar h , eph_i ti );
void cambiarRegionesGBAaPampeana ( eph_h & th );
hogar hogarDeIndividuo ( individuo i, eph_h th );
void concatenar ( vector<vector<dato>> & a, vector<vector<dato>> & b );
eph_i individuosEnHogar ( hogar h, eph_i ti );
eph_i sacarHabitantesQueCumplen ( hogar h, eph_i & individuos, vector <pair<int, dato>> busqueda );
bool cumpleBusqueda ( individuo i, vector <pair<int, dato>> busqueda );
float distanciaEuclideana (pair<int,int> centro , int latitud , int longitud);
bool hogarEnAnillo(int distDesde, int distHasta , pair<int, int> centro, hogar h);
int  cantHogaresEnAnillo(int distDesde , int distHasta, pair<int, int> centro, eph_h th);
vector<int> hogaresEnAnillosConcentricos (vector<int> distancias , pair<int, int> centro, eph_h th);
void ordenarHogaresPorRegionYCodusu ( eph_h & th );
void ordenarPorHogcodusu( eph_h & th );
void ordenarIndividuosSegunHogarYComponente ( eph_h & th, eph_i & ti );
bool ordenCorrectoSegunHogares ( individuo i1, individuo i2, eph_h & th );
void ordenarPorIngresos( eph_h & th, eph_i & ti );
vector<hogar> mayorMuestraHomogenea ( eph_h th, eph_i ti );
vector<hogar> mayorMuestraHomoDesde ( int i, eph_h th, eph_i ti );
vector<hogar> mayorMuestraHomoDesdeConDif ( int i, int dif, eph_h th, eph_i ti );

#endif //SOLUCION_AUXILIARES_H
