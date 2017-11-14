#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calcform.h"
#include "satcalcform.h"
#include "plotptform.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ThermoState currentState;
    MainWindow();
    bool isFormActived(QString frmName);
    QMdiSubWindow *swForm;
    QMdiArea *mdiArea;
    QList <QMdiSubWindow *> windowlist;
signals:
    void sendDataSignal(ThermoState state);
private slots:
    void recieveDataSlot(ThermoState state);
    void exitAppSlot();
    void calcFormSlot();
    void satCalcFormSlot();
    void plotpTFormSlot();
    calcForm *createCalcFormMdiChildForm();
    satCalcForm *createSatCalcFormMdiChildForm();
    plotpTForm *createPlotpTFormMdiChildForm();

private:
   QMenu *windowMenu;
   QAction *exitAct;
   QAction *calcAct;
   QAction *satCalcAct;
   QAction *plotptAct;
   void createActions();
};

#endif // MAINWINDOW_H
