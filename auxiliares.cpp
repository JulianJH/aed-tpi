#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

bool esValida ( eph_h th, eph_i ti ) {
    bool resp = true;

    resp = (!vacia(ti) && !vacia(th) && esMatriz(ti) && esMatriz(th));
    resp = resp && (cantidadCorrectaDeColumnasI(ti) && cantidadCorrectaDeColumnasH(th));
    resp = resp && (!hayIndividuosSinHogares(ti, th) && !hayHogaresSinIndividuos(ti, th));
    resp = resp && (!hayRepetidosI(ti) && !hayRepetidosH(th));
    resp = resp && mismoAnioYTrimestre(ti, th);
    resp = resp && menosDe21MiembrosPorHogar(th, ti);
    resp = resp && cantidadValidaDormitorios(th);
    resp = resp && (valoresEnRangoI(ti) && valoresEnRangoH(th));

    return resp;
}

bool esMatriz ( vector<vector<dato>> t ) {
    bool resp = true;

    for (int i = 1; i < t.size() && resp; i++) {
        resp = (t[i].size() == t[i-1].size());
    }

    return resp;
}

bool vacia ( vector<vector<dato>> t ) {
    return t.empty();
}

bool cantidadCorrectaDeColumnasI ( eph_i ti) {
    bool correcta = true;

    for (int i = 0; i < ti.size() && correcta; i++) {
        correcta = (ti[i].size()==FILAS_INDIVIDUO);
    }

    return correcta;
}

bool cantidadCorrectaDeColumnasH ( eph_h th) {
    bool correcta = true;

    for (int i = 0; i < th.size() && correcta; i++) {
        correcta = (th[i].size()==FILAS_HOGAR);
    }

    return correcta;
}

bool hayIndividuosSinHogares ( eph_i ti, eph_h th ) {
    bool haySin = false;

    for (int i = 0; i < ti.size() && !haySin; i++) {
        haySin = !hayHogarConCodigo(th, ti[i][INDCODUSU]);
    }

    return haySin;
}

bool hayHogarConCodigo ( eph_h th, dato c ) {
    bool hay = false;

    for (int i = 0; i < th.size() && !hay; i++) {
        hay = (th[i][HOGCODUSU] == c);
    }

    return hay;
}

bool hayHogaresSinIndividuos ( eph_i ti, eph_h th ) {
    bool haySin = false;

    for (int i = 0; i < ti.size() && !haySin; i++) {
        haySin = !hayIndividuoConCodigo(th, ti[i][HOGCODUSU]);
    }

    return haySin;
}

bool hayIndividuoConCodigo ( eph_i ti, dato c ) {
    bool hay = false;

    for (int i = 0; i < ti.size() && !hay; i++) {
        hay = (ti[i][INDCODUSU] == c);
    }

    return hay;
}

bool hayRepetidosI ( eph_i ti ) {
    bool repetidos = false;

    for (int i = 0; i < ti.size() && !repetidos; i++) {
        for (int j = 0; j < ti.size() && !repetidos; j++) {
            if (i != j && mismoCodusuYComponente(ti[i], ti[j])) {
                repetidos = true;
            }
        }
    }

    return repetidos;
}

bool mismoCodusuYComponente ( individuo i1, individuo i2 ) {
    return (i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE]);
}

bool hayRepetidosH ( eph_h th ) {
    bool repetidos = false;

    for (int i = 0; i < th.size() && !repetidos; i++) {
        for (int j = 0; j < th.size() && !repetidos; j++) {
            if (i != j && th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                repetidos = true;
            }
        }
    }

    return repetidos;
}

