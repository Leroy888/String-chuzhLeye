/********************************************************************************
** Form generated from reading UI file 'LookCmdAction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOKCMDACTION_H
#define UI_LOOKCMDACTION_H

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

class Ui_LookCmdAction
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_OK;
    QPushButton *Btn_NG;
    QLineEdit *lineEdit_LOOKDIR;
    QPushButton *Btn_LOOKDIR;

    void setupUi(QWidget *LookCmdAction)
    {
        if (LookCmdAction->objectName().isEmpty())
            LookCmdAction->setObjectName(QStringLiteral("LookCmdAction"));
        LookCmdAction->resize(502, 92);
        gridLayout = new QGridLayout(LookCmdAction);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Btn_OK = new QPushButton(LookCmdAction);
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

        horizontalLayout_3->addWidget(Btn_OK);

        Btn_NG = new QPushButton(LookCmdAction);
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

        horizontalLayout_3->addWidget(Btn_NG);

        lineEdit_LOOKDIR = new QLineEdit(LookCmdAction);
        lineEdit_LOOKDIR->setObjectName(QStringLiteral("lineEdit_LOOKDIR"));
        lineEdit_LOOKDIR->setMinimumSize(QSize(200, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        lineEdit_LOOKDIR->setFont(font1);
        lineEdit_LOOKDIR->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_LOOKDIR);

        Btn_LOOKDIR = new QPushButton(LookCmdAction);
        Btn_LOOKDIR->setObjectName(QStringLiteral("Btn_LOOKDIR"));
        Btn_LOOKDIR->setMinimumSize(QSize(120, 40));

        horizontalLayout_3->addWidget(Btn_LOOKDIR);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(LookCmdAction);

        QMetaObject::connectSlotsByName(LookCmdAction);
    } // setupUi

    void retranslateUi(QWidget *LookCmdAction)
    {
        LookCmdAction->setWindowTitle(QApplication::translate("LookCmdAction", "Form", Q_NULLPTR));
        Btn_OK->setText(QApplication::translate("LookCmdAction", "OK", Q_NULLPTR));
        Btn_OK->setShortcut(QApplication::translate("LookCmdAction", "1", Q_NULLPTR));
        Btn_NG->setText(QApplication::translate("LookCmdAction", "NG", Q_NULLPTR));
        Btn_NG->setShortcut(QApplication::translate("LookCmdAction", "2", Q_NULLPTR));
        Btn_LOOKDIR->setText(QApplication::translate("LookCmdAction", "\345\244\226\350\247\202\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LookCmdAction: public Ui_LookCmdAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOKCMDACTION_H
