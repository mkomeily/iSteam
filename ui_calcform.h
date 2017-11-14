/********************************************************************************
** Form generated from reading UI file 'calcform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCFORM_H
#define UI_CALCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calcForm
{
public:
    QTableView *tableView;
    QTextEdit *txtThermoState;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblMode;
    QComboBox *cmbMode;
    QLabel *lblProperty1;
    QLineEdit *lnProperty1;
    QComboBox *cmbPropertyUnit1;
    QLabel *lblProperty2;
    QLineEdit *lnProperty2;
    QComboBox *cmbPropertyUnit2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlot;
    QPushButton *btnCalculate;
    QPushButton *btnClose;

    void setupUi(QWidget *calcForm)
    {
        if (calcForm->objectName().isEmpty())
            calcForm->setObjectName(QStringLiteral("calcForm"));
        calcForm->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calcForm->sizePolicy().hasHeightForWidth());
        calcForm->setSizePolicy(sizePolicy);
        tableView = new QTableView(calcForm);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(11, 340, 781, 250));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(0, 250));
        tableView->setMaximumSize(QSize(16777215, 250));
        txtThermoState = new QTextEdit(calcForm);
        txtThermoState->setObjectName(QStringLiteral("txtThermoState"));
        txtThermoState->setGeometry(QRect(390, 5, 401, 321));
        txtThermoState->setMinimumSize(QSize(0, 321));
        txtThermoState->setMaximumSize(QSize(16777215, 350));
        layoutWidget = new QWidget(calcForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 361, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblMode = new QLabel(layoutWidget);
        lblMode->setObjectName(QStringLiteral("lblMode"));

        gridLayout->addWidget(lblMode, 0, 0, 1, 1);

        cmbMode = new QComboBox(layoutWidget);
        cmbMode->setObjectName(QStringLiteral("cmbMode"));

        gridLayout->addWidget(cmbMode, 0, 1, 1, 1);

        lblProperty1 = new QLabel(layoutWidget);
        lblProperty1->setObjectName(QStringLiteral("lblProperty1"));

        gridLayout->addWidget(lblProperty1, 1, 0, 1, 1);

        lnProperty1 = new QLineEdit(layoutWidget);
        lnProperty1->setObjectName(QStringLiteral("lnProperty1"));

        gridLayout->addWidget(lnProperty1, 1, 1, 1, 1);

        cmbPropertyUnit1 = new QComboBox(layoutWidget);
        cmbPropertyUnit1->setObjectName(QStringLiteral("cmbPropertyUnit1"));
        QFont font;
        font.setPointSize(8);
        cmbPropertyUnit1->setFont(font);

        gridLayout->addWidget(cmbPropertyUnit1, 1, 2, 1, 1);

        lblProperty2 = new QLabel(layoutWidget);
        lblProperty2->setObjectName(QStringLiteral("lblProperty2"));

        gridLayout->addWidget(lblProperty2, 2, 0, 1, 1);

        lnProperty2 = new QLineEdit(layoutWidget);
        lnProperty2->setObjectName(QStringLiteral("lnProperty2"));

        gridLayout->addWidget(lnProperty2, 2, 1, 1, 1);

        cmbPropertyUnit2 = new QComboBox(layoutWidget);
        cmbPropertyUnit2->setObjectName(QStringLiteral("cmbPropertyUnit2"));
        cmbPropertyUnit2->setFont(font);

        gridLayout->addWidget(cmbPropertyUnit2, 2, 2, 1, 1);

        layoutWidget1 = new QWidget(calcForm);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 300, 371, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPlot = new QPushButton(layoutWidget1);
        btnPlot->setObjectName(QStringLiteral("btnPlot"));

        horizontalLayout->addWidget(btnPlot);

        btnCalculate = new QPushButton(layoutWidget1);
        btnCalculate->setObjectName(QStringLiteral("btnCalculate"));

        horizontalLayout->addWidget(btnCalculate);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        retranslateUi(calcForm);

        QMetaObject::connectSlotsByName(calcForm);
    } // setupUi

    void retranslateUi(QWidget *calcForm)
    {
        calcForm->setWindowTitle(QApplication::translate("calcForm", "calcForm", Q_NULLPTR));
        lblMode->setText(QApplication::translate("calcForm", "Input Mode: ", Q_NULLPTR));
        cmbMode->clear();
        cmbMode->insertItems(0, QStringList()
         << QApplication::translate("calcForm", "Select Mode", Q_NULLPTR)
         << QApplication::translate("calcForm", "State (p,T)", Q_NULLPTR)
         << QApplication::translate("calcForm", "State (p,h)", Q_NULLPTR)
         << QApplication::translate("calcForm", "State (p,s)", Q_NULLPTR)
         << QApplication::translate("calcForm", "State (h,s)", Q_NULLPTR)
         << QApplication::translate("calcForm", "P_Sat (T)", Q_NULLPTR)
         << QApplication::translate("calcForm", "T_Sat (p)", Q_NULLPTR)
         << QApplication::translate("calcForm", "State (Rho,T)", Q_NULLPTR)
         << QApplication::translate("calcForm", "P3_Sat(h)", Q_NULLPTR)
        );
        lblProperty1->setText(QApplication::translate("calcForm", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        lblProperty2->setText(QString());
        btnPlot->setText(QApplication::translate("calcForm", "Plot", Q_NULLPTR));
        btnCalculate->setText(QApplication::translate("calcForm", "Calculate", Q_NULLPTR));
        btnClose->setText(QApplication::translate("calcForm", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class calcForm: public Ui_calcForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCFORM_H
