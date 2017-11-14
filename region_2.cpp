#include "region_2.h"
#include "common.h"
#include <QtMath>
#include <QDebug>

//State as a function of pT

static double Region_2_Gamar(double Pi, double Tau);
static double Region_2_GamarPi(double Pi, double Tau);
static double Region_2_GamarPiPi(double Pi, double Tau);
static double Region_2_GamarTau(double Pi, double Tau);
static double Region_2_GamarTauTau(double Pi, double Tau);
static double Region_2_GamarPiTau(double Pi, double Tau);
static double Region_2_Gamao(double Pi, double Tau);
static double Region_2_GamaoTau(double Tau);
static double Region_2_GamaoTauTau(double Tau);
static double Region_2_Gama(double pi, double tau);

const Jn_Data Region_2_g_pT_Ideal_Data[] = {
     {0,	-0.96927686500217E+01}
    ,{1,	0.10086655968018E+02}
    ,{-5,	-0.56087911283020E-02}
    ,{-4,	0.71452738081455E-01}
    ,{-3,	-0.40710498223928E+00}
    ,{-2,	0.14240819171444E+01}
    ,{-1,	-0.43839511319450E+01}
    ,{2,	-0.28408632460772E+00}
    ,{3,	0.21268463753307E-01}
};

const IJn_Data Region_2_g_pT_Residual_Data[] = {
     {1,	0,	-0.17731742473213E-02}
    ,{1,	1,	-0.17834862292358E-01}
    ,{1,	2,	-0.45996013696365E-01}
    ,{1,	3,	-0.57581259083432E-01}
    ,{1,	6,	-0.50325278727930E-01}
    ,{2,	1,	-0.33032641670203E-04}
    ,{2,	2,	-0.18948987516315E-03}
    ,{2,	4,	-0.39392777243355E-02}
    ,{2,	7,	-0.43797295650573E-01}
    ,{2,	36,	-0.26674547914087E-04}
    ,{3,	0,	0.20481737692309E-07}
    ,{3,	1,	0.43870667284435E-06}
    ,{3,	3,	-0.32277677238570E-04}
    ,{3,	6,	-0.15033924542148E-02}
    ,{3,	35,	-0.40668253562649E-01}
    ,{4,	1,	-0.78847309559367E-09}
    ,{4,	2,	0.12790717852285E-07}
    ,{4,	3,	0.48225372718507E-06}
    ,{5,	7,	0.22922076337661E-05}
    ,{6,	3,	-0.16714766451061E-10}
    ,{6,	16,	-0.21171472321355E-02}
    ,{6,	35,	-0.23895741934104E+02}
    ,{7,	0,	-0.59059564324270E-17}
    ,{7,	11,	-0.12621808899101E-05}
    ,{7,	25,	-0.38946842435739E-01}
    ,{8,	8,	0.11256211360459E-10}
    ,{8,	36,	-0.82311340897998E+01}
    ,{9,	13,	0.19809712802088E-07}
    ,{10,	4,	0.10406965210174E-18}
    ,{10,	10,	-0.10234747095929E-12}
    ,{10,	14,	-0.10018179379511E-08}
    ,{16,	29,	-0.80882908646985E-10}
    ,{16,	50,	0.10693031879409E+00}
    ,{18,	57,	-0.33662250574171E+00}
    ,{20,	20,	0.89185845355421E-24}
    ,{20,	35,	0.30629316876232E-12}
    ,{20,	48,	-0.42002467698208E-05}
    ,{21,	21,	-0.59056029685639E-25}
    ,{22,	53,	0.37826947613457E-05}
    ,{23,	39,	-0.12768608934681E-14}
    ,{24,	26,	0.73087610595061E-28}
    ,{24,	40,	0.55414715350778E-16}
    ,{24,	58,	-0.94369707241210E-06}
};

