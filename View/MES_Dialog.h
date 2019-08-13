#ifndef MES_DIALOG_H
#define MES_DIALOG_H

#include <QDialog>
#include "Controller/LogicController.h"


namespace Ui {
class MES_Dialog;
}

class MES_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit MES_Dialog(QWidget *parent = 0);
    ~MES_Dialog();

    void  OnController(LogicController * pController);

private slots:
    void on_BtnPush_clicked();

    void on_BtnSelect_clicked();

    void on_BtnScan_clicked();

private:
    Ui::MES_Dialog *ui;
    LogicController *  m_pController;
};

#endif // MES_DIALOG_H
