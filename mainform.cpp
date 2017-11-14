#include <QtWidgets>
#include <QApplication>
#include "mainform.h"
#include <QDebug>

MainForm::MainForm()
{
    this->setFixedSize(320,240);
    QVBoxLayout VBoxInput;

    QLineEdit prpInput1(this);
    QComboBox prpType1(this);
    QLineEdit prpInput2(this);
    QComboBox prpType2(this);

    prpType1.addItem("Item 1-1");
    prpType2.addItem("Item 2-1");

    VBoxInput.addWidget(&prpType1);
    VBoxInput.addWidget(&prpInput1);
    VBoxInput.addWidget(&prpType2);
    VBoxInput.addWidget(&prpInput2);

    this->setLayout(&VBoxInput);
    qDebug() << VBoxInput.parent()->objectName();

}
void MainForm::formLoad(){

}

