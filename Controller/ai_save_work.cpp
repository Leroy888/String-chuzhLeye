#include "ai_save_work.h"
#include "../Controller/LogicController.h"
#include <QDebug>
#pragma execution_character_set("utf-8")

AI_save_work::AI_save_work(QImage * pImage,vector<string> ElDefect,vector<string> ElPosition,QString codename,bool AI_OK,int okNum,int ngNum,int errNum,int misNum,string strpath, int AI_EL_num,Data* data)
{
    m_pImage = pImage->copy();
    m_ElDefect = ElDefect;
    m_ElPosition = ElPosition;

    m_AI_OK = AI_OK;
    m_data = data;

    m_strFileName = m_data->GetAttribute("StringEL_AI_path").GetString();
    m_ngstrFileName =   m_data->GetAttribute("StringEL_AING_path").GetString();
    m_AI_EL_num   = m_data->GetAttribute("StringEL_AI_num");
    m_AI_EL_NGnum   = m_data->GetAttribute("StringEL_AI_EL_NGnum");
    m_AI_img_path = m_data->GetAttribute("StringEL_AIimg_path").GetString();
    m_AI_ngimg_path =  m_data->GetAttribute("StringEL_NGAIimg_path").GetString();
    m_AI_NG_PATH  = m_data->GetAttribute("StringEL_AI_all_ng_path").GetString();
    m_SAB  = m_data->GetAttribute("StringEL_AI_SAB").GetString();
    m_AI_NG_img_PATH  = m_data->GetAttribute("StringEL_AI_all_ng_img_path").GetString();

    m_AI_Total_PATH  = m_data->GetAttribute("StringEL_Total_path").GetString();
   // m_FalseMissed = FM;

    m_AI_Total_PATH  = m_data->GetAttribute("StringEL_Total_path").GetString();

    this->okNum = okNum;
    this->ngNum = ngNum;
    this->errorNum = errNum;
    this->missNum = misNum;
    this->csvTotalPath = QString::fromStdString(strpath);

    file = new QFile(m_strFileName);
    if(m_AI_EL_num == 1)
    {
        initcsv(m_strFileName);
    }
}

void AI_save_work::initcsv(QString path)
{
    mkdir_path(path);
    if (!file->exists())
    {
        if(!file->open(QIODevice::Append))
        {
            return;
        }
        SACsvStream csv(file);
        csv << "条码" << "方向" << "串数" << "缺陷" << "位置" << "结果" <<"日期"<< endl;
        file->close();
    }

}
void AI_save_work::run()
{
    Set_Total_CSV();
    if(m_ElDefect.empty())
    {
        Set_CSVdode(true);
    }
    else
    {
        Set_CSVdode(false);
    }
}

//数据每日运行记录 2090519
void AI_save_work::Set_Total_CSV()  //写入CSV文件
{
    //CSV 文件保存路径 和 名称
    mkdir_path(m_AI_NG_PATH);

    mkdir_path(csvTotalPath);

    QFile *NG_File;
    NG_File = new QFile(csvTotalPath);
    if(NG_File->exists())
        NG_File->remove();
    if (!NG_File->exists())
    {
        if(!NG_File->open(QIODevice::Append))
        {
            return;
        }
        SACsvStream acsv(NG_File);

        acsv<<tr("日期")<<"班别"<<("检验数")<<("OK组件数")<<("NG组件数")
          <<("漏检数")<<("误判数")<<("良率")<<("漏检率")
         <<("NG率")<<("误判率")<<endl;

        NG_File->close();
    }

    if(!NG_File->open(QIODevice::Append))
    {
        return;
    }

    SACsvStream csv(NG_File);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd");
    //临时以时间命名条码 20190518
  //  QString cutDate = current_date_time.toString("yyyyMMddhhmmssFF");
    QString day = "白班";
    QTime  time = QTime::currentTime();
    //夜班
    if(time.hour() <8||time.hour() >=20)
    {
        day = "晚班";
    }
    int sum = okNum + ngNum;

    QString ngPer = QString::number((float)ngNum/sum,'f',3);
    QString missPer = QString::number((float)missNum/sum,'f',3);
    QString errorPer = QString::number((float)errorNum/sum,'f',3);
    float fOk = 1 - (float)(missNum+errorNum)/sum;
    QString okPer = QString::number(fOk,'f',3);

    csv << current_date<< day<<sum <<okNum <<ngNum <<missNum <<errorNum <<okPer <<missPer <<ngPer <<errorPer<< endl;

    NG_File->close();
}

void AI_save_work::mkdir_path(QString path)   //
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


