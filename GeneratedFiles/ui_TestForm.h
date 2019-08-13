/********************************************************************************
** Form generated from reading UI file 'TestForm.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTFORM_H
#define UI_TESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_ng7;
    QPushButton *pushButton_ng6;
    QPushButton *pushButton_ng8;
    QPushButton *pushButton_ng2;
    QPushButton *pushButton_ng5;
    QPushButton *pushButton_ng1;
    QPushButton *pushButton_ng3;
    QPushButton *pushButton_ng4;

    void setupUi(QWidget *TestForm)
    {
        if (TestForm->objectName().isEmpty())
            TestForm->setObjectName(QStringLiteral("TestForm"));
        TestForm->resize(400, 300);
        TestForm->setMinimumSize(QSize(400, 300));
        TestForm->setMaximumSize(QSize(400, 300));
        TestForm->setStyleSheet(QStringLiteral("QWidget{background-color: transparent; border: 0px solid black;}"));
        gridLayout_2 = new QGridLayout(TestForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, -1, 5, -1);
        pushButton_ok = new QPushButton(TestForm);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(80);
        sizePolicy.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy);
        pushButton_ok->setMinimumSize(QSize(80, 80));
        pushButton_ok->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ok, 0, 0, 1, 1);

        pushButton_ng7 = new QPushButton(TestForm);
        pushButton_ng7->setObjectName(QStringLiteral("pushButton_ng7"));
        sizePolicy.setHeightForWidth(pushButton_ng7->sizePolicy().hasHeightForWidth());
        pushButton_ng7->setSizePolicy(sizePolicy);
        pushButton_ng7->setMinimumSize(QSize(80, 80));
        pushButton_ng7->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng7, 2, 1, 1, 1);

        pushButton_ng6 = new QPushButton(TestForm);
        pushButton_ng6->setObjectName(QStringLiteral("pushButton_ng6"));
        sizePolicy.setHeightForWidth(pushButton_ng6->sizePolicy().hasHeightForWidth());
        pushButton_ng6->setSizePolicy(sizePolicy);
        pushButton_ng6->setMinimumSize(QSize(80, 80));
        pushButton_ng6->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng6, 2, 0, 1, 1);

        pushButton_ng8 = new QPushButton(TestForm);
        pushButton_ng8->setObjectName(QStringLiteral("pushButton_ng8"));
        sizePolicy.setHeightForWidth(pushButton_ng8->sizePolicy().hasHeightForWidth());
        pushButton_ng8->setSizePolicy(sizePolicy);
        pushButton_ng8->setMinimumSize(QSize(80, 80));
        pushButton_ng8->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng8, 2, 2, 1, 1);

        pushButton_ng2 = new QPushButton(TestForm);
        pushButton_ng2->setObjectName(QStringLiteral("pushButton_ng2"));
        sizePolicy.setHeightForWidth(pushButton_ng2->sizePolicy().hasHeightForWidth());
        pushButton_ng2->setSizePolicy(sizePolicy);
        pushButton_ng2->setMinimumSize(QSize(80, 80));
        pushButton_ng2->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#000000;\n"
"	background-color: rgb(229, 229, 229);\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng2, 0, 2, 1, 1);

        pushButton_ng5 = new QPushButton(TestForm);
        pushButton_ng5->setObjectName(QStringLiteral("pushButton_ng5"));
        sizePolicy.setHeightForWidth(pushButton_ng5->sizePolicy().hasHeightForWidth());
        pushButton_ng5->setSizePolicy(sizePolicy);
        pushButton_ng5->setMinimumSize(QSize(80, 80));
        pushButton_ng5->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng5, 1, 2, 1, 1);

        pushButton_ng1 = new QPushButton(TestForm);
        pushButton_ng1->setObjectName(QStringLiteral("pushButton_ng1"));
        sizePolicy.setHeightForWidth(pushButton_ng1->sizePolicy().hasHeightForWidth());
        pushButton_ng1->setSizePolicy(sizePolicy);
        pushButton_ng1->setMinimumSize(QSize(80, 80));
        pushButton_ng1->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng1, 0, 1, 1, 1);

        pushButton_ng3 = new QPushButton(TestForm);
        pushButton_ng3->setObjectName(QStringLiteral("pushButton_ng3"));
        sizePolicy.setHeightForWidth(pushButton_ng3->sizePolicy().hasHeightForWidth());
        pushButton_ng3->setSizePolicy(sizePolicy);
        pushButton_ng3->setMinimumSize(QSize(80, 80));
        pushButton_ng3->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng3, 1, 0, 1, 1);

        pushButton_ng4 = new QPushButton(TestForm);
        pushButton_ng4->setObjectName(QStringLiteral("pushButton_ng4"));
        sizePolicy.setHeightForWidth(pushButton_ng4->sizePolicy().hasHeightForWidth());
        pushButton_ng4->setSizePolicy(sizePolicy);
        pushButton_ng4->setMinimumSize(QSize(80, 80));
        pushButton_ng4->setStyleSheet(QLatin1String("QPushButton { \n"
"                            color:#ffffff;\n"
"                            background-color:#424956;\n"
"                            border-style: outset;\n"
"                            border-width:2px;\n"
"                            border-radius:10px;\n"
"                            border-color: beige;\n"
"                            font: bold 16px;\n"
"                            padding:6px;\n"
"                            }\n"
"                            QPushButton:hover{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:pressed{\n"
"                            color:#ffffff;\n"
"                                background-color:#ff5500\n"
"                            }\n"
"                            QPushButton:!enabled{\n"
"									\n"
"								color: rgb(235, 235, 235);\n"
"								\n"
"	background-color: rgb(143, 143, 143);\n"
"							}"));

        gridLayout->addWidget(pushButton_ng4, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(TestForm);

        QMetaObject::connectSlotsByName(TestForm);
    } // setupUi

    void retranslateUi(QWidget *TestForm)
    {
        TestForm->setWindowTitle(QApplication::translate("TestForm", "Form", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("TestForm", "\346\255\243\345\270\270", Q_NULLPTR));
        pushButton_ok->setShortcut(QApplication::translate("TestForm", "Space", Q_NULLPTR));
        pushButton_ng7->setText(QApplication::translate("TestForm", "NG7", Q_NULLPTR));
        pushButton_ng7->setShortcut(QString());
        pushButton_ng6->setText(QApplication::translate("TestForm", "NG6", Q_NULLPTR));
        pushButton_ng6->setShortcut(QString());
        pushButton_ng8->setText(QApplication::translate("TestForm", "NG8", Q_NULLPTR));
        pushButton_ng8->setShortcut(QApplication::translate("TestForm", "8", Q_NULLPTR));
        pushButton_ng2->setText(QApplication::translate("TestForm", "NG2", Q_NULLPTR));
        pushButton_ng2->setShortcut(QApplication::translate("TestForm", "2", Q_NULLPTR));
        pushButton_ng5->setText(QApplication::translate("TestForm", "NG5", Q_NULLPTR));
        pushButton_ng5->setShortcut(QString());
        pushButton_ng1->setText(QApplication::translate("TestForm", "\347\231\273\345\205\245\346\241\206", Q_NULLPTR));
        pushButton_ng1->setShortcut(QString());
        pushButton_ng3->setText(QApplication::translate("TestForm", "NG3", Q_NULLPTR));
        pushButton_ng3->setShortcut(QApplication::translate("TestForm", "3", Q_NULLPTR));
        pushButton_ng4->setText(QApplication::translate("TestForm", "NG4", Q_NULLPTR));
        pushButton_ng4->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class TestForm: public Ui_TestForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTFORM_H
