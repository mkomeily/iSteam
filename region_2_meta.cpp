#include "region_2_meta.h"
#include "common.h"
#include "math.h"
#include <QtMath>

static double Region_2_meta_Gamar(double Pi, double Tau);
static double Region_2_meta_GamarPi(double Pi, double Tau);
static double Region_2_meta_GamarPiPi(double Pi, double Tau);
static double Region_2_meta_GamarTau(double Pi, double Tau);
static double Region_2_meta_GamarTauTau(double Pi, double Tau);
static double Region_2_meta_GamarPiTau(double Pi, double Tau);
static double Region_2_meta_Gamao(double Pi, double Tau);
static double Region_2_meta_GamaoTau(double Tau);
static double Region_2_meta_GamaoTauTau(double Tau);
static double Region_2_meta_Gama(double pi, double tau);

const Jn_Data Region_2_meta__pT_Ideal_Data[] = {
     {0,	-0.96937268393049E+01}
    ,{1,	0.10087275970006E+02}
    ,{-5,	-0.56087911283020E-02}
    ,{-4,	0.71452738081455E-01}
    ,{-3,	-0.40710498223928E+00}
    ,{-2,	0.14240819171444E+01}
    ,{-1,	-0.43839511319450E+01}
    ,{2,	-0.28408632460772E+00}
    ,{3,	0.21268463753307E-01}
};




const IJn_Data Region_2_meta__pT_Residual_Data[] = {
     {1,0,-0.73362260186506E-02}
    ,{1,2,-0.88223831943146E-01}
    ,{1,5,-0.72334555213245E-01}
    ,{1,11,-0.40813178534455E-02}
    ,{2,1,0.20097803380207E-02}
    ,{2,7,-0.53045921898642E-01}
    ,{2,16,-0.7619040908697E-02}
    ,{3,4,-0.63498037657313E-02}
    ,{3,16,-0.86043093028588E-01}
    ,{4,7,0.7532158152277E-02}
    ,{4,10,-0.79238375446139E-02}
    ,{5,9,-0.22888160778447E-03}
    ,{5,10,-0.2645650148281E-02}
};

double Region_2_meta_Gamar(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
        sum += Region_2_meta__pT_Residual_Data[i].n * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I) * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_meta_GamarPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
        sum += Region_2_meta__pT_Residual_Data[i].n * Region_2_meta__pT_Residual_Data[i].I * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I - 1) * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_meta_GamarPiPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
    sum += Region_2_meta__pT_Residual_Data[i].n * Region_2_meta__pT_Residual_Data[i].I * (Region_2_meta__pT_Residual_Data[i].I -1) * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I - 2) * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_meta_GamarTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
        sum += Region_2_meta__pT_Residual_Data[i].n * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I) * Region_2_meta__pT_Residual_Data[i].J * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_2_meta_GamarTauTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
        sum += Region_2_meta__pT_Residual_Data[i].n * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I) * Region_2_meta__pT_Residual_Data[i].J * (Region_2_meta__pT_Residual_Data[i].J - 1) * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J - 2);
    }
    return sum;
}
double Region_2_meta_GamarPiTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<13 ; i++){
        sum += Region_2_meta__pT_Residual_Data[i].n * Region_2_meta__pT_Residual_Data[i].I * qPow(Pi,Region_2_meta__pT_Residual_Data[i].I - 1) * Region_2_meta__pT_Residual_Data[i].J * Region_2_meta__pT_Residual_Data[i].J * qPow((Tau - 0.5),Region_2_meta__pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_2_meta_Gamao(double Pi,double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_meta__pT_Ideal_Data[i].n * qPow(Tau,Region_2_meta__pT_Ideal_Data[i].J);
    }
    sum += qLn(Pi);
    return sum;
}
double Region_2_meta_GamaoTau(double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_meta__pT_Ideal_Data[i].n * Region_2_meta__pT_Ideal_Data[i].J * qPow(Tau,Region_2_meta__pT_Ideal_Data[i].J - 1);
    }
    return sum;
}
double Region_2_meta_GamaoTauTau(double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_meta__pT_Ideal_Data[i].n * Region_2_meta__pT_Ideal_Data[i].J * (Region_2_meta__pT_Ideal_Data[i].J - 1) * qPow(Tau,Region_2_meta__pT_Ideal_Data[i].J - 2);
    }
    return sum;
}
double Region_2_meta_GamaoPi(double Pi){
    double result = 0;
    result = 1 / Pi;
    return result;
}
double Region_2_meta_GamaoPiPi(double Pi){
    double result = 0;
    result = -1 / qPow(Pi,2);
    return result;
}
double Region_2_meta_GamaoPiTau(){
    return 0;
}
double Region_2_meta_Gama(double Pi, double Tau){
    double result = 0;
    result = Region_2_meta_Gamao(Pi,Tau) + Region_2_meta_Gamar(Pi,Tau);
    return result;
}
double Region_2_meta__pT(double p,double T){
    double result = 0;
    result = Region_2_meta_Gama(p,T) * R * T;
    return result;
}
double Region_2_meta_v_pT(double p, double T){
    double Pi = p / Region_2_meta_g_pT_p_Star;
    double Tau = Region_2_meta_g_pT_T_Star / T;
    return (Pi * (Region_2_meta_GamaoPi(Pi) + Region_2_meta_GamarPi(Pi,Tau)) * (R * T / p) * 1000);
}
double Region_2_meta_s_pT(double p, double T){
    double Pi = p / Region_2_meta_g_pT_p_Star;
    double Tau = Region_2_meta_g_pT_T_Star / T;
    return ((Tau * (Region_2_meta_GamaoTau(Tau) + Region_2_meta_GamarTau(Pi,Tau)) - Region_2_meta_Gama(Pi,Tau)) * R);
}
double Region_2_meta_h_pT(double p, double T){
    double Pi = p / Region_2_meta_g_pT_p_Star;
    double Tau = Region_2_meta_g_pT_T_Star / T;
    return ((Tau * (Region_2_meta_GamaoTau(Tau) + Region_2_meta_GamarTau(Pi,Tau))) * (R * T));
}
ThermoState Region_2_meta_pT(double p,double T){
    ThermoState state;
    state.p = p;
    state.T = T;
    state.v = Region_2_meta_v_pT(p,T);
    state.h = Region_2_meta_h_pT(p,T);
    state.s = Region_2_meta_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.region = "Region 2 Metastable";
    state.phase = findPhase(state);
    return state;
}





