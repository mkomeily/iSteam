#include "common.h"
#include "region_1.h"
#include "region_2.h"
#include "region_2_meta.h"
#include "region_3.h"
#include "region_4.h"
#include "region_5.h"
#include "boundry_23.h"
#include "boundry_3_psat_h.h"
#include "boundry_3_psat_s.h"
#include "boundry_13_h_s.h"
#include "boundry_23_h_s.h"
#include <QtMath>
#include <QDebug>

Line makeLine(Point A, Point B){
   Line line;
   line.A = 0;
   line.B = -1 * (B.Y - A.Y) / (B.X - A.X);
   line.C = A.X - A.Y;
   return line;
}
double toLine(Line line, Point X){
    double f = 0;
    f = line.A * X.X + line.B * X.Y + line.C ;
    return f;
}

float sign (Point p1, Point p2, Point p3)
{
    return (p1.X - p3.X) * (p2.Y - p3.Y) - (p2.X - p3.X) * (p1.Y - p3.Y);
}

bool isInsideCriticalTriangle(Point p){
    Point P1; //(T,p)
    Point P2;
    Point P3;
    bool b1, b2, b3;

    P1.X = 643.15; // T
    P1.Y = Region_4_p_Sat_T(643.15); // p

    P2.X = Boundry_3qu_T_p(22.5 * qPow(10,6)); // T
    P2.Y = 22.5 * qPow(10,6); // p

    P3.X = Boundry_3rx_T_p(22.5 * qPow(10,6)); // T
    P3.Y = 22.5 * qPow(10,6); // p

    b1 = sign(p, P1, P2) < 0.0f;
    b2 = sign(p, P2, P3) < 0.0f;
    b3 = sign(p, P3, P1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

int findRegion_pT(double p, double T){
    int region = 0;
    double p_Sat;
    if ((T >= Region_2_g_pT_T_Max && T <= Region_5_g_pT_T_Max ) && (p > Region_5_g_pT_p_Min && p <= Region_5_g_pT_p_Max)){
        region = 5;
    } else if ((T <= Region_2_g_pT_T_Max && T >= Region_1_g_pT_T_Min ) && (p > Region_1_g_pT_p_Min && p <= Region_1_g_pT_p_Max)) {
        if (T > Region_1_g_pT_T_Max){
            if (p > Boundry_23_p_T(T)){
                region = 3;
                if (T < T_TriplePoint){
                    p_Sat = Region_4_p_Sat_T(T);
                    if ( abs(p - p_Sat) < eps_p ){
                        region = 4;
                    }
                }
            }
            else { // meta OR 2
                region = 2;
                 }
        } else {
            p_Sat = Region_4_p_Sat_T(T);
            if ( abs(p - p_Sat) < eps_p ){
                region = 4;
            } else if (p > p_Sat) {
                region = 1;
            } else { // meta OR 2
                     region = 2;
            }
        }
    } else {
        region = 0; // Error, outside valid area
    }
    return region;
}

QString findPhase(ThermoState state){
    double T_Sat;
    double p , T;
    QString phase="";
    p = state.p;
    T = state.T;
    T_Sat = Region_4_T_Sat_p(p);
    if (T > T_Sat)
    {
        phase = "Superheat Vapor";
    }else if (T < T_Sat){
        phase = "Subcooled Substance";
    }else if (T = T_Sat){
        phase = "Saturated Area";
    }
    return phase;
}
ThermoState calcState_pT_Region(double p,double T,int region){
    ThermoState state;
    switch (region) {
    case 0:
        break;
    case 1:
        state = Region_1_pT(p,T);
        break;
    case 2:
        state = Region_2_pT(p,T);
        break;
    case 201:
        state = Region_2_meta_pT(p,T);
        break;
    case 3:
        state = Region_3_pT(p,T);
        break;
    case 4:
        break;
    case 5:
        state = Region_5_pT(p,T);
        break;
    default:
        break;
    }
    return state;
}
int findRegion_ph(double p, double h){
    int region = 0;
    if (p < p_TriplePoint || p > Region_1_g_pT_p_Max){
        return region = 0;
    }
    if (p < Region_4_p_Sat_T(623.15)){
        double T_Sat = Region_4_T_Sat_p(p);
        double h_l = Region_1_h_pT(p,T_Sat);
        if (h <= h_l) {
            return region = 1;
        }
        double h_v = Region_2_h_pT(p,T_Sat);
        if (h <= h_v) {
            return region = 4;
        }
        double h_45 = Region_2_h_pT(p,Region_5_g_pT_T_Min);
        if (h <= h_45) {
            return region = 2;
        }
        if (p > 50 * qPow(10,6)){
            return region = 0;
        }
        double h_5u = Region_5_h_pT(p,Region_5_g_pT_T_Max);
        if(h < h_5u){
            return region = 5;
        }
        return region = 0;
    }else{
        if (h < Region_1_h_pT(p,Region_1_g_pT_T_Max)){
            return region = 1;
        }
        if (h < Region_2_h_pT(p,Boundry_23_T_p(p))){
            if (p > Region_3_pSat_h(h)) {
                 return region = 3;
            }else{
                 return region = 4;
            }
        }
        if (h < Region_2_h_pT(p,Region_2_g_pT_T_Max)){
            return region = 2;
        }
    }
    return region=0;
}
ThermoState calcState_ph_Region(double p,double h,int region){
    ThermoState state;
    switch (region) {
    case 0:
        break;
    case 1:
        state = Region_1_ph(p,h);
        break;
    case 2:
        state = Region_2_ph(p,h);
        break;
    case 3:
        state = Region_3_ph(p,h);
        break;
    case 4:
        break;
    case 5:
        //state = Region_5_ph(p,h);
        break;
    default:
        break;
    }
    return state;
}

int findRegion_ps(double p, double s){
   double region;
   if ((p < p_TriplePoint) || (p > 100 * qPow(10,6)) || (s < 0) || (s > Region_5_pT(p,Region_5_g_pT_T_Max).s) ){
       return region=0;
   }
   if (s > Region_2_pT(p,Region_2_g_pT_T_Max).s){
        if (p <= (50 * qPow(10,6))){
            return region=5;
        }else{
            return region=0;
        }
    }
    double ss = 0;
    if (p > Region_4_p_Sat_T(623.15)){
        ss = Region_2_pT(p, Boundry_23_T_p(p)).s;
    }else{
        ss = Region_2_pT(p, Region_4_T_Sat_p(p)).s;
    }
    if (s > ss){
        return region=2;
    }
    ss = Region_1_pT(p,Region_1_g_pT_T_Max).s;
    if ((p > Region_4_p_Sat_T(623.15)) && (s > ss)){
        if (p > Region_3_pSat_s(s)){
            return region=3;
        }else{
            return region=4;
        }
    }
    if ((p < Region_4_p_Sat_T(623.15)) && (s > Region_1_pT(p, Region_4_p_Sat_T(p)).s)){
        return 4;
    }
    if ((p > p_TriplePoint) && (s > Region_1_pT(p,Region_1_g_pT_T_Min).s)){
        return region=1;
    }
    return region=0;
}
ThermoState calcState_ps_Region(double p,double s,int region){
    ThermoState state;
    switch (region) {
    case 0:
        break;
    case 1:
        state = Region_1_ps(p,s);
        break;
    case 2:
        state = Region_2_ps(p,s);
        break;
    case 3:
        state = Region_3_ps(p,s);
        break;
    case 4:
        break;
    case 5:
        //state = Region_5_ps(p,s);
        break;
    default:
        break;
    }
    return state;
}
int findRegion_hs(double h, double s){
    double region = 0;
    if (s < Region_4_s_Tx(273.15,0)){
        qDebug() << "##";
        return region = 0;
    }
//    %Check linear adaption to p=0.000611. if bellow region 4.
//    hMin = (((-0.0415878 - 2500.89262) / (-0.00015455 - 9.155759)) * s);
//    if s < 9.155759395  && h < hMin
//        region_hs = 0;
//        return
//    end

//    %******Kolla 1 eller 4. (+liten bit �ver B13)    
    if ((s >= Region_4_s_Tx(273.15,0)) && (s <= Region_4_s_Tx(623.15,0))){
        qDebug() << "#0";
        if (h < Region_4_h_s(s)){
            qDebug() << "#1";
            return region = 4;
        }else if (s < Region_1_s_pT(100 * qPow(10,6),623.15)){  // %100MPa line is limiting
            qDebug() << "#2";
            double TMax = Region_1_ps(100 * qPow(10,6), s).T;
            double hMax = Region_1_h_pT(100 * qPow(10,6), TMax);
            if (h < hMax){
                qDebug() << "#3";
                return region = 1;
            }else{
                qDebug() << "#4";
                return region = 0;
            }
        }else{  // %The point is either in region 4,1,3. Check B23
            qDebug() << "#5";
            double hB = Boundry_13_h_s(s);
            if (h < hB){
                qDebug() << "#6";
                return region = 1;
            }
            double TMax = Region_3_ps(100 * qPow(10,6), s).T;
            double vmax = Region_3_ps(100 * qPow(10,6), s).v;
            double rho = (1 / vmax);
            double hMax = Region_3_h_RhoT(rho , TMax);
            if (h < hMax){
                qDebug() << "#7";
                return region = 3;
            }else{
                qDebug() << "#8";
                return region = 0;
            }
        }
    }

//    %******Kolla region 2 eller 4. (�vre delen av omr�de b23-> max)
    if ((s >= Boundry_23_hs_s_Max) && (s <= Region_2_s_pT(Region_4_p_Sat_T(273.15),1073.15))){
        qDebug() << "#0";
        double hMax = 0;
        if (s > Region_4_s_Tx(273.15,1)){  //%Above region 4
            qDebug() << "#1";
            double Tmin = Region_2_ps(Region_4_p_Sat_T(273.15), s).T;
            double hMin = Region_2_pT(Region_4_p_Sat_T(273.15), Tmin).h;
            //%function adapted to h(1073.15,s)
            hMax = -0.07554022 * qPow(s,4) + 3.341571 * qPow(s,3) - 55.42151 * qPow(s,2) + 408.515 * s + 3031.338;
            if ((h > hMin)  && (h < hMax)){
                qDebug() << "#3";
                return region = 2;
            }else{
                qDebug() << "#4";
                return region = 0;
            }
        }
        double hV = Region_4_h_s(s);
        if (h < hV){   //%Region 4. Under region 3.
            qDebug() << "#5";
            return region = 4;
        }        
        if (s < Region_2_s_pT(100 * qPow(10,6),1073.15)){
            qDebug() << "#6";
            double TMax = Region_2_ps(100 * qPow(10,6), s).T;
            hMax = Region_2_pT(100 * qPow(10,6), TMax).h;
        }else{        //%function adapted to h(1073.15,s)
            qDebug() << "#7";
            hMax = -2.988734 * qPow(s,4) + 121.4015 * qPow(s,3) - 1805.15 * qPow(s,2) + 11720.16 * s - 23998.33;
        }
        if (h < hMax){   //%Region 2. �ver region 4.
            qDebug() << "#8";
            return region = 2;
        }else{
            qDebug() << "#9";
            return region = 0;
        }
    }

//    %Kolla region 3 eller 4. Under kritiska punkten.
    if ((s >= Region_4_s_Tx(623.15,0)) && (s <= s_Critical)){
        qDebug() << "#10";
        if (h < Region_4_h_s(s)){
            qDebug() << "#11";
            return region = 4;
        }
        double TMax = Region_3_ps(100 * qPow(10,6), s).T;
        double vmax = Region_3_ps(100 * qPow(10,6), s).v;
        double rho = (1 / vmax);
        double hMax = Region_3_h_RhoT(rho , TMax);
        if (h < hMax){
            qDebug() << "#12";
            return region = 3;
        }else{
            qDebug() << "#13";
            return region = 0;
        }
    }

//    Check region 3 or 4 from the critical point to the upper part of b23
    if ((s >= s_Critical) && (s <= Boundry_23_hs_s_Max)){
        qDebug() << "#14";
        if (h < Region_4_h_s(s)){
            qDebug() << "#15";
            return region = 4;
        }
//    Check if we are under b23 validity.
        if (s <= Boundry_23_hs_s_Min){
            qDebug() << "#16";
            double TMax = Region_3_ps(100 * qPow(10,6), s).T;
            double vmax = Region_3_ps(100 * qPow(10,6), s).v;
            double rho = (1 / vmax);
            double hMax = Region_3_h_RhoT(rho , TMax);
            if (h < hMax){
                qDebug() << "#17";
                return region = 3;
            }else{
                qDebug() << "#18";
                return region = 0;
            }
        }else{    // Inside the area for B23 in the left.
            qDebug() << "#19";
            if (h > Region_2_h_pT(100 * qPow(10,6),863.15)){    //Above the B23 h_left
                qDebug() << "#20";
                if (s > Region_2_s_pT(100 * qPow(10,6),623.15)){
                    qDebug() << "#21";
                    double TMax = Region_2_ps(100 * qPow(10,6), s).T;
                    double hMax = Region_2_pT(100 * qPow(10,6), TMax).h;
                    if (h < hMax){
                        qDebug() << "#22";
                        return region = 2;
                    }else{
                        qDebug() << "#23";
                        return region = 0;
                    }
                }else{
                    qDebug() << "#24";
                    return region = 0;
                }
            }
            if (h < Region_4_h_Tx(623.15,1)){    // Below is B23 in h_left but we have already checked above the hV_2c3b
                qDebug() << "#25";
                return region = 3;
            }
            // We are in the b23 area in the s and h joints.
            double Tact = Boundry_23_T_hs(h, s); // ### NOT OK ###
            double pact = Region_2_hs(h, s).p;
            double pBound = Boundry_23_p_T(Tact);
            qDebug() << Tact;
            qDebug() << pact;
            qDebug() << pBound;
            if (pact > pBound){
                qDebug() << "#26";
                return region = 3;
            }else{
                qDebug() << "#27";
                return region = 2;
            }
        }
    }
}

ThermoState calcState_hs_Region(double h,double s,int region){
    ThermoState state;
    switch (region) {
    case 0:
        break;
    case 1:
        state = Region_1_hs(h,s);
        break;
    case 2:
        state = Region_2_hs(h,s);
        break;
    case 3:
        state = Region_3_hs(h,s);
        break;
    case 4:
        state = Region_4_hs(h,s);
        break;
    case 5:
        break;
    default:
        break;
    }
    return state;
}

QString htmlMaker(ThermoState state){
    QString html;
    QString sp = " ";
    html =  "<body>"
            "<table>"
            "<tr>"
            "<th align=left>Property</th>"
            "<th align=left>Value</th>"
            "<th align=left>Unit</th>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Temptature: </td>"
            "<td class=\"value\">"+ QString::number(state.T,'e',9) +"</td>"
            "<td class=\"unit\">[K]</td>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Pressure: </td>"
            "<td class=\"value\">"+ QString::number(state.p,'e',9) +"</td>"
            "<td class=\"unit\">[Pa]</td>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Specific Volume: </td>"
            "<td class=\"value\">"+ QString::number(state.v,'e',9) +"</td>"
            "<td class=\"unit\">[m3 / kg]</td>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Specific Enthalpy: </td>"
            "<td class=\"value\">"+ QString::number(state.h,'e',9) +"</td>"
            "<td class=\"unit\">[kJ / kg]</td>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Specific Entropy: </td>"
            "<td class=\"value\">"+ QString::number(state.s,'e',9) +"</td>"
            "<td class=\"unit\">[kJ / (kg * K)]</td>"
            "</tr>"
            "<tr>"
            "<td class=\"title\">Quality: </td>"
            "<td class=\"value\">"+ QString::number(state.x * 100,'e',9) +"</td>"
            "<td class=\"unit\">[ % ]</td>"
            "</tr>"
            "</table>"
            "</body>";
    return html;
}
QString cssMaker(){
    QString css;
    css = "body {background-color: #E0EBEF;} "
          "th {color: darkgreen; padding-bottom: 10px;} "
          "td.title {color: darkblue;} "
          "td.unit {color: red} "
          "td.value {color: black} "
          "td.value {padding-right: 10px;}";
    return css;
}
double Pa_to_MPa(double p){
    return (p / pow(10,6));
}
double MPa_to_Pa(double p){
    return (p * pow(10,6));
}
double Pa_to_kPa(double p){
    return (p / pow(10,3));
}
double kPa_to_Pa(double p){
    return (p * pow(10,3));
}
double C_to_K(double c){
    return (c + 273.15);
}
double K_to_C(double k){
    return (k - 273.15);
}


