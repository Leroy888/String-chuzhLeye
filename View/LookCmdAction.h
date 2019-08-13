#ifndef LOOKCMDACTION_H
#define LOOKCMDACTION_H

#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include "NGDialog.h"

class LogicController;
namespace Ui {
class LookCmdAction;
}

class LookCmdAction : public QWidget
{
    Q_OBJECT

public:
    explicit LookCmdAction(QWidget *parent = 0);
    ~LookCmdAction();
    void    SetController(LogicController * pController);
    void    InitModel();
    void    OnEnableBtnOKNG(bool bEnabel);
    void    GetParams(vector<string> &points, std::vector<std::string> &stdCmd, std::vector<std::string> &strDetails);

private slots:
    void on_Btn_LOOKDIR_clicked();
    void on_Btn_OK_clicked();

    void on_Btn_NG_clicked();



signals:
    void  sig_cmd(int nCmd);

private:
    Ui::LookCmdAction *ui;
    LogicController *   m_pController;
    NGDialog            m_NGDialog;

};

#endif // LOOKCMDACTION_H
