/********************************************************************************
** Form generated from reading UI file 'FileNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILENAMEDIALOG_H
#define UI_FILENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_FileNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *FileNameDialog)
    {
        if (FileNameDialog->objectName().isEmpty())
            FileNameDialog->setObjectName(QStringLiteral("FileNameDialog"));
        FileNameDialog->resize(365, 159);
        buttonBox = new QDialogButtonBox(FileNameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(FileNameDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 40, 311, 31));
        label = new QLabel(FileNameDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 121, 16));

        retranslateUi(FileNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileNameDialog);
    } // setupUi

    void retranslateUi(QDialog *FileNameDialog)
    {
        FileNameDialog->setWindowTitle(QApplication::translate("FileNameDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FileNameDialog", "\350\257\267\350\276\223\345\205\245\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileNameDialog: public Ui_FileNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILENAMEDIALOG_H
