#include "WorkerOriSave.h"
#include "LogicController.h"
#include <QDate>
#include <QDir>
#pragma execution_character_set("utf-8")
WorkerOriSave::WorkerOriSave(LogicController * pLogic, bool bEL)
{
    m_pLogic = pLogic;
    m_bEL = bEL;

}


void WorkerOriSave::run()
{
    if(!m_pLogic)
        return ;

 //   QString strCode  = m_pLogic->m_ELUIObj.GetBarCode().c_str();

    if(m_bEL)
    {
        QString strPath = GetPath(true);

        strPath += QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
        strPath +="_";
        vector<void * > buffers = m_pLogic->m_pVELCahceImages;

        for(int i = 0; i <4; ++i)
        {
            QString strName = strPath+QString::number(i);
            strName+=".png";
            QImage img((uchar *)buffers[i],1920,1200,QImage::Format_Grayscale8);
            img.save(strName,"PNG");

        }
    }
//    else
//    {
//        QString strPath = GetPath(false);

//        strPath += strCode;
//        strPath +="_";
//        vector<void * > buffers = m_pLogic->m_pVLookCacheImages;

//        for(int i = 0; i <12; ++i)
//        {
//            QString strName = strPath+QString::number(i);
//            strName+=".jpg";
//            QImage img((uchar *)buffers[i],5440,3648,QImage::Format_RGB888);
//            img.save(strName,"JPG");

//        }
//    }


}

QString WorkerOriSave::GetPath(bool EL)
{
    QString strPath = "c:/opt";

    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
            return "";
    }

    strPath += "/";
    QString strDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    strPath+= strDate;
    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
            return "";
    }
    strPath += "/";
    if(EL)
    {
        strPath +="EL";
    }
    else
    {
        strPath += "WG";
    }

    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
            return "";
    }

    strPath += "/";

    return strPath;


}