void AI_save_work::Set_NG_CSV()  //写入CSV文件
{
    mkdir_path(m_AI_NG_PATH);
    mkdir_path(m_AI_NG_img_PATH);
    QFile *NG_File;
    NG_File = new QFile(m_AI_NG_PATH);
    if (!NG_File->exists())
    {
        if(!NG_File->open(QIODevice::Append))
        {
            return;
        }
        SACsvStream acsv(NG_File);
        acsv << "条码" << "方向" << "串数" << "缺陷" << "位置" << "结果" <<"日期"<< endl;
        NG_File->close();
    }
    if(!NG_File->open(QIODevice::Append))
    {
        return;
    }
    SACsvStream csv(NG_File);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    //临时以时间命名条码 20190518
    QString cutDate = current_date_time.toString("yyyyMMddhhmmss");

    for(int i=0 ; i<m_ElDefect.size(); ++i)
    {
        csv << cutDate << m_SAB << m_AI_EL_NGnum <<m_ElDefect[i].c_str() << m_ElPosition[i].c_str()<<"NG"<<current_date<< endl;
        //ng 图像的命名方式 缺陷位置+缺陷类型
        m_AI_NG_img_PATH = m_AI_NG_img_PATH+"_"+m_ElPosition[i].c_str()+m_ElDefect[i].c_str();
    }

    NG_File->close();
    m_AI_NG_img_PATH = m_AI_NG_img_PATH+".jpg";
    m_pImage.save(m_AI_NG_img_PATH,"JPG");
}


//数据每日运行记录 2090519
void AI_save_work::Set_Total_CSV(bool bOK)  //写入CSV文件
{
    //CSV 文件保存路径 和 名称
    mkdir_path(m_AI_Total_PATH);

    QFile *NG_File;
    NG_File = new QFile(m_AI_Total_PATH);
    if (!NG_File->exists())
    {
        if(!NG_File->open(QIODevice::Append))
        {
            return;
        }
        SACsvStream acsv(NG_File);
        //        acsv << "条码" << "串数" << "缺陷" << "位置" << "结果" <<"日期"<< endl;
        acsv  <<"日期"<< "条码"<< "AI结果"<< "AI缺陷" << "AI位置" <<"人工判定"<<"综合评判"<<endl;

        NG_File->close();
    }

    if(!NG_File->open(QIODevice::Append))
    {
        return;
    }

    SACsvStream csv(NG_File);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ");
    //临时以时间命名条码 20190518
    QString cutDate = current_date_time.toString("yyyyMMddhhmmssFF");

    if(bOK)
    {
        csv << current_date << cutDate<<"OK"<< "无缺陷"<<"无缺陷"<<m_FalseMissed<<"等待结果"<<endl;
    }
    else
    {
        for(int i=0 ; i<m_ElDefect.size(); ++i)
        {
            csv << current_date << cutDate<<"NG"<<m_ElDefect[i].c_str() << m_ElPosition[i].c_str()<<m_FalseMissed<<"等待结果"<<endl;
        }
    }
    NG_File->close();
}


void AI_save_work::Set_CSVdode(bool bOK)  //写入CSV文件
{
    QString name = "11";

    if(!file->open(QIODevice::Append))
    {
        return;
    }

    //新增总统计数据CSV
  //  Set_Total_CSV(bOK);


    SACsvStream csv(file);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");

    //临时以时间命名条码 20190518
    QString cutDate = current_date_time.toString("yyyyMMddhhmmss");


    if(bOK)
    {
        csv << cutDate<<m_SAB<<m_AI_EL_num << ""<< "" <<"OK"<<current_date<< endl;
        m_AI_img_path = m_AI_img_path+"_"+"OK.jpg";
        m_pImage.save(m_AI_img_path,"JPG");
    }else
    {
        Set_NG_CSV();
        ////////////////////////////////////////////////////////////////
        mkdir_path(m_ngstrFileName);
        mkdir_path(m_AI_NG_PATH);
        QFile *NG_File;
        NG_File = new QFile(m_ngstrFileName);
        if (!NG_File->exists())
        {
            if(!NG_File->open(QIODevice::Append))
            {
                return;
            }
            SACsvStream acsv(NG_File);
            acsv << "条码" << "方向" << "串数" << "缺陷" << "位置" << "结果" <<"日期"<< endl;
            NG_File->close();
        }
        if(!NG_File->open(QIODevice::Append))
        {
            return;
        }
        SACsvStream ngcsv(NG_File);
        QString ElDefect = "";
        QString ElPosition = "";
        for(int i=0 ; i<m_ElDefect.size(); ++i)
        {
            ElDefect = ElDefect+m_ElDefect[i].c_str()+";";
            ElPosition =ElPosition+ m_ElPosition[i].c_str()+";";
        }
        ngcsv << "111" << m_SAB << m_AI_EL_NGnum <<ElDefect << ElPosition<<"NG"<<current_date<< endl;
        m_AI_ngimg_path = m_AI_ngimg_path+"_"+ElDefect+ElPosition;

        NG_File->close();
        m_AI_ngimg_path = m_AI_ngimg_path+".jpg";
        m_pImage.save(m_AI_ngimg_path,"JPG");
    }

    file->close();
}
