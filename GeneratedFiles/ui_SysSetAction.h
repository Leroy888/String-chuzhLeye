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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysSetAction
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_ini;
    QPushButton *pushButton;
    QPushButton *Btn_SysSet;
    QPushButton *pushButton_EL_SAVE;
    QPushButton *pushButton_ClearBuffer;
    QPushButton *pushButton_ReSend;

    void setupUi(QWidget *SysSetAction)
    {
        if (SysSetAction->objectName().isEmpty())
            SysSetAction->setObjectName(QStringLiteral("SysSetAction"));
        SysSetAction->resize(744, 62);
        horizontalLayout = new QHBoxLayout(SysSetAction);
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

        pushButton_ClearBuffer = new QPushButton(SysSetAction);
        pushButton_ClearBuffer->setObjectName(QStringLiteral("pushButton_ClearBuffer"));
        pushButton_ClearBuffer->setMinimumSize(QSize(120, 40));
        pushButton_ClearBuffer->setMaximumSize(QSize(120, 40));

        horizontalLayout->addWidget(pushButton_ClearBuffer);

        pushButton_ReSend = new QPushButton(SysSetAction);
        pushButton_ReSend->setObjectName(QStringLiteral("pushButton_ReSend"));
        pushButton_ReSend->setMinimumSize(QSize(120, 40));
        pushButton_ReSend->setMaximumSize(QSize(120, 40));

        horizontalLayout->addWidget(pushButton_ReSend);


        retranslateUi(SysSetAction);

        QMetaObject::connectSlotsByName(SysSetAction);
    } // setupUi

    void retranslateUi(QWidget *SysSetAction)
    {
        SysSetAction->setWindowTitle(QApplication::translate("SysSetAction", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SysSetAction", "\351\205\215\346\226\271", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SysSetAction", "PushButton", Q_NULLPTR));
        Btn_SysSet->setText(QApplication::translate("SysSetAction", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_EL_SAVE->setText(QApplication::translate("SysSetAction", "EL\345\233\276\347\211\207\346\224\266\351\233\206", Q_NULLPTR));
        pushButton_ClearBuffer->setText(QApplication::translate("SysSetAction", "\346\211\213\345\212\250\346\213\215\347\205\247", Q_NULLPTR));
        pushButton_ReSend->setText(QApplication::translate("SysSetAction", "MES\351\207\215\344\274\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysSetAction: public Ui_SysSetAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETACTION_H
