/********************************************************************************
** Form generated from reading UI file 'StateColor.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATECOLOR_H
#define UI_STATECOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateColor
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *StateColor)
    {
        if (StateColor->objectName().isEmpty())
            StateColor->setObjectName(QStringLiteral("StateColor"));
        StateColor->resize(433, 46);
        horizontalLayout = new QHBoxLayout(StateColor);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_1 = new QLabel(StateColor);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 127);"));
        label_1->setFrameShape(QFrame::NoFrame);
        label_1->setAlignment(Qt::AlignCenter);
        label_1->setMargin(0);
        label_1->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout_2->addWidget(label_1);

        label_2 = new QLabel(StateColor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);
        label_2->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(StateColor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 255);"));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(0);
        label_3->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(StateColor);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(170, 85, 255);"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(0);
        label_4->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(horizontalLayout_2);


        retranslateUi(StateColor);

        QMetaObject::connectSlotsByName(StateColor);
    } // setupUi

    void retranslateUi(QWidget *StateColor)
    {
        StateColor->setWindowTitle(QApplication::translate("StateColor", "Form", Q_NULLPTR));
        label_1->setText(QApplication::translate("StateColor", "\346\213\215\347\205\2471", Q_NULLPTR));
        label_2->setText(QApplication::translate("StateColor", "\346\213\215\347\205\2472", Q_NULLPTR));
        label_3->setText(QApplication::translate("StateColor", "\346\213\215\347\205\2473", Q_NULLPTR));
        label_4->setText(QApplication::translate("StateColor", "\345\210\206\351\200\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StateColor: public Ui_StateColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATECOLOR_H
