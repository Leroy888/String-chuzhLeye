#include "StartAction.h"
#include "ui_StartAction.h"
#include "../Controller/LogicController.h"
#include "../Controller/ExcelThread.h"
#include <QTime>
#include <QDebug>
#pragma execution_character_set("utf-8")

StartAction::StartAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartAction),
    m_pController(nullptr),
    m_bStart(false)
{
    ui->setupUi(this);
}

StartAction::~StartAction()
{
    delete ui;
}

void StartAction::SetController(LogicController *pController)
{
    m_pController = pController;
}

void StartAction::UpDataIcon(bool bFalse)
{


    if(bFalse)
    {
         ui->Btn_Start->setStyleSheet("border-image: url(:/Resources/Image/stop_0.png);");
         m_bStart = true;
    }
    else
    {
        ui->Btn_Start->setStyleSheet("border-image: url(:/Resources/Image/start_0.png);");
         m_bStart = false;
    }

}

void StartAction::on_Btn_Start_clicked()
{
    if(m_pController)
    {
        if(m_bStart)
        {
            m_pController->OnStop();
        }
        else
        {
//            QString day = "wanban";
//            QTime  time = QTime::currentTime();
//            int hour = time.hour();
//            qDebug()<<"8888888888888888888888888888888888888888888888888888888888888     hour  "<<QString::number(hour);

//            if(8< time.hour() && time.hour() <20 )
//            {

//                day = "白班";
//                qDebug()<<"999999999999999999999999999999999999999999999999999999999999999   "<<day;
//            }
//            QString strPath = QString::fromLocal8Bit("F:/20190609/夜班/统计表格.csv");
//            int okNum = 100;
//            int ngNum = 10;
//            int errorNum = 3;
//            int missNum = 5;
//            bool aiOk = false;
//            ExcelThread* thd = new ExcelThread(aiOk, okNum, ngNum, errorNum, missNum, strPath);
//            thd->start();
             m_pController->OnStart();
        }


        m_bStart =!m_bStart;

         UpdateIcon();


    }
}

void StartAction::UpdateIcon()
{
    if(m_bStart)
    {
         ui->Btn_Start->setStyleSheet("border-image: url(:/Resources/Image/stop_0.png);");
    }
    else
    {
        ui->Btn_Start->setStyleSheet("border-image: url(:/Resources/Image/start_0.png);");
    }
}
