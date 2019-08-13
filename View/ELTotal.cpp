#include "ELTotal.h"
#include "ui_ELTotal.h"
#include <QTextCodec>
#pragma execution_character_set("utf-8")
ELTotal::ELTotal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ELTotal),
      m_Set("el_total.data",QSettings::IniFormat)
{
    ui->setupUi(this);
    m_Set.setIniCodec(QTextCodec::codecForName("GBK"));



}

ELTotal::~ELTotal()
{
    delete ui;
}
void ELTotal::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        QWidget::changeEvent(event);
    }
}
void ELTotal::InitHeaders(QStringList &lists)
{
    ui->Table_Widget->AddRows(lists);
    m_nNum = lists.count();
    initData();
}

void ELTotal::AddValue(QString date)
{
   int nRow =  ui->Table_Widget->Getnumber(date);
    if(nRow >= m_vTotal.size())
        return;

//    for(int i= 0;i<=m_vTotal.size();i++)
//    {
//        ui->Table_Widget.
//    }
    int nNumber = m_vTotal[nRow];
    ++nNumber;
    m_vTotal[nRow] = nNumber;

    ui->Table_Widget->SetValue(nRow, nNumber);
    //ui->Table_Widget->getdate(nRow, nNumber);
    QString strValue = QString::asprintf("value%d",nRow);
    m_Set.setValue(strValue,nNumber);
    m_Set.sync();
}



void ELTotal::on_Btn_Clear_clicked()
{
    for(int i = 0; i < m_nNum; ++i)
    {
        QString strValue = QString::asprintf("value%d",i);
        m_Set.setValue(strValue,0);
        m_vTotal[i] = 0;
        ui->Table_Widget->SetValue(i,m_vTotal[i]);
    }
    m_Set.sync();
}

void ELTotal::initData()
{
    m_vTotal.resize(m_nNum,0);

    for(int i = 0; i < m_nNum; ++i)
    {
        QString strValue = QString::asprintf("value%d",i);
        m_vTotal[i] = m_Set.value(strValue).toInt();
        ui->Table_Widget->SetValue(i,m_vTotal[i]);
    }
    AddValue("OK");
}
