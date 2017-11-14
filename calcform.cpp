#include <QtWidgets>
#include "common.h"
#include "calcform.h"
#include "ui_calcform.h"
#include "mainwindow.h"
#include "region_1.h"
#include "region_2.h"
#include "region_3.h"
#include "boundry_3_psat_h.h"
#include "region_4.h"
#include "region_5.h"


calcForm::calcForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calcForm)
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
calcForm::~calcForm()
{
    delete ui;
}
void calcForm::recieveDataSlot(){
    emit sendDataSignal(currentState);
}
void calcForm::CloseMe(){
    this->parentWidget()->close();
}
void calcForm::FormLoad(){
    ui->txtThermoState->setReadOnly(true);
    ui->txtThermoState->insertHtml("<b>Welcome</b>");
    ui->txtThermoState->insertHtml("<br></br>");
    ClearForm();
    MakeTable();
}
void calcForm::ClearForm(){
    ui->cmbMode->setCurrentIndex(0);
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
    ui->lblProperty1->clear();
    ui->lblProperty2->clear();
}
void calcForm::MakeTable(){
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStandardItemModel *model = new QStandardItemModel(0,7,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("IAWPS-IF 97")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Phase")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("p")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("T")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("v")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("h")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("s")));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setFixedWidth(30);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void calcForm::AddToTable(ThermoState state){
    QAbstractItemModel *m = ui->tableView->model();
    int i = m->rowCount();
    m->insertRow(i);
    m->setData(m->index(i, 0), state.region);
    m->setData(m->index(i, 1), state.phase);
    m->setData(m->index(i, 2), QString::number(state.p , 'e',9));
    m->setData(m->index(i, 3), QString::number(state.T , 'e',9));
    m->setData(m->index(i, 4), QString::number(state.v, 'e', 9));
    m->setData(m->index(i, 5), QString::number(state.h, 'e',9));
    m->setData(m->index(i, 6), QString::number(state.s, 'e',9));
    m->submit();
    ui->tableView->setModel(m);
}
void calcForm::UnitChanged(){
    int mode = ui->cmbMode->currentIndex();
    int unit1,unit2;
    switch (mode) {
    case 0:
        unit1 = 1;
        unit2 = 1;
        break;
    case 1:
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
            Convert_Factor_Property2 = 0;
            break;
        case 1:
            Convert_Factor_Property2 = +273.15;
            break;
        default:
            break;
        }
        break;
    case 2:
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
    case 3:
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
    case 4:
        Convert_Factor_Property1 = 1;
        Convert_Factor_Property2 = 1;
        break;
    case 5:
        unit2 = ui->cmbPropertyUnit2->currentIndex();
        switch (unit2) {
        case 0:
            Convert_Factor_Property2 = 0;
            break;
        case 1:
            Convert_Factor_Property2 = +273.15;
            break;
        default:
            break;
        }
        break;
    case 6:
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
            Convert_Factor_Property2 = 0;
            break;
        case 1:
            Convert_Factor_Property2 = +273.15;
            break;
        default:
            break;
        }
        break;
    case 7:
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        Convert_Factor_Property1 = 1;
        unit2 = ui->cmbPropertyUnit2->currentIndex();
        switch (unit2) {
        case 0:
            Convert_Factor_Property2 = 0;
            break;
        case 1:
            Convert_Factor_Property2 = +273.15;
            break;
        default:
            break;
        }
            break;
    case 8:
        unit1 = ui->cmbPropertyUnit1->currentIndex();
        Convert_Factor_Property1 = 1;
        Convert_Factor_Property2 = 0;
    case 9:
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
            Convert_Factor_Property2 = 0;
            break;
        case 1:
            Convert_Factor_Property2 = +273.15;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void calcForm::ModeChanged(){
    int mode = ui->cmbMode->currentIndex();
    switch (mode) {
    case 0:
        ClearForm();
        break;
    case 1:
        ui->lblProperty1->setText("Pressure: ");        
        ui->lblProperty2->setText("Temperature: ");
        SetUnit_pT();
        break;
    case 2:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText("Enthalpy: ");
        SetUnit_ph();
        break;
    case 3:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText("Entropy: ");
        SetUnit_ps();
        break;
    case 4:
        ui->lblProperty1->setText("Enthalpy: ");
        ui->lblProperty2->setText("Entropy: ");
        SetUnit_hs();
        break;
    case 5:
        ui->lblProperty1->setText(" ");
        ui->lblProperty2->setText("Temperature: ");
        SetUnit_T_Sat();
        break;
    case 6:
        ui->lblProperty1->setText("Pressure: ");
        ui->lblProperty2->setText(" ");
        SetUnit_p_Sat();
        break;
    case 7:
        ui->lblProperty1->setText("Density: ");
        ui->lblProperty2->setText("Temperature: ");
        SetUnit_RhoT();
        break;
    case 8:
        ui->lblProperty1->setText("Enthalpy: ");
        ui->lblProperty2->setText(" ");
        SetUnit_h();
       break;
    default:
        break;
    }
}
void calcForm::SetUnit_Nothing(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
}
void calcForm::SetUnit_pT(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[K]");
    ui->cmbPropertyUnit2->addItem("[C]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_ph(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ / kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_ps(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ / (kg * K)]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_RhoT(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[kg / (m^3)]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[K]");
    ui->cmbPropertyUnit2->addItem("[C]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_hs(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit1->addItem("[kJ / kg]");
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[kJ / (kg * K)]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_p_Sat(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit1->addItem("[MPa]");
    ui->cmbPropertyUnit1->addItem("[kPa]");
    ui->cmbPropertyUnit1->addItem("[Pa]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
}
void calcForm::SetUnit_T_Sat(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit2->addItem("[K]");
    ui->cmbPropertyUnit2->addItem("[C]");
    ui->cmbPropertyUnit2->setCurrentIndex(0);
}
void calcForm::SetUnit_h(){
    ui->cmbPropertyUnit1->clear();
    ui->cmbPropertyUnit2->clear();
    ui->cmbPropertyUnit1->addItem("[kJ / kg]");
    ui->cmbPropertyUnit1->setCurrentIndex(0);
}

void calcForm::Calculate(){
    int region;
    ThermoState state;
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
    case 1: // State(p,T)
        region = findRegion_pT(prp1,prp2);
        state = calcState_pT_Region(prp1,prp2,region);
        break;
    case 2: // State(p,h)
        region = findRegion_ph(prp1,prp2);
        state = calcState_ph_Region(prp1,prp2,region);
        break;
    case 3: // State(p,s)
        region = findRegion_ps(prp1,prp2);
        state = calcState_ps_Region(prp1,prp2,region);
        break;
    case 4: // State(h,s)
        region = findRegion_hs(prp1,prp2);
        qDebug() << "RGN : " << region;
        state = calcState_hs_Region(prp1,prp2,region);
        break;
    case 5: // Sat(T)
        state.p = Region_4_p_Sat_T(prp2);
        state.T = prp2;
        state.v = 0;
        state.h = 0;
        state.s = 0;
        break;
    case 6: // Sat(P)
        state.T = Region_4_T_Sat_p(prp1);
        state.p = prp1;
        state.v = 0;
        state.h = 0;
        state.s = 0;
        break;
    case 7:
        state = Region_3_RhoT(prp1,prp2);
        break;
    case 8:
        state.h = prp1;
        state.p = Region_3_pSat_h(prp1);
        state.v = 0;
        state.T = 0;
        state.s = 0;
        break;
    case 0:
        break;
    default:
        break;
    }

    // Show Result
    QString html , css;
    html = htmlMaker(state);
    css = cssMaker();
    QTextDocument *content = new QTextDocument();
    content->setDefaultStyleSheet(css);
    content->setHtml(html);
    ui->txtThermoState->setDocument(content);

    //Table
    AddToTable(state);
    currentState = state;
}


