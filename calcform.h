#ifndef calcForm_H
#define calcForm_H

#include <QWidget>
#include "common.h"
#include "plotptform.h"

namespace Ui {
class calcForm;
}

class calcForm : public QWidget
{
    Q_OBJECT

public:
    void MakeTable();
    void AddToTable(ThermoState state);
    double Convert_Factor_Property1;
    double Convert_Factor_Property2;
    ThermoState state;    
    ThermoState currentState;
    explicit calcForm(QWidget *parent = 0);
    ~calcForm();
private:
    Ui::calcForm *ui;
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
    void SetUnit_pT();
    void SetUnit_ph();
    void SetUnit_ps();
    void SetUnit_hs();
    void SetUnit_RhoT();
    void SetUnit_p_Sat();
    void SetUnit_T_Sat();
    void SetUnit_h();
    void recieveDataSlot();
};

#endif // calcForm_H
