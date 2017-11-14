#ifndef REGION_1_H
#define REGION_1_H

#include "common.h"

//State as function of pT
double Region_1_v_pT(double p, double T);
double Region_1_s_pT(double p, double T);
double Region_1_h_pT(double p, double T);
double Region_1_g_pT(double p, double T);
ThermoState Region_1_pT(double p,double T);

//State as function of ph
double Region_1_T_ph(double p, double h);
ThermoState Region_1_ph(double p,double h);

//State as function of ps
double Region_1_T_ps(double p, double s);
ThermoState Region_1_ps(double p,double s);

double Region_1_T_hs(double h, double s);
ThermoState Region_1_hs(double h,double s);

#endif // REGION_1_H
