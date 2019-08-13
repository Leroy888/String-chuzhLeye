/********************************************************************************
** Form generated from reading UI file 'AuthorityMes.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORITYMES_H
#define UI_AUTHORITYMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AuthorityMes
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AuthorityMes)
    {
        if (AuthorityMes->objectName().isEmpty())
            AuthorityMes->setObjectName(QStringLiteral("AuthorityMes"));
        AuthorityMes->resize(373, 87);
        buttonBox = new QDialogButtonBox(AuthorityMes);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(190, 40, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AuthorityMes);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 171, 20));

        retranslateUi(AuthorityMes);
        QObject::connect(buttonBox, SIGNAL(accepted()), AuthorityMes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AuthorityMes, SLOT(reject()));

        QMetaObject::connectSlotsByName(AuthorityMes);
    } // setupUi

    void retranslateUi(QDialog *AuthorityMes)
    {
        AuthorityMes->setWindowTitle(QApplication::translate("AuthorityMes", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthorityMes: public Ui_AuthorityMes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORITYMES_H
