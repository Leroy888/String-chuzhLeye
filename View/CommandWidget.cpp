#include "CommandWidget.h"
#include <qDebug>
#pragma execution_character_set("utf-8")

CommandWidget::CommandWidget( QWidget *parent) : QWidget(parent)
{
    m_nRow = 6;
    m_nCol = 6;

}

void CommandWidget::InitUI(bool bEL)
{
    //初始化
   DefectBtnModel &db = DefectBtnModel::Instance();
    if(bEL)
    {

      m_vTitals = db.m_EL_Titles;
      m_vCmds  = db.m_EL_CMDS;
      m_vBools.resize(m_vTitals.size());
    }
    else
    {
        m_vTitals = db.m_WG_Titles;
        m_vCmds  = db.m_WG_CMDS;
        m_vBools.resize(m_vTitals.size());

    }
     initButton();
    for(auto &it : m_vBools)
    {
        it = false;
    }
    updateState();

}

vector<bool> CommandWidget::GetCmd(vector<string> & vCmds, vector<string> & vTitles)
{


    vCmds.clear();
    vTitles.clear();

    for(int i=0 ; i<m_vBools.size(); ++i)
    {
        if(m_vBools.at(i))
        {
            vCmds.push_back(m_vCmds[i]);
            vTitles.push_back(m_Buttons.at(i)->text().toStdString());
        }

    }

    return  m_vBools;

}

int CommandWidget::GetNum()
{
    return m_vBools.size();
}

void CommandWidget::OnClear()
{
    for(auto &it : m_vBools)
    {
        it = false;
    }
    updateState();
}

void CommandWidget::initButton()
{
    m_pSignalMap = new QSignalMapper(this);
    connect(m_pSignalMap, SIGNAL(mapped(int)),this, SLOT(OnClick(int)));
     m_Buttons.clear();

     for(int i = 0 ; i < m_vTitals.size(); ++i)
     {
         QPushButton * pBtn = new QPushButton(this);
         pBtn->setText(m_vTitals.at(i).c_str());
         connect(pBtn, SIGNAL(clicked()), m_pSignalMap, SLOT(map()));
         m_pSignalMap->setMapping(pBtn,i);
         m_Buttons.push_back(pBtn);
     }

}

void CommandWidget::updateUI()
{
    float fW = this->width();
    float fH = this->height();

    float fBW = fW/m_nCol;
    float fBH = fH/m_nRow;

    for(int i = 0; i < m_Buttons.size(); ++i)
    {
        int nRow = i/m_nCol;
        int nCol = i%m_nCol;
        m_Buttons[i]->setGeometry(nCol*fBW, nRow*fBH, fBW, fBH);
    }

}

void CommandWidget::updateState()
{
    for(int i = 0; i < m_vBools.size(); ++i)
    {
        bool bState = m_vBools[i];

        if(bState)
        {

            m_Buttons[i]->setStyleSheet("QPushButton {\
                                        color:#ffffff;\
                                        background-color:#ff5500;\
                                        border-style: outset;\
                                        border-width:2px;\
                                        border-radius:10px;\
                                        border-color: beige;\
                                        font: bold 16px;\
                                        padding:6px;\
                                        }\
                                        QPushButton:!enabled{\
                               color: rgb(235, 235, 235);\
                              background-color: rgb(143, 143, 143);\
                           }");
        }
        else
        {

            m_Buttons[i]->setStyleSheet("QPushButton {\
                                        color:#000000;\
                                        background-color: rgb(229, 229, 229);\
                                        border-style: outset;\
                                        border-width:2px;\
                                        border-radius:10px;\
                                        border-color: beige;\
                                        font: bold 16px;\
                                        padding:6px;\
                                        }\
QPushButton:!enabled{\
color: rgb(235, 235, 235);\
background-color: rgb(143, 143, 143);\
}");
        }
    }
}

void CommandWidget::resizeEvent(QResizeEvent *event)
{
     updateUI();
     QWidget::resizeEvent(event);
}

void CommandWidget::OnClick(int nIndex)
{
    m_vBools[nIndex] = ! m_vBools[nIndex];
    emit sig_Click(nIndex);
    updateState();
}
