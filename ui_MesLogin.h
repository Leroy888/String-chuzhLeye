/********************************************************************************
** Form generated from reading UI file 'MesLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESLOGIN_H
#define UI_MESLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MesLogin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_11;
    QLineEdit *lineEdit_user_3;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_12;
    QLineEdit *lineEdit_pwd_3;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *btn_login_3;
    QSpacerItem *horizontalSpacer_14;

    void setupUi(QDialog *MesLogin)
    {
        if (MesLogin->objectName().isEmpty())
            MesLogin->setObjectName(QStringLiteral("MesLogin"));
        MesLogin->resize(528, 245);
        verticalLayout = new QVBoxLayout(MesLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(MesLogin);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/Resources/Image/LOGO.png")));

        horizontalLayout_10->addWidget(label_9);

        label_10 = new QLabel(MesLogin);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_10);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        label_11 = new QLabel(MesLogin);
        label_11->setObjectName(QStringLiteral("label_11"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        label_11->setFont(font1);

        horizontalLayout_11->addWidget(label_11);

        lineEdit_user_3 = new QLineEdit(MesLogin);
        lineEdit_user_3->setObjectName(QStringLiteral("lineEdit_user_3"));
        lineEdit_user_3->setFont(font1);

        horizontalLayout_11->addWidget(lineEdit_user_3);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_17);

        label_12 = new QLabel(MesLogin);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_12->addWidget(label_12);

        lineEdit_pwd_3 = new QLineEdit(MesLogin);
        lineEdit_pwd_3->setObjectName(QStringLiteral("lineEdit_pwd_3"));
        lineEdit_pwd_3->setFont(font1);
        lineEdit_pwd_3->setEchoMode(QLineEdit::Password);

        horizontalLayout_12->addWidget(lineEdit_pwd_3);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);

        btn_login_3 = new QPushButton(MesLogin);
        btn_login_3->setObjectName(QStringLiteral("btn_login_3"));
        btn_login_3->setMinimumSize(QSize(180, 60));
        btn_login_3->setStyleSheet(QLatin1String("QPushButton { \n"
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

        horizontalLayout_9->addWidget(btn_login_3);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_9);


        retranslateUi(MesLogin);

        QMetaObject::connectSlotsByName(MesLogin);
    } // setupUi

    void retranslateUi(QDialog *MesLogin)
    {
        MesLogin->setWindowTitle(QApplication::translate("MesLogin", "Dialog", Q_NULLPTR));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("MesLogin", "MES\347\231\273\345\205\245", Q_NULLPTR));
        label_11->setText(QApplication::translate("MesLogin", "\350\264\246\345\217\267:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MesLogin", "\345\257\206\347\240\201:", Q_NULLPTR));
        btn_login_3->setText(QApplication::translate("MesLogin", "\347\231\273\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MesLogin: public Ui_MesLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESLOGIN_H
