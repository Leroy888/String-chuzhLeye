#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include <QSignalMapper>
#include <QPushButton>
#include <QTimer>
#include <functional>
#include <vector>
#include <string>

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = 0);
    ~TestForm();

    void   OnButtonsTitle(std::vector<std::string> &names);
    void   OnShowButton(int nNum);
    void   OnDeylay(bool bOpen, int nMs = 500);
    void   OnSetCallBack(std::function<bool(int)> func);
private:
    void   InitButton();
    void   SendCmd();


private slots:
    void  OnClicked(int nCmd);
    void  OnTimerOut();

private:
    Ui::TestForm *ui;
private:
    QList<QPushButton *>  m_Buttons;
    QSignalMapper   * m_pSignalMap;
    bool              m_bDeylay;
    int               m_nTimeMs;
    int               m_nCmd;
    QTimer  *         m_pTimer;
    std::function<bool(int)>    m_callBack;
};

#endif // TESTFORM_H
