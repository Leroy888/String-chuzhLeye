#include "ExcelThread.h"
#include <QFile>
#include <QDateTime>
#include <QTime>
#include <QDir>
#include <QDebug>

ExcelThread::ExcelThread(bool AI_OK, int okNum, int ngNum, int errNum, int misNum, QString strPath)
{
    this->aiOk = AI_OK;
    this->okNum = okNum;
    this->ngNum = ngNum;
    this->errorNum = errNum;
    this->missNum = misNum;
    this->strPath = strPath;
}

void ExcelThread::run()
{
    saveTotalExcel();
}

void ExcelThread::saveTotalExcel()
{
    mkdir_path(strPath);
    //QDateTime
    QFile *NG_File;
    NG_File = new QFile(strPath);
    if(NG_File->exists())
        NG_File->remove();
    if (!NG_File->exists())
    {
        if(!NG_File->open(QIODevice::ReadWrite))
        {
            qDebug()<<"1111111111111111111111111111111111111111111111111111111";

            return;
        }
        SACsvStream acsv(NG_File);

        acsv<<QStringLiteral("DayOrNight")/*白班夜班*/
            <<QStringLiteral("TotalNum")/*总产出*/
            <<QStringLiteral("OKNum")/*OK数*/
            <<QStringLiteral("NGNum")/*NG数*/
            <<QStringLiteral("MissNum")/*漏判数*/
            <<QStringLiteral("ErrorNum")/*误判数*/
            <<QStringLiteral("QualifiedRate%")/*良率*/
            <<QStringLiteral("MissRate%")/*漏判率*/
            <<QStringLiteral("NGRate%")/*NG率*/
            <<QStringLiteral("ErrorRate%")/*误判率*/<<endl;

        NG_File->close();
    }

    if(!NG_File->open(QIODevice::Append))
    {
        qDebug()<<"222222222222222222222222222222222222222222222222222222";
        return;
    }

    SACsvStream csv(NG_File);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd");
    //临时以时间命名条码 20190518
  //  QString cutDate = current_date_time.toString("yyyyMMddhhmmssFF");
    QString day = QStringLiteral("dayWork");
    QTime  time = QTime::currentTime();
    //夜班
    if(time.hour() <8||time.hour() >20)
    {
        day = QStringLiteral("NightWork");
    }
    int sum = okNum + ngNum;

//    QString ngPer = QString::number((float)ngNum/sum,'f',3);
//    QString missPer = QString::number((float)missNum/sum,'f',3);
//    QString errorPer = QString::number((float)errorNum/sum,'f',3);
//    float fOk = 1 - (float)(missNum+errorNum)/sum;
//    QString okPer = QString::number(fOk,'f',3);

    float ngRate = (ngNum*1.0/sum*1.0)*100.0;
    float missRate = (missNum*1.0/sum*1.0)*100.0;
    float errorRate = (errorNum*1.0/sum*1.0)*100.0;
    //float okRate = 1 - (missNum*1.0+errorNum*1.0)/sum*1.0;
    float okRate = (1- (missRate*1.0+errorRate*1.0))*100.0;

    csv << day<<        /*白班夜班*/
           sum <<       /*总产出*/
           okNum <<     /*OK数*/
           ngNum <<     /*NG数*/
           missNum <<   /*漏判数*/
           errorNum <<  /*误判数*/
           okRate <<    /*良率*/
           missRate <<  /*漏判率*/
           ngRate <<    /*NG率*/
           errorRate<<  /*误判率*/
           endl;
qDebug()<<"333333333333333333333333333333333333333333333333333333333";
    NG_File->close();
}

void ExcelThread::mkdir_path(QString path)   //
{
    QStringList list = path.split("/");
    QString mkdir_path = "";
    for(int i = 0;i<list.size()-1;i++)
    {
        mkdir_path = mkdir_path +list[i];
        if(!QDir(mkdir_path).exists())
        {
            if(!QDir().mkdir(mkdir_path))
            {
                return;
            }
        }
        mkdir_path = mkdir_path +"/";
    }
}
