#ifndef MESLOGIN_H
#define MESLOGIN_H

#include <QDialog>
#include <string>
#include "Model/MesObj.h"

namespace Ui {
class MesLogin;
}

class MesLogin : public QDialog
{
    Q_OBJECT

public:
    explicit MesLogin(QWidget *parent = 0);
    ~MesLogin();
      std::string     m_strUser;
private slots:
    void on_btn_login_3_clicked();

private:
    Ui::MesLogin *ui;
    MesObj  m_MesObj;

};

#endif // MESLOGIN_H
