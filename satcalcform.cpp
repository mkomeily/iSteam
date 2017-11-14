#include <QtWidgets>
#include "common.h"
#include "satcalcform.h"
#include "ui_satcalcform.h"
#include "mainwindow.h"
#include "region_1.h"
#include "region_2.h"
#include "region_3.h"
#include "boundry_3_psat_h.h"
#include "region_4.h"
#include "region_5.h"


satCalcForm::satCalcForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::satCalcForm)
{
    ui->setupUi(this);
    connect(ui->btnClose,SIGNAL(pressed()),this,SLOT(CloseMe()));
    connect(ui->btnCalculate,SIGNAL(pressed()),this,SLOT(Calculate()));
    connect(ui->cmbMode,SIGNAL(currentTextChanged(QString)),this,SLOT(ModeChanged()));
    connect(ui->cmbPropertyUnit1,SIGNAL(currentIndexChanged(QString)),this,SLOT(UnitChanged()));
    connect(ui->cmbPropertyUnit2,SIGNAL(currentIndexChanged(QString)),this,SLOT(UnitChanged()));
    connect(ui->btnPlot,SIGNAL(pressed()),this,SLOT(recieveDataSlot()));
    FormLoad();
}
satCalcForm::~satCalcForm()
{
    delete ui;
}
void satCalcForm::recieveDataSlot(){
    emit sendDataSignal(currentState);
}
void satCalcForm::CloseMe(){
    this->parentWidget()->close();
}
void satCalcForm::FormLoad(){
    ClearForm();
    MakeTable();
}
void satCalcForm::ClearForm(){
    ui->cmbMode->setCurrentIndex(0);
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
    ui->lblProperty1->clear();
    ui->lblProperty2->clear();
}
void satCalcForm::MakeTable(){
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStandardItemModel *model = new QStandardItemModel(0,6,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("x")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("p")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("T")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("v")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("h")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("s")));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setFixedWidth(30);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void satCalcForm::AddToTable(ThermoState state){
    QAbstractItemModel *m = ui->tableView->model();
    int i = m->rowCount();
    m->insertRow(i);    
    m->setData(m->index(i, 0), state.x);
    m->setData(m->index(i, 1), QString::number(state.p , 'f',0));
    m->setData(m->index(i, 2), QString::number(state.T , 'g',7));
    m->setData(m->index(i, 3), QString::number(state.v, 'e', 5));
    m->setData(m->index(i, 4), QString::number(state.h, 'f',5));
    m->setData(m->index(i, 5), QString::number(state.s, 'f',5));
    m->submit();
    ui->tableView->setModel(m);

}

void satCalcForm::AddToTableColorful(ThermoState state, QString clr){
    QAbstractItemModel *m = ui->tableView->model();
    int i = m->rowCount();
    m->insertRow(i);
    m->setData(m->index(i, 0), state.x);
    m->setData(m->index(i, 1), QString::number(state.p , 'f',0));
    m->setData(m->index(i, 2), QString::number(state.T , 'g',7));
    m->setData(m->index(i, 3), QString::number(state.v, 'e', 5));
    m->setData(m->index(i, 4), QString::number(state.h, 'f',5));
    m->setData(m->index(i, 5), QString::number(state.s, 'f',5));
    if (clr == "RED"){
    for ( int j =0;j<6;j++){
         m->setData(m->index(i, j), QVariant(QBrush(QColor(255,77,77))), Qt::BackgroundRole);
    }
    }else if(clr == "BLUE"){
        for ( int j =0;j<6;j++){
             m->setData(m->index(i, j), QVariant(QBrush(QColor(0,191,255))), Qt::BackgroundRole);
        }
    }
    m->submit();
    ui->tableView->setModel(m);
}

