#include "AuthorityMes.h"
#include "ui_AuthorityMes.h"
#include <QMessageBox>
#pragma execution_character_set("utf-8")

AuthorityMes::AuthorityMes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorityMes),
    m_bOK(false)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("验证权限"));
}

AuthorityMes::~AuthorityMes()
{
    delete ui;
}

void AuthorityMes::on_buttonBox_accepted()
{
    QString  strAutoCode = ui->lineEdit->text();
    if(strAutoCode == "jktest")
    {
        m_bOK = true;
    }
    else
    {
        QMessageBox::warning(NULL,QString::fromLocal8Bit("权限不够"),QString::fromLocal8Bit("输入授权码不正确"));
    }
}
