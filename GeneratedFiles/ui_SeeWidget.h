/********************************************************************************
** Form generated from reading UI file 'SeeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEWIDGET_H
#define UI_SEEWIDGET_H

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
#include "SeeView.h"

QT_BEGIN_NAMESPACE

class Ui_SeeWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    OptRuler *ruler_w;
    QHBoxLayout *horizontalLayout_2;
    OptRuler *ruler_h;
    SeeView *widget_img;

    void setupUi(QWidget *SeeWidget)
    {
        if (SeeWidget->objectName().isEmpty())
            SeeWidget->setObjectName(QStringLiteral("SeeWidget"));
        SeeWidget->resize(1166, 664);
        gridLayout = new QGridLayout(SeeWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_5 = new QWidget(SeeWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(80, 80));
        widget_5->setMaximumSize(QSize(80, 80));
        widget_5->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(widget_5);

        ruler_w = new OptRuler(SeeWidget);
        ruler_w->setObjectName(QStringLiteral("ruler_w"));
        ruler_w->setMinimumSize(QSize(0, 80));
        ruler_w->setMaximumSize(QSize(16777215, 80));
        ruler_w->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(ruler_w);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ruler_h = new OptRuler(SeeWidget);
        ruler_h->setObjectName(QStringLiteral("ruler_h"));
        ruler_h->setMinimumSize(QSize(80, 0));
        ruler_h->setMaximumSize(QSize(80, 16777215));
        ruler_h->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(ruler_h);

        widget_img = new SeeView(SeeWidget);
        widget_img->setObjectName(QStringLiteral("widget_img"));
        widget_img->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(widget_img);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 200);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SeeWidget);

        QMetaObject::connectSlotsByName(SeeWidget);
    } // setupUi

    void retranslateUi(QWidget *SeeWidget)
    {
        SeeWidget->setWindowTitle(QApplication::translate("SeeWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeeWidget: public Ui_SeeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEWIDGET_H