bool mismoAnioYTrimestre ( eph_i ti, eph_h th ) {
    bool mismo = true;

    for (int i = 1; i < ti.size() && mismo; i++) {
        mismo = (ti[i][INDANIO] == ti[i-1][INDANIO] && ti[i][INDTRIMESTRE] == ti[i-1][INDTRIMESTRE]);
    }
    for (int i = 1; i < th.size() && mismo; i++) {
        mismo = (th[i][HOGANIO] == th[i-1][HOGANIO] && th[i][HOGTRIMESTRE] == th[i-1][HOGTRIMESTRE]);
    }

    if (!ti.empty() && !th.empty() && mismo) {
        mismo = (th[0][HOGANIO] == ti[0][INDANIO] && th[0][HOGTRIMESTRE] == ti[0][INDTRIMESTRE]);
    }

    return mismo;
}

bool menosDe21MiembrosPorHogar ( eph_h th, eph_i ti ) {
    bool menosDe21 = true;

    for (int i = 0; i < th.size() && menosDe21; i++) {
        if (cantHabitantes(th[i], ti) >= 21) {
            menosDe21 = false;
        }
    }

    return menosDe21;
}

int cantHabitantes ( hogar h, eph_i ti ) {
    int suma = 0;

    for (int i = 0; i < ti.size(); i++) {
        if (esSuHogar(h, ti[i])) {
            suma++;
        }
    }

    return suma;
}

bool esSuHogar ( hogar h, individuo i ) {
    return (h[HOGCODUSU] == i[INDCODUSU]);
}

bool cantidadValidaDormitorios ( eph_h th ) {
    bool cantValida = true;

    for (int i = 0; i < th.size() && cantValida; i++) {
        cantValida = (th[i][IV2] >= th[i][II2]);
    }

    return cantValida;
}

bool valoresEnRangoI( eph_i ti ) {
    bool enRango = true;

    for (int i = 0; i < ti.size() && enRango; i++) {
        enRango = individuoValido(ti[i]);
    }

    return enRango;
}

bool individuoValido ( individuo i ) {
    bool resp = true;

    resp = resp && (i[INDCODUSU] > 0);
    resp = resp && (i[COMPONENTE] > 0);
    resp = resp && (i[INDTRIMESTRE] > 0 && i[INDTRIMESTRE] <= 4);
    resp = resp && (i[CH4] > 0 && i[CH4] <= 2);
    resp = resp && (i[CH6] >= 0);
    resp = resp && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1);
    resp = resp && (i[ESTADO] >= -1 && i[ESTADO] <= 1);
    resp = resp && (i[CAT_OCUP] >= 0 && i[CAT_OCUP] <= 4);
    resp = resp && (i[p47T] >= 0 || i[p47T] == -1);
    resp = resp && (i[PP04G] >= 0 && i[PP04G] <= 10);

    return resp;
}

bool valoresEnRangoH( eph_h th ) {
    bool enRango = true;

    for (int i = 0; i < th.size() && enRango; i++) {
        enRango = hogarValido(th[i]);
    }

    return enRango;
}

bool hogarValido ( hogar h ) {
    bool resp = true;

    resp = resp && (h[HOGCODUSU] > 0);
    resp = resp && (h[HOGTRIMESTRE] > 0 && h[HOGTRIMESTRE] <= 4);
    resp = resp && (h[II7] > 0 && h[II7] <= 3);
    resp = resp && valorRegionValido(h[REGION]);
    resp = resp && (h[MAS_500] == 0 || h[MAS_500] == 1);
    resp = resp && (h[IV1] > 0 && h[IV1] <= 5);
    resp = resp && (h[IV2] > 0);
    resp = resp && (h[II2] >= 1);
    resp = resp && (h[II3] == 1 || h[II3] == 2);

    return resp;
}

bool valorRegionValido ( dato r ) {
    return ((r == 1) || (r >= 40 && r <= 44));
}

bool esCasa ( hogar h ) {
    return (h[IV1] == 1);
}

int ingresos ( hogar h, eph_i ti ) {
    int suma = 0;

    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1) {
            suma += ti[i][p47T];
        }
    }

    return suma;
}

int maxCantHabitacionesEnCasaEnRegion ( eph_h th, dato r ) {
    int maxHabs = 0;

    for (int i = 0; i < th.size(); i++) {
        if (esCasa(th[i]) && th[i][REGION] == r && th[i][IV2] > maxHabs) {
            maxHabs = th[i][IV2];
        }
    }

    return maxHabs;
}

