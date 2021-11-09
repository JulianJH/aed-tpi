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
        resp = (float) hogaresConHC/hogaresValidos;
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

bool suHogarTieneEspaciosReservadosParaElTrabajo ( individuo i , eph_h th ) {
    bool tieneEspacioParaTrabajo = false;
    for (int j = 0 ; j < th.size(); j++) {
        if (esSuHogar(th[j],i)) {
            tieneEspacioParaTrabajo = tieneEspaciosReservadosParaElTrabajo(th[j]);
        }
    }
    return tieneEspacioParaTrabajo;
}

bool esDeCiudadGrande ( hogar h ) {
    return (h[MAS_500] == 1);
}

int trimestre ( eph_i ti ) {
    return ti[0][INDTRIMESTRE];
}

bool individuoEnHogarValido ( individuo i , eph_h th ) {
    bool enHogarValido = false;
    for (int j = 0 ; j < th.size(); j++) {
        if (esSuHogar(th[j],i)) {
            enHogarValido = (esDeCiudadGrande(th[j]) && esCasaODepartamento(th[j]));
        }
    }
    return enHogarValido;
}

bool trabajaEnSuVivienda ( individuo i , eph_h th ) {
    return (realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i,th));
}

int cantidadDeIndividuosQueTrabajan ( eph_h th , eph_i ti ) {
    int res= 0;
    for (int k = 0 ; k < ti.size() ; k++) {
        if (trabaja(ti[k]) && individuoEnHogarValido(ti[k], th)) {
            res++;
        }
    }
    return res;
}

int cantIndividuosTrabajandoEnSuVivienda ( eph_h th , eph_i ti ) {
    int res= 0;
    for (int k = 0 ; k < ti.size() ; k++) {
        if (trabaja(ti[k]) && individuoEnHogarValido(ti[k], th) && trabajaEnSuVivienda(ti[k], th)) {
            res++;
        }
    }
    return res;
}

float proporcionTeleworking (eph_h th , eph_i ti ) {
    float res = 0;
    int cantQueTrabajan = cantidadDeIndividuosQueTrabajan(th,ti);

    if (cantQueTrabajan > 0) {
        res = (float) cantIndividuosTrabajandoEnSuVivienda(th, ti) / cantQueTrabajan;
    }

    return res;
}

bool tieneCasaPropia ( hogar h ) {
    return h[II7] == 1;
}

bool tieneCasaChica ( hogar h , eph_i ti ) {
    return cantHabitantes(h,ti) - 2 > h[II2];
}

void cambiarRegionesGBAaPampeana( eph_h & th ) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][REGION] == GBA) {
            th[i][REGION] = PAMPEANA;
        }
    }
}

hogar hogarDeIndividuo ( individuo i, eph_h th ) {
    for (int j = 0; j < th.size(); ++j) {
        if (esSuHogar(th[j],i)) {
            return th[j];
        }
    }
}

void concatenar ( vector<vector<dato>> & a, vector<vector<dato>> & b ) {
    a.insert(a.end(), b.begin(), b.end());
}

eph_i individuosEnHogar ( hogar h, eph_i ti ) {
    eph_i resp;
    for (int i = 0; i < ti.size(); ++i) {
        if (esSuHogar(h, ti[i])) {
            resp.push_back(ti[i]);
        }
    }
    return resp;
}

eph_i sacarHabitantesQueCumplen ( hogar h, eph_i & habitantes, vector <pair<int, dato>> busqueda ) {
    eph_i resp;
    for (int k = 0; k < habitantes.size(); ++k) {
        individuo i = habitantes[k];
        if (cumpleBusqueda(i, busqueda)) {
            resp.push_back(i);
            habitantes.erase(habitantes.begin() + k);
            k--;
        }
    }
    return resp;
}

bool cumpleBusqueda ( individuo i, vector <pair<int, dato>> busqueda ) {
    for (int k = 0; k < busqueda.size(); ++k) {
        pair < int, dato > criterio = busqueda[k];
        if (i[criterio.first] != criterio.second) {
            return false;
        }
    }
    return true;
}

vector<int> hogaresEnAnillosConcentricos (vector<int> distancias , pair<int, int> centro, eph_h th){
    vector<int> res;
    res.push_back(cantHogaresEnAnillo(0, distancias[0], centro, th));
    for (int i =0; i < distancias.size() -1; i++){
        res.push_back(cantHogaresEnAnillo(distancias[i], distancias[i+1], centro, th));
    }
    return res;
}

int  cantHogaresEnAnillo(int distDesde , int distHasta, pair<int, int> centro, eph_h th){
    int res = 0;
    for (int i =0; i < th.size();i++){
        if (hogarEnAnillo(distDesde, distHasta, centro, th[i])){
            res++;
        }
    }
    return res;
}

bool hogarEnAnillo(int distDesde, int distHasta , pair<int, int> centro, hogar h){
    float res1 = distanciaEuclideana(centro,h[HOGLATITUD], h[HOGLONGITUD]);
    return ( distDesde < res1 && res1 <= distHasta);
}

