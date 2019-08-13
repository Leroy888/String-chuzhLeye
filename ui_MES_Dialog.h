/********************************************************************************
** Form generated from reading UI file 'MES_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MES_DIALOG_H
#define UI_MES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MES_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *BtnSelect;
    QLabel *label;
    QPushButton *BtnPush;
    QLabel *label_2;
    QLabel *lab_code;
    QLineEdit *lineEdit_barCode;
    QPushButton *BtnScan;

    void setupUi(QDialog *MES_Dialog)
    {
        if (MES_Dialog->objectName().isEmpty())
            MES_Dialog->setObjectName(QStringLiteral("MES_Dialog"));
        MES_Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MES_Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        BtnSelect = new QPushButton(MES_Dialog);
        BtnSelect->setObjectName(QStringLiteral("BtnSelect"));
        BtnSelect->setGeometry(QRect(290, 30, 81, 21));
        label = new QLabel(MES_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 251, 21));
        label->setInputMethodHints(Qt::ImhNone);
        label->setFrameShape(QFrame::Box);
        BtnPush = new QPushButton(MES_Dialog);
        BtnPush->setObjectName(QStringLiteral("BtnPush"));
        BtnPush->setGeometry(QRect(290, 140, 81, 21));
        label_2 = new QLabel(MES_Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 31, 16));
        lab_code = new QLabel(MES_Dialog);
        lab_code->setObjectName(QStringLiteral("lab_code"));
        lab_code->setGeometry(QRect(60, 140, 191, 16));
        lab_code->setInputMethodHints(Qt::ImhNone);
        lab_code->setFrameShape(QFrame::Box);
        lineEdit_barCode = new QLineEdit(MES_Dialog);
        lineEdit_barCode->setObjectName(QStringLiteral("lineEdit_barCode"));
        lineEdit_barCode->setGeometry(QRect(20, 80, 251, 20));
        BtnScan = new QPushButton(MES_Dialog);
        BtnScan->setObjectName(QStringLiteral("BtnScan"));
        BtnScan->setGeometry(QRect(290, 80, 81, 21));

        retranslateUi(MES_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MES_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MES_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MES_Dialog);
    } // setupUi

    void retranslateUi(QDialog *MES_Dialog)
    {
        MES_Dialog->setWindowTitle(QApplication::translate("MES_Dialog", "Dialog", Q_NULLPTR));
        BtnSelect->setText(QApplication::translate("MES_Dialog", "\351\200\211\346\213\251\344\270\212\344\274\240\345\233\276\347\211\207", Q_NULLPTR));
        label->setText(QString());
        BtnPush->setText(QApplication::translate("MES_Dialog", "\344\270\212\344\274\240", Q_NULLPTR));
        label_2->setText(QApplication::translate("MES_Dialog", "\346\235\241\347\240\201:", Q_NULLPTR));
        lab_code->setText(QString());
        BtnScan->setText(QApplication::translate("MES_Dialog", "\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MES_Dialog: public Ui_MES_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MES_DIALOG_H
