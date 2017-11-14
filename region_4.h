#ifndef REGION_4_H
#define REGION_4_H

#include "common.h"

const double Region_4_Sat_pT_n[10] = {
                                     0.11670521452767E+04
                                    , -0.72421316703206E+06
                                    , -0.17073846940092E+02
                                    , 0.12020824702470E+05
                                    , -0.32325550322333E+07
                                    , 0.14915108613530E+02
                                    , -0.48232657361591E+04
                                    , 0.40511340542057E+06
                                    , -0.23855557567849E+00
                                    , 0.65017534844798E+03
                                      };

const double Region_4_p_Star = 1 * qPow(10,6); // Pa
const double Region_4_T_Star = 1; // K

double  Region_4_p_Sat_T(double T);
double  Region_4_T_Sat_p(double p);

double  Region_4_Rhof_T(double T);
double  Region_4_Rhog_T(double T);

double  Region_4_v_Tx(double T, double x);
double  Region_4_h_Tx(double T, double x);
double  Region_4_s_Tx(double T, double x);

double  Region_4_x_Th(double T, double h);
double  Region_4_x_Ts(double T, double s);
double  Region_4_x_Tv(double T, double v);

ThermoState Region_4_Tx(double T,double x);
ThermoState Region_4_px(double p,double x);
ThermoState Region_4_Th(double T,double h);
ThermoState Region_4_ph(double p,double h);
ThermoState Region_4_ps(double T,double s);
ThermoState Region_4_hs(double h,double s);
ThermoState Region_4_Ts(double p,double s);
ThermoState Region_4_pv(double p,double v);
ThermoState Region_4_Tv(double T,double v);

//double Region_4_dpsatdT_T(double T);

double Region_4_T_Sat_hs(double h,double s);
double Region_4_p_Sat_hs(double h,double s);
double Region_4_x_hs(double h,double s);
double Region_4_h_s(double s);
double Region_4_h_f_1_s(double s);
double Region_4_h_f_3a_s(double s);
double Region_4_h_g_2c3b_s(double s);
double Region_4_h_g_2ab_s(double s);


#endif // REGION_4_H

