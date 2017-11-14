#include "region_1.h"
#include <QDebug>
//State as a function of pT

static double Region_1_Gama(double Pi, double Tau);
static double Region_1_GamaPi(double Pi, double Tau);
static double Region_1_GamaPiPi(double Pi, double Tau);
static double Region_1_GamaTau(double Pi, double Tau);
static double Region_1_GamaTauTau(double Pi, double Tau);
static double Region_1_GamaPiTau(double Pi, double Tau);

const IJn_Data Region_1_g_pT_Data[] = {
     {0,	-2,	0.14632971213167E+00}
    ,{0,	-1,	-0.84548187169114E+00}
    ,{0,   	0,	-0.37563603672040E+01}
    ,{0,	1,	0.33855169168385E+01}
    ,{0,	2,	-0.95791963387872E+00}
    ,{0,	3,	0.15772038513228E+00}
    ,{0,	4,	-0.16616417199501E-01}
    ,{0,	5,	0.81214629983568E-03}
    ,{1,	-9,	0.28319080123804E-03}
    ,{1,	-7,	-0.60706301565874E-03}
    ,{1,	-1,	-0.18990068218419E-01}
    ,{1,	0,	-0.32529748770505E-01}
    ,{1,	1,	-0.21841717175414E-01}
    ,{1,	3,	-0.52838357969930E-04}
    ,{2,	-3,	-0.47184321073267E-03}
    ,{2,	0,	-0.30001780793026E-03}
    ,{2,	1,	0.47661393906987E-04}
    ,{2,	3,	-0.44141845330846E-05}
    ,{2,	17,	-0.72694996297594E-15}
    ,{3,	-4,	-0.31679644845054E-04}
    ,{3,	0,	-0.28270797985312E-05}
    ,{3,	6,	-0.85205128120103E-09}
    ,{4,	-5,	-0.22425281908000E-05}
    ,{4,	-2,	-0.65171222895601E-06}
    ,{4,	10,	-0.14341729937924E-12}
    ,{5,	-8,	-0.40516996860117E-06}
    ,{8,	-11,	-0.12734301741641E-08}
    ,{8,	-6,	-0.17424871230634E-09}
    ,{21,	-29,	-0.68762131295531E-18}
    ,{23,	-31,	0.14478307828521E-19}
    ,{29,	-38,	0.26335781662795E-22}
    ,{30,	-39,	-0.11947622640071E-22}
    ,{31,	-40,	0.18228094581404E-23}
    ,{32,	-41,	-0.93537087292458E-25}
};

double Region_1_Gama(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (Region_1_g_pT_Data[i].n)*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I))*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J));
    }
    return sum;
}
double Region_1_GamaPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (-1 * Region_1_g_pT_Data[i].n * Region_1_g_pT_Data[i].I)*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I-1))*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J));
    }
    return sum;
}
double Region_1_GamaPiPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (Region_1_g_pT_Data[i].n * Region_1_g_pT_Data[i].I * (Region_1_g_pT_Data[i].I-1))*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I-2))*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J));
    }
    return sum;
}
double Region_1_GamaTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (Region_1_g_pT_Data[i].n)*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I))*(Region_1_g_pT_Data[i].J)*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J-1));
    }
    return sum;
}
double Region_1_GamaTauTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (Region_1_g_pT_Data[i].n)*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I))*(Region_1_g_pT_Data[i].J)*(Region_1_g_pT_Data[i].J-1)*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J-2));
    }
    return sum;
}
double Region_1_GamaPiTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0 ; i<34 ; i++){
        sum += (-1 * Region_1_g_pT_Data[i].n)*(Region_1_g_pT_Data[i].I)*(qPow((7.1 - Pi),Region_1_g_pT_Data[i].I-1))*(Region_1_g_pT_Data[i].J)*(qPow((Tau - 1.222),Region_1_g_pT_Data[i].J-1));
    }
    return sum;
}
double Region_1_g_pT(double p, double T){
    double result = 0;
    double Pi = p / Region_1_g_pT_p_Star;
    double Tau = Region_1_g_pT_T_Star / T;
    result = Region_1_Gama(Pi,Tau) * R * T;
    return result;
}
double Region_1_v_pT(double p, double T){
    double Pi = p / Region_1_g_pT_p_Star;
    double Tau = Region_1_g_pT_T_Star / T;
    return (((Pi * Region_1_GamaPi(Pi,Tau)) * R * T / p) * 1000);
}
double Region_1_s_pT(double p, double T){
    double Pi = p / Region_1_g_pT_p_Star;
    double Tau = Region_1_g_pT_T_Star / T;
    return ((Tau * Region_1_GamaTau(Pi,Tau) - Region_1_Gama(Pi,Tau)) * R);
}
double Region_1_h_pT(double p, double T){
    double Pi = p / Region_1_g_pT_p_Star;
    double Tau = Region_1_g_pT_T_Star / T;
    return ((Tau * Region_1_GamaTau(Pi,Tau)) * (R * T));
}
ThermoState Region_1_pT(double p,double T){
    ThermoState state;
    state.p = p;
    state.T = T;
    state.v = Region_1_v_pT(p,T);
    state.h = Region_1_h_pT(p,T);
    state.s = Region_1_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.region = "Regiron 1";
    state.x = 0;
    state.phase = findPhase(state);
    return state;
}

//State as a function of ph

