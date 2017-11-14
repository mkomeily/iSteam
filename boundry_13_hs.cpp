#include "boundry_13_hs.h"

double Boundry_13_hs(double s){
    double sum = 0;
    double Sigma = s / Boundry_13_h_s_s_Star;
    for (int i=0 ; i < 6; i++){
        sum += Boundry_13_h_s_Data[i].n + qPow((Sigma -0.884),Boundry_13_h_s_Data[i].I) * qPow((Sigma - 0.864),Boundry_13_h_s_Data[i].J);
    }
    return sum *= Boundry_13_h_s_h_Star;
}
