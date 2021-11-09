#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;


TEST(ordenarRegionYCODUSUTEST, regionesDistintas) {

    eph_h th = {
        {334,  2017, 1, 1, 2, 0, 40, 3, 1, 2},
        {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
    };

    eph_i ti = {
        {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
        {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
        {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
        {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6}
    };

    eph_h th_esperado = {
        {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
        {334,  2017, 1, 1, 2, 0, 40, 3, 1, 2},
    };

    eph_i ti_esperado = {
        {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6},
        {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
        {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
        {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}

TEST(ordenarRegionYCODUSUTEST, mismasRegiones) {

    eph_h th = {
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {1060,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
    };

    eph_i ti = {
            {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {1060,  2017, 1, 1, 0, 2, 20, 1,  3, 7000,  1},
            {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6}
    };

    eph_h th_esperado = {
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {1060,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti_esperado = {
            {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6},
            {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {1060,  2017, 1, 1, 0, 2, 20, 1,  3, 7000,  1},
    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}

TEST(ordenarRegionYCODUSUTEST, cobertura100) {

    eph_h th = {
            {334,  2017, 1, 1, 2, 0, 40, 3, 1, 2},
            {341,  2017, 1, 1, 2, 0, 41, 3, 1, 2},
            {342,  2017, 1, 1, 2, 0, 42, 3, 1, 2},
            {343,  2017, 1, 1, 2, 0, 43, 3, 1, 2},
            {344,  2017, 1, 1, 2, 0, 44, 3, 1, 2},
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {123,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
    };

    eph_i ti = {
            {123,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {123,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {341,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {342,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {343,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {344,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6},
            {123,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6}
    };

    eph_h th_esperado = {
            {123,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {334,  2017, 1, 1, 2, 0, 40, 3, 1, 2},
            {341,  2017, 1, 1, 2, 0, 41, 3, 1, 2},
            {342,  2017, 1, 1, 2, 0, 42, 3, 1, 2},
            {343,  2017, 1, 1, 2, 0, 43, 3, 1, 2},
            {344,  2017, 1, 1, 2, 0, 44, 3, 1, 2},
    };

    eph_i ti_esperado = {
            {123,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6},
            {123,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {123,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {960,  2017, 1, 1, 0, 2, 19, 0,  0, 0,     6},
            {960,  2017, 2, 1, 0, 2, 20, 1,  3, 7000,  1},
            {960,  2017, 3, 1, 1, 2, 51, 1,  4, 1280,  1},
            {334,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {341,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {342,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {343,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
            {344,  2017, 1, 1, 0, 1, 36, 1,  3, 16300, 1},
    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}