double Region_2_Gamar(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){
        sum += Region_2_g_pT_Residual_Data[i].n * qPow(Pi,Region_2_g_pT_Residual_Data[i].I) * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_GamarPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){
        sum += Region_2_g_pT_Residual_Data[i].n * Region_2_g_pT_Residual_Data[i].I * qPow(Pi,Region_2_g_pT_Residual_Data[i].I - 1) * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_GamarPiPi(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){ //m³ / kg
    sum += Region_2_g_pT_Residual_Data[i].n * Region_2_g_pT_Residual_Data[i].I * (Region_2_g_pT_Residual_Data[i].I -1) * qPow(Pi,Region_2_g_pT_Residual_Data[i].I - 2) * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J);
    }
    return sum;
}
double Region_2_GamarTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){
        sum += Region_2_g_pT_Residual_Data[i].n * qPow(Pi,Region_2_g_pT_Residual_Data[i].I) * Region_2_g_pT_Residual_Data[i].J * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_2_GamarTauTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){
        sum += Region_2_g_pT_Residual_Data[i].n * qPow(Pi,Region_2_g_pT_Residual_Data[i].I) * Region_2_g_pT_Residual_Data[i].J * (Region_2_g_pT_Residual_Data[i].J - 1) * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J - 2);
    }
    return sum;
}
double Region_2_GamarPiTau(double Pi, double Tau){
    double sum = 0;
    for (int i=0; i<43 ; i++){
        sum += Region_2_g_pT_Residual_Data[i].n * Region_2_g_pT_Residual_Data[i].I * qPow(Pi,Region_2_g_pT_Residual_Data[i].I - 1) * Region_2_g_pT_Residual_Data[i].J * Region_2_g_pT_Residual_Data[i].J * qPow((Tau - 0.5),Region_2_g_pT_Residual_Data[i].J - 1);
    }
    return sum;
}
double Region_2_Gamao(double Pi,double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_g_pT_Ideal_Data[i].n * qPow(Tau,Region_2_g_pT_Ideal_Data[i].J);
    }
    sum += qLn(Pi);
    return sum;
}
double Region_2_GamaoTau(double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_g_pT_Ideal_Data[i].n * Region_2_g_pT_Ideal_Data[i].J * qPow(Tau,Region_2_g_pT_Ideal_Data[i].J - 1);
    }
    return sum;
}
double Region_2_GamaoTauTau(double Tau){
    double sum = 0;
    for (int i=0; i<9 ; i++){
        sum += Region_2_g_pT_Ideal_Data[i].n * Region_2_g_pT_Ideal_Data[i].J * (Region_2_g_pT_Ideal_Data[i].J - 1) * qPow(Tau,Region_2_g_pT_Ideal_Data[i].J - 2);
    }
    return sum;
}
double Region_2_GamaoPi(double Pi){
    double result = 0;
    result = 1 / Pi;
    return result;
}
double Region_2_GamaoPiPi(double Pi){
    double result = 0;
    result = -1 / qPow(Pi,2);
    return result;
}
double Region_2_GamaoPiTau(){
    return 0;
}
double Region_2_Gama(double Pi, double Tau){
    double result = 0;
    result = Region_2_Gamao(Pi,Tau) + Region_2_Gamar(Pi,Tau);
    return result;
}
double Region_2_g_pT(double p,double T){
    double result = 0;
    double Pi = p / Region_2_g_pT_p_Star;
    double Tau = Region_2_g_pT_T_Star / T;
    result = Region_2_Gama(p,T) * R * T;
    return result;
}
double Region_2_v_pT(double p, double T){
    double Pi = p / Region_2_g_pT_p_Star;
    double Tau = Region_2_g_pT_T_Star / T;
    return (Pi * (Region_2_GamaoPi(Pi) + Region_2_GamarPi(Pi,Tau)) * (R * T / p) * 1000);
}
double Region_2_s_pT(double p, double T){
    double Pi = p / Region_2_g_pT_p_Star;
    double Tau = Region_2_g_pT_T_Star / T;
    return ((Tau * (Region_2_GamaoTau(Tau) + Region_2_GamarTau(Pi,Tau)) - Region_2_Gama(Pi,Tau)) * R);
}
double Region_2_h_pT(double p, double T){
    double Pi = p / Region_2_g_pT_p_Star;
    double Tau = Region_2_g_pT_T_Star / T;
    return ((Tau * (Region_2_GamaoTau(Tau) + Region_2_GamarTau(Pi,Tau))) * (R * T));
}
ThermoState Region_2_pT(double p,double T){
    ThermoState state;
    state.p = p;
    state.T = T;
    state.v = Region_2_v_pT(p,T);
    state.h = Region_2_h_pT(p,T);
    state.s = Region_2_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Region 2";
    state.phase = findPhase(state);
    return state;
}

