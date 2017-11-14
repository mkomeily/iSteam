#include "region_4.h"
#include "region_1.h"
#include "region_2.h"
#include "region_3.h"
#include "boundry_23.h"
#include <QtMath>
#include <QDebug>

double Region_4_p_Sat_T(double T){
    double nou = (T/Region_4_T_Star) + (Region_4_Sat_pT_n[8] / (T/Region_4_T_Star - Region_4_Sat_pT_n[9]));
    double A = qPow(nou,2) + Region_4_Sat_pT_n[0] * nou + Region_4_Sat_pT_n[1];
    double B = Region_4_Sat_pT_n[2] * qPow(nou,2) + Region_4_Sat_pT_n[3] * nou + Region_4_Sat_pT_n[4];
    double C = Region_4_Sat_pT_n[5] * qPow(nou,2) + Region_4_Sat_pT_n[6] * nou + Region_4_Sat_pT_n[7];
    double p_Sat = qPow(2 * C / (-B + qSqrt(qPow(B,2) - 4 * A * C)),4) * Region_4_p_Star;
    return p_Sat;
}
double Region_4_T_Sat_p(double p){
    double beta = qPow((p / Region_4_p_Star) , 0.25);
    double E = qPow(beta,2) + Region_4_Sat_pT_n[2] * beta + Region_4_Sat_pT_n[5];
    double F = Region_4_Sat_pT_n[0] * qPow(beta,2) + Region_4_Sat_pT_n[3] * beta + Region_4_Sat_pT_n[6];
    double G = Region_4_Sat_pT_n[1] * qPow(beta,2) + Region_4_Sat_pT_n[4] * beta + Region_4_Sat_pT_n[7];
    double D = (2 * G) / (-F - qPow((qPow(F,2) - 4 * E * G) , 0.5));
    double T_Sat = (Region_4_Sat_pT_n[9] + D - qPow(qPow((Region_4_Sat_pT_n[9] + D) , 2) - 4 * (Region_4_Sat_pT_n[8] + Region_4_Sat_pT_n[9] * D) , 0.5)) / 2 * Region_4_T_Star;
    return T_Sat;
}

ThermoState Region_4_Tx(double T,double x){
    ThermoState state;
    double p = 0;
    p = Region_4_p_Sat_T(T);
    state.x = x;
    state.phase = "Saturation";
    state.region = "Region 4";
    state.p = p;
    state.p_Sat = p;
    state.T = T;
    state.T_Sat = T;
    state.h = Region_4_h_Tx(T,x);
    state.h_Fluid = Region_4_h_Tx(T,0);
    state.h_Gas = Region_4_h_Tx(T,1);
    state.s = Region_4_s_Tx(T,x);
    state.s_Fluid = Region_4_s_Tx(T,0);
    state.s_Gas = Region_4_s_Tx(T,1);
    state.v = Region_4_v_Tx(T,x);
    state.v_Fluid = Region_4_v_Tx(T,0);
    state.v_Gas = Region_4_v_Tx(T,1);
    return state;
}

ThermoState Region_4_px(double p,double x){
    ThermoState state;
    double T = 0;
    T = Region_4_T_Sat_p(p);
    state.x = x;
    state.phase = "Saturation";
    state.region = "Region 4";
    state.p = p;
    state.p_Sat = p;
    state.T = T;
    state.T_Sat = T;
    state.h = Region_4_h_Tx(T,x);
    state.h_Fluid = Region_4_h_Tx(T,0);
    state.h_Gas = Region_4_h_Tx(T,1);
    state.s = Region_4_s_Tx(T,x);
    state.s_Fluid = Region_4_s_Tx(T,0);
    state.s_Gas = Region_4_s_Tx(T,1);
    state.v = Region_4_v_Tx(T,x);
    state.v_Fluid = Region_4_v_Tx(T,0);
    state.v_Gas = Region_4_v_Tx(T,1);
    return state;
}

