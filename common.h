#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include "math.h"
#include <QtMath>
#include <QPoint>

const double eps_T = 0.00001;
const double eps_p = 0.00001;

const double R = 0.461526;
const double T_Critical = 647.096; //K
const double p_Critical = 22.064 * qPow(10,6); //Pa
const double s_Critical = 4.41202148223476; //kJ / (kg * K)
const double Rho_Critical = 322;  //kg / m³
const double T_TriplePoint = 273.16; //K
const double p_TriplePoint = 611.657 ; //Pa

//Region 1
const double Region_1_g_pT_T_Min = 273.15; //K
const double Region_1_g_pT_T_Max = 623.15; //K
const double Region_1_g_pT_p_Min = 611.657 ; //Pa
const double Region_1_g_pT_p_Max = 100 * qPow(10,6); //Pa
const double Region_1_g_pT_p_Star = 16.53 * qPow(10,6); //Pa
const double Region_1_g_pT_T_Star = 1386; //K

const double Region_1_T_ph_h_Star = 2500; //kJ
const double Region_1_T_ph_p_Star = 1 * qPow(10,6); //Pa
const double Region_1_T_ph_T_Star = 1; //K

const double Region_1_T_ps_p_Star = 1 * qPow(10,6); //Pa
const double Region_1_T_ps_s_Star = 1; //kJ / (kg * K)
const double Region_1_T_ps_T_Star = 1; //K

const double Region_1_p_hs_p_Star = 100 * qPow(10,6); //Pa
const double Region_1_p_hs_s_Star = 7.6; //kJ / (kg * K)
const double Region_1_p_hs_h_Star = 3400; //KJ

//Region 2
const double Region_2_g_pT_T_Min = 273.15; //K
const double Region_2_g_pT_T_Max = 1073.15; //K
const double Region_2_g_pT_p_Min = 0; //Pa
const double Region_2_g_pT_p_Max = 100 * qPow(10,6); //Pa
const double Region_2_g_pT_p_Star = 1 * qPow(10,6); //Pa
const double Region_2_g_pT_T_Star = 540; //K

const double Region_2_T_ph_h_Star = 2000; //kJ / kg
const double Region_2_T_ph_p_Star = 1 * qPow(10,6); //Pa
const double Region_2_T_ph_T_Star = 1; //K

const double Boundry_2bc_p_Star= 1 * qPow(10,6); //Pa
const double Boundry_2bc_h_Star= 1; //kJ / kg

const double Boundry_2bc_s = 5.85; //kJ / (kg * K)

const double Region_2a_T_ps_s_Star = 2; //kJ / (kg * K)
const double Region_2b_T_ps_s_Star = 0.7853; //kJ / (kg * K)
const double Region_2c_T_ps_s_Star = 2.9251; //kJ / (kg * K)
const double Region_2_T_ps_p_Star = 1 * qPow(10,6); //Pa
const double Region_2_T_ps_T_Star = 1; //K

const double Region_2a_p_hs_p_Star = 4 * qPow(10,6); //Pa
const double Region_2a_p_hs_s_Star = 12; //kJ / (kg * K)
const double Region_2a_p_hs_h_Star = 4200; //KJ
const double Region_2b_p_hs_p_Star = 100 * qPow(10,6); //Pa
const double Region_2b_p_hs_s_Star = 7.9; //kJ / (kg * K)
const double Region_2b_p_hs_h_Star = 4100; //KJ
const double Region_2c_p_hs_p_Star = 100 * qPow(10,6); //Pa
const double Region_2c_p_hs_s_Star = 5.9; //kJ / (kg * K)
const double Region_2c_p_hs_h_Star = 3500; //KJ

//Region 2 Meta
const double Region_2_meta_g_pT_p_Star = 1 * qPow(10,6); //Pa
const double Region_2_meta_g_pT_T_Star = 540; //K

//Region 3
const double Region_3_f_RhoT_Rho_Star = Rho_Critical;
const double Region_3_f_RhoT_T_Star = T_Critical;
const double Region_3_f_RhoT_T_Min = 623.15; //K
const double Region_3_f_RhoT_T_Max = 863.15; //K
const double Region_3_f_RhoT_p_Max = 100 * qPow(10,6); //Pa

const double Boundry_3ab_p_Star = 1 * qPow(10,6); //Pa
const double Boundry_3ab_h_Star = 1; //kJ / kg

const double Region_3a_T_ph_h_Star = 2300; //kJ / Kg
const double Region_3a_T_ph_p_Star = 100 * qPow(10,6); //Pa
const double Region_3a_T_ph_T_Star = 760; //K

const double Region_3b_T_ph_h_Star = 2800; //kJ / kg
const double Region_3b_T_ph_p_Star = 100 * qPow(10,6); //Pa
const double Region_3b_T_ph_T_Star = 860; //K

const double Region_3a_v_ph_h_Star = 2100; //kJ / kg
const double Region_3a_v_ph_p_Star = 100 * qPow(10,6); //Pa
const double Region_3a_v_ph_v_Star = 0.0028; //m³ / kg

const double Region_3b_v_ph_h_Star = 2800; //kJ / kg
const double Region_3b_v_ph_p_Star = 100 * qPow(10,6); //Pa
const double Region_3b_v_ph_v_Star = 0.0088; //m³ / kg

