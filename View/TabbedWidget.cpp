#include "TabbedWidget.h"
#pragma execution_character_set("utf-8")
TabbedWidget::TabbedWidget(QWidget *parent) : QWidget(parent),m_pSignalMap(nullptr)
{
    m_AsicRuler = {"A","B","C","D","E","F","G","H","I","J","L","M","N"};
    m_IntRuler = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
}

void TabbedWidget::OnInitUI(int nRow, int nCol)//ROW：y  COL:X
{
    if(!nRow||!nCol)
        return ;

    if(m_pSignalMap)
    {
        delete m_pSignalMap;
        m_pSignalMap = nullptr;
    }

    m_pSignalMap = new QSignalMapper(this);
    connect(m_pSignalMap, SIGNAL(mapped(int)),this, SLOT(OnClick(int)));

    m_nRow = nRow;
    m_nCol = nCol;

    for(auto it:m_Buttons)
    {
        delete it;
    }
    m_Buttons.clear();

    //开始创建控件
    for(int i = 0; i < m_nRow; ++i)
    {
        QString strRow = m_AsicRuler[i];
        for(int j =0; j < m_nCol; ++j)
        {
            QString strTitle = strRow + m_IntRuler[j];
            QPushButton * pBtn = new QPushButton(this);
            pBtn->setText(strTitle);
            m_Buttons.push_back(pBtn);
            pBtn->setEnabled(false);
        }
    }

    int nTotal = m_nRow*m_nCol;
    m_vBools.resize(nTotal);
    for(auto& it:m_vBools)
    {
        it = false;
    }

    //绑定事件
    for(int i = 0; i < m_Buttons.size(); ++i)
    {
        QPushButton * pBtn = m_Buttons.at(i);
        connect(pBtn, SIGNAL(clicked()), m_pSignalMap, SLOT(map()));
        m_pSignalMap->setMapping(pBtn, i);
    }

    updateUI();
    updateState();

}



void TabbedWidget::OnClear()
{
    for(auto &it : m_vBools)
    {
        it = false;
    }
    updateState();
}

int TabbedWidget::GetNum()
{
    return m_vBools.size();
}

void TabbedWidget::OnGetState(vector<bool> &vState)
{
    vState = m_vBools;
}

void TabbedWidget::OnShowState(std::vector<bool> &vState)
{
    if(vState.empty()||vState.size() != m_Buttons.size())
    {
        onStateEnable(false);
        return ;
    }

    onStateEnable(true);

    m_vBools = vState;

    updateState();
}

string TabbedWidget::GetTabbeds(std::vector<bool> &vState)
{
    string strTabbeds;

    for(int i=0 ; i<vState.size(); ++i)
    {
        if(vState[i])
        {
            if(!strTabbeds.empty())
            {
                strTabbeds+=",";
            }
            strTabbeds+=m_Buttons.at(i)->text().toStdString();

        }
    }

    return  strTabbeds;
}

vector<string> TabbedWidget::GetTabbedsXY(std::vector<bool> &vState)
{

    vector<string> result;
    if(vState.size() != m_nRow*m_nCol)
        return result;


    for(int nY = 0; nY < m_nRow;++nY)
        for( int nX = 0; nX < m_nCol; ++nX)
        {
            if(vState[nY*m_nCol+nX])
            {
                string str = std::to_string(nX+1)+"-";
                str+= std::to_string(nY+1);
                result.push_back(str);
            }
        }

    return result;

}

void TabbedWidget::updateUI()
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

void TabbedWidget::updateState()
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

void TabbedWidget::onStateEnable(bool bEnable)
{
    //绑定事件
    for(int i = 0; i < m_Buttons.size(); ++i)
    {
        QPushButton * pBtn = m_Buttons.at(i);
        pBtn->setEnabled(bEnable);
    }
}

void TabbedWidget::resizeEvent(QResizeEvent *event)
{
    do{
        if(m_nRow == 0 || m_nCol == 0)
        {
            break;
        }
        updateUI();
        //界面变化
    }
    while(0);
    QWidget::resizeEvent(event);
}

void TabbedWidget::OnClick(int nIndex)
{

     m_vBools[nIndex] = ! m_vBools[nIndex];
     emit sig_Click(nIndex);
     updateState();
}
