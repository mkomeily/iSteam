#ifndef BOUNDRY_3_PSAT_S_H
#define BOUNDRY_3_PSAT_S_H

#include <QtMath>
#include "common.h"

const IJn_Data Region_3_pSat_s_Data[] = {
    {  0,	0,	 0.639767553612785}
        , {1,	1,	-0.129727445396014e2}
        , {1,	32,	-0.224595125848403e16}
        , {4,	7,	 0.177466741801846e7}
        , {12,	4,	 0.717079349571538e10}
        , {12,	14,	-0.378829107169011e18}
        , {16,	36,	-0.955586736431328e35}
        , {24,	10,	 0.187269814676188e24}
        , {28,	0,	 0.119254746466473e12}
        , {32,	18,	 0.110649277244882e37}
};

const double Region_3_pSat_s_p_Star = 22 * qPow(10,6); // Pa
const double Region_3_pSat_s_s_Star = 5.2; // Kj / (Kg * K)
double Region_3_pSat_s(double s);

#endif // BOUNDRY_3_PSAT_S_H