//State as a function of ph

const double Boundry_2bc_n[5] = {
    0.90584278514723E+03
   ,-0.67955786399241
   ,0.12809002730136E-03
   ,0.26526571908428E+04
   ,0.45257578905948E+01
};

double Boundry_2bc_p_h(double h){
    double Eta = h / Boundry_2bc_h_Star;
    double sum = 0;
    sum = Boundry_2bc_n[0] + Eta * Boundry_2bc_n[1] + qPow(Eta,2) * Boundry_2bc_n[2];
    return sum *= Boundry_2bc_p_Star;
}
double Boundry_2bc_h_p(double p){
    double Pi = p / Boundry_2bc_p_Star;
    double sum = 0;
    sum = Boundry_2bc_n[3] + qSqrt((Pi - Boundry_2bc_n[4]) / Boundry_2bc_n[2]);
    return sum *= Boundry_2bc_h_Star;
}

const IJn_Data Region_2a_T_ph_Data[] = {
    {0,	0,	1089.8952318288}
    ,{0,	1,	849.51654495535}
    ,{0,	2,	-107.81748091826}
    ,{0,	3,	33.153654801263}
    ,{0,	7,	-7.4232016790248}
    ,{0,	20,	11.765048724356}
    ,{1,	0,	1.844574935579}
    ,{1,	1,	-4.1792700549624}
    ,{1,	2,	6.2478196935812}
    ,{1,	3,	-17.344563108114}
    ,{1,	7,	-200.58176862096}
    ,{1,	9,	271.96065473796}
    ,{1,	11,	-455.11318285818}
    ,{1,	18,	3091.9688604755}
    ,{1,	44,	252266.40357872}
    ,{2,	0,	-6.1707422868339E-03}
    ,{2,	2,	-0.31078046629583}
    ,{2,	7,	11.670873077107}
    ,{2,	36,	128127984.04046}
    ,{2,	38,	-985549096.23276}
    ,{2,	40,	2822454697.3002}
    ,{2,	42,	-3594897141.0703}
    ,{2,	44,	1722734991.3197}
    ,{3,	24,	-13551.334240775}
    ,{3,	44,	12848734.66465}
    ,{4,	12,	1.3865724283226}
    ,{4,	32,	235988.32556514}
    ,{4,	44,	-13105236.545054}
    ,{5,	32,	7399.9835474766}
    ,{5,	36,	-551966.9703006}
    ,{5,	42,	3715408.5996233}
    ,{6,	34,	19127.72923966}
    ,{6,	44,	-415351.64835634}
    ,{7,	28,	-62.459855192507}

};

