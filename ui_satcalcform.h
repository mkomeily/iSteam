/********************************************************************************
** Form generated from reading UI file 'satcalcform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SATCALCFORM_H
#define UI_SATCALCFORM_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_satCalcForm
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *lblMode;
    QComboBox *cmbMode;
    QLabel *lblProperty1;
    QLineEdit *lnProperty1;
    QComboBox *cmbPropertyUnit1;
    QLabel *lblProperty2;
    QLineEdit *lnProperty2;
    QComboBox *cmbPropertyUnit2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlot;
    QPushButton *btnCalculate;
    QPushButton *btnClose;

    void setupUi(QWidget *satCalcForm)
    {
        if (satCalcForm->objectName().isEmpty())
            satCalcForm->setObjectName(QStringLiteral("satCalcForm"));
        satCalcForm->resize(690, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(satCalcForm->sizePolicy().hasHeightForWidth());
        satCalcForm->setSizePolicy(sizePolicy);
        tableView = new QTableView(satCalcForm);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 140, 671, 200));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(0, 200));
        tableView->setMaximumSize(QSize(16777215, 0));
        layoutWidget = new QWidget(satCalcForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 12, 671, 122));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblMode = new QLabel(layoutWidget);
        lblMode->setObjectName(QStringLiteral("lblMode"));

        gridLayout->addWidget(lblMode, 0, 0, 1, 1);

        cmbMode = new QComboBox(layoutWidget);
        cmbMode->setObjectName(QStringLiteral("cmbMode"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmbMode->sizePolicy().hasHeightForWidth());
        cmbMode->setSizePolicy(sizePolicy2);
        cmbMode->setMinimumSize(QSize(140, 23));

        gridLayout->addWidget(cmbMode, 0, 1, 1, 1);

        lblProperty1 = new QLabel(layoutWidget);
        lblProperty1->setObjectName(QStringLiteral("lblProperty1"));

        gridLayout->addWidget(lblProperty1, 1, 0, 1, 1);

        lnProperty1 = new QLineEdit(layoutWidget);
        lnProperty1->setObjectName(QStringLiteral("lnProperty1"));
        sizePolicy2.setHeightForWidth(lnProperty1->sizePolicy().hasHeightForWidth());
        lnProperty1->setSizePolicy(sizePolicy2);
        lnProperty1->setMinimumSize(QSize(140, 23));

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
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lnProperty2->sizePolicy().hasHeightForWidth());
        lnProperty2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lnProperty2, 2, 1, 1, 1);

        cmbPropertyUnit2 = new QComboBox(layoutWidget);
        cmbPropertyUnit2->setObjectName(QStringLiteral("cmbPropertyUnit2"));
        cmbPropertyUnit2->setFont(font);

        gridLayout->addWidget(cmbPropertyUnit2, 2, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPlot = new QPushButton(layoutWidget);
        btnPlot->setObjectName(QStringLiteral("btnPlot"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnPlot->sizePolicy().hasHeightForWidth());
        btnPlot->setSizePolicy(sizePolicy4);
        btnPlot->setMinimumSize(QSize(150, 23));
        btnPlot->setMaximumSize(QSize(250, 23));

        horizontalLayout->addWidget(btnPlot);

        btnCalculate = new QPushButton(layoutWidget);
        btnCalculate->setObjectName(QStringLiteral("btnCalculate"));
        sizePolicy4.setHeightForWidth(btnCalculate->sizePolicy().hasHeightForWidth());
        btnCalculate->setSizePolicy(sizePolicy4);
        btnCalculate->setMinimumSize(QSize(150, 23));
        btnCalculate->setMaximumSize(QSize(250, 23));

        horizontalLayout->addWidget(btnCalculate);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        sizePolicy4.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy4);
        btnClose->setMinimumSize(QSize(150, 23));
        btnClose->setMaximumSize(QSize(250, 23));

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(satCalcForm);

        QMetaObject::connectSlotsByName(satCalcForm);
    } // setupUi

    void retranslateUi(QWidget *satCalcForm)
    {
        satCalcForm->setWindowTitle(QApplication::translate("satCalcForm", "calcForm", Q_NULLPTR));
        lblMode->setText(QApplication::translate("satCalcForm", "Input Mode: ", Q_NULLPTR));
        cmbMode->clear();
        cmbMode->insertItems(0, QStringList()
         << QApplication::translate("satCalcForm", "Select Mode", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(p,x)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(T,x)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(p,h)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(T,h)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(p,s)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(T,s)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(p,v)", Q_NULLPTR)
         << QApplication::translate("satCalcForm", "State(T,v)", Q_NULLPTR)
        );
        lblProperty1->setText(QApplication::translate("satCalcForm", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        lblProperty2->setText(QString());
        btnPlot->setText(QApplication::translate("satCalcForm", "Plot", Q_NULLPTR));
        btnCalculate->setText(QApplication::translate("satCalcForm", "Calculate", Q_NULLPTR));
        btnClose->setText(QApplication::translate("satCalcForm", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class satCalcForm: public Ui_satCalcForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SATCALCFORM_H
