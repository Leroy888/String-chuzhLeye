/********************************************************************************
** Form generated from reading UI file 'ELTotal.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELTOTAL_H
#define UI_ELTOTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TotalTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ELTotal
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    TotalTableWidget *Table_Widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Clear;

    void setupUi(QWidget *ELTotal)
    {
        if (ELTotal->objectName().isEmpty())
            ELTotal->setObjectName(QStringLiteral("ELTotal"));
        ELTotal->resize(517, 491);
        gridLayout = new QGridLayout(ELTotal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Table_Widget = new TotalTableWidget(ELTotal);
        Table_Widget->setObjectName(QStringLiteral("Table_Widget"));

        verticalLayout->addWidget(Table_Widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_Clear = new QPushButton(ELTotal);
        Btn_Clear->setObjectName(QStringLiteral("Btn_Clear"));
        Btn_Clear->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(Btn_Clear);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ELTotal);

        QMetaObject::connectSlotsByName(ELTotal);
    } // setupUi

    void retranslateUi(QWidget *ELTotal)
    {
        ELTotal->setWindowTitle(QApplication::translate("ELTotal", "Form", Q_NULLPTR));
        Btn_Clear->setText(QApplication::translate("ELTotal", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ELTotal: public Ui_ELTotal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELTOTAL_H
