#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = false;

	resp = esValida(th, ti);
	
	return resp;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    int maxHabsEnRegion = maxCantHabitacionesEnCasaEnRegion(th, region);
	vector < int > resultado(maxHabsEnRegion, 0);

    for (int i = 0; i < th.size(); i++) {
        if (esCasa(th[i]) && th[i][REGION] == region) {
            int habs = th[i][IV2];
            resultado[habs-1]++; // habs-1 ya que los indices de resultado empiezan en 0
        }
    }
	
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {
            make_pair(1,-1.0),
            make_pair(40, -1.0),
            make_pair(41, -1.0),
            make_pair(42, -1.0),
            make_pair(43, -1.0),
            make_pair(44, -1.0)
    };

    for (int i = 0; i < resp.size(); i++) {
        int region = resp[i].first;
        resp[i].second = proporcionDeCasasConHC(th, ti, region);
    }
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	
	return (proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i));
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp = 0;

	for (int i = 0; i < th.size(); i++){
	    if (tieneCasaPropia(th[i]) && tieneCasaChica(th[i] ,ti)){
	        resp += monto;
	    }
	}
	
  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
