#ifndef satCalcForm_H
#define satCalcForm_H

#include <QWidget>
#include "common.h"
#include "plotptform.h"

namespace Ui {
class satCalcForm;
}

class satCalcForm : public QWidget
{
    Q_OBJECT

public:
    void MakeTable();
    void AddToTable(ThermoState state);
    void AddToTableColorful(ThermoState state,QString clr);
    double Convert_Factor_Property1;
    double Convert_Factor_Property2;
    double Converted_Property1;
    double Converted_Property2;
    ThermoState state;    
    ThermoState currentState;
    explicit satCalcForm(QWidget *parent = 0);
    ~satCalcForm();
private:
    Ui::satCalcForm *ui;
signals:
    void sendDataSignal(ThermoState state);
public slots:
    void FormLoad();
    void ClearForm();
    void CloseMe();
    void Calculate();
    void ModeChanged();
    void UnitChanged();
    void SetUnit_Nothing();
    void SetUnit_px();
    void SetUnit_ph();
    void SetUnit_ps();
    void SetUnit_pv();
    void SetUnit_Tx();
    void SetUnit_Th();
    void SetUnit_Ts();
    void SetUnit_Tv();
    void recieveDataSlot();
private slots:

};

#endif // satCalcForm_H
