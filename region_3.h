#ifndef REGION_3_H
#define REGION_3_H

#include "common.h"

double Region_3_p_RhoT(double Rho, double T);
double Region_3_s_RhoT(double Rho, double T);
double Region_3_h_RhoT(double Rho, double T);
double Region_3_f_RhoT(double Rho, double T);

double Boundry_3ab_T_p(double p);
double Boundry_3cd_T_p(double p);
double Boundry_3ef_T_p(double p);
double Boundry_3gh_T_p(double p);
double Boundry_3ij_T_p(double p);
double Boundry_3jk_T_p(double p);
double Boundry_3mn_T_p(double p);
double Boundry_3op_T_p(double p);
double Boundry_3qu_T_p(double p);
double Boundry_3rx_T_p(double p);
double Boundry_3uv_T_p(double p);
double Boundry_3wx_T_p(double p);

double Region_3c_v_pT(double p, double T);
double Region_3t_v_pT(double p, double T);
double Region_3s_v_pT(double p, double T);
double Region_3u_v_pT(double p, double T);
double Region_3x_v_pT(double p, double T);
double Region_3y_v_pT(double p, double T);
double Region_3z_v_pT(double p, double T);

ThermoState Region_3_RhoT(double Rho,double T);
ThermoState Region_3_pT(double p,double T);
ThermoState Region_3_ph(double p,double h);
ThermoState Region_3_ps(double p,double s);
ThermoState Region_3_hs(double h,double s);

#endif // REGION_3_H