const IJn_Data Region_2b_T_ph_Data[] = {
    {0,	0,	1489.5041079516}
    ,{0,	1,	743.07798314034}
    ,{0,	2,	-97.708318797837}
    ,{0,	12,	2.4742464705674}
    ,{0,	18,	-0.63281320016026}
    ,{0,	24,	1.1385952129658}
    ,{0,	28,	-0.47811863648625}
    ,{0,	40,	8.5208123431544E-03}
    ,{1,	0,	0.93747147377932}
    ,{1,	2,	3.3593118604916}
    ,{1,	6,	3.3809355601454}
    ,{1,	12,	0.16844539671904}
    ,{1,	18,	0.73875745236695}
    ,{1,	24,	-0.47128737436186}
    ,{1,	28,	0.15020273139707}
    ,{1,	40,	-0.002176411421975}
    ,{2,	2,	-0.021810755324761}
    ,{2,	8,	-0.10829784403677}
    ,{2,	18,	-0.046333324635812}
    ,{2,	40,	7.1280351959551E-05}
    ,{3,	1,	1.1032831789999E-04}
    ,{3,	2,	1.8955248387902E-04}
    ,{3,	12,	3.0891541160537E-03}
    ,{3,	24,	1.3555504554949E-03}
    ,{4,	2,	2.8640237477456E-07}
    ,{4,	12,	-1.0779857357512E-05}
    ,{4,	18,	-7.6462712454814E-05}
    ,{4,	24,	1.4052392818316E-05}
    ,{4,	28,	-3.1083814331434E-05}
    ,{4,	40,	-1.0302738212103E-06}
    ,{5,	18,	2.821728163504E-07}
    ,{5,	24,	1.2704902271945E-06}
    ,{5,	40,	7.3803353468292E-08}
    ,{6,	28,	-1.1030139238909E-08}
    ,{7,	2,	-8.1456365207833E-14}
    ,{7,	28,	-2.5180545682962E-11}
    ,{9,	1,	-1.7565233969407E-18}
    ,{9,	40,	8.6934156344163E-15}

};

const IJn_Data Region_2c_T_ph_Data[] = {
    {-7,	0,	-3236839855524.2}
    ,{-7,	4,	7326335090218.1}
    ,{-6,	0,	358250899454.47}
    ,{-6,	2,	-583401318515.9}
    ,{-5,	0,	-10783068217.47}
    ,{-5,	2,	20825544563.171}
    ,{-2,	0,	610747.83564516}
    ,{-2,	1,	859777.2253558}
    ,{-1,	0,	-25745.72360417}
    ,{-1,	2,	31081.088422714}
    ,{0,	0,	1208.2315865936}
    ,{0,	1,	482.19755109255}
    ,{1,	4,	3.7966001272486}
    ,{1,	8,	-10.842984880077}
    ,{2,	4,	-0.04536417267666}
    ,{6,	0,	1.4559115658698E-13}
    ,{6,	1,	1.126159740723E-12}
    ,{6,	4,	-1.7804982240686E-11}
    ,{6,	10,	1.2324579690832E-07}
    ,{6,	12,	-1.1606921130984E-06}
    ,{6,	16,	2.7846367088554E-05}
    ,{6,	20,	-5.9270038474176E-04}
    ,{6,	22,	1.2918582991878E-03}

};


int findSubRegion2_ph(double p, double h){
    if (p < 4 * qPow(10,6)){ // Sub-Region a
        return 'a';
    }else {
        if( h > Boundry_2bc_h_p(p)){ // Sub-Region b
            return 'b';
        }else{ // Sub-Region c
            return 'c';
        }
    }
}

double Region_2_T_ph(double p, double h){
    double Pi = p / Region_2_T_ph_p_Star;
    double Eta = h / Region_2_T_ph_h_Star;
    double sum =0;
    char sub = findSubRegion2_ph(p,h);
    switch (sub) {
    case 'a':
        for (int i=0; i < 34; i++){
            sum += Region_2a_T_ph_Data[i].n * qPow(Pi,Region_2a_T_ph_Data[i].I) * qPow((Eta-2.1),Region_2a_T_ph_Data[i].J);
        }
        break;
    case 'b':
        for (int i=0; i < 38; i++){
            sum += Region_2b_T_ph_Data[i].n * qPow((Pi-2),Region_2b_T_ph_Data[i].I) * qPow((Eta-2.6),Region_2b_T_ph_Data[i].J);
        }
        break;
    case 'c':
        for (int i=0; i < 23; i++){
            sum += Region_2c_T_ph_Data[i].n * qPow((Pi+25),Region_2c_T_ph_Data[i].I) * qPow((Eta-1.8),Region_2c_T_ph_Data[i].J);
        }
        break;
    default:
        break;
    }
    return sum *= Region_2_T_ph_T_Star;
}

