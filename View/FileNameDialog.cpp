#include "FileNameDialog.h"
#include "ui_FileNameDialog.h"
#pragma execution_character_set("utf-8")

FileNameDialog::FileNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileNameDialog),
    m_pStr(nullptr)
{
    ui->setupUi(this);
}

FileNameDialog::~FileNameDialog()
{
    delete ui;
}

void FileNameDialog::SetFileString(std::string *pStr)
{
    m_pStr = pStr;
}

void FileNameDialog::on_lineEdit_textChanged(const QString &arg1)
{
    if(m_pStr)
    {
        *m_pStr = ui->lineEdit->text().toStdString();
    }
}
