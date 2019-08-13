#ifndef STARTACTION_H
#define STARTACTION_H

#include <QWidget>

namespace Ui {
class StartAction;
}

class LogicController;

class StartAction : public QWidget
{
    Q_OBJECT

public:
    explicit StartAction(QWidget *parent = 0);
    ~StartAction();
     void    SetController(LogicController * pController);
     void    UpDataIcon(bool bFalse);
private slots:
    void on_Btn_Start_clicked();
private:
    void    UpdateIcon();
private:
    Ui::StartAction *ui;
    LogicController * m_pController;
    bool        m_bStart;
};

#endif // STARTACTION_H