ThermoState Region_2_ph(double p,double h){
    ThermoState state;
    double T = Region_2_T_ph(p,h);
    state.p = p;
    state.h = h;
    state.T = T;
    state.v = Region_2_v_pT(p,T);
    state.s = Region_2_s_pT(p,T);
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 2";
    state.phase = findPhase(state);
    return state;
}

//State as a function of ps

const IJn_Data2 Region_2a_T_ps_Data[] = {
     {-1.5, 	-24,	-392359.83861984}
    ,{-1.5,     -23,	515265.7382727}
    ,{-1.5,     -19,	40482.443161048}
    ,{-1.5,     -13,	-321.93790923902}
    ,{-1.5,     -11,	96.961424218694}
    ,{-1.5, 	-10,	-22.867846371773}
    ,{-1.25,	-19,	-449429.14124357}
    ,{-1.25,	-15,	-5011.8336020166}
    ,{-1.25,   	-6,     0.35684463560015}
    ,{-1.0,     -26,	44235.33584819}
    ,{-1.0,     -21,  	-13673.388811708}
    ,{-1.0,     -17,  	421632.60207864}
    ,{-1.0, 	-16,  	22516.925837475}
    ,{-1.0, 	-9,  	474.42144865646}
    ,{-1.0, 	-8,  	-149.31130797647}
    ,{-0.75,	-15,  	-197811.26320452}
    ,{-0.75,	-14,  	-23554.39947076}
    ,{-0.5,     -26,  	-19070.616302076}
    ,{-0.5, 	-13,      55375.669883164}
    ,{-0.5, 	-9,      3829.3691437363}
    ,{-0.5,     -7,  	-603.91860580567}
    ,{-0.25,	-27,  	1936.3102620331}
    ,{-0.25,	-25,  	4266.064369861}
    ,{-0.25,	-11,  	-5978.0638872718}
    ,{-0.25,	-6,  	-704.01463926862}
    ,{0.25, 	1,  	338.36784107553}
    ,{0.25, 	4,  	20.862786635187}
    ,{0.25, 	8,  	0.033834172656196}
    ,{0.25, 	11,  	-4.3124428414893E-05}
    ,{0.5,      0,      166.53791356412}
    ,{0.5,  	1,  	-139.86292055898}
    ,{0.5,  	5,  	-0.78849547999872}
    ,{0.5,  	6,  	0.072132411753872}
    ,{0.5,  	10,  	-5.9754839398283E-03}
    ,{0.5,  	14,  	-1.2141358953904E-05}
    ,{0.5,  	16,  	2.3227096733871E-07}
    ,{0.75, 	0,  	-10.538463566194}
    ,{0.75, 	4,  	2.0718925496502}
    ,{0.75, 	9,      -0.072193155260427}
    ,{0.75, 	17,  	2.074988708112E-07}
    ,{1.0,  	7,  	-0.018340657911379}
    ,{1.0,  	18,  	2.9036272348696E-07}
    ,{1.25,     3,  	0.21037527893619}
    ,{1.25,     15,  	2.5681239729999E-04}
    ,{1.5,      5,  	-0.012799002933781}
    ,{1.5,      18,  	-8.2198102652018E-06}
};

