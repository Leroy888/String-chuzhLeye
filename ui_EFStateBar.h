/********************************************************************************
** Form generated from reading UI file 'EFStateBar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFSTATEBAR_H
#define UI_EFSTATEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "StateColor.h"

QT_BEGIN_NAMESPACE

class Ui_EFStateBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *btn_editCode;
    QFrame *line;
    QLabel *label_2;
    QLabel *came_el_status;
    QLabel *label_4;
    QLabel *plc_status;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    StateColor *widget_state;

    void setupUi(QWidget *EFStateBar)
    {
        if (EFStateBar->objectName().isEmpty())
            EFStateBar->setObjectName(QStringLiteral("EFStateBar"));
        EFStateBar->resize(1153, 42);
        EFStateBar->setMinimumSize(QSize(0, 40));
        horizontalLayout = new QHBoxLayout(EFStateBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        lineEdit = new QLineEdit(EFStateBar);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(300, 40));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"        border-radius: 4px;\n"
"        height: 25px;\n"
"        border: 1px solid rgb(100, 100, 100);\n"
"        background: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit:enabled {\n"
"        color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:enabled:hover, QLineEdit:enabled:focus {\n"
"        color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:!enabled {\n"
"        color: rgb(155, 155, 155);\n"
"}"));
        lineEdit->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit);

        btn_editCode = new QPushButton(EFStateBar);
        btn_editCode->setObjectName(QStringLiteral("btn_editCode"));
        btn_editCode->setMinimumSize(QSize(160, 40));

        horizontalLayout->addWidget(btn_editCode);

        line = new QFrame(EFStateBar);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_2 = new QLabel(EFStateBar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setMaximumSize(QSize(80, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        came_el_status = new QLabel(EFStateBar);
        came_el_status->setObjectName(QStringLiteral("came_el_status"));
        came_el_status->setMinimumSize(QSize(80, 0));
        came_el_status->setMaximumSize(QSize(80, 16777215));
        came_el_status->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        came_el_status->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(came_el_status);

        label_4 = new QLabel(EFStateBar);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        plc_status = new QLabel(EFStateBar);
        plc_status->setObjectName(QStringLiteral("plc_status"));
        plc_status->setMinimumSize(QSize(80, 0));
        plc_status->setMaximumSize(QSize(80, 16777215));
        plc_status->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        plc_status->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(plc_status);

        label_3 = new QLabel(EFStateBar);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        label = new QLabel(EFStateBar);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_state = new StateColor(EFStateBar);
        widget_state->setObjectName(QStringLiteral("widget_state"));
        widget_state->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(widget_state);


        retranslateUi(EFStateBar);

        QMetaObject::connectSlotsByName(EFStateBar);
    } // setupUi

    void retranslateUi(QWidget *EFStateBar)
    {
        EFStateBar->setWindowTitle(QApplication::translate("EFStateBar", "Form", Q_NULLPTR));
        lineEdit->setText(QString());
        btn_editCode->setText(QApplication::translate("EFStateBar", "\346\211\213\345\212\250\350\276\223\345\205\245\346\235\241\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("EFStateBar", "EL\347\233\270\346\234\272", Q_NULLPTR));
        came_el_status->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));
        label_4->setText(QApplication::translate("EFStateBar", "PLC", Q_NULLPTR));
        plc_status->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));
        label_3->setText(QApplication::translate("EFStateBar", "AI\350\207\252\345\212\250\350\257\206\345\210\253", Q_NULLPTR));
        label->setText(QApplication::translate("EFStateBar", "\346\234\252\345\274\200\345\220\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EFStateBar: public Ui_EFStateBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFSTATEBAR_H