const double Boundry_3ab_s = s_Critical; //kJ / (kg * K)

const double Region_3a_T_ps_s_Star = 4.4; //kJ / (kg * K)
const double Region_3a_T_ps_p_Star = 100 * qPow(10,6); //Pa
const double Region_3a_T_ps_T_Star = 760; //K

const double Region_3b_T_ps_s_Star = 5.3; //kJ / (kg * K)
const double Region_3b_T_ps_p_Star = 100 * qPow(10,6); //Pa
const double Region_3b_T_ps_T_Star = 860; //K

const double Region_3a_v_ps_s_Star = 4.4; //kJ / (kg * K)
const double Region_3a_v_ps_p_Star = 100 * qPow(10,6); //Pa
const double Region_3a_v_ps_v_Star = 0.0028; //m³ / kg

const double Region_3b_v_ps_s_Star = 5.3; //kJ / (kg * K)
const double Region_3b_v_ps_p_Star = 100 * qPow(10,6); //Pa
const double Region_3b_v_ps_v_Star = 0.0088; //m³ / kg

const double Boundry_3sub_pT_p_Star= 1 * qPow(10,6); //Pa
const double Boundry_3sub_pT_T_Star= 1; //K
const double Boundry_dTetadPi_c= 3.727888004; // at Page 111

const double Region_3a_p_hs_s_Star = 4.4; //kJ / (kg * K)
const double Region_3a_p_hs_p_Star = 99 * qPow(10,6); //Pa
const double Region_3a_p_hs_h_Star = 2300; //KJ
const double Region_3b_p_hs_s_Star = 5.3; //kJ / (kg * K)
const double Region_3b_p_hs_p_Star = 16.6 * qPow(10,6); //Pa
const double Region_3b_p_hs_h_Star = 2800; //KJ

//Region 4
const double Region_4_T_Sat_hs_h_Star = 2800;
const double Region_4_T_Sat_hs_s_Star = 9.2;
const double Region_4_T_Sat_hs_T_Star = 550;

const double Region_4_h_f_1_s_s_Star = 3.8;
const double Region_4_h_f_1_s_h_Star = 1700;

const double Region_4_h_f_3a_s_s_Star = 3.8;
const double Region_4_h_f_3a_s_h_Star = 1700;

const double Region_4_h_g_2c3b_s_s_Star = 5.9;
const double Region_4_h_g_2c3b_s_h_Star = 2800;

const double Region_4_h_g_2ab_s_s1_Star = 5.21;
const double Region_4_h_g_2ab_s_s2_Star = 9.2;
const double Region_4_h_g_2ab_s_h_Star = 2800;

//Intersection

const double Intersection_T3cd_p_pSat_T = 634.659; //K
const double Intersection_T3qu_p_pSat_T = 643.15; //K

//Region 5
const double Region_5_g_pT_T_Min = 1073.15; //K
const double Region_5_g_pT_T_Max = 2273.16; //K
const double Region_5_g_pT_p_Min = 0; //Pa
const double Region_5_g_pT_p_Max = 50 * qPow(10,6); //Pa
const double Region_5_g_pT_p_Star = 1 * qPow(10,6); //Pa
const double Region_5_g_pT_T_Star = 1000; //K

typedef struct ThermoState{
    double p;
    double p_Sat;
    double T;
    double T_Sat;
    double v;
    double v_Fluid;
    double v_Gas;
    double Rho;
    double h;
    double h_Fluid;
    double h_Gas;
    double s;
    double s_Fluid;
    double s_Gas;
    double x;
    QString region;
    QString sub;
    QString phase;
}ThermoState;

typedef struct IJn_Data{
    int I, J;
    double n;
} IJn_Data;

typedef struct IJn_Data2{
    double I, J;
    double n;
} IJn_Data2;

typedef struct SubRegions_Data{
    char sub;
    double v_Star, p_Star , T_Star;
    int N;
    double a,b,c,d,e;
} SubRegions_Data;

typedef struct Jn_Data{
    int J;
    double n;
} Jn_Data;

typedef struct In_Data{
    int I;
    double n;
} In_Data;

typedef struct Line{
    double A;
    double B;
    double C;
} Line;

typedef struct Point{
    double X;
    double Y;
} Point;
typedef struct Triangle{
    Point A;
    Point B;
    Point C;
} Triangle;

QString htmlMaker(ThermoState state);
QString cssMaker();

double Pa_to_MPa(double p);
double MPa_to_Pa(double p);
double Pa_to_kPa(double p);
double kPa_to_Pa(double p);

double C_to_K(double c);
double K_to_C(double k);

int findRegion_pT(double p, double T);
int findRegion_ph(double p, double h);
int findRegion_ps(double p, double s);
int findRegion_hs(double h, double s);

ThermoState calcState_pT_Region(double p,double T,int region);
ThermoState calcState_ph_Region(double p,double h,int region);
ThermoState calcState_ps_Region(double p,double s,int region);
ThermoState calcState_hs_Region(double h,double s,int region);

Line makeLine(Point A,Point B);
double toLine(Line line, Point X);
QString findPhase(ThermoState state);
bool isInsideCriticalTriangle(Point p);

#endif // COMMON_H
