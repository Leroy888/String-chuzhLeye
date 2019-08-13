#include "DefectBtnModel.h"
#include <QTextCodec>
#pragma execution_character_set("utf-8")

DefectBtnModel::DefectBtnModel(QObject *parent) : QObject(parent)
  ,m_Set("ModuleConfig/MES.ini",QSettings::IniFormat)
{
    m_Set.setIniCodec(QTextCodec::codecForName("GBK"));
    InitData();
}

DefectBtnModel &DefectBtnModel::Instance()
{
  static DefectBtnModel * pModel = new DefectBtnModel;
  return *pModel;
}



void DefectBtnModel::InitData()
{
    m_bCheck = m_Set.value("checkOpen").toBool();

    m_Url = m_Set.value("WsUrl").toString().toStdString();
    m_NameSpace = m_Set.value("WsNameSpace").toString().toStdString();
    m_FacilityId = m_Set.value("WsFacilityId").toString().toStdString();


    m_ftpAddr = m_Set.value("jkFtpAddr").toString().toStdString();
    m_strCenterWork =m_Set.value("jkTestData").toString().toStdString();
    m_TestData = m_Set.value("jkWorkerCenterID").toString().toStdString();
    m_ftpUser = m_Set.value("ftpUserName").toString().toStdString();
    m_ftpPwd = m_Set.value("ftpPassWord").toString().toStdString();

    m_ELId = m_Set.value("WsELId").toString().toStdString();
    m_WGId = m_Set.value("WsWGId").toString().toStdString();

    int nELNUM = m_Set.value("WsELDefectTypeNum").toInt();
    int nWGNUM = m_Set.value("WsWgDefectTypeNum").toInt();
    int nOKNUM = m_Set.value("WsOKDefectTypeNum").toInt();


    m_EL_Titles.clear();
    m_EL_CMDS.clear();
    m_EL_OKtype.clear();
    for(int i = 1; i <= nOKNUM; ++i)
    {
        QString strELDetail = QString("OKDefectType%1").arg(i);
        string  strValue = m_Set.value(strELDetail).toString().toStdString();
        m_EL_OKtype.push_back(strValue);
    }
    for(int i = 1; i <= nELNUM; ++i)
    {
        QString strELDetail = QString("ELDetail%1").arg(i);
        string  strValue = m_Set.value(strELDetail).toString().toStdString();
        m_EL_Titles.push_back(strValue);

        QString strELCmd = QString("ELReason%1").arg(i);
        string  strCmdValue = m_Set.value(strELCmd).toString().toStdString();
        m_EL_CMDS.push_back(strCmdValue);
    }

    for(int i = 1; i <= nWGNUM; ++i)
    {
        QString strWGDetail = QString("WGDetail%1").arg(i);
        string  strValue = m_Set.value(strWGDetail).toString().toStdString();
        m_WG_Titles.push_back(strValue);

        QString strWGCmd = QString("WGReason%1").arg(i);
        string  strCmdValue = m_Set.value(strWGCmd).toString().toStdString();
        m_WG_CMDS.push_back(strCmdValue);
    }

    m_bAICheck = m_Set.value("AIOpen").toBool();
    m_strAIUrl = m_Set.value("AIUrl").toString();

}




