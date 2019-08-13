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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ELCmdAction
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *Btn_OK;
    QPushButton *Btn_NG;
    QPushButton *BTN_SAVE_EL_DIR;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *BTN_SAVE_EL_DIR_3;
    QPushButton *BTN_SAVE_EL_DIR_2;
    QLineEdit *lineEdit_ELDIR;

    void setupUi(QWidget *ELCmdAction)
    {
        if (ELCmdAction->objectName().isEmpty())
            ELCmdAction->setObjectName(QStringLiteral("ELCmdAction"));
        ELCmdAction->resize(800, 122);
        ELCmdAction->setMinimumSize(QSize(800, 50));
        ELCmdAction->setMaximumSize(QSize(800, 158));
        gridLayout_2 = new QGridLayout(ELCmdAction);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Btn_OK = new QPushButton(ELCmdAction);
        Btn_OK->setObjectName(QStringLiteral("Btn_OK"));
        Btn_OK->setMinimumSize(QSize(60, 60));
        Btn_OK->setMaximumSize(QSize(60, 60));
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

        gridLayout->addWidget(Btn_OK, 0, 0, 2, 1);

        Btn_NG = new QPushButton(ELCmdAction);
        Btn_NG->setObjectName(QStringLiteral("Btn_NG"));
        Btn_NG->setMinimumSize(QSize(60, 60));
        Btn_NG->setMaximumSize(QSize(60, 60));
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

        gridLayout->addWidget(Btn_NG, 0, 1, 2, 1);

        BTN_SAVE_EL_DIR = new QPushButton(ELCmdAction);
        BTN_SAVE_EL_DIR->setObjectName(QStringLiteral("BTN_SAVE_EL_DIR"));
        BTN_SAVE_EL_DIR->setMinimumSize(QSize(120, 40));

        gridLayout->addWidget(BTN_SAVE_EL_DIR, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_7 = new QPushButton(ELCmdAction);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 30));
        pushButton_7->setMaximumSize(QSize(50, 30));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(ELCmdAction);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 30));
        pushButton_8->setMaximumSize(QSize(50, 30));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(ELCmdAction);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(50, 30));
        pushButton_9->setMaximumSize(QSize(50, 30));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_3->addWidget(pushButton_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(ELCmdAction);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 30));
        pushButton_4->setMaximumSize(QSize(50, 30));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(ELCmdAction);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 30));
        pushButton_5->setMaximumSize(QSize(50, 30));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(ELCmdAction);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 30));
        pushButton_6->setMaximumSize(QSize(50, 30));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_1 = new QPushButton(ELCmdAction);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setEnabled(true);
        pushButton_1->setMinimumSize(QSize(50, 30));
        pushButton_1->setMaximumSize(QSize(50, 30));
        pushButton_1->setStyleSheet(QLatin1String("QPushButton { \n"
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
        pushButton_1->setAutoRepeatDelay(300);

        horizontalLayout_2->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(ELCmdAction);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 30));
        pushButton_2->setMaximumSize(QSize(50, 30));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ELCmdAction);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 30));
        pushButton_3->setMaximumSize(QSize(50, 30));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 2, 2, 1);

        BTN_SAVE_EL_DIR_3 = new QPushButton(ELCmdAction);
        BTN_SAVE_EL_DIR_3->setObjectName(QStringLiteral("BTN_SAVE_EL_DIR_3"));
        BTN_SAVE_EL_DIR_3->setMinimumSize(QSize(120, 40));

        gridLayout->addWidget(BTN_SAVE_EL_DIR_3, 1, 4, 1, 1);

        BTN_SAVE_EL_DIR_2 = new QPushButton(ELCmdAction);
        BTN_SAVE_EL_DIR_2->setObjectName(QStringLiteral("BTN_SAVE_EL_DIR_2"));
        BTN_SAVE_EL_DIR_2->setMinimumSize(QSize(120, 40));

        gridLayout->addWidget(BTN_SAVE_EL_DIR_2, 0, 4, 1, 1);

        lineEdit_ELDIR = new QLineEdit(ELCmdAction);
        lineEdit_ELDIR->setObjectName(QStringLiteral("lineEdit_ELDIR"));

        gridLayout->addWidget(lineEdit_ELDIR, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ELCmdAction);

        QMetaObject::connectSlotsByName(ELCmdAction);
    } // setupUi

    void retranslateUi(QWidget *ELCmdAction)
    {
        ELCmdAction->setWindowTitle(QApplication::translate("ELCmdAction", "Form", Q_NULLPTR));
        Btn_OK->setText(QApplication::translate("ELCmdAction", "OK", Q_NULLPTR));
        Btn_OK->setShortcut(QApplication::translate("ELCmdAction", "0", Q_NULLPTR));
        Btn_NG->setText(QApplication::translate("ELCmdAction", "NG", Q_NULLPTR));
        Btn_NG->setShortcut(QApplication::translate("ELCmdAction", ".", Q_NULLPTR));
        BTN_SAVE_EL_DIR->setText(QApplication::translate("ELCmdAction", "EL\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_9->setShortcut(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        BTN_SAVE_EL_DIR_3->setText(QApplication::translate("ELCmdAction", "\350\257\257\346\243\200\345\233\276\345\203\217\346\224\266\351\233\206", Q_NULLPTR));
        BTN_SAVE_EL_DIR_2->setText(QApplication::translate("ELCmdAction", "\346\274\217\346\243\200\345\233\276\345\203\217\346\224\266\351\233\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ELCmdAction: public Ui_ELCmdAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELCMDACTION_H
