#include "TotalAction.h"
#include "ui_TotalAction.h"
#include <QDateTime>
#include <QTextCodec>
#pragma execution_character_set("utf-8")
TotalAction::TotalAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotalAction),
    m_nNG(0),
    m_nOK(0),
    m_Set("total.data",QSettings::IniFormat)
{
    m_Set.setIniCodec(QTextCodec::codecForName("GBK"));
    ui->setupUi(this);
    InitData();
}

TotalAction::~TotalAction()
{
    delete ui;
}

void TotalAction::AddOK()
{
    ++excelOk;
    ++m_nOK;
    ui->lcdNumber_OK->display(m_nOK);
    m_Set.setValue("OK",m_nOK);
    m_Set.setValue("excelOk",excelOk);
}

void TotalAction::AddNG()
{
    ++excelNg;
    ++m_nNG;
    ui->lcdNumber_NG->display(m_nNG);
    m_Set.setValue("NG",m_nNG);
    m_Set.setValue("excelNg",excelNg);
}

void TotalAction::addMissNum()
{

    ++missNum;
    m_Set.setValue("missNum",missNum);

}

void TotalAction::addErrorNum()
{
    ++errorNum;
    m_Set.setValue("errorNum",errorNum);
}

int TotalAction::getOkNum()
{
    return excelOk;
}

int TotalAction::getNgNum()
{
    return excelNg;
}

int TotalAction::getMissNum()
{
    return missNum;
}

int TotalAction::getErrorNum()
{
    return errorNum;
}

void TotalAction::InitData()
{
    m_nNG = m_Set.value("NG").toInt();
    m_nOK = m_Set.value("OK").toInt();
    missNum = m_Set.value("missNum").toInt();
    errorNum = m_Set.value("errorNum").toInt();
    excelNg = m_Set.value("excelNg").toInt();
    excelOk = m_Set.value("excelOk").toInt();

    ui->lcdNumber_OK->display(m_nOK);
    ui->lcdNumber_NG->display(m_nNG);

}

void TotalAction::SaveData()
{
    QString str = QString("OK:[%1] NG:[%2] total:[%3]").arg(m_nOK).arg(m_nNG).arg(m_nOK+m_nNG);
    QString data = QDateTime::currentDateTime().toString("yyyyMMdd hhMMss");
    m_Set.setValue(data,str);
}


void TotalAction::on_pushButton_Clear_clicked()
{

    //保存之前的
    SaveData();
    m_nOK = 0;
    m_nNG = 0;

    ui->lcdNumber_OK->display(0);
    ui->lcdNumber_NG->display(0);
    m_Set.setValue("NG",0);
    m_Set.setValue("OK",0);

}

void TotalAction::clearExcelData()
{
    missNum = 0;
    errorNum = 0;
    excelNg = 0;
    excelOk = 0;

    m_Set.setValue("excelOk",0);
    m_Set.setValue("excelNg",0);
    m_Set.setValue("missNum",0);
    m_Set.setValue("errorNum",0);
}
