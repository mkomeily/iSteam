#include "mainwindow.h"
#include "calcform.h"
#include "plotptform.h"
#include <QtWidgets>

MainWindow::MainWindow()
    : mdiArea(new QMdiArea)
{
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    createActions();
    //createStatusBar();
    //updateMenus();
    //readSettings();

    setUnifiedTitleAndToolBarOnMac(true);
    this->setWindowTitle("Main MDI Form");
    this->showMaximized();
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    //Calculator Form
    calcAct = new QAction(tr("&Calculator"), this);
    calcAct->setShortcut(Qt::Key_F5);
    calcAct->setStatusTip(tr("Thermodynamic Calculator"));
    connect(calcAct, &QAction::triggered, this, &MainWindow::calcFormSlot);
    fileMenu->addAction(calcAct);

    //Saturation Calculator Form
    satCalcAct = new QAction(tr("&Saturation Calculator"), this);
    satCalcAct->setShortcut(Qt::Key_F6);
    satCalcAct->setStatusTip(tr("Thermodynamic Saturation Calculator"));
    connect(satCalcAct, &QAction::triggered, this, &MainWindow::satCalcFormSlot);
    fileMenu->addAction(satCalcAct);

    //Plot p-T Form
    plotptAct = new QAction(tr("&Plot p-T"), this);
    plotptAct->setShortcut(Qt::Key_F7);
    plotptAct->setStatusTip(tr("p-T Diagram for IAWPS-IF 97 Regions"));
    connect(plotptAct, &QAction::triggered, this, &MainWindow::plotpTFormSlot);
    fileMenu->addAction(plotptAct);

    //Exit
    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(Qt::Key_F10);
    exitAct->setStatusTip(tr("Exit from App"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::exitAppSlot);
    fileMenu->addAction(exitAct);
}
calcForm *MainWindow::createCalcFormMdiChildForm()
{
    calcForm *frm = new calcForm;
    swForm = mdiArea->addSubWindow(frm);
    return frm;
  }

satCalcForm *MainWindow::createSatCalcFormMdiChildForm()
{
    satCalcForm *frm = new satCalcForm;
    swForm = mdiArea->addSubWindow(frm);
    return frm;
  }

plotpTForm *MainWindow::createPlotpTFormMdiChildForm()
{
    plotpTForm *frm = new plotpTForm;    
    swForm = mdiArea->addSubWindow(frm);
    return frm;
  }

bool MainWindow::isFormActived(QString frmName){
    bool result = false;
    windowlist = mdiArea->subWindowList();
    if (!windowlist.count() == 0){
        int i;
        for (i=0 ; i < windowlist.count(); i++){
            if (windowlist.at(i)->windowTitle() == frmName){
                result = true;
                break;
            }
        }
    }else{
        result = false;
    }
    return result;
}
void MainWindow::recieveDataSlot(ThermoState state){
    currentState = state;
    emit MainWindow::sendDataSignal(currentState);
}
void MainWindow::calcFormSlot(){
    if (!isFormActived("calcForm")){
        calcForm *calcForm = createCalcFormMdiChildForm();
        connect(calcForm,SIGNAL(sendDataSignal(ThermoState)),this,SLOT(recieveDataSlot(ThermoState)));
        int x,y;
        x = (this->width() - calcForm->width())/2;
        y = (this->height() - calcForm->height())/2;
        swForm->move(x,y);
        swForm->setFixedSize(800,625);
        calcForm->show();
    }
}
void MainWindow::satCalcFormSlot(){
    if (!isFormActived("satCalcForm")){
        satCalcForm *satCalcForm = createSatCalcFormMdiChildForm();
        connect(satCalcForm,SIGNAL(sendDataSignal(ThermoState)),this,SLOT(recieveDataSlot(ThermoState)));
        int x,y;
        x = (this->width() - satCalcForm->width())/2;
        y = (this->height() - satCalcForm->height())/2;
        swForm->move(x,y);
        swForm->setFixedSize(705,380);
        satCalcForm->show();
    }
}
void MainWindow::plotpTFormSlot(){
    if (!isFormActived("plotpTForm")){
        plotpTForm *plotpTForm = createPlotpTFormMdiChildForm();
        connect(this,SIGNAL(sendDataSignal(ThermoState)),plotpTForm,SLOT(recieveDataSlot(ThermoState)));
        connect(this,SIGNAL(sendDataSignal(ThermoState)),plotpTForm,SLOT(repaint()));
        emit MainWindow::sendDataSignal(currentState);
        int x,y;
        x = (this->width() - plotpTForm->width())/2;
        y = (this->height() - plotpTForm->height())/2;
        swForm->move(x,y);
        swForm->setFixedSize(800,600);
        plotpTForm->show();
    }
}

void MainWindow::exitAppSlot(){
    qApp->exit();
}
