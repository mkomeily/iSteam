#include "region_5.h"
#include "common.h"
#include <QtMath>

static double Region_5_r(double Pi, double Tau);
static double Region_5_rPi(double Pi, double Tau);
static double Region_5_rPiPi(double Pi, double Tau);
static double Region_5_rTau(double Pi, double Tau);
static double Region_5_rTauTau(double Pi, double Tau);
static double Region_5_rPiTau(double Pi, double Tau);
static double Region_5_o(double Pi, double Tau);
static double Region_5_oTau(double Tau);
static double Region_5_oTauTau(double Tau);
static double Region_5_(double pi, double tau);

const Jn_Data Region_5_g_pT_Ideal_Data[] = {
     {0,	-0.13179983674201E+02}
    ,{1,	0.68540841634434E+01}
    ,{-3,   -0.24805148933466E-01}
    ,{-2,	0.36901534980333E+00}
    ,{-1,	-0.31161318213955E+01}
    ,{2,	-0.32961626538918E+00}
};

const IJn_Data Region_5_g_pT_Residual_Data[] = {
     {1,	1,	0.15736404855259E-02}
    ,{1,	2,	0.90153761673944E-03}
    ,{1,	3,	-0.50270077677648E-02}
    ,{2,	3,	0.22440037409485E-05}
    ,{2,	9,	-0.41163275453471E-05}
    ,{3,	7,	0.37919454822955E-07}
};

double Region_5_Gamar(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Residual_Data[i].n * qPow(Pi,Region_5_g_pT_Residual_Data[i].I) * qPow(Tau,Region_5_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_5_GamarPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Residual_Data[i].n * Region_5_g_pT_Residual_Data[i].I * qPow(Pi,Region_5_g_pT_Residual_Data[i].I - 1) * qPow(Tau,Region_5_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_5_GamarPiPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
    sum += Region_5_g_pT_Residual_Data[i].n * Region_5_g_pT_Residual_Data[i].I * (Region_5_g_pT_Residual_Data[i].I -1) * qPow(Pi,Region_5_g_pT_Residual_Data[i].I - 2) * qPow(Tau,Region_5_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_5_GamarTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Residual_Data[i].n * qPow(Pi,Region_5_g_pT_Residual_Data[i].I) * Region_5_g_pT_Residual_Data[i].J * qPow(Tau,Region_5_g_pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_5_GamarTauTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Residual_Data[i].n * qPow(Pi,Region_5_g_pT_Residual_Data[i].I) * Region_5_g_pT_Residual_Data[i].J * (Region_5_g_pT_Residual_Data[i].J - 1) * qPow(Tau,Region_5_g_pT_Residual_Data[i].J - 2);
    }
    return sum;
}
double Region_5_GamarPiTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Residual_Data[i].n * Region_5_g_pT_Residual_Data[i].I * qPow(Pi,Region_5_g_pT_Residual_Data[i].I - 1) * Region_5_g_pT_Residual_Data[i].J * Region_5_g_pT_Residual_Data[i].J * qPow(Tau,Region_5_g_pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_5_Gamao(double Pi,double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Ideal_Data[i].n * qPow(Tau,Region_5_g_pT_Ideal_Data[i].J);
    }
    sum += qLn(Pi);
    return sum;
}
double Region_5_GamaoTau(double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Ideal_Data[i].n * Region_5_g_pT_Ideal_Data[i].J * qPow(Tau,Region_5_g_pT_Ideal_Data[i].J - 1);
    }
    return sum;
}
double Region_5_GamaoTauTau(double Tau){
    double sum = 0;
    for (int i=0; i<6 ; i++){
        sum += Region_5_g_pT_Ideal_Data[i].n * Region_5_g_pT_Ideal_Data[i].J * (Region_5_g_pT_Ideal_Data[i].J - 1) * qPow(Tau,Region_5_g_pT_Ideal_Data[i].J - 2);
    }
    return sum;
}
double Region_5_GamaoPi(double Pi){
    double result = 0;
    result = 1 / Pi;
    return result;
}
double Region_5_GamaoPiPi(double Pi){
    double result = 0;
    result = -1 / qPow(Pi,2);
    return result;
}
double Region_5_GamaoPiTau(){
    return 0;
}
double Region_5_Gama(double Pi, double Tau){
    double result = 0;
    result = Region_5_Gamao(Pi,Tau) + Region_5_Gamar(Pi,Tau);
    return result;
}
double Region_5_v_pT(double p, double T){
    double Pi = p / Region_5_g_pT_p_Star;
    double Tau = Region_5_g_pT_T_Star / T;
    return (Pi * (Region_5_GamaoPi(Pi) + Region_5_GamarPi(Pi,Tau)) * (R * T / p) * 1000);
}
double Region_5_s_pT(double p, double T){
    double Pi = p / Region_5_g_pT_p_Star;
    double Tau = Region_5_g_pT_T_Star / T;
    return ((Tau * (Region_5_GamaoTau(Tau) + Region_5_GamarTau(Pi,Tau)) - Region_5_Gama(Pi,Tau)) * R);
}
double Region_5_h_pT(double p, double T){
    double Pi = p / Region_5_g_pT_p_Star;
    double Tau = Region_5_g_pT_T_Star / T;
    return ((Tau * (Region_5_GamaoTau(Tau) + Region_5_GamarTau(Pi,Tau))) * (R * T));
}
double Region_5_g_pT(double p, double T){
    double result = 0;
    double Pi = p / Region_5_g_pT_p_Star;
    double Tau = Region_5_g_pT_T_Star / T;
    result = Region_5_Gama(Pi,Tau) * R * T;
    return result;
}
ThermoState Region_5_pT(double p,double T){
    ThermoState state;
    state.p = p;
    state.T = T;
    state.v = Region_5_v_pT(p,T);
    state.h = Region_5_h_pT(p,T);
    state.s = Region_5_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Region 5";
    state.phase = findPhase(state);
    return state;
}
