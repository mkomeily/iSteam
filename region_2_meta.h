#ifndef REGION_2_META_H
#define REGION_2_META_H

#include "common.h"

double Region_2_meta_v_pT(double p, double T);
double Region_2_meta_s_pT(double p, double T);
double Region_2_meta_h_pT(double p, double T);
double Region_2_meta_g_pT(double p, double T);

ThermoState Region_2_meta_pT(double p,double T);

#endif // REGION_2_META_H