const IJn_Data2 Region_2b_T_ps_Data[] = {
     {-6,	0,	316876.65083497}
    ,{-6,	11,	20.864175881858}
    ,{-5,   0,	-398593.99803599}
    ,{-5,	11,	-21.816058518877}
    ,{-4,	0,	223697.85194242}
    ,{-4,	1,	-2784.1703445817}
    ,{-4,	11,	9.920743607148}
    ,{-3,	0,	-75197.512299157}
    ,{-3,	1,	2970.8605951158}
    ,{-3,	11,	-3.4406878548526}
    ,{-3,	12,	0.38815564249115}
    ,{-2,	0,	17511.29508575}
    ,{-2,	1,	-1423.7112854449}
    ,{-2,	6,	 1.0943803364167}
    ,{-2,	10,	0.89971619308495}
    ,{-1,	0,	-3375.9740098958}
    ,{-1,	1,	 471.62885818355}
    ,{-1,	5,	-1.9188241993679}
    ,{-1,	8,	0.41078580492196}
    ,{-1,	9,	-0.33465378172097}
    ,{0,	0,	1387.0034777505}
    ,{0,	1,	-406.63326195838}
    ,{0,	2,	41.72734715961}
    ,{0,	4,	2.1932549434532}
    ,{0,	5,	-1.0320050009077}
    ,{0,	6,	0.35882943516703}
    ,{0,	9,	5.2511453726066E-03}
    ,{1,	0,	12.838916450705}
    ,{1,	1,	-2.8642437219381}
    ,{1,	2,	0.56912683664855}
    ,{1,	3,	-0.099962954584931}
    ,{1,	7,	-3.2632037778459E-03}
    ,{1,	8,	2.3320922576723E-04}
    ,{2,	0,	-0.1533480985745}
    ,{2,	1,	0.029072288239902}
    ,{2,	5,	3.7534702741167E-04}
    ,{3,	0,	1.7296691702411E-03}
    ,{3,	1,	-3.8556050844504E-04}
    ,{3,	3,	-3.5017712292608E-05}
    ,{4,	0,	-1.4566393631492E-05}
    ,{4,	1,	5.6420857267269E-06}
    ,{5,	0,	4.1286150074605E-08}
    ,{5,	1,	-2.0684671118824E-08}
    ,{5,	2,	1.6409393674725E-09}
};

const IJn_Data2 Region_2c_T_ps_Data[] = {
      {-2, 0, 909.68501005365}
    , { -2,  1,  2404.566708842}
    , { -1,  0,  -591.6232638713}
    , { 0,  0,  541.45404128074}
    , { 0,  1,  -270.98308411192}
    , { 0,  2,  979.76525097926}
    , { 0,  3,  -469.66772959435}
    , { 1,  0,  14.399274604723}
    , { 1,  1,  -19.104204230429}
    , { 1,  3,  5.3299167111971}
    , { 1,  4,  -21.252975375934}
    , { 2,  0,  -0.3114733441376}
    , { 2,  1,  0.60334840894623}
    , { 2,  2,  -0.042764839702509}
    , { 3,  0,  5.8185597255259E-03}
    , { 3,  1,  -0.014597008284753}
    , { 3,  5,  5.6631175631027E-03}
    , { 4,  0,  -7.6155864584577E-05}
    , { 4,  1,  2.2440342919332E-04}
    , { 4,  4,  -1.2561095013413E-05}
    , { 5,  0,  6.3323132660934E-07}
    , { 5,  1,  -2.0541989675375E-06}
    , { 5,  2,  3.6405370390082E-08}
    , { 6,  0,  -2.9759897789215E-09}
    , { 6,  1,  1.0136618529763E-08}
    , { 7,  0,  5.9925719692351E-12}
    , { 7,  1,  -2.0677870105164E-11}
    , { 7,  3,  -2.0874278181886E-11}
    , { 7,  4,  1.0162166825089E-10}
    , { 7,  5,  -1.6429828281347E-10}
};


int findSubRegion2_ps(double p, double s){
    if (p < 4 * qPow(10,6)){ // Sub-Region a
        return 'a';
    }else {
        if( s > Boundry_2bc_s){ // Sub-Region b
            return 'b';
        }else{ // Sub-Region c
            return 'c';
        }
    }
}

double Region_2_T_ps(double p, double s){
    double Pi = p / Region_2_T_ps_p_Star;
    double Sigma = 0;
    double sum = 0;
    char sub = findSubRegion2_ps(p,s);
    switch (sub) {
    case 'a':
        Sigma = s / Region_2a_T_ps_s_Star;
        for (int i=0; i < 46; i++){
            sum += Region_2a_T_ps_Data[i].n * qPow(Pi,Region_2a_T_ps_Data[i].I) * qPow((Sigma-2),Region_2a_T_ps_Data[i].J);
        }
        break;
    case 'b':
        Sigma = s / Region_2b_T_ps_s_Star;
        for (int i=0; i < 44; i++){
            sum += Region_2b_T_ps_Data[i].n * qPow(Pi,Region_2b_T_ps_Data[i].I) * qPow((10-Sigma),Region_2b_T_ps_Data[i].J);
        }
        break;
    case 'c':
        Sigma = s / Region_2c_T_ps_s_Star;
        for (int i=0; i < 30; i++){
            sum += Region_2c_T_ps_Data[i].n * qPow(Pi,Region_2c_T_ps_Data[i].I) * qPow((2-Sigma),Region_2c_T_ps_Data[i].J);
        }
        break;
    default:
        break;
    }
    return sum *= Region_2_T_ps_T_Star;
}

