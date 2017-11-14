#ifndef BOUNDRY_3_PSAT_H_H
#define BOUNDRY_3_PSAT_H_H

#include <QtMath>
#include "common.h"

const IJn_Data Region_3_pSat_h_Data[] = {
    { 0,	0,	 0.600073641753024}
    ,{1,	1,	-0.936203654849857e1}
    ,{1,	3,	 0.246590798594147e2}
    ,{1,	4,	-0.107014222858224e3}
    ,{1,	36,	-0.915821315805768e14}
    ,{5,	3,	-0.862332011700662e4}
    ,{7,	0,	-0.235837344740032e2}
    ,{8,	24,	 0.252304969384128e18}
    ,{14,	16,	-0.389718771997719e19}
    ,{20,	16,	-0.333775713645296e23}
    ,{22,	3,	 0.356499469636328e11}
    ,{24,	18,	-0.148547544720641e27}
    ,{28,	8,	 0.330611514838798e19}
    ,{36,	24,	 0.813641294467829e38}
};

const double Region_3_pSat_h_p_Star = 22 * qPow(10,6); // Pa
const double Region_3_pSat_h_h_Star = 2600; // Kj / Kg
double Region_3_pSat_h(double h);

#endif // BOUNDRY_3_PSAT_H_H