ThermoState Region_4_ph(double p,double h){
    ThermoState state;
    double T=0;
    double x=0;
    T = Region_4_T_Sat_p(p);
    x = Region_4_x_Th(T,h);
    state = Region_4_Tx(T,x);
    return state;
}

ThermoState Region_4_Th(double T,double h){
    ThermoState state;
    double x=0;
    x = Region_4_x_Th(T,h);
    state = Region_4_Tx(T,x);    
    return state;
}

ThermoState Region_4_ps(double p,double s){
    ThermoState state;
    double x=0;
    double T=0;
    T = Region_4_T_Sat_p(p);
    x = Region_4_x_Ts(T,s);
    state = Region_4_Tx(T,x);
    return state;
}

ThermoState Region_4_hs(double h,double s){
    ThermoState state;
    double x=0;
    double T=0;
    T = Region_4_T_Sat_hs(h,s);
    x = Region_4_x_Th(T,s);
    state = Region_4_Tx(T,x);
    return state;
}

ThermoState Region_4_Ts(double T,double s){
    ThermoState state;
    double x=0;
    x = Region_4_x_Ts(T,s);
    state = Region_4_Tx(T,x);
    return state;
}
ThermoState Region_4_pv(double p,double v){
    ThermoState state;
    double x=0;
    double T=0;
    T = Region_4_T_Sat_p(p);
    x = Region_4_x_Tv(T,v);
    state = Region_4_Tx(T,x);
    return state;
}
ThermoState Region_4_Tv(double T,double v){
    ThermoState state;
    double x=0;
    x = Region_4_x_Tv(T,v);
    state = Region_4_Tx(T,x);
    return state;
}

double  Region_4_x_Th(double T, double h){
    double x = 0;
    double h_f = 0;
    double h_g = 0;
    double rho = 0;
    double v = 0;
    double p_Sat = Region_4_p_Sat_T(T);
    if (T <= Region_1_g_pT_T_Max) {
        h_f = Region_1_h_pT(p_Sat,T);
        h_g = Region_2_h_pT(p_Sat,T);        
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v = Region_3c_v_pT(p_Sat,T);
        rho = 1 / v;
        h_f = Region_3_h_RhoT(rho,T);
        //Volume Gas
        v = Region_3t_v_pT(p_Sat,T);
        rho = 1 / v;
        h_g = Region_3_h_RhoT(rho,T);        
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3x_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
             qDebug() << h_f;
             qDebug() << h_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v = Region_3y_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
            qDebug() << h_f;
            qDebug() << h_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
            qDebug() << h_f;
            qDebug() << h_g;
        }
    }
    x = (h - h_f) / (h_g - h_f);
    return x;
}
double  Region_4_x_Ts(double T, double s){
    double x = 0;
    double s_f = 0;
    double s_g = 0;
    double v = 0;
    double rho = 0;
    double p_Sat = Region_4_p_Sat_T(T);
    if (T <= Region_1_g_pT_T_Max) {
        s_f = Region_1_s_pT(p_Sat,T);
        s_g = Region_2_s_pT(p_Sat,T);
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v = Region_3c_v_pT(p_Sat,T);
        rho = 1 / v;
        s_f = Region_3_s_RhoT(rho,T);
        //Volume Gas
        v = Region_3t_v_pT(p_Sat,T);
        rho = 1 / v;
        s_g = Region_3_s_RhoT(rho,T);
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3x_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
             qDebug() << s_f;
             qDebug() << s_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v = Region_3y_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
            qDebug() << s_f;
            qDebug() << s_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
            qDebug() << s_f;
            qDebug() << s_g;
        }
    }
    x = ((s - s_f) / (s_g - s_f));
    return x;
}
double  Region_4_x_Tv(double T, double v){
    double x = 0;
    double v_f = 0;
    double v_g = 0;
    double p_Sat = Region_4_p_Sat_T(T);
    if (T <= Region_1_g_pT_T_Max) {
        v_f = Region_1_v_pT(p_Sat,T);
        v_g = Region_2_v_pT(p_Sat,T);
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v_f = Region_3c_v_pT(p_Sat,T);
        //Volume Gas
        v_g = Region_3t_v_pT(p_Sat,T);
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v_f = Region_3u_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3x_v_pT(p_Sat,T);
             qDebug() << v_f;
             qDebug() << v_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v_f = Region_3y_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3z_v_pT(p_Sat,T);
            qDebug() << v_f;
            qDebug() << v_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v_f = Region_3u_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3z_v_pT(p_Sat,T);
            qDebug() << v_f;
            qDebug() << v_g;
        }
    }
    x = (v_g - v_f) / (v - v_f);
    return x;
}

