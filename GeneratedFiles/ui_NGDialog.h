/********************************************************************************
** Form generated from reading UI file 'NGDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NGDIALOG_H
#define UI_NGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "CommandWidget.h"
#include "TabbedWidget.h"

QT_BEGIN_NAMESPACE

class Ui_NGDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    TabbedWidget *w_xy;
    CommandWidget *w_cmd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *NGDialog)
    {
        if (NGDialog->objectName().isEmpty())
            NGDialog->setObjectName(QStringLiteral("NGDialog"));
        NGDialog->resize(960, 800);
        gridLayout = new QGridLayout(NGDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        w_xy = new TabbedWidget(NGDialog);
        w_xy->setObjectName(QStringLiteral("w_xy"));

        verticalLayout->addWidget(w_xy);

        w_cmd = new CommandWidget(NGDialog);
        w_cmd->setObjectName(QStringLiteral("w_cmd"));

        verticalLayout->addWidget(w_cmd);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(NGDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(400, 80));
        pushButton->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(NGDialog);

        QMetaObject::connectSlotsByName(NGDialog);
    } // setupUi

    void retranslateUi(QDialog *NGDialog)
    {
        NGDialog->setWindowTitle(QApplication::translate("NGDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NGDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton->setShortcut(QApplication::translate("NGDialog", "Space", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NGDialog: public Ui_NGDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NGDIALOG_H
