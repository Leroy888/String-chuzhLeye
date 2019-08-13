#include "AiExcelThread.h"
#include "Model/sacsvstream.h"
#include <QFile>
#include <QDir>
#include <QDateTime>


AiExcelThread::AiExcelThread(QImage * pImage, bool isOk,vector<string> elDefect,vector<string> elPosition,string strCode, QString ngPath, QString okNgPath, QString totalPath, int okNum, int ngNum, int ylNum,int xhNum,int ylAndXhNum,int otherNum)
{
    m_pImage = pImage->copy();
    this->m_bAi_Ok = isOk;
    m_strCode = QString::fromStdString(strCode);
    m_ElDefect = elDefect;
    m_ElPosition = elPosition;
    this->m_okNgPath = okNgPath;
    this->m_ngPath = ngPath;
    this->m_totalPath = totalPath;
    this->m_okNum = okNum;
    this->m_ngNum = ngNum;
    this->m_ylNum = ylNum;
    this->m_xhNum = xhNum;
    this->m_ylAndXhNum = ylAndXhNum;
    this->m_otherNum = otherNum;

  //  initcsv(m_totalPath);
}

void AiExcelThread::setSAB(QString strSAB)
{
    this->m_SAB = strSAB;
}

void AiExcelThread::setStringNum(QString stringNum)
{
    this->m_stringNum = stringNum;
}

void AiExcelThread::run()
{
    mkdir_path(m_totalPath);
    saveTotalExcel();
    if(m_bAi_Ok)
    {
        mkdir_path(m_okNgPath);
        QString aiImgPath = m_okNgPath + m_strCode + ".jpg";
        m_pImage.save(aiImgPath,"JPG");
        saveOkExcel();
    }
    else
    {
        mkdir_path(m_ngPath);
        QString aiImgPath = m_ngPath + m_strCode +".jpg";
        m_pImage.save(aiImgPath,"JPG");
        saveNgExcel();
    }
}

void AiExcelThread::initcsv(QString path)
{
    mkdir_path(path);
    QFile *file = new QFile(path + m_strCode + ".csv");
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

void AiExcelThread::mkdir_path(QString path)   //
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

void AiExcelThread::saveNgExcel()
{
    QTime  time = QTime::currentTime();
    QDate  date = QDate::currentDate();
    if(time.hour() <8)
    {
        date= date.addDays(-1);
    }
    QString fileName = date.toString("yyyy-MM-dd");

    mkdir_path(m_okNgPath);
    QFile *NG_File;
    NG_File = new QFile(m_okNgPath +fileName + ".csv");
    if(NG_File->exists())
        NG_File->remove();
    if (!NG_File->exists())
    {
        if(!NG_File->open(QIODevice::ReadWrite))
        {
            return;
        }
        SACsvStream acsv(NG_File);

        acsv<<QStringLiteral("类型")<<QStringLiteral("隐裂")<<QStringLiteral("虚焊")<<QStringLiteral("隐裂&虚焊")
           <<QStringLiteral("其他")<<QStringLiteral("NG总数")<<endl;

        NG_File->close();
    }

    if(!NG_File->open(QIODevice::Append))
    {
        return;
    }

    int totalNum = m_okNum + m_ngNum;

    SACsvStream csv(NG_File);
    csv<<QStringLiteral("数量")<<m_ylNum<<m_xhNum<<m_ylAndXhNum<<m_otherNum<<m_ngNum << endl;
    NG_File->close();

    mkdir_path(m_ngPath);

    QFile *file;
    file = new QFile(m_ngPath  +fileName + ".csv");
    bool isExists = true;
    if(!file->exists())
    {
        isExists = false;
    }
    if(!file->open(QIODevice::Append))
    {
        return;
    }

    SACsvStream ngCsv(file);
    if(!isExists)
    {
    ngCsv<<QStringLiteral("条码")<<QStringLiteral("方向")<<QStringLiteral("串数")<<QStringLiteral("缺陷")
        <<QStringLiteral("位置")<<QStringLiteral("结果")<<QStringLiteral("日期")<<endl;
    }

    QString strCode = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    //QString strDirect = "";
    QString strRes = "NG";
    QString strDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    for(int i=0 ; i<m_ElDefect.size(); ++i)
    {
       ngCsv << m_strCode << m_SAB << m_stringNum <<m_ElDefect[i].c_str() << m_ElPosition[i].c_str()<<strRes<<strDate<< endl;
       //ng 图像的命名方式 缺陷位置+缺陷类型
    //   m_AI_NG_img_PATH = m_AI_NG_img_PATH+"_"+m_ElPosition[i].c_str()+m_ElDefect[i].c_str();
    }
    //ngCsv<<strCode<<m_SAB<<stringNum<<strDef<<strPosition<<strRes<<strDate<<endl;
    file->close();
}

void AiExcelThread::saveOkExcel()
{
    QFile *ok_File;
    ok_File = new QFile(m_okNgPath  + QStringLiteral("OK总表.csv"));
    if(ok_File->exists())
        ok_File->remove();
    if (!ok_File->exists())
    {
        if(!ok_File->open(QIODevice::ReadWrite))
        {
            return;
        }
        SACsvStream acsv(ok_File);

        acsv<<QStringLiteral("OK总数")<<m_okNum<<endl;
        ok_File->close();
    }
}

void AiExcelThread::saveTotalExcel()
{
    QFile *ok_File;
    ok_File = new QFile(m_totalPath  + QStringLiteral("测试总数.csv"));
    if(ok_File->exists())
        ok_File->remove();
    if (!ok_File->exists())
    {
        if(!ok_File->open(QIODevice::ReadWrite))
        {
            return;
        }
        SACsvStream acsv(ok_File);
        acsv<<QStringLiteral("测试总数")<<QStringLiteral("OK总数")<<QStringLiteral("NG总数")<<QStringLiteral("隐裂总数")
           <<QStringLiteral("虚焊总数")<<QStringLiteral("隐裂&虚焊总数")<<QStringLiteral("其他NG总数")<<endl;

        acsv<<m_okNum + m_ngNum<<m_okNum<<m_ngNum<<m_ylNum<<m_xhNum<<m_ylAndXhNum<<m_otherNum<< endl;
        ok_File->close();
    }
}
