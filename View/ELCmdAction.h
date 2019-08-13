#ifndef ELCMDACTION_H
#define ELCMDACTION_H

#include <QWidget>
#include <QPushButton>
#include "NGDialog.h"
#include <QSignalMapper>
namespace Ui {
class ELCmdAction;
}

class LogicController;

class ELCmdAction : public QWidget
{
    Q_OBJECT

public:
    explicit ELCmdAction(QWidget *parent = 0);
    ~ELCmdAction();

    void    SetController(LogicController * pController);
    void    InitModel();
    void    OnEnableBtnOKNG(bool bEnable);
   void    GetParams(std::vector<std::string> &points, std::vector<std::string> &stdCmd, std::vector<std::string> &strDetails);

   string  GetJKParams();

   int FalseMissed=0;
private slots:
    void on_BTN_SAVE_EL_DIR_clicked();

    void on_BTN_SAVE_EL_DIR_2_clicked();

    void on_BTN_SAVE_EL_DIR_3_clicked();

    void on_pushButton_1_clicked();

//    void on_Btn_OK_2_clicked();

    void on_Btn_OK2_clicked();

public slots:
    void on_Btn_NG_clicked();

    void on_Btn_OK_clicked();

protected:
   void changeEvent(QEvent * event);

signals:
    void  sig_cmd(int,QStringList);

protected slots:
    void OnClick(int cmd);
private:
    Ui::ELCmdAction *ui;
    LogicController * m_pController;
    QVector<QPushButton *>   OK_buts;
    QSignalMapper   * m_pSignalMap;
    //  NGDialog            m_NGDialog;
};

#endif // ELCMDACTION_H
