#include "boundry_3_psat_h.h"

double Region_3_pSat_h(double h){
    double Eta = h / Region_3_pSat_h_h_Star;
    double sum =0;
    for (int i=0; i < 14; i++){
        sum += Region_3_pSat_h_Data[i].n * qPow((Eta-1.02),Region_3_pSat_h_Data[i].I) * qPow((Eta-0.608),Region_3_pSat_h_Data[i].J);
    }
    return sum *= Region_3_pSat_h_p_Star;
}
