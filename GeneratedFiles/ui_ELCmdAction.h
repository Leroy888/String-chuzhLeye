/********************************************************************************
** Form generated from reading UI file 'ELCmdAction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELCMDACTION_H
#define UI_ELCMDACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ELCmdAction
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Btn_OK;
    QPushButton *Btn_NG;
    QLineEdit *lineEdit_ELDIR;
    QPushButton *BTN_SAVE_EL_DIR;

    void setupUi(QWidget *ELCmdAction)
    {
        if (ELCmdAction->objectName().isEmpty())
            ELCmdAction->setObjectName(QStringLiteral("ELCmdAction"));
        ELCmdAction->resize(502, 100);
        gridLayout = new QGridLayout(ELCmdAction);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Btn_OK = new QPushButton(ELCmdAction);
        Btn_OK->setObjectName(QStringLiteral("Btn_OK"));
        Btn_OK->setMinimumSize(QSize(90, 90));
        Btn_OK->setMaximumSize(QSize(90, 90));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        Btn_OK->setFont(font);
        Btn_OK->setStyleSheet(QLatin1String("QPushButton { \n"
"	\n"
"	\n"
"                            color:#ffffff;\n"
"                          background-color: rgb(0, 170, 0);\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"\n"
"  QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color: rgb(0, 255, 0);\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color: rgb(0, 255, 0);\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
""
                        "							}"));

        horizontalLayout_4->addWidget(Btn_OK);

        Btn_NG = new QPushButton(ELCmdAction);
        Btn_NG->setObjectName(QStringLiteral("Btn_NG"));
        Btn_NG->setMinimumSize(QSize(90, 90));
        Btn_NG->setMaximumSize(QSize(90, 90));
        Btn_NG->setFont(font);
        Btn_NG->setStyleSheet(QLatin1String("QPushButton { \n"
"	\n"
"                            color:#ffffff;\n"
"                         	 background-color: rgb(255, 0, 0);\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"	\n"
"\n"
"  QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                 background-color: rgb(255, 85, 127);\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color: rgb(255, 85, 127);\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, "
                        "143);\n"
"							}"));

        horizontalLayout_4->addWidget(Btn_NG);

        lineEdit_ELDIR = new QLineEdit(ELCmdAction);
        lineEdit_ELDIR->setObjectName(QStringLiteral("lineEdit_ELDIR"));
        lineEdit_ELDIR->setMinimumSize(QSize(200, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        lineEdit_ELDIR->setFont(font1);
        lineEdit_ELDIR->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_ELDIR);

        BTN_SAVE_EL_DIR = new QPushButton(ELCmdAction);
        BTN_SAVE_EL_DIR->setObjectName(QStringLiteral("BTN_SAVE_EL_DIR"));
        BTN_SAVE_EL_DIR->setMinimumSize(QSize(120, 40));

        horizontalLayout_4->addWidget(BTN_SAVE_EL_DIR);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(ELCmdAction);

        QMetaObject::connectSlotsByName(ELCmdAction);
    } // setupUi

    void retranslateUi(QWidget *ELCmdAction)
    {
        ELCmdAction->setWindowTitle(QApplication::translate("ELCmdAction", "Form", Q_NULLPTR));
        Btn_OK->setText(QApplication::translate("ELCmdAction", "OK", Q_NULLPTR));
        Btn_OK->setShortcut(QApplication::translate("ELCmdAction", "0", Q_NULLPTR));
        Btn_NG->setText(QApplication::translate("ELCmdAction", "NG", Q_NULLPTR));
        Btn_NG->setShortcut(QApplication::translate("ELCmdAction", "1", Q_NULLPTR));
        BTN_SAVE_EL_DIR->setText(QApplication::translate("ELCmdAction", "EL\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ELCmdAction: public Ui_ELCmdAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELCMDACTION_H
