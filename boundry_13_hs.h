#ifndef BOUNDRY_13_H_S_H
#define BOUNDRY_13_H_S_H

#include <QtMath>
#include "common.h"

const IJn_Data Boundry_13_h_s_Data[6] = {
     {0 ,0      ,0.913965547600543E+00}
    ,{1 ,-2     ,-0.430944856041991E-04}
    ,{1 ,2      ,0.603235694765419E+02}
    ,{3 ,-12    ,0.117518273082168E-17}
    ,{5 ,-4     ,0.220000904781292E+00}
    ,{6 ,-3     ,-0.690815545851641E+02}
};

const double Boundry_13_h_s_h_Star = 1700; // kJ / kg
const double Boundry_13_h_s_s_Star = 3.8; // kJ / (kg * K)
double Boundry_13_h_s(double s);

#endif // BOUNDRY_13_H_S_H
