#include "TestForm.h"
#include "ui_TestForm.h"
#pragma execution_character_set("utf-8")
TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);

    InitButton();

    OnShowButton(0);

}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::OnButtonsTitle(std::vector<std::string> &names)
{
     for(auto &it : m_Buttons)
     {
         it->setText("");
     }

    int nTotal = qMin((int)names.size(),9);

    for(int i =0; i< nTotal; ++i)
    {
        m_Buttons[i]->setText(names[i].c_str());
    }

    OnShowButton(nTotal);
}

void TestForm::OnShowButton(int nNum)
{
    for(auto &it : m_Buttons)
    {
        it->setEnabled(false);
    }

    int nTotal = qMin(nNum,9);
    for(int i =0; i < nTotal; ++i)
    {
        m_Buttons[i]->setEnabled(true);
    }
}

void TestForm::OnDeylay(bool bOpen, int nMs)
{
    m_bDeylay = bOpen;
    m_nTimeMs = nMs;
}

void TestForm::OnSetCallBack(std::function<bool (int)> func)
{
    m_callBack = func;
}

void TestForm::InitButton()
{
    m_callBack = nullptr;
     m_bDeylay = false;
     m_nTimeMs = 500;
     m_nCmd = -1;

     m_pSignalMap = new QSignalMapper(this);
     connect(m_pSignalMap, SIGNAL(mapped(int)),this, SLOT(OnClicked(int)));

     m_pTimer = new QTimer(this);
     connect(m_pTimer, SIGNAL(timeout()), this, SLOT(OnTimerOut()));


    m_Buttons.clear();
    m_Buttons.push_back(ui->pushButton_ok);
    m_Buttons.push_back(ui->pushButton_ng1);
    m_Buttons.push_back(ui->pushButton_ng2);
    m_Buttons.push_back(ui->pushButton_ng3);
    m_Buttons.push_back(ui->pushButton_ng4);
    m_Buttons.push_back(ui->pushButton_ng5);
    m_Buttons.push_back(ui->pushButton_ng6);
    m_Buttons.push_back(ui->pushButton_ng7);
    m_Buttons.push_back(ui->pushButton_ng8);

    for(int i = 0; i < m_Buttons.size(); ++i)
    {
        QPushButton * pBtn = m_Buttons.at(i);
        connect(pBtn, SIGNAL(clicked()), m_pSignalMap, SLOT(map()));
        m_pSignalMap->setMapping(pBtn, i);
    }
}

void TestForm::SendCmd()
{
    if(!m_callBack)
        return ;

    if(m_callBack(m_nCmd))
    {
        m_nCmd = -1;
        OnShowButton(0);
    }

}

void TestForm::OnClicked(int nCmd)
{
     m_nCmd = nCmd;

    if(m_bDeylay)
    {
        m_pTimer->stop();

        m_pTimer->start(m_nTimeMs);
    }
    else
    {
       SendCmd();
    }
}

void TestForm::OnTimerOut()
{
     m_pTimer->stop();
     SendCmd();
}


