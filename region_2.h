#ifndef REGION_2_H
#define REGION_2_H

#include "common.h"

double Region_2_v_pT(double p, double T);
double Region_2_s_pT(double p, double T);
double Region_2_h_pT(double p, double T);
double Region_2_g_pT(double p, double T);

double Boundry_2bc_p_h(double h);
double Boundry_2bc_h_p(double p);

ThermoState Region_2_pT(double p,double T);
ThermoState Region_2_ph(double p,double h);
ThermoState Region_2_ps(double p,double s);
ThermoState Region_2_hs(double h,double s);

#endif // REGION_2_H
