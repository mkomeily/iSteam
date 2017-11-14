/********************************************************************************
** Form generated from reading UI file 'plotptform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTPTFORM_H
#define UI_PLOTPTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plotpTForm
{
public:

    void setupUi(QWidget *plotpTForm)
    {
        if (plotpTForm->objectName().isEmpty())
            plotpTForm->setObjectName(QStringLiteral("plotpTForm"));
        plotpTForm->setEnabled(true);
        plotpTForm->resize(800, 600);

        retranslateUi(plotpTForm);

        QMetaObject::connectSlotsByName(plotpTForm);
    } // setupUi

    void retranslateUi(QWidget *plotpTForm)
    {
        plotpTForm->setWindowTitle(QApplication::translate("plotpTForm", "plotpTForm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class plotpTForm: public Ui_plotpTForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTPTFORM_H
