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

    for (int i = 1; i < t.size(); i++) {
        resp = resp && (t[i].size() == t[i-1].size());
    }

    return resp;
}

bool vacia ( vector<vector<dato>> t ) {
    return t.empty();
}

bool cantidadCorrectaDeColumnasI ( eph_i ti) {
    bool resp = true;

    for (int i = 0; i < ti.size(); i++) {
        resp = resp && (ti[i].size()==FILAS_INDIVIDUO);
    }

    return resp;
}

bool cantidadCorrectaDeColumnasH ( eph_h th) {
    bool resp = true;

    for (int i = 0; i < th.size(); i++) {
        resp = resp && (th[i].size()==FILAS_HOGAR);
    }

    return resp;
}

bool hayIndividuosSinHogares ( eph_i ti, eph_h th ) {
    bool resp = false;

    for (int i = 0; i < ti.size(); i++) {
        resp = resp || !hayHogarConCodigo(th, ti[i][INDCODUSU]);
    }

    return resp;
}

bool hayHogarConCodigo ( eph_h th, dato c ) {
    bool resp = false;

    for (int i = 0; i < th.size(); i++) {
        resp = resp || th[i][HOGCODUSU] == c;
    }

    return resp;
}

bool hayHogaresSinIndividuos ( eph_i ti, eph_h th ) {
    bool resp = false;

    for (int i = 0; i < ti.size(); i++) {
        resp = resp || !hayIndividuoConCodigo(th, ti[i][HOGCODUSU]);
    }

    return resp;
}

bool hayIndividuoConCodigo ( eph_i ti, dato c ) {
    bool resp = false;

    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][INDCODUSU] == c) {
            resp = true;
        }
    }

    return resp;
}

bool hayRepetidosI ( eph_i ti ) {
    bool resp = false;

    for (int i = 0; i < ti.size(); i++) {
        for (int j = 0; j < ti.size(); j++) {
            if (i != j && mismoCodusuYComponente(ti[i], ti[j])) {
                resp = true;
            }
        }
    }

    return resp;
}

bool mismoCodusuYComponente ( individuo i1, individuo i2 ) {
    return (i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE]);
}

bool hayRepetidosH ( eph_h th ) {
    bool resp = false;

    for (int i = 0; i < th.size(); i++) {
        for (int j = 0; j < th.size(); j++) {
            if (i != j && th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                resp = true;
            }
        }
    }

    return resp;
}

bool mismoAnioYTrimestre ( eph_i ti, eph_h th ) {
    bool resp = true;

    for (int i = 1; i < ti.size(); i++) {
        resp = resp && (ti[i][INDANIO] == ti[i-1][INDANIO] && ti[i][INDTRIMESTRE] == ti[i-1][INDTRIMESTRE]);
    }
    for (int i = 1; i < th.size(); i++) {
        resp = resp && (th[i][HOGANIO] == th[i-1][HOGANIO] && th[i][HOGTRIMESTRE] == th[i-1][HOGTRIMESTRE]);
    }

    if (!ti.empty() && !th.empty()) {
        resp = resp && (th[0][HOGANIO] == ti[0][INDANIO] && th[0][HOGTRIMESTRE] == ti[0][INDTRIMESTRE]);
    }

    return resp;
}

bool menosDe21MiembrosPorHogar ( eph_h th, eph_i ti ) {
    bool resp = true;

    for (int i = 0; i < th.size(); i++) {
        if (cantHabitantes(th[i], ti) >= 21) {
            resp = false;
        }
    }

    return resp;
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
    bool resp = true;

    for (int i = 0; i < th.size(); i++) {
        resp = resp && (th[i][IV2] >= th[i][II2]);
    }

    return resp;
}

bool valoresEnRangoI( eph_i ti ) {
    bool resp = true;

    for (int i = 0; i < ti.size(); i++) {
        resp = resp && individuoValido(ti[i]);
    }

    return resp;
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
    bool resp = true;

    for (int i = 0; i < th.size(); i++) {
        resp = resp && hogarValido(th[i]);
    }

    return resp;
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
    int hogaresValidos = 0;
    int hogaresConHC = 0;

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