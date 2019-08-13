#ifndef COMMANDWIDGET_H
#define COMMANDWIDGET_H

#include <QWidget>
#include "Model/DefectBtnModel.h"
#include <QPushButton>
#include <QSignalMapper>
using namespace  std;


class CommandWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CommandWidget(QWidget *parent = 0);

    void    InitUI(bool bEL);

    vector<bool>    GetCmd(vector<string> & vCmds, vector<string> & vTitles);

    int     GetNum();

    void    OnClear();

private:
    void    initButton();
    void    updateUI();
    void    updateState();
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    QList<QPushButton *>  m_Buttons;
    std::vector<bool>     m_vBools;
    vector<string>      m_vCmds;
    vector<string>      m_vTitals;
    QSignalMapper   * m_pSignalMap;
    int             m_nRow;
    int             m_nCol;
signals:
    void        sig_Click(int i);

public slots:
    void    OnClick(int i);
};

#endif // COMMANDWIDGET_H