double Region_4_s_Tx(double T, double x)
{
    double v = 0;
    double rho = 0;
    double s = 0;
    double s_f = 0;
    double s_g = 0;
    double  p_Sat = Region_4_p_Sat_T(T);
    if (T <= Region_1_g_pT_T_Max) {
        s_f = Region_1_s_pT(p_Sat,T);
        s_g = Region_2_s_pT(p_Sat,T);
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v = Region_3c_v_pT(p_Sat,T);
        rho = 1 / v;
        s_f = Region_3_s_RhoT(rho,T);
        //Volume Gas
        v = Region_3t_v_pT(p_Sat,T);
        rho = 1 / v;
        s_g = Region_3_s_RhoT(rho,T);
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3x_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
             qDebug() << s_f;
             qDebug() << s_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v = Region_3y_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
            qDebug() << s_f;
            qDebug() << s_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            s_f = Region_3_s_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            s_g = Region_3_s_RhoT(rho,T);
            qDebug() << s_f;
            qDebug() << s_g;
        }
    }
    s = ((1 - x) * s_f) + (x * s_g);
    return s;
}

double Region_4_h_Tx(double T, double x)
{
    double v = 0;
    double rho = 0;
    double h = 0;
    double h_f = 0;
    double h_g = 0;
    double p_Sat = Region_4_p_Sat_T(T);
    if (T <= Region_1_g_pT_T_Max) {
        h_f = Region_1_h_pT(p_Sat,T);
        h_g = Region_2_h_pT(p_Sat,T);
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v = Region_3c_v_pT(p_Sat,T);
        rho = 1 / v;
        h_f = Region_3_h_RhoT(rho,T);
        //Volume Gas
        v = Region_3t_v_pT(p_Sat,T);
        rho = 1 / v;
        h_g = Region_3_h_RhoT(rho,T);
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3x_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
             qDebug() << h_f;
             qDebug() << h_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v = Region_3y_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
            qDebug() << h_f;
            qDebug() << h_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v = Region_3u_v_pT(p_Sat,T);
            rho = 1 / v;
            h_f = Region_3_h_RhoT(rho,T);
            //Volume Gas
            v = Region_3z_v_pT(p_Sat,T);
            rho = 1 / v;
            h_g = Region_3_h_RhoT(rho,T);
            qDebug() << h_f;
            qDebug() << h_g;
        }
    }
    h = ((1 - x) * h_f) + (x * h_g);
    return h;
}

