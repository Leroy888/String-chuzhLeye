/********************************************************************************
** Form generated from reading UI file 'SysSetAction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSETACTION_H
#define UI_SYSSETACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysSetAction
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_ini;
    QPushButton *pushButton;
    QPushButton *Btn_SysSet;
    QPushButton *pushButton_EL_SAVE;
    QPushButton *pushButton_ReSend;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_ClearBuffer;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_YL;
    QCheckBox *checkBox_XH;
    QCheckBox *checkBox_other;

    void setupUi(QWidget *SysSetAction)
    {
        if (SysSetAction->objectName().isEmpty())
            SysSetAction->setObjectName(QStringLiteral("SysSetAction"));
        SysSetAction->resize(1092, 154);
        gridLayout = new QGridLayout(SysSetAction);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SysSetAction);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox_ini = new QComboBox(SysSetAction);
        comboBox_ini->setObjectName(QStringLiteral("comboBox_ini"));
        comboBox_ini->setMinimumSize(QSize(120, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(9);
        comboBox_ini->setFont(font1);

        horizontalLayout->addWidget(comboBox_ini);

        pushButton = new QPushButton(SysSetAction);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(50, 30));

        horizontalLayout->addWidget(pushButton);

        Btn_SysSet = new QPushButton(SysSetAction);
        Btn_SysSet->setObjectName(QStringLiteral("Btn_SysSet"));
        Btn_SysSet->setMinimumSize(QSize(120, 40));
        Btn_SysSet->setFont(font);

        horizontalLayout->addWidget(Btn_SysSet);

        pushButton_EL_SAVE = new QPushButton(SysSetAction);
        pushButton_EL_SAVE->setObjectName(QStringLiteral("pushButton_EL_SAVE"));
        pushButton_EL_SAVE->setMinimumSize(QSize(120, 40));
        pushButton_EL_SAVE->setMaximumSize(QSize(120, 40));

        horizontalLayout->addWidget(pushButton_EL_SAVE);

        pushButton_ReSend = new QPushButton(SysSetAction);
        pushButton_ReSend->setObjectName(QStringLiteral("pushButton_ReSend"));
        pushButton_ReSend->setMinimumSize(QSize(120, 40));
        pushButton_ReSend->setMaximumSize(QSize(120, 40));

        horizontalLayout->addWidget(pushButton_ReSend);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_6 = new QPushButton(SysSetAction);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 40));
        pushButton_6->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(SysSetAction);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 40));
        pushButton_8->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(pushButton_8);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(SysSetAction);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(SysSetAction);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_4 = new QPushButton(SysSetAction);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(SysSetAction);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_7 = new QPushButton(SysSetAction);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 40));
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_ClearBuffer = new QPushButton(SysSetAction);
        pushButton_ClearBuffer->setObjectName(QStringLiteral("pushButton_ClearBuffer"));
        pushButton_ClearBuffer->setMinimumSize(QSize(0, 40));
        pushButton_ClearBuffer->setMaximumSize(QSize(120, 40));
        pushButton_ClearBuffer->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(pushButton_ClearBuffer);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        checkBox_YL = new QCheckBox(SysSetAction);
        checkBox_YL->setObjectName(QStringLiteral("checkBox_YL"));
        checkBox_YL->setStyleSheet(QLatin1String("font: 12pt \"Arial\";\n"
"background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(checkBox_YL);

        checkBox_XH = new QCheckBox(SysSetAction);
        checkBox_XH->setObjectName(QStringLiteral("checkBox_XH"));
        checkBox_XH->setStyleSheet(QLatin1String("font: 12pt \"Arial\";\n"
"background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(checkBox_XH);

        checkBox_other = new QCheckBox(SysSetAction);
        checkBox_other->setObjectName(QStringLiteral("checkBox_other"));
        checkBox_other->setStyleSheet(QLatin1String("font: 12pt \"Arial\";\n"
"background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(checkBox_other);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);


        retranslateUi(SysSetAction);

        QMetaObject::connectSlotsByName(SysSetAction);
    } // setupUi

    void retranslateUi(QWidget *SysSetAction)
    {
        SysSetAction->setWindowTitle(QApplication::translate("SysSetAction", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SysSetAction", "\351\205\215\346\226\271", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SysSetAction", "\346\265\213\350\257\225", Q_NULLPTR));
        Btn_SysSet->setText(QApplication::translate("SysSetAction", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_EL_SAVE->setText(QApplication::translate("SysSetAction", "EL\345\233\276\347\211\207\346\224\266\351\233\206", Q_NULLPTR));
        pushButton_ReSend->setText(QApplication::translate("SysSetAction", "MES\351\207\215\344\274\240", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("SysSetAction", "\344\270\200\351\224\256\345\244\215\344\275\215", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("SysSetAction", "\344\270\200\351\224\256\346\213\215\347\205\247", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SysSetAction", "\345\267\246\344\276\247\346\260\224\347\274\270\344\270\213\345\216\213", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("SysSetAction", "\345\267\246\344\276\247\346\260\224\347\274\270\345\244\271\347\264\247", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("SysSetAction", "\345\217\263\344\276\247\346\260\224\347\274\270\344\270\213\345\216\213", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("SysSetAction", "\345\217\263\344\276\247\346\260\224\347\274\270\345\244\271\347\264\247", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("SysSetAction", "\346\211\213\345\212\250\344\270\212\347\224\265", Q_NULLPTR));
        pushButton_ClearBuffer->setText(QApplication::translate("SysSetAction", "\346\211\213\345\212\250\346\213\215\347\205\247", Q_NULLPTR));
        checkBox_YL->setText(QApplication::translate("SysSetAction", "\351\232\220\350\243\202", Q_NULLPTR));
        checkBox_XH->setText(QApplication::translate("SysSetAction", "\350\231\232\347\204\212", Q_NULLPTR));
        checkBox_other->setText(QApplication::translate("SysSetAction", "\345\205\266\344\273\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysSetAction: public Ui_SysSetAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETACTION_H