void satCalcForm::UnitChanged(){
    int mode = ui->cmbMode->currentIndex();
    int unit1,unit2;
    switch (mode) {
    case 0: // Select Mode
        unit1 = 1;
        unit2 = 1;
        break;
    case 1: // State(p,x)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 1 * pow(10,6);
            break;
        case 1:
            Convert_Factor_Property1 = 1 * pow(10,3);
            break;
        case 2:
            Convert_Factor_Property1 = 1;
            break;
        default:
            break;
        }        
        unit2 = ui->cmbPropertyUnit2->currentIndex();
        switch (unit2) {
        case 0:
            Convert_Factor_Property2 = 1;
            break;
        case 1:
            Convert_Factor_Property2 = 100;
            break;
        default:
            break;
        }
        break;
    case 2: // State(T,x)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 0;
            break;
        case 1:
            Convert_Factor_Property1 = +273.15;
            break;
        default:
            break;
        }
        unit2 = ui->cmbPropertyUnit2->currentIndex();
        switch (unit2) {
        case 0:
            Convert_Factor_Property2 = 1;
            break;
        case 1:
            Convert_Factor_Property2 = 100;
            break;
        default:
            break;
        }
        break;
    case 3: // State(p,h)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 1 * pow(10,6);
            break;
        case 1:
            Convert_Factor_Property1 = 1 * pow(10,3);
            break;
        case 2:
            Convert_Factor_Property1 = 1;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    case 4: // State(T,h)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 0;
            break;
        case 1:
            Convert_Factor_Property1 = +273.15;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    case 5: // State(p,s)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 1 * pow(10,6);
            break;
        case 1:
            Convert_Factor_Property1 = 1 * pow(10,3);
            break;
        case 2:
            Convert_Factor_Property1 = 1;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    case 6:// State(T,s)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 0;
            break;
        case 1:
            Convert_Factor_Property1 = +273.15;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    case 7: // State(p,v)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 1 * pow(10,6);
            break;
        case 1:
            Convert_Factor_Property1 = 1 * pow(10,3);
            break;
        case 2:
            Convert_Factor_Property1 = 1;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    case 8: // State(T,v)
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        switch (unit1) {
        case 0:
            Convert_Factor_Property1 = 0;
            break;
        case 1:
            Convert_Factor_Property1 = +273.15;
            break;
        default:
            break;
        }
        Convert_Factor_Property2 = 1;
        break;
    default:
        break;
    }
}
void satCalcForm::ModeChanged(){
    int mode = ui->cmbMode->currentIndex();
    switch (mode) {
    case 0:
        ClearForm();
        break;
    case 1:
        ui->lblProperty1->setText("Pressure: ");        
        ui->lblProperty2->setText("Quality: ");
        SetUnit_px();
        break;
    case 2:
        ui->lblProperty1->setText("Temperature: ");
        ui->lblProperty2->setText("Quality: ");
        SetUnit_Tx();
        break;
    case 3:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText("Enthalpy: ");
        SetUnit_ph();
        break;
    case 4:
        ui->lblProperty1->setText("Temperature: ");
        ui->lblProperty2->setText("Enthalpy: ");
        SetUnit_Th();
        break;
    case 5:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText("Entropy: ");
        SetUnit_ps();
        break;
    case 6:
        ui->lblProperty1->setText("Temperature: ");
        ui->lblProperty2->setText("Entropy: ");
        SetUnit_Ts();
        break;
    case 7:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText("Volume: ");
        SetUnit_pv();
        break;
    case 8:
        ui->lblProperty1->setText("Temperature: ");
        ui->lblProperty2->setText("Volume: ");
        SetUnit_Tv();
        break;
    default:
        break;
    }
}
void satCalcForm::SetUnit_Nothing(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
}
void satCalcForm::SetUnit_px(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[0,1]");
    ui->cmbPropertyUnit2->addItem("%");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_Tx(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[K]");
    ui->cmbPropertyUnit1->addItem("[C]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[0,1]");
    ui->cmbPropertyUnit2->addItem("%");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_ph(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ/kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_Th(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[K]");
    ui->cmbPropertyUnit1->addItem("[C]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ/kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_ps(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ/(kg*K)]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_Ts(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[K]");
    ui->cmbPropertyUnit1->addItem("[C]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ/(kg*K)]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_pv(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[(m^3)/kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::SetUnit_Tv(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[K]");
    ui->cmbPropertyUnit1->addItem("[C]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[(m^3)/kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}

void satCalcForm::Calculate(){    
    ThermoState state , stt;
    double prp1 = 0;
    double prp2 = 0;   
    int mode = ui->cmbMode->currentIndex();
    if (ui->lblProperty1->text() == "Temperature: "){       
        prp1 = ui->lnProperty1->text().toDouble() + Convert_Factor_Property1;
    } else {
        prp1 = ui->lnProperty1->text().toDouble() * Convert_Factor_Property1;
    }
    if (ui->lblProperty2->text() == "Temperature: "){
        prp2 = ui->lnProperty2->text().toDouble() + Convert_Factor_Property2;
    } else {
        prp2 = ui->lnProperty2->text().toDouble() * Convert_Factor_Property2;
    }
    switch (mode) {
    case 1: // State(p,x)
        state.p = prp1;
        state.x = prp2;
        state = Region_4_Tx( Region_4_T_Sat_p(prp1),prp2);
        break;
    case 2: // State(T,x)
        state.T = prp1;
        state.x = prp2;
        state = Region_4_Tx(prp1,prp2);
        break;
    case 3: // State(p,h)
        state.p = prp1;
        state.h = prp2;
        state = Region_4_ph(prp1,prp2);
        break;
    case 4: // State(T,h)
        state.T = prp1;
        state.h = prp2;
        state = Region_4_Th(prp1,prp2);
        break;
    case 5: // State(p,s)
        state.p = prp1;
        state.s = prp2;
        state = Region_4_ps(prp1,prp2);
        break;
    case 6: // State(T,s)
        state.T = prp1;
        state.s = prp2;
        state = Region_4_Ts(prp1,prp2);
        break;
    case 7: // State(p,v)
        state.p = prp1;
        state.v = prp2;
        state = Region_4_pv(prp1,prp2);
        break;
    case 8: // State(T,v)
        state.T = prp1;
        state.v = prp2;
        state = Region_4_Tv(prp1,prp2);
        break;
    default:
        break;
    }

    //Table
    stt = Region_4_Tx(state.T,0);
    AddToTableColorful(stt,"BLUE");
    AddToTable(state);
    stt = Region_4_Tx(state.T,1);
    AddToTableColorful(stt,"RED");
    currentState = state;
}