const IJn_Data Region_1_T_ph_Data[] = {
     {0     , 0     , -0.23872489924521E+03}
    ,{0     , 1     , 0.40421188637945E+03}
    ,{0     , 2     , 0.11349746881718E+03}
    ,{0     , 6     , -0.58457616048039E+01}
    ,{0     , 22    , -0.1528548241314E-03}
    ,{0     , 32    , -0.10866707695377E-05}
    ,{1     , 0     , -0.13391744872602E+02}
    ,{1     , 1     , 0.43211039183559E+02}
    ,{1     , 2     , -0.54010067170506E+02}
    ,{1     , 3     , 0.30535892203916E+02}
    ,{1     , 4     , -0.65964749423638E+01}
    ,{1     ,10     , 0.93965400878363E-02}
    ,{1     ,32     , 0.1157364750534E-06}
    ,{2     ,10     ,-0.25858641282073E-04}
    ,{2     ,32     ,-0.40644363084799E-08}
    ,{3     ,10     ,0.66456186191635E-07}
    ,{3     ,32     ,0.80670734103027E-10}
    ,{4     ,32     ,-0.93477771213947E-12}
    ,{5     ,32     ,0.58265442020601E-14}
    ,{6     ,32     ,-0.15020185953503E-16}
};

double Region_1_T_ph(double p, double h){
    double Pi = p / Region_1_T_ph_p_Star;
    double Eta = h / Region_1_T_ph_h_Star;
    double sum =0;
    for (int i=0; i < 20; i++){
        sum += Region_1_T_ph_Data[i].n * qPow(Pi,Region_1_T_ph_Data[i].I) * qPow((Eta+1),Region_1_T_ph_Data[i].J);
    }
    return sum *= Region_1_T_ph_T_Star;
}

ThermoState Region_1_ph(double p,double h){
    ThermoState state;
    double T = Region_1_T_ph(p,h);
    state.p = p;
    state.h = h;
    state.T = T;
    state.v = Region_1_v_pT(p,T);
    state.s = Region_1_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 1";
    state.phase = findPhase(state);
    return state;
}

//State as a function of ps

const IJn_Data Region_1_T_ps_Data[] = {
     {0     , 0     , 174.78268058307}
    ,{0     , 1     , 34.806930892873}
    ,{0     , 2     , 6.5292584978455}
    ,{0     , 3     , 0.33039981775489}
    ,{0     , 11    , -1.9281382923196E-07}
    ,{0     , 31    , -2.4909197244573E-23}
    ,{1     , 0     , -0.26107636489332}
    ,{1     , 1     , 0.22592965981586}
    ,{1     , 2     , -0.064256463395226}
    ,{1     , 3     , 7.8876289270526E-03}
    ,{1     , 12    , 3.5672110607366E-10}
    ,{1     , 31    , 1.7332496994895E-24}
    ,{2     , 0     , 5.6608900654837E-04}
    ,{2     , 1     , -3.2635483139717E-04}
    ,{2     , 2     , 4.4778286690632E-05}
    ,{2     , 9     , -5.1322156908507E-10}
    ,{2     , 31    , -4.2522657042207E-26}
    ,{3     , 10    , 2.6400441360689E-13}
    ,{3     , 32    , 7.8124600459723E-29}
    ,{4     , 32    , -3.0732199903668E-31}
};

double Region_1_T_ps(double p, double s){
    double Pi = p / Region_1_T_ps_p_Star;
    double Sigma = s / Region_1_T_ps_s_Star;
    double sum =0;
    for (int i=0; i < 20; i++){
        sum += Region_1_T_ps_Data[i].n * qPow(Pi,Region_1_T_ps_Data[i].I) * qPow((Sigma+2),Region_1_T_ps_Data[i].J);
    }
    return sum *= Region_1_T_ps_T_Star;
}

ThermoState Region_1_ps(double p,double s){
    ThermoState state;
    double T = Region_1_T_ps(p,s);
    state.p = p;
    state.s = s;
    state.T = T;
    state.v = Region_1_v_pT(p,T);
    state.h = Region_1_h_pT(p,T);
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 1";
    state.phase = findPhase(state);
    return state;
}

//State as a function of hs

const IJn_Data Region_1_p_hs_Data[] = {
    {0, 0, -0.691997014660582}
    , {0, 1, -18.361254878756}
    , {0, 2, -9.28332409297335}
    , {0, 4, 65.9639569909906}
    , {0, 5, -16.2060388912024}
    , {0, 6, 450.620017338667}
    , {0, 8, 854.68067822417}
    , {0, 14, 6075.23214001162}
    , {1, 0, 32.6487682621856}
    , {1, 1, -26.9408844582931}
    , {1, 4, -319.9478483343}
    , {1, 6, -928.35430704332}
    , {2, 0, 30.3634537455249}
    , {2, 1, -65.0540422444146}
    , {2, 10, -4309.9131651613}
    , {3, 4, -747.512324096068}
    , {4, 1, 730.000345529245}
    , {4, 4, 1142.84032569021}
    , {5, 0, -436.407041874559}
    };

double Region_1_p_hs(double h, double s){
    double Eta = h / Region_1_p_hs_h_Star;
    double Sigma = s / Region_1_p_hs_s_Star;
    double sum =0;
    for (int i=0; i < 19; i++){
        sum += Region_1_p_hs_Data[i].n * qPow((Eta + 0.05),Region_1_p_hs_Data[i].I) * qPow((Sigma + 0.05),Region_1_p_hs_Data[i].J);
    }
    return sum *= Region_1_p_hs_p_Star;
}

ThermoState Region_1_hs(double h,double s){
    ThermoState state;
    double p = Region_1_p_hs(h,s);
    double T = Region_1_T_ph(p,h);
    state.p = p;
    state.s = s;
    state.T = T;
    state.v = Region_1_v_pT(p,T);
    state.h = h;
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 1";
    state.phase = findPhase(state);
    return state;
}
