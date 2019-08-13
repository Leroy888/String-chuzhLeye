#include "StateColor.h"
#include "ui_StateColor.h"
#pragma execution_character_set("utf-8")

StateColor::StateColor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateColor)
{
    ui->setupUi(this);
    m_colors = {"background-color: rgb(0, 255, 127);","background-color: rgb(255, 255, 127);","background-color: rgb(0, 170, 255);","background-color: rgb(170, 85, 255);"};
    m_clearColor = "background-color: rgb(255, 255, 255);";
    m_labels.push_back(ui->label_1);
    m_labels.push_back(ui->label_2);
    m_labels.push_back(ui->label_3);
    m_labels.push_back(ui->label_4);
}

StateColor::~StateColor()
{
    delete ui;
}

void StateColor::setState(int nIndex)
{
    if(nIndex <-1||nIndex >3)
        return ;

    if(nIndex == -1)
    {
        for(int i = 0; i < m_labels.size(); ++i)
        {
            m_labels[i]->setStyleSheet(m_clearColor);
        }
    }
    else
    {
        m_labels[nIndex]->setStyleSheet(m_colors[nIndex]);
    }
}
