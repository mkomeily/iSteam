#include "boundry_23.h"
#include <math.h>

double Boundry_23_p_T(double T){
    double p = (Boundry_23_n[0] + Boundry_23_n[1] * Boundry_23_theta(T) + Boundry_23_n[2] * pow(Boundry_23_theta(T),2)) * Boundry_23_p_Star;
    return p;
}

double Boundry_23_T_p(double p){
    double T = (Boundry_23_n[3] + sqrt((Boundry_23_pi(p) - Boundry_23_n[4])/Boundry_23_n[2])) * Boundry_23_T_Star;
    return T;
}

double Boundry_23_theta(double T){
    double theta = T / Boundry_23_T_Star;
    return theta;
}
double Boundry_23_pi(double p){
    double pi = p / Boundry_23_p_Star;
    return pi;
}

const IJn_Data Boundry_23_T_hs_Data[] = {
    {-12, 10, 6.2909626082981E-04}
    , {-10, 8, -8.23453502583165E-04}
    , {-8, 3, 5.15446951519474E-08}
    , {-4, 4, -1.17565945784945}
    , {-3, 3, 3.48519684726192}
    , {-2, -6, -5.07837382408313E-12}
    , {-2, 2, -2.84637670005479}
    , {-2, 3, -2.36092263939673}
    , {-2, 4, 6.01492324973779}
    , {0, 0, 1.48039650824546}
    , {1, -3, 3.60075182221907E-04}
    , {1, -2, -1.26700045009952E-02}
    , {1, 10, -1221843.32521413}
    , {3, -2, 0.149276502463272}
    , {3, -1, 0.698733471798484}
    , {5, -5, -2.52207040114321E-02}
    , {6, -6, 1.47151930985213E-02}
    , {6, -3, -1.08618917681849}
    , {8, -8, -9.36875039816322E-04}
    , {8, -2, 81.9877897570217}
    , {8, -1, -182.041861521835}
    , {12, -12, 2.61907376402688E-06}
    , {12, -1, -29162.6417025961}
    , {14, -12, 1.40660774926165E-05}
    , {14, 1, 7832370.62349385}
    };

double Boundry_23_T_hs(double h,double s){
    double sum = 0;
    double Sigma = s / Boundry_23_T_hs_s_Star;
    double Eta = h / Boundry_23_T_hs_h_Star;
    for (int i=0 ; i < 25; i++){
        sum += Boundry_23_T_hs_Data[i].n + qPow((Eta - 0.727),Boundry_23_T_hs_Data[i].I) * qPow((Sigma - 0.864),Boundry_23_T_hs_Data[i].J);
    }
    return sum *= Boundry_23_T_hs_T_Star;
}