float distanciaEuclideana (pair<int,int> centro , int latitud , int longitud){
    return (float) sqrt(pow((centro.first - latitud),2) + pow((centro.second - longitud),2));
}

void ordenarHogaresPorRegionYCodusu( eph_h & th ) {
    // vector de listas de hogares agrupados por región (en orden ascendente)
    vector<eph_h> hogaresPorRegion(CANTIDAD_DE_REGIONES);

    for (int i = 0; i < th.size(); ++i) {
        switch (th[i][REGION]) {
            case GBA:
                hogaresPorRegion[0].push_back(th[i]);
                break;
            case NOA:
                hogaresPorRegion[1].push_back(th[i]);
                break;
            case NEA:
                hogaresPorRegion[2].push_back(th[i]);
                break;
            case CUYO:
                hogaresPorRegion[3].push_back(th[i]);
                break;
            case PAMPEANA:
                hogaresPorRegion[4].push_back(th[i]);
                break;
            case PATAGONIA:
                hogaresPorRegion[5].push_back(th[i]);
                break;
        }
    }

    th.clear();

    for (int r = 0; r < CANTIDAD_DE_REGIONES; ++r) {
        ordenarPorHogcodusu(hogaresPorRegion[r]);

        for (int i = 0; i < hogaresPorRegion[r].size(); ++i) {
            th.push_back(hogaresPorRegion[r][i]);
        }
    }

    return;
}

void ordenarPorHogcodusu( eph_h & th ) {
    for(int i = 0; i<th.size(); i++) {
        hogar h = th[i];
        int j = i;
        while(j > 0 && th[j-1][HOGCODUSU]>h[HOGCODUSU]) {
            th[j] = th[j-1];
            j--;
        }
        th[j] = h;
    }

    return;
}

void ordenarIndividuosSegunHogarYComponente ( eph_h & th, eph_i & ti ) {
    for(int i = 0; i<ti.size(); i++) {
        individuo ind = ti[i];
        int j = i;
        //Ordeno por orden de th
        while(j > 0 && !ordenCorrectoSegunHogares(ti[j-1], ind, th)) {
            ti[j] = ti[j-1];
            j--;
        }
        // Ordeno a los de un mismo hogar según su componente
        while(j > 0 && ti[j-1][INDCODUSU]==ind[INDCODUSU] && ti[j-1][COMPONENTE] > ind[COMPONENTE]) {
            ti[j] = ti[j-1];
            j--;
        }
        ti[j] = ind;
    }

    return;
}

bool ordenCorrectoSegunHogares ( individuo i1, individuo i2, eph_h & th ) {
    hogar h1 = hogarDeIndividuo(i1, th);
    hogar h2 = hogarDeIndividuo(i2, th);
    bool mismaRegion = (h1[REGION] == h2[REGION]);
    bool mismaRegionCodusuAsciende = mismaRegion && (i1[INDCODUSU] <= i2[INDCODUSU]);
    bool distintaRegionYAsciende = !mismaRegion && (h1[REGION] <= h2[REGION]);

    return (mismaRegionCodusuAsciende || distintaRegionYAsciende);
}

void ordenarPorIngresos( eph_h & th, eph_i & ti ) {
    for (int i = 0; i < th.size(); ++i) {
        int min = ingresos(th[i], ti);
        int indiceMin = i;
        for (int j = i; j < th.size(); ++j) {
            int temp = ingresos(th[j], ti);
            if (temp < min) {
                min = temp;
                indiceMin = j;
            }
        }
        swap(th[i], th[indiceMin]);
    }
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

vector<hogar> mayorMuestraHomogenea ( eph_h th, eph_i ti ) {
    vector<hogar> resp;
    for (int i = 0; i < th.size(); ++i) {
        vector<hogar> temp = mayorMuestraHomoDesde(i, th, ti);
        if (temp.size() > resp.size()) {
            resp = temp;
        }
    }
    return resp;
}

vector<hogar> mayorMuestraHomoDesde ( int i, eph_h th, eph_i ti ) {
    vector<hogar> resp;
    for (int j = i+1; j < th.size(); ++j) {
        int dif = ingresos(th[j], ti) - ingresos(th[i], ti);
        if (dif > 0) {
            vector<hogar> temp = mayorMuestraHomoDesdeConDif(i, dif, th, ti);
            if (temp.size() > resp.size()) {
                resp = temp;
            }
        }
    }
    return resp;
}

vector<hogar> mayorMuestraHomoDesdeConDif ( int i, int dif, eph_h th, eph_i ti ) {
    vector<hogar> resp = {th[i]};
    for (int k = i + 1; k < th.size(); ++k) {
        if (ingresos(th[k], ti) - ingresos(resp[resp.size() - 1], ti) == dif) {
            resp.push_back(th[k]);
        }
    }
    if (resp.size() >= 3) {
        return resp;
    }
    return {};
}
