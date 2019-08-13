#include "Login.h"
#include "ui_Login.h"
#include <QMessageBox>
#include <QPalette>
#pragma execution_character_set("utf-8")

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowTitle(QApplication::translate("TestForm", "\347\231\273\345\205\245\346\241\206", Q_NULLPTR));
   // QPalette pl = palette();
    //pl.setColor(QPalette::Window, QColor(0, 0, 0, 200));    //   设置背景颜色为黑色，如果不设置默认为白色
   // setPalette(pl);
    setAutoFillBackground(true);
    setWindowOpacity(1.0);

}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_login_clicked()
{
    QString strUser = ui->lineEdit_user->text();
    QString strPwd  = ui->lineEdit_pwd->text();

    if(strUser.isEmpty() || strPwd.isEmpty())
    {
        QMessageBox::information(NULL, "Title", "User or pwd empty!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return ;
    }

    if(strUser == "opt" && strPwd == "opt")
    {
       done(1);
       return ;
    }

    if(strUser == "admin" && strPwd == "admin")
    {
        done(2);
        return ;
    }

    QMessageBox::information(NULL, "Title", "User or pwd error!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);


}
