#ifndef EFSTATEBAR_H
#define EFSTATEBAR_H

#include <QWidget>
#include <vector>
namespace Ui {
class EFStateBar;
}
class LogicController;

class EFStateBar : public QWidget
{
    Q_OBJECT

public:
    explicit EFStateBar(QWidget *parent = 0);
    ~EFStateBar();

     void    SetController(LogicController * pController);

    void updateState(int nState);

   // void cameraState(bool bOpen);

    void plcState(bool bOpen);

    void cameraELState(bool bOpen);

    std::string GetBarCode();

    //设置条码
    void   SetBarCode(QString strCode);

    void    EditBarCode();


    void AI_state(bool bOpen);
private slots:
    void on_lineEdit_editingFinished();

    void on_btn_editCode_clicked();

private:
    void    initStates();
private:
    Ui::EFStateBar *ui;
    std::vector<std::string>    m_states;
    LogicController * m_pController;
};

#endif // EFSTATEBAR_H