ThermoState Region_2_ps(double p,double s){
    ThermoState state;
    double T = Region_2_T_ps(p,s);
    state.p = p;
    state.h = Region_2_h_pT(p,T);
    state.T = T;
    state.v = Region_2_v_pT(p,T);
    state.s = s;
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 2";
    state.phase = findPhase(state);
    return state;
}

//State as a function of hs

const IJn_Data2 Region_2a_p_hs_Data[] = {
    {0, 1, -1.82575361923032E-02}
    , {0, 3, -0.125229548799536}
    , {0, 6, 0.592290437320145}
    , {0, 16, 6.04769706185122}
    , {0, 20, 238.624965444474}
    , {0, 22, -298.639090222922}
    , {1, 0, 0.051225081304075}
    , {1, 1, -0.437266515606486}
    , {1, 2, 0.413336902999504}
    , {1, 3, -5.16468254574773}
    , {1, 5, -5.57014838445711}
    , {1, 6, 12.8555037824478}
    , {1, 10, 11.414410895329}
    , {1, 16, -119.504225652714}
    , {1, 20, -2847.7798596156}
    , {1, 22, 4317.57846408006}
    , {2, 3, 1.1289404080265}
    , {2, 16, 1974.09186206319}
    , {2, 20, 1516.12444706087}
    , {3, 0, 1.41324451421235E-02}
    , {3, 2, 0.585501282219601}
    , {3, 3, -2.97258075863012}
    , {3, 6, 5.94567314847319}
    , {3, 16, -6236.56565798905}
    , {4, 16, 9659.86235133332}
    , {5, 3, 6.81500934948134}
    , {5, 16, -6332.07286824489}
    , {6, 3, -5.5891922446576}
    , {7, 1, 4.00645798472063E-02}
    };

const IJn_Data2 Region_2b_p_hs_Data[] = {
    {0, 0, 8.01496989929495E-02}
    , {0, 1, -0.543862807146111}
    , {0, 2, 0.337455597421283}
    , {0, 4, 8.9055545115745}
    , {0, 8, 313.840736431485}
    , {1, 0, 0.797367065977789}
    , {1, 1, -1.2161697355624}
    , {1, 2, 8.72803386937477}
    , {1, 3, -16.9769781757602}
    , {1, 5, -186.552827328416}
    , {1, 12, 95115.9274344237}
    , {2, 1, -18.9168510120494}
    , {2, 6, -4334.0703719484}
    , {2, 18, 543212633.012715}
    , {3, 0, 0.144793408386013}
    , {3, 1, 128.024559637516}
    , {3, 7, -67230.9534071268}
    , {3, 12, 33697238.0095287}
    , {4, 1, -586.63419676272}
    , {4, 16, -22140322476.9889}
    , {5, 1, 1716.06668708389}
    , {5, 12, -570817595.806302}
    , {6, 1, -3121.09693178482}
    , {6, 8, -2078413.8463301}
    , {6, 18, 3056059461577.86}
    , {7, 1, 3221.57004314333}
    , {7, 16, 326810259797.295}
    , {8, 1, -1441.04158934487}
    , {8, 3, 410.694867802691}
    , {8, 14, 109077066873.024}
    , {8, 18, -24796465425889.3}
    , {12, 10, 1888019068.65134}
    , {14, 16, -123651009018773}
    };


