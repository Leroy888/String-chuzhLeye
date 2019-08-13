/********************************************************************************
** Form generated from reading UI file 'TotalAction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALACTION_H
#define UI_TOTALACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TotalAction
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber_OK;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_NG;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Clear;

    void setupUi(QWidget *TotalAction)
    {
        if (TotalAction->objectName().isEmpty())
            TotalAction->setObjectName(QStringLiteral("TotalAction"));
        TotalAction->resize(400, 300);
        TotalAction->setMinimumSize(QSize(400, 300));
        TotalAction->setMaximumSize(QSize(400, 300));
        gridLayout = new QGridLayout(TotalAction);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TotalAction);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 100));
        label->setMaximumSize(QSize(80, 100));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        lcdNumber_OK = new QLCDNumber(TotalAction);
        lcdNumber_OK->setObjectName(QStringLiteral("lcdNumber_OK"));
        lcdNumber_OK->setMinimumSize(QSize(280, 100));
        lcdNumber_OK->setMaximumSize(QSize(280, 100));
        lcdNumber_OK->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        lcdNumber_OK->setSmallDecimalPoint(false);
        lcdNumber_OK->setDigitCount(5);
        lcdNumber_OK->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_OK->setProperty("value", QVariant(9999));
        lcdNumber_OK->setProperty("intValue", QVariant(9999));

        horizontalLayout->addWidget(lcdNumber_OK);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(TotalAction);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 100));
        label_2->setMaximumSize(QSize(80, 100));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        lcdNumber_NG = new QLCDNumber(TotalAction);
        lcdNumber_NG->setObjectName(QStringLiteral("lcdNumber_NG"));
        lcdNumber_NG->setMinimumSize(QSize(280, 100));
        lcdNumber_NG->setMaximumSize(QSize(280, 100));
        lcdNumber_NG->setStyleSheet(QStringLiteral("color: rgb(255, 85, 127);"));
        lcdNumber_NG->setSmallDecimalPoint(false);
        lcdNumber_NG->setDigitCount(5);
        lcdNumber_NG->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_NG->setProperty("value", QVariant(9999));
        lcdNumber_NG->setProperty("intValue", QVariant(9999));

        horizontalLayout_2->addWidget(lcdNumber_NG);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_Clear = new QPushButton(TotalAction);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setMinimumSize(QSize(120, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_Clear->setFont(font1);

        horizontalLayout_3->addWidget(pushButton_Clear);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(TotalAction);

        QMetaObject::connectSlotsByName(TotalAction);
    } // setupUi

    void retranslateUi(QWidget *TotalAction)
    {
        TotalAction->setWindowTitle(QApplication::translate("TotalAction", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("TotalAction", "OK", Q_NULLPTR));
        label_2->setText(QApplication::translate("TotalAction", "NG", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("TotalAction", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TotalAction: public Ui_TotalAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALACTION_H
