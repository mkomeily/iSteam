#include "boundry_3_psat_s.h"

double Region_3_pSat_s(double s){
    double Sigma = s / Region_3_pSat_s_s_Star;
    double sum =0;
    for (int i=0; i < 10; i++){
        sum += Region_3_pSat_s_Data[i].n * qPow((Sigma-1.03),Region_3_pSat_s_Data[i].I) * qPow((Sigma-0.699),Region_3_pSat_s_Data[i].J);
    }
    return sum *= Region_3_pSat_s_p_Star;
}
