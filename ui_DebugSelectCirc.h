/********************************************************************************
** Form generated from reading UI file 'DebugSelectCirc.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGSELECTCIRC_H
#define UI_DEBUGSELECTCIRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "DebugSelectView.h"

QT_BEGIN_NAMESPACE

class Ui_DebugSelectCirc
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Btn_Load;
    QPushButton *Btn_Pre;
    QPushButton *Btn_Edit;
    QSpacerItem *verticalSpacer;
    DebugSelectView *graphicsView;

    void setupUi(QWidget *DebugSelectCirc)
    {
        if (DebugSelectCirc->objectName().isEmpty())
            DebugSelectCirc->setObjectName(QStringLiteral("DebugSelectCirc"));
        DebugSelectCirc->resize(718, 518);
        gridLayout = new QGridLayout(DebugSelectCirc);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        Btn_Load = new QPushButton(DebugSelectCirc);
        Btn_Load->setObjectName(QStringLiteral("Btn_Load"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Btn_Load->sizePolicy().hasHeightForWidth());
        Btn_Load->setSizePolicy(sizePolicy);
        Btn_Load->setMinimumSize(QSize(80, 80));
        Btn_Load->setMaximumSize(QSize(80, 80));

        verticalLayout->addWidget(Btn_Load);

        Btn_Pre = new QPushButton(DebugSelectCirc);
        Btn_Pre->setObjectName(QStringLiteral("Btn_Pre"));
        sizePolicy.setHeightForWidth(Btn_Pre->sizePolicy().hasHeightForWidth());
        Btn_Pre->setSizePolicy(sizePolicy);
        Btn_Pre->setMinimumSize(QSize(80, 80));
        Btn_Pre->setMaximumSize(QSize(80, 80));

        verticalLayout->addWidget(Btn_Pre);

        Btn_Edit = new QPushButton(DebugSelectCirc);
        Btn_Edit->setObjectName(QStringLiteral("Btn_Edit"));
        sizePolicy.setHeightForWidth(Btn_Edit->sizePolicy().hasHeightForWidth());
        Btn_Edit->setSizePolicy(sizePolicy);
        Btn_Edit->setMinimumSize(QSize(80, 80));
        Btn_Edit->setMaximumSize(QSize(80, 80));

        verticalLayout->addWidget(Btn_Edit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        graphicsView = new DebugSelectView(DebugSelectCirc);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);


        retranslateUi(DebugSelectCirc);

        QMetaObject::connectSlotsByName(DebugSelectCirc);
    } // setupUi

    void retranslateUi(QWidget *DebugSelectCirc)
    {
        DebugSelectCirc->setWindowTitle(QApplication::translate("DebugSelectCirc", "Form", Q_NULLPTR));
        Btn_Load->setText(QApplication::translate("DebugSelectCirc", "\345\212\240\350\275\275\345\233\276\347\211\207", Q_NULLPTR));
        Btn_Pre->setText(QApplication::translate("DebugSelectCirc", "\351\242\204\350\247\210\346\250\241\345\274\217", Q_NULLPTR));
        Btn_Edit->setText(QApplication::translate("DebugSelectCirc", "\347\274\226\350\276\221\346\250\241\345\274\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DebugSelectCirc: public Ui_DebugSelectCirc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGSELECTCIRC_H
