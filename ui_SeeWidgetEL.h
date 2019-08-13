/********************************************************************************
** Form generated from reading UI file 'SeeWidgetEL.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEWIDGETEL_H
#define UI_SEEWIDGETEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "OptRuler.h"
#include "SeeViewGraphic.h"

QT_BEGIN_NAMESPACE

class Ui_SeeWidgetEL
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    OptRuler *ruler_h;
    SeeViewGraphic *graphicsView;

    void setupUi(QWidget *SeeWidgetEL)
    {
        if (SeeWidgetEL->objectName().isEmpty())
            SeeWidgetEL->setObjectName(QStringLiteral("SeeWidgetEL"));
        SeeWidgetEL->resize(1119, 702);
        SeeWidgetEL->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(SeeWidgetEL);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ruler_h = new OptRuler(SeeWidgetEL);
        ruler_h->setObjectName(QStringLiteral("ruler_h"));
        ruler_h->setMinimumSize(QSize(50, 0));
        ruler_h->setMaximumSize(QSize(80, 16777215));
        ruler_h->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(ruler_h);

        graphicsView = new SeeViewGraphic(SeeWidgetEL);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMaximumSize(QSize(2600, 800));

        horizontalLayout_2->addWidget(graphicsView);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 200);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SeeWidgetEL);

        QMetaObject::connectSlotsByName(SeeWidgetEL);
    } // setupUi

    void retranslateUi(QWidget *SeeWidgetEL)
    {
        SeeWidgetEL->setWindowTitle(QApplication::translate("SeeWidgetEL", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeeWidgetEL: public Ui_SeeWidgetEL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEWIDGETEL_H
