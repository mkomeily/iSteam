#ifndef BOUNDRY_23_H
#define BOUNDRY_23_H

#include "common.h"
#include <QtMath>

const double Boundry_23_n[5] = { 0.34805185628969E+03,
                                 -0.11671859879975E+01
                                 , 0.10192970039326E-02
                                 , 0.57254459862746E+03
                                 , 0.13918839778870E+02};

const double Boundry_23_p_Star = 1 * qPow(10,6); // Pa
const double Boundry_23_T_Star = 1; // K

const double Boundry_23_T_hs_s_Star = 5.3;
const double Boundry_23_T_hs_h_Star = 3000;
const double Boundry_23_T_hs_T_Star = 900;

const double Boundry_23_hs_s_Min = 5.048096828; // kj / (kg * K)
const double Boundry_23_hs_s_Max = 5.260578707; // kj / (kg * K)

const double Boundry_23_hs_h_Min = 2563.592004; // kj / kg
const double Boundry_23_hs_h_Max = 2812.942061; // kj / kg

double Boundry_23_T_hs(double h,double s);

double Boundry_23_p_T(double T);
double Boundry_23_T_p(double p);

double Boundry_23_theta(double T);
double Boundry_23_pi(double p);

#endif //BOUNDRY_23_H