float proporcionDeCasasConHC ( eph_h th, eph_i ti, dato region ) {
    float resp = 0;
    float hogaresValidos = 0;
    float hogaresConHC = 0;

    for (int i = 0; i < th.size(); i++) {
        if (esHogarConPosibleHC(th[i], region)) {
            hogaresValidos++;
            if (esHogarConHacinamientoCritico(th[i], ti)) {
                hogaresConHC++;
            }
        }
    }

    if (hogaresValidos > 0) {
        resp = hogaresConHC/hogaresValidos;
    }

    return resp;
}

bool esHogarConPosibleHC ( hogar h, dato region ) {
    return (esCasa(h) && h[REGION] == region && h[MAS_500] == 0);
}

bool esHogarConHacinamientoCritico ( hogar h, eph_i ti ) {
    return (cantHabitantes(h, ti) > 3*h[II2]);
}

bool trabaja ( individuo i ) {
    return i[ESTADO] == 1;
}

bool esCasaODepartamento ( hogar h ) {
    return (h[IV1]== 1 || h[IV1] == 2);
}

bool realizaSusTareasEnEsteHogar ( individuo i ) {
    return i[PP04G] == 6;
}

bool tieneEspaciosReservadosParaElTrabajo ( hogar h ) {
    return h[II3] == 1;
}

bool suHogarEsCasaODepartamento ( individuo i, eph_h th ) {
    for (int j = 0 ; j < th.size(); j++) {
        if (esSuHogar(th[j],i)) {
            return esCasaODepartamento(th[j]);
        }
    }
}

bool suHogarTieneEspaciosReservadosParaElTrabajo ( individuo i , eph_h th ) {
    for (int j = 0 ; j < th.size(); j++) {
        if (esSuHogar(th[j],i)) {
            return tieneEspaciosReservadosParaElTrabajo(th[j]);
        }
    }
}

bool esDeCiudadGrande ( individuo i , eph_h th ) {
    for (int j = 0 ; j < th.size(); j++) {
        if (esSuHogar(th[j],i)) {
            return th[j][MAS_500] == 1;
        }
    }
}

int trimestre ( eph_i ti ) {
    return ti[0][INDTRIMESTRE];
}

int anio ( eph_i ti ) {
    return ti[0][INDANIO];
}

bool individuoEnHogarValido ( individuo i , eph_h th ) {
    return (esDeCiudadGrande(i,th) && suHogarEsCasaODepartamento(i,th));
}

bool trabajaEnSuVivienda ( individuo i , eph_h th ) {
    return (realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i,th));
}

float cantidadDeIndividuosQueTrabajan ( eph_h th , eph_i ti ) {
    float res= 0;
    for (int k = 0 ; k < ti.size() ; k++) {
        if (trabaja(ti[k]) && individuoEnHogarValido(ti[k], th)) {
            res++;
        }
    }
    return res;
}

float cantIndividuosTrabajandoEnSuVivienda ( eph_h th , eph_i ti ) {
    float res= 0;
    for (int k = 0 ; k < ti.size() ; k++) {
        if (trabaja(ti[k]) && individuoEnHogarValido(ti[k], th) && trabajaEnSuVivienda(ti[k], th)) {
            res++;
        }
    }
    return res;
}

float proporcionTeleworking (eph_h th , eph_i ti ) {
    float res = 0;

    if (cantidadDeIndividuosQueTrabajan(th,ti) > 0) {
        res = cantIndividuosTrabajandoEnSuVivienda(th, ti) / cantidadDeIndividuosQueTrabajan(th, ti);
    }

    return res;
}

bool tieneCasaPropia ( hogar h ) {
    return h[II7] == 1;
}

bool tieneCasaChica ( hogar h , eph_i ti ) {
    return cantHabitantes(h,ti) - 2 > h[II2];
}
