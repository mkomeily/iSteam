#include "plotptform.h"
#include "ui_plotptfrom.h"

plotpTFrom::plotpTFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plotpTFrom)
{
    ui->setupUi(this);
}

plotpTFrom::~plotpTFrom()
{
    delete ui;
}
