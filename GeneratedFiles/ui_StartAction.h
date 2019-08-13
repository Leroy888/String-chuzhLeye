/********************************************************************************
** Form generated from reading UI file 'StartAction.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTACTION_H
#define UI_STARTACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartAction
{
public:
    QGridLayout *gridLayout;
    QPushButton *Btn_Start;

    void setupUi(QWidget *StartAction)
    {
        if (StartAction->objectName().isEmpty())
            StartAction->setObjectName(QStringLiteral("StartAction"));
        StartAction->resize(61, 60);
        gridLayout = new QGridLayout(StartAction);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Btn_Start = new QPushButton(StartAction);
        Btn_Start->setObjectName(QStringLiteral("Btn_Start"));
        Btn_Start->setMinimumSize(QSize(60, 60));
        Btn_Start->setMaximumSize(QSize(60, 60));
        Btn_Start->setStyleSheet(QStringLiteral("border-image: url(:/Resources/Image/start_0.png);"));

        gridLayout->addWidget(Btn_Start, 0, 0, 1, 1);


        retranslateUi(StartAction);

        QMetaObject::connectSlotsByName(StartAction);
    } // setupUi

    void retranslateUi(QWidget *StartAction)
    {
        StartAction->setWindowTitle(QApplication::translate("StartAction", "Form", Q_NULLPTR));
        Btn_Start->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartAction: public Ui_StartAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTACTION_H