const IJn_Data2 Region_2c_p_hs_Data[] = {
    {0, 0, 0.112225607199012}
    , {0, 1, -3.39005953606712}
    , {0, 2, -32.0503911730094}
    , {0, 3, -197.5973051049}
    , {0, 4, -407.693861553446}
    , {0, 8, 13294.3775222331}
    , {1, 0, 1.70846839774007}
    , {1, 2, 37.3694198142245}
    , {1, 5, 3581.44365815434}
    , {1, 8, 423014.446424664}
    , {1, 14, -751071025.760063}
    , {2, 2, 52.3446127607898}
    , {2, 3, -228.351290812417}
    , {2, 7, -960652.417056937}
    , {2, 10, -80705929.2526074}
    , {2, 18, 1626980172256.69}
    , {3, 0, 0.772465073604171}
    , {3, 5, 46392.9973837746}
    , {3, 8, -13731788.5134128}
    , {3, 16, 1704703926305.12}
    , {3, 18, -25110462818730.8}
    , {4, 18, 31774883083552}
    , {5, 1, 53.8685623675312}
    , {5, 4, -55308.9094625169}
    , {5, 6, -1028615.22421405}
    , {5, 14, 2042494187562.34}
    , {6, 8, 273918446.626977}
    , {6, 18, -2.63963146312685E+15}
    , {10, 7, -1078908541.08088}
    , {12, 7, -29649262098.0124}
    , {16, 10, -1.11754907323424E+15}
    };

double Region_2ab_h_s(double s){
    return (-3498.98083432139 + 2575.60716905876 * s - 421.073558227969 * qPow(s,2) + 27.6349063799944 * qPow(s,3));
}

int findSubRegion2_hs(double h, double s){
    char sub = 0;
    if (h < Region_2ab_h_s(s)) {
        sub = 'a';
    }else{
        if (s < 5.85){
            sub = 'c';
    }else{
            sub = 'b';
        }
    }
    return sub;
}

double Region_2_p_hs(double h, double s){
    double Eta = 0;
    double Sigma = 0;
    double sum = 0;
    char sub = findSubRegion2_hs(h,s);
    switch (sub) {
    case 'a':
        Eta = h / Region_2a_p_hs_h_Star;
        Sigma = s / Region_2a_p_hs_s_Star;
        for (int i=0; i < 29; i++){
            sum += Region_2a_p_hs_Data[i].n * qPow((Eta - 0.5),Region_2a_p_hs_Data[i].I) * qPow((Sigma- 1.2),Region_2a_p_hs_Data[i].J);
        }
        sum = qPow(sum,4);
        return sum *= Region_2a_p_hs_p_Star;
        break;
    case 'b':
        Eta = h / Region_2b_p_hs_h_Star;
        Sigma = s / Region_2b_p_hs_s_Star;
        for (int i=0; i < 33; i++){
            sum += Region_2b_p_hs_Data[i].n * qPow((Eta - 0.6),Region_2b_p_hs_Data[i].I) * qPow((Sigma - 1.01),Region_2b_p_hs_Data[i].J);
        }
        sum = qPow(sum,4);
        return sum *= Region_2b_p_hs_p_Star;
        break;
    case 'c':
        Eta = h / Region_2c_p_hs_h_Star;
        Sigma = s / Region_2c_p_hs_s_Star;
        for (int i=0; i < 31; i++){
            sum += Region_2c_p_hs_Data[i].n * qPow((Eta - 0.7),Region_2c_p_hs_Data[i].I) * qPow((Sigma - 1.1),Region_2c_p_hs_Data[i].J);
        }
        sum = qPow(sum,4);
        return sum *= Region_2c_p_hs_p_Star;
        break;
    default:
        break;
    }
}

ThermoState Region_2_hs(double h,double s){
    ThermoState state;
    double p = Region_2_p_hs(h,s);
    double T = Region_2_T_ph(p,h);
    state.p = p;
    state.h = h;
    state.T = T;
    state.v = Region_2_v_pT(p,T);
    state.s = s;
    state.Rho = (1 / state.v);
    state.x = 0;
    state.region = "Regiron 2";
    state.phase = findPhase(state);
    return state;
}
