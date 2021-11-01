#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;


TEST(costoSubsidioMejoraTEST, noHayCasas) {
    eph_h th = {
        {15726,2018,3,336630,646391,2,40,1,1,3,3,2},     // no es propia
        {188,2018,3,325187,635309,3,40,0,1,3,2,2},       // no es propia
        {8596,2018,3,336582,646678,2,40,1,1,1,1,2},      // alcanzan las habs
        {11867,2018,3,320329,630940,1,43,1,1,3,2,2}      // alcanzan las habs
    };

    eph_i ti = {
        {15726,2018,1,0,3,2,50,1,3,10000,0},
        {15726,2018,2,0,3,1,47,1,3,10000,5},
        {15726,2018,3,0,3,1,27,1,1,18000,8},
        {15726,2018,4,0,3,1,26,1,3,16000,5},
        {15726,2018,5,0,3,2,19,0,0,0,10},
        {15726,2018,6,0,3,2,3,0,0,0,10},
        {188,2018,1,0,3,2,60,0,0,6000,10},
        {188,2018,2,0,3,1,71,0,0,7000,10},
        {188,2018,3,0,3,1,39,1,2,2000,9},
        {188,2018,4,0,3,1,36,0,0,0,10},
        {188,2018,5,0,3,1,29,1,2,1000,8},
        {188,2018,6,0,3,1,10,0,0,0,10},
        {8596,2018,1,0,3,2,56,1,3,18000,1},
        {11867,2018,2,1,3,1,26,1,3,21000,1},
        {11867,2018,3,0,3,2,22,0,2,20000,10}
    };

    int monto = 10;

    int res = costoSubsidioMejora(th, ti, monto);

    EXPECT_EQ(0, res);
}

TEST(costoSubsidioMejoraTEST, casoFacil) {
    eph_h th = {
        {15726,2018,3,336630,646391,1,40,1,1,3,3,2},     // propia, no alcanzan
        {188,2018,3,325187,635309,1,40,0,1,3,2,2},       // propia, no alcanzan
        {11867,2018,3,320329,630940,1,43,1,1,3,2,2},     // propia, alcanzan
        {14914,2018,3,321889,631412,2,43,0,2,3,1,2},     // no propia, no alcanzan
    };

    eph_i ti = {
        {15726,2018,1,0,3,2,50,1,3,10000,0},
        {15726,2018,2,0,3,1,47,1,3,10000,5},
        {15726,2018,3,0,3,1,27,1,1,18000,8},
        {15726,2018,4,0,3,1,26,1,3,16000,5},
        {15726,2018,5,0,3,2,19,0,0,0,10},
        {15726,2018,6,0,3,2,3,0,0,0,10},
        {188,2018,1,0,3,2,60,0,0,6000,10},
        {188,2018,2,0,3,1,71,0,0,7000,10},
        {188,2018,3,0,3,1,39,1,2,2000,9},
        {188,2018,4,0,3,1,36,0,0,0,10},
        {188,2018,5,0,3,1,29,1,2,1000,8},
        {188,2018,6,0,3,1,10,0,0,0,10},
        {11867,2018,2,1,3,1,26,1,3,21000,1},
        {11867,2018,3,0,3,2,22,0,2,20000,10},
        {14914,2018,1,0,3,1,48,1,3,43000,1},
        {14914,2018,2,0,3,2,45,1,2,17000,6},
        {14914,2018,3,1,3,2,24,1,3,17000,1},
        {14914,2018,4,0,3,2,17,0,0,0,10}
    };

    int monto = 8;

    int res = costoSubsidioMejora(th, ti, monto);

    EXPECT_EQ(2*monto, res);
}

//TODO: Añadir test case para cobertura 100%