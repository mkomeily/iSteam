#ifndef PLOTPTFORM_H
#define PLOTPTFORM_H

#include <QWidget>
#include <QWheelEvent>
#include <QPainter>
#include <QPaintEvent>
#include "common.h"

namespace Ui {
class plotpTForm;
}

class plotpTForm : public QWidget
{
    Q_OBJECT

public:
    void formLoad();
    bool preLoadData;
    ThermoState currentState;
    double zoomLevel = 1;
    double offsetX = 10;
    double offsetY = 10;
    double shiftX = 10;
    double shiftY = 10;
    double W = 0;
    double H = 0;
    QPoint NewCoordinate(double x, double y);
    explicit plotpTForm(QWidget *parent = 0);
    ~plotpTForm();
protected:
    void paintEvent(QPaintEvent * event);
    void wheelEvent(QWheelEvent * event);
private:
    Ui::plotpTForm *ui;
public slots:
    void recieveDataSlot(ThermoState state);
};

#endif // PLOTPTFORM_H
