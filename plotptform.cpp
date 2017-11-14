#include "plotptform.h"
#include "ui_plotptform.h"
#include "common.h"
#include "region_4.h"
#include "boundry_23.h"
#include <QPainter>
#include <QDebug>
#include "mainwindow.h"

plotpTForm::plotpTForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plotpTForm)
{
    ui->setupUi(this);
}
void plotpTForm::recieveDataSlot(ThermoState state){
    preLoadData = true;
    currentState = state;
}
void plotpTForm::wheelEvent(QWheelEvent *event){
    if (event->buttons() && Qt::MiddleButton){
    float wheel = event->delta() / 120 ;
    float zoom = qPow(1.0 + qAbs(wheel)/4.0 , wheel > 0 ? 1 : -1);
    zoomLevel *= zoom;
    plotpTForm::repaint();
    }
}
void plotpTForm::formLoad(){

}
void plotpTForm::paintEvent(QPaintEvent *event){

    //QPainter painter;
    QWidget *plotArea(this);
    plotArea->setGeometry(10,35,780,555);
    plotArea->show();
    QPainter painter(plotArea);
    W = plotArea->width();
    H = plotArea->height();
    double ScaleX = ((W - 2*offsetX)/ 2273.15) * zoomLevel;
    double ScaleY = ((H - 2*offsetY)/ 100) * zoomLevel;
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));

    // Axis X , Y
    painter.drawPoint(NewCoordinate(0,0));
    painter.drawLine(NewCoordinate(0,0),NewCoordinate(W,0));
    painter.drawLine(NewCoordinate(0,0),NewCoordinate(0,H));

    //Arrow X
    painter.drawLine(NewCoordinate(W -offsetX,0),NewCoordinate(W -offsetX - 5 , 5));
    painter.drawLine(NewCoordinate(W -offsetX ,0),NewCoordinate(W -offsetX - 5 , -5));

    //Arrow Y
    painter.drawLine(NewCoordinate(0 ,H -offsetY ),NewCoordinate(  5 , H - offsetY - 5));
    painter.drawLine(NewCoordinate(0 ,H -offsetX),NewCoordinate( - 5, H - offsetX - 5));

    //Draw Regions
    QPoint xy;
    double w,h;
    painter.setPen(QPen(Qt::blue, 0.75, Qt::SolidLine, Qt::RoundCap));
    xy = NewCoordinate(273.15 * ScaleX , 100 * ScaleY);
    w= 800 * ScaleX;
    h = 100 * ScaleY;
    painter.drawRect(xy.x(),xy.y(),w,h);

    //Region 5
    w = 1200 * ScaleX;
    h = 50 * ScaleY;    
    painter.drawLine(NewCoordinate(1073.15* ScaleX ,50* ScaleY),NewCoordinate(2273.15* ScaleX ,50* ScaleY ));
    painter.drawLine(NewCoordinate(2273.15* ScaleX ,50* ScaleY),NewCoordinate(2273.15* ScaleX ,0* ScaleY));
    painter.drawLine(NewCoordinate(2273.15* ScaleX ,0* ScaleY),NewCoordinate(1073.15* ScaleX ,0* ScaleY));

    // T = 623.15
    painter.setPen(QPen(Qt::blue, 0.75, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(NewCoordinate(623.15 * ScaleX, 100 * ScaleY),NewCoordinate(623.15 * ScaleX,(Region_4_p_Sat_T(623.15) / qPow(10,6)) * ScaleY));

    //Boundry 23
    double j=1 * qPow(10,4);
    double p1 = Region_4_p_Sat_T(623.15);
    double T1 = 623.15;
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap));
    while (p1 <= 100 * qPow(10,6))
    {
        T1 = Boundry_23_T_p(p1) ;
        painter.drawPoint(NewCoordinate(T1 * ScaleX,p1 / qPow(10,6) * ScaleY));
        p1 = p1 + j;
    }

    //Region 4
    double i= 1 * qPow(10,3);
    double p = p_TriplePoint;
    double T = 0;
    painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap));
    while (p <= p_Critical)
    {
        T = Region_4_T_Sat_p(p);
        painter.drawPoint(NewCoordinate(T * ScaleX,p / qPow(10,6) * ScaleY));
        p = p + i;
    }

    // Pre Load Data Draw
    if (preLoadData){
        painter.setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(NewCoordinate(currentState.T * ScaleX,currentState.p / qPow(10,6) * ScaleY));
    }

}
QPoint plotpTForm::NewCoordinate(double x , double y){
    QPoint tp;
    tp.setX(x + offsetX);
    tp.setY(H - y - offsetY);
    return tp;
}

plotpTForm::~plotpTForm()
{
    delete ui;
}
