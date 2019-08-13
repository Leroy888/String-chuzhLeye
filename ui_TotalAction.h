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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TotalAction
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Clear;
    QHBoxLayout *horizontalLayout;
    QLabel *label_OK;
    QLCDNumber *lcdNumber_OK;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ErrorJudge;
    QLCDNumber *lcdNumber_Error;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_NG;
    QLCDNumber *lcdNumber_NG;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_MissJudge;
    QLCDNumber *lcdNumber_Miss;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_MissJudge_Rate;
    QLCDNumber *lcdNumber_MissJudge_Rate;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_ErrorJudge_Rate;
    QLCDNumber *lcdNumber_ErrorJudge_Rate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_NG_Rate;
    QLCDNumber *lcdNumber_NG_Rate;

    void setupUi(QWidget *TotalAction)
    {
        if (TotalAction->objectName().isEmpty())
            TotalAction->setObjectName(QStringLiteral("TotalAction"));
        TotalAction->resize(256, 587);
        TotalAction->setMinimumSize(QSize(200, 500));
        TotalAction->setMaximumSize(QSize(384, 700));
        gridLayout = new QGridLayout(TotalAction);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_Clear = new QPushButton(TotalAction);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton_Clear->setFont(font);

        horizontalLayout_3->addWidget(pushButton_Clear);


        gridLayout->addLayout(horizontalLayout_3, 9, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_OK = new QLabel(TotalAction);
        label_OK->setObjectName(QStringLiteral("label_OK"));
        label_OK->setMinimumSize(QSize(0, 0));
        label_OK->setMaximumSize(QSize(80, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
        label_OK->setFont(font1);
        label_OK->setStyleSheet(QStringLiteral(""));
        label_OK->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_OK);

        lcdNumber_OK = new QLCDNumber(TotalAction);
        lcdNumber_OK->setObjectName(QStringLiteral("lcdNumber_OK"));
        lcdNumber_OK->setMinimumSize(QSize(0, 0));
        lcdNumber_OK->setMaximumSize(QSize(250, 100));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        lcdNumber_OK->setPalette(palette);
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(18);
        lcdNumber_OK->setFont(font2);
        lcdNumber_OK->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        lcdNumber_OK->setSmallDecimalPoint(false);
        lcdNumber_OK->setDigitCount(5);
        lcdNumber_OK->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_OK->setProperty("value", QVariant(0));
        lcdNumber_OK->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(lcdNumber_OK);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_ErrorJudge = new QLabel(TotalAction);
        label_ErrorJudge->setObjectName(QStringLiteral("label_ErrorJudge"));
        label_ErrorJudge->setMinimumSize(QSize(0, 0));
        label_ErrorJudge->setMaximumSize(QSize(80, 100));
        label_ErrorJudge->setFont(font1);
        label_ErrorJudge->setStyleSheet(QStringLiteral(""));
        label_ErrorJudge->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_ErrorJudge);

        lcdNumber_Error = new QLCDNumber(TotalAction);
        lcdNumber_Error->setObjectName(QStringLiteral("lcdNumber_Error"));
        lcdNumber_Error->setMinimumSize(QSize(0, 0));
        lcdNumber_Error->setMaximumSize(QSize(280, 100));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lcdNumber_Error->setPalette(palette1);
        lcdNumber_Error->setFont(font2);
        lcdNumber_Error->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
""));
        lcdNumber_Error->setSmallDecimalPoint(false);
        lcdNumber_Error->setDigitCount(5);
        lcdNumber_Error->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Error->setProperty("value", QVariant(0));
        lcdNumber_Error->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(lcdNumber_Error);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_NG = new QLabel(TotalAction);
        label_NG->setObjectName(QStringLiteral("label_NG"));
        label_NG->setMinimumSize(QSize(0, 0));
        label_NG->setMaximumSize(QSize(80, 100));
        label_NG->setFont(font1);
        label_NG->setStyleSheet(QStringLiteral(""));
        label_NG->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_NG);

        lcdNumber_NG = new QLCDNumber(TotalAction);
        lcdNumber_NG->setObjectName(QStringLiteral("lcdNumber_NG"));
        lcdNumber_NG->setMinimumSize(QSize(0, 0));
        lcdNumber_NG->setMaximumSize(QSize(280, 100));
        QPalette palette2;
        QBrush brush2(QColor(255, 85, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        lcdNumber_NG->setPalette(palette2);
        lcdNumber_NG->setFont(font2);
        lcdNumber_NG->setStyleSheet(QStringLiteral("color: rgb(255, 85, 127);"));
        lcdNumber_NG->setSmallDecimalPoint(false);
        lcdNumber_NG->setDigitCount(5);
        lcdNumber_NG->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_NG->setProperty("value", QVariant(0));
        lcdNumber_NG->setProperty("intValue", QVariant(0));

        horizontalLayout_2->addWidget(lcdNumber_NG);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_MissJudge = new QLabel(TotalAction);
        label_MissJudge->setObjectName(QStringLiteral("label_MissJudge"));
        label_MissJudge->setMinimumSize(QSize(0, 0));
        label_MissJudge->setMaximumSize(QSize(80, 100));
        label_MissJudge->setFont(font1);
        label_MissJudge->setStyleSheet(QStringLiteral(""));
        label_MissJudge->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_MissJudge);

        lcdNumber_Miss = new QLCDNumber(TotalAction);
        lcdNumber_Miss->setObjectName(QStringLiteral("lcdNumber_Miss"));
        lcdNumber_Miss->setMinimumSize(QSize(0, 0));
        lcdNumber_Miss->setMaximumSize(QSize(280, 100));
        QPalette palette3;
        QBrush brush3(QColor(255, 85, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        lcdNumber_Miss->setPalette(palette3);
        lcdNumber_Miss->setFont(font2);
        lcdNumber_Miss->setStyleSheet(QStringLiteral("color: rgb(255, 85, 255);"));
        lcdNumber_Miss->setSmallDecimalPoint(false);
        lcdNumber_Miss->setDigitCount(5);
        lcdNumber_Miss->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Miss->setProperty("value", QVariant(0));
        lcdNumber_Miss->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(lcdNumber_Miss);


        gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_MissJudge_Rate = new QLabel(TotalAction);
        label_MissJudge_Rate->setObjectName(QStringLiteral("label_MissJudge_Rate"));
        label_MissJudge_Rate->setMaximumSize(QSize(80, 16777215));
        label_MissJudge_Rate->setFont(font2);
        label_MissJudge_Rate->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_MissJudge_Rate);

        lcdNumber_MissJudge_Rate = new QLCDNumber(TotalAction);
        lcdNumber_MissJudge_Rate->setObjectName(QStringLiteral("lcdNumber_MissJudge_Rate"));
        QPalette palette4;
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        QBrush brush5(QColor(164, 166, 168, 96));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush6(QColor(208, 208, 208, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        lcdNumber_MissJudge_Rate->setPalette(palette4);
        lcdNumber_MissJudge_Rate->setFont(font2);
        lcdNumber_MissJudge_Rate->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_MissJudge_Rate->setProperty("intValue", QVariant(0));

        horizontalLayout_6->addWidget(lcdNumber_MissJudge_Rate);


        gridLayout->addLayout(horizontalLayout_6, 8, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_ErrorJudge_Rate = new QLabel(TotalAction);
        label_ErrorJudge_Rate->setObjectName(QStringLiteral("label_ErrorJudge_Rate"));
        label_ErrorJudge_Rate->setMaximumSize(QSize(80, 16777215));
        label_ErrorJudge_Rate->setFont(font1);
        label_ErrorJudge_Rate->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_ErrorJudge_Rate);

        lcdNumber_ErrorJudge_Rate = new QLCDNumber(TotalAction);
        lcdNumber_ErrorJudge_Rate->setObjectName(QStringLiteral("lcdNumber_ErrorJudge_Rate"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        lcdNumber_ErrorJudge_Rate->setPalette(palette5);
        lcdNumber_ErrorJudge_Rate->setFont(font2);
        lcdNumber_ErrorJudge_Rate->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_ErrorJudge_Rate->setProperty("intValue", QVariant(0));

        horizontalLayout_7->addWidget(lcdNumber_ErrorJudge_Rate);


        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_NG_Rate = new QLabel(TotalAction);
        label_NG_Rate->setObjectName(QStringLiteral("label_NG_Rate"));
        label_NG_Rate->setMaximumSize(QSize(80, 100));
        label_NG_Rate->setFont(font1);
        label_NG_Rate->setLayoutDirection(Qt::LeftToRight);
        label_NG_Rate->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_NG_Rate);

        lcdNumber_NG_Rate = new QLCDNumber(TotalAction);
        lcdNumber_NG_Rate->setObjectName(QStringLiteral("lcdNumber_NG_Rate"));
        lcdNumber_NG_Rate->setMinimumSize(QSize(0, 0));
        lcdNumber_NG_Rate->setMaximumSize(QSize(16777215, 100));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        lcdNumber_NG_Rate->setPalette(palette6);
        lcdNumber_NG_Rate->setFont(font2);
        lcdNumber_NG_Rate->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_NG_Rate->setProperty("intValue", QVariant(0));

        horizontalLayout_8->addWidget(lcdNumber_NG_Rate);


        gridLayout->addLayout(horizontalLayout_8, 4, 0, 1, 1);


        retranslateUi(TotalAction);

        QMetaObject::connectSlotsByName(TotalAction);
    } // setupUi

    void retranslateUi(QWidget *TotalAction)
    {
        TotalAction->setWindowTitle(QApplication::translate("TotalAction", "Form", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("TotalAction", "\346\270\205\347\251\272", Q_NULLPTR));
        label_OK->setText(QApplication::translate("TotalAction", "OK", Q_NULLPTR));
        label_ErrorJudge->setText(QApplication::translate("TotalAction", "\350\257\257\345\210\244", Q_NULLPTR));
        label_NG->setText(QApplication::translate("TotalAction", "NG", Q_NULLPTR));
        label_MissJudge->setText(QApplication::translate("TotalAction", "\346\274\217\346\243\200", Q_NULLPTR));
        label_MissJudge_Rate->setText(QApplication::translate("TotalAction", "\346\274\217\346\243\200\347\216\207", Q_NULLPTR));
        label_ErrorJudge_Rate->setText(QApplication::translate("TotalAction", "\350\257\257\345\210\244\347\216\207", Q_NULLPTR));
        label_NG_Rate->setText(QApplication::translate("TotalAction", "NG\347\216\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TotalAction: public Ui_TotalAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALACTION_H