double Region_4_v_Tx(double T, double x)
{
    double v = 0;
    double v_f = 0;
    double v_g = 0;
    double p_Sat = Region_4_p_Sat_T(T);;
    if (T <= Region_1_g_pT_T_Max) {
        v_f = Region_1_v_pT(p_Sat,T);
        v_g = Region_2_v_pT(p_Sat,T);
    }else if ((T > Region_1_g_pT_T_Max) && (T <= 643.15)){
        //Volume Fluid
        v_f = Region_3c_v_pT(p_Sat,T);
        //Volume Gas
        v_g = Region_3t_v_pT(p_Sat,T);
    }else if ((T > 643.15) && (T <= T_Critical)){
        if (T <= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) {
            qDebug() << "#1";
            // u , x
            //Volume Fluid
            v_f = Region_3u_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3x_v_pT(p_Sat,T);
             qDebug() << v_f;
             qDebug() << v_g;
        }else if (T >= Region_4_T_Sat_p(21.93161551 * qPow(10,6))){
            qDebug() << "#3";
            // y , z
            //Volume Fluid
            v_f = Region_3y_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3z_v_pT(p_Sat,T);
            qDebug() << v_f;
            qDebug() << v_g;
        }else if ((T >= Region_4_T_Sat_p(21.90096265 * qPow(10,6))) && (T < Region_4_T_Sat_p(21.93161551 * qPow(10,6)))){
            qDebug() << "#2";
            // u, z
            //Volume Fluid
            v_f = Region_3u_v_pT(p_Sat,T);
            //Volume Gas
            v_g = Region_3z_v_pT(p_Sat,T);
            qDebug() << v_f;
            qDebug() << v_g;
        }
    }
    v = ((1 - x) * v_f) + (x * v_g);
    return v;
}

// State As Function of hs

const IJn_Data Region_4_T_Sat_hs_Data[] = {
    {0, 0, 0.179882673606601}
    , {0, 3, -0.267507455199603}
    , {0, 12, 1.162767226126}
    , {1, 0, 0.147545428713616}
    , {1, 1, -0.512871635973248}
    , {1, 2, 0.421333567697984}
    , {1, 5, 0.56374952218987}
    , {2, 0, 0.429274443819153}
    , {2, 5, -3.3570455214214}
    , {2, 8, 10.8890916499278}
    , {3, 0, -0.248483390456012}
    , {3, 2, 0.30415322190639}
    , {3, 3, -0.494819763939905}
    , {3, 4, 1.07551674933261}
    , {4, 0, 7.33888415457688E-02}
    , {4, 1, 1.40170545411085E-02}
    , {5, 1, -0.106110975998808}
    , {5, 2, 1.68324361811875E-02}
    , {5, 4, 1.25028363714877}
    , {5, 16, 1013.16840309509}
    , {6, 6, -1.51791558000712}
    , {6, 8, 52.4277865990866}
    , {6, 22, 23049.5545563912}
    , {8, 1, 2.49459806365456E-02}
    , {10, 20, 2107964.67412137}
    , {10, 36, 366836848.613065}
    , {12, 24, -144814105.365163}
    , {14, 1, -1.7927637300359E-03}
    , {14, 28, 4899556021.00459}
    , {16, 12, 471.262212070518}
    , {16, 32, -82929439019.8652}
    , {18, 14, -1715.45662263191}
    , {18, 22, 3557776.82973575}
    , {18, 36, 586062760258.436}
    , {20, 24, -12988763.5078195}
    , {28, 36, 31724744937.1057}
    };

double Region_4_T_Sat_hs(double h,double s){
    double Eta = h / Region_4_T_Sat_hs_h_Star;
    double Sigma = s / Region_4_T_Sat_hs_s_Star;
    double sum =0;
    for (int i=0; i < 36; i++){
        sum += Region_4_T_Sat_hs_Data[i].n * qPow((Eta - 0.119),Region_4_T_Sat_hs_Data[i].I) * qPow((Sigma - 1.07),Region_4_T_Sat_hs_Data[i].J);
    }
    return sum *= Region_4_T_Sat_hs_T_Star;
}

double Region_4_p_Sat_hs(double h,double s){
    double T_Sat = Region_4_T_Sat_hs(h,s);
    double p_Sat = Region_4_p_Sat_T(T_Sat);
    return p_Sat;
}

double Region_4_x_hs(double h,double s){
    double T_Sat = Region_4_T_Sat_hs(h,s);
    double p_Sat = Region_4_p_Sat_T(T_Sat);
    double h_f = Region_1_h_pT(T_Sat,p_Sat);
    double h_g = Region_2_h_pT(T_Sat,p_Sat);
    double x = (h - h_f) / (h_g - h_f);
    return x;
}

