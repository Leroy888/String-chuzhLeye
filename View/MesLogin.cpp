#include "MesLogin.h"
#include "ui_MesLogin.h"
#include <QMessageBox>
#pragma execution_character_set("utf-8")

MesLogin::MesLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MesLogin)
{
     setWindowTitle(QApplication::translate("TestForm", "\347\231\273\345\205\245\346\241\206", Q_NULLPTR));
    ui->setupUi(this);
}

MesLogin::~MesLogin()
{
    delete ui;
}

void MesLogin::on_btn_login_3_clicked()
{
    QString strUser = ui->lineEdit_user_3->text();
    QString strPwd  = ui->lineEdit_pwd_3->text();
    std::string strRet;
    bool bRet = m_MesObj.OnLogin(strUser.toStdString(), strPwd.toStdString(), strRet);

    if(bRet)
    {
        QMessageBox::information(NULL,"Login OK",strRet.c_str(),QMessageBox::Yes , QMessageBox::Yes);
        m_strUser = strUser.toStdString();
        done(1);
    }
    else
    {
        QMessageBox::information(NULL,"Login Fatel",strRet.c_str(),QMessageBox::Yes , QMessageBox::Yes);
    }

}