const IJn_Data Region_4_h_f_1_s_Data[] = {
    {0, 14, 0.332171191705237}
    , {0, 36, 6.11217706323496E-04}
    , {1, 3, -8.82092478906822}
    , {1, 16, -0.45562819254325}
    , {2, 0, -2.63483840850452E-05}
    , {2, 5, -22.3949661148062}
    , {3, 4, -4.28398660164013}
    , {3, 36, -0.616679338856916}
    , {4, 4, -14.682303110404}
    , {4, 16, 284.523138727299}
    , {4, 24, -113.398503195444}
    , {5, 18, 1156.71380760859}
    , {5, 24, 395.551267359325}
    , {7, 1, -1.54891257229285}
    , {8, 4, 19.4486637751291}
    , {12, 2, -3.57915139457043}
    , {12, 4, -3.35369414148819}
    , {14, 1, -0.66442679633246}
    , {14, 22, 32332.1885383934}
    , {16, 10, 3317.66744667084}
    , {20, 12, -22350.1257931087}
    , {20, 28, 5739538.75852936}
    , {22, 8, 173.226193407919}
    , {24, 3, -3.63968822121321E-02}
    , {28, 0, 8.34596332878346E-07}
    , {32, 6, 5.03611916682674}
    , {32, 8, 65.5444787064505}
    };

double Region_4_h_f_1_s(double s){
    double Sigma = s / Region_4_h_f_1_s_s_Star;
    double sum =0;
    for (int i=0; i < 27; i++){
        sum += Region_4_h_f_1_s_Data[i].n * qPow((Sigma - 1.09),Region_4_h_f_1_s_Data[i].I) * qPow((Sigma + 0.366 * qPow(10,-4)),Region_4_h_f_1_s_Data[i].J);
    }
    return sum *= Region_4_h_f_1_s_h_Star;
}


const IJn_Data Region_4_h_f_3a_s_Data[] = {
{0, 1, 0.822673364673336}
, {0, 4, 0.181977213534479}
, {0, 10, -0.011200026031362}
, {0, 16, -7.46778287048033E-04}
, {2, 1, -0.179046263257381}
, {3, 36, 4.24220110836657E-02}
, {4, 3, -0.341355823438768}
, {4, 16, -2.09881740853565}
, {5, 20, -8.22477343323596}
, {5, 36, -4.99684082076008}
, {6, 4, 0.191413958471069}
, {7, 2, 5.81062241093136E-02}
, {7, 28, -1655.05498701029}
, {7, 32, 1588.70443421201}
, {10, 14, -85.0623535172818}
, {10, 32, -31771.4386511207}
, {10, 36, -94589.0406632871}
, {32, 0, -1.3927384708869E-06}
, {32, 6, 0.63105253224098}
};

double Region_4_h_f_3a_s(double s){
    double Sigma = s / Region_4_h_f_3a_s_s_Star;
    double sum =0;
    for (int i=0; i < 19; i++){
        sum += Region_4_h_f_3a_s_Data[i].n * qPow((Sigma - 1.09),Region_4_h_f_3a_s_Data[i].I) * qPow((Sigma + 0.366 * qPow(10,-4)),Region_4_h_f_3a_s_Data[i].J);
    }
    return sum *= Region_4_h_f_3a_s_h_Star;
}

const IJn_Data Region_4_h_g_2c3b_s_Data[] = {
    {0, 0, 1.04351280732769}
    , {0, 3, -2.27807912708513}
    , {0, 4, 1.80535256723202}
    , {1, 0, 0.420440834792042}
    , {1, 12, -105721.24483466}
    , {5, 36, 4.36911607493884E+24}
    , {6, 12, -328032702839.753}
    , {7, 16, -6.7868676080427E+15}
    , {8, 2, 7439.57464645363}
    , {8, 20, -3.56896445355761E+19}
    , {12, 32, 1.67590585186801E+31}
    , {16, 36, -3.55028625419105E+37}
    , {22, 2, 396611982166.538}
    , {22, 32, -4.14716268484468E+40}
    , {24, 7, 3.59080103867382E+18}
    , {36, 20, -1.16994334851995E+40}
    };

double Region_4_h_g_2c3b_s(double s){
    double Sigma = s / Region_4_h_g_2c3b_s_s_Star;
    double sum =0;
    for (int i=0; i < 16; i++){
        sum += Region_4_h_g_2c3b_s_Data[i].n * qPow((Sigma - 1.02),Region_4_h_g_2c3b_s_Data[i].I) * qPow((Sigma - 0.726),Region_4_h_g_2c3b_s_Data[i].J);
    }
    sum = qPow(sum,4);
    return sum *= Region_4_h_g_2c3b_s_h_Star;
}

const IJn_Data Region_4_h_g_2ab_s_Data[] = {
    {1, 8, -524.581170928788}
    , {1, 24, -9269472.18142218}
    , {2, 4, -237.385107491666}
    , {2, 32, 21077015581.2776}
    , {4, 1, -23.9494562010986}
    , {4, 2, 221.802480294197}
    , {7, 7, -5104725.33393438}
    , {8, 5, 1249813.96109147}
    , {8, 12, 2000084369.96201}
    , {10, 1, -815.158509791035}
    , {12, 0, -157.612685637523}
    , {12, 7, -11420042233.2791}
    , {18, 10, 6.62364680776872E+15}
    , {20, 12, -2.27622818296144E+18}
    , {24, 32, -1.71048081348406E+31}
    , {28, 8, 6.60788766938091E+15}
    , {28, 12, 1.66320055886021E+22}
    , {28, 20, -2.18003784381501E+29}
    , {28, 22, -7.87276140295618E+29}
    , {28, 24, 1.51062329700346E+31}
    , {32, 2, 7957321.70300541}
    , {32, 7, 1.31957647355347E+15}
    , {32, 12, -3.2509706829914E+23}
    , {32, 14, -4.18600611419248E+25}
    , {32, 24, 2.97478906557467E+34}
    , {36, 10, -9.53588761745473E+19}
    , {36, 12, 1.66957699620939E+24}
    , {36, 20, -1.75407764869978E+32}
    , {36, 22, 3.47581490626396E+34}
    , {36, 28, -7.10971318427851E+38}
    };

double Region_4_h_g_2ab_s(double s){
    double Sigma1 = s / Region_4_h_g_2ab_s_s1_Star;
    double Sigma2 = s / Region_4_h_g_2ab_s_s2_Star;
    double sum =0;
    for (int i=0; i < 30; i++){
        sum += Region_4_h_g_2ab_s_Data[i].n * qPow((qPow(Sigma1,-1) - 0.513),Region_4_h_g_2ab_s_Data[i].I) * qPow((Sigma2 + 0.524),Region_4_h_g_2ab_s_Data[i].J);
    }
    sum = qExp(sum);
    return sum *= Region_4_h_g_2ab_s_h_Star;
}

double Region_4_h_s(double s){
    double h_Sat = 0;
    if ((s > Region_4_s_Tx(273.15,0)) && (s <= Region_4_s_Tx(623.15,0))){
        h_Sat = Region_4_h_f_1_s(s);
    }else if ((s > Region_4_s_Tx(623.15,0)) && (s <= s_Critical)){
        h_Sat = Region_4_h_f_3a_s(s);
    }else if ((s > s_Critical) && (s <= Boundry_2bc_s)){
        h_Sat = Region_4_h_g_2c3b_s(s);
    }else if ((s > Boundry_2bc_s) && (s < Region_4_s_Tx(273.15,1))){
        h_Sat = Region_4_h_g_2ab_s(s);
    }
    return h_Sat;
}
