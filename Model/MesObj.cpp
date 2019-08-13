#include "MesObj.h"
#include "WebServiceHelp.h"
#include "DefectBtnModel.h"
#pragma execution_character_set("utf-8")


MesObj::MesObj(QObject *parent) : QObject(parent)
{

}

void MesObj::Login(const std::string &strUser)
{
    m_strUser = strUser;

}
bool MesObj::OnLogin(const string &strUser, const string &strPassword, string &strRet)
{
    //开始登入
     DefectBtnModel & df = DefectBtnModel::Instance();

     QtSoapMessage msg;
     msg.setMethod("login",df.m_NameSpace.c_str());
     msg.addMethodArgument("userName","",strUser.c_str());
     msg.addMethodArgument("password","",strPassword.c_str());
     msg.addMethodArgument("facilityId","",df.m_FacilityId.c_str());

    //

     QString strUrl = df.m_Url.c_str();
     QString strMothed = strUrl + "/login";
     QByteArray retMsg;
     QNetworkReply::NetworkError ret=WebServiceHelp::getInstance()->sendPostRequest(strUrl,strMothed,msg,retMsg,5000);
     if(ret==QNetworkReply::NoError)
     {
         qDebug()<<"OK";
         qDebug()<<retMsg;

         QDomDocument domDocument;
         if (!domDocument.setContent(retMsg, true))
         {
             strRet = "ERROR DOC:"+retMsg;
             return  false;
         }

         QDomElement tree      = domDocument.documentElement();
         QDomNode n = tree.firstChild();

         if (!n.isNull())
         {
             QDomElement e = n.toElement(); //将节点转换为元素
             if (!e.isNull())
             {
                 QJsonParseError simp_json_error;
                 QJsonDocument simp_parse_doucment = QJsonDocument::fromJson(e.text().toUtf8(), &simp_json_error);
                 if (simp_parse_doucment.isObject())
                 {
                     //开始解析json对象

                     QJsonObject obj = simp_parse_doucment.object();

                     bool bRet =  false;
                     if(obj.contains("msg"))
                     {
                        // qDebug()<<obj.take("msg").toString();
                         strRet = obj.take("msg").toString().toStdString();
                     }

                     if(obj.contains("success"))
                     {
                         bRet = obj.take("success").toBool();
                        // qDebug()<<obj.take("success").toBool();
                     }

                     return bRet;

                 }
             }
             strRet = "NO body";
             return false;

         }
         strRet = retMsg;
         return false;
     }
     else
     {
         qDebug()<<"error";
         strRet = "timeout!";
         return false;
     }
    return false;

}
bool MesObj::OnDispatchLotEL(int nCmd, const std::string &strCodeBar, const vector<std::string> &strPoints, const vector<std::string> &strCmd, const vector<std::string> &strDetails, std::string &strRet)
{
    //EL MES 上传
    if(strCodeBar.empty())
        return false;

    DefectBtnModel & df = DefectBtnModel::Instance();

	QString strMsg = "";
	QString strDetal = "";
    QString strP = "";
    QString strTranData = "";
    if(nCmd>0&&strCmd.size()>0)
	{

        strTranData  =  QString("{'parameter':{'items':[");
         QString  strTemp;
        for(int i = 0; i < strCmd.size(); ++i)
        {
             strP = strPoints[i].c_str();
            if(!strTemp.isEmpty())
            {
                strTemp += ",";
            }

            QString  Temp = QString("{'lotId':'%1','parameterSeq':'0','parameterId':'FLD_GRADE','parameterValue':'A','reasonCode':'%2','reasonDetail':'%3','location':'%4'}").arg(strCodeBar.c_str()).arg(strCmd[i].c_str()).arg(strDetails[i].c_str()).arg(strP);
            strTemp += Temp;
        }
        strTranData += strTemp;
        strTranData += "],'collectionType':'BY_LOT'}}";
//
	}
    else
    {
        strTranData = QString("{'parameter':{'items':[{'lotId':'%1','parameterSeq':'0','parameterId':'FLD_GRADE','parameterValue':'A','reasonCode':'%2','reasonDetail':'%3','location':'%4'}],'collectionType':'BY_LOT'}}").arg(strCodeBar.c_str()).arg(strMsg).arg(strDetal).arg(strP);

    }


    qDebug()<<strTranData;


    QtSoapMessage msg;
    msg.setMethod("dispatchLot",df.m_NameSpace.c_str());
    msg.addMethodArgument("facilityId","",df.m_FacilityId.c_str());
    msg.addMethodArgument("userName","",m_strUser.c_str());
    msg.addMethodArgument("eqipId","",df.m_ELId.c_str());
    msg.addMethodArgument("lotIds","",QString("['%1']").arg(strCodeBar.c_str()));
    msg.addMethodArgument("transData","",strTranData);

    QString strUrl = df.m_Url.c_str();
    QString strMothed = strUrl + "/dispatchLot";
    QByteArray retMsg;
    QNetworkReply::NetworkError ret=WebServiceHelp::getInstance()->sendPostRequest(strUrl,strMothed,msg,retMsg,5000);
    if(ret==QNetworkReply::NoError)
    {
        qDebug()<<"OK";
        qDebug()<<retMsg;

        QDomDocument domDocument;
        if (!domDocument.setContent(retMsg, true))
        {
            strRet = "ERROR DOC:"+retMsg;
            return  false;
        }

        QDomElement tree      = domDocument.documentElement();
        QDomNode n = tree.firstChild();

        if (!n.isNull())
        {
            QDomElement e = n.toElement(); //将节点转换为元素
            if (!e.isNull())
            {
                QJsonParseError simp_json_error;
                QJsonDocument simp_parse_doucment = QJsonDocument::fromJson(e.text().toUtf8(), &simp_json_error);
                if (simp_parse_doucment.isObject())
                {
                    //开始解析json对象

                    QJsonObject obj = simp_parse_doucment.object();

                    bool bRet =  false;
                    if(obj.contains("msg"))
                    {
                       // qDebug()<<obj.take("msg").toString();
                        strRet = obj.take("msg").toString().toStdString();
                    }

                    if(obj.contains("success"))
                    {
                        bRet = obj.take("success").toBool();
                       // qDebug()<<obj.take("success").toBool();
                    }

                    return bRet;

                }
            }
            strRet = "NO body";
            return false;

        }
        strRet = retMsg;
        return false;
    }
    else
    {
        qDebug()<<"error";
        strRet = "timeout!";
        return false;
    }


    return false;
}

bool MesObj::OnDispatchLotLook(int nCmd, const std::string &strCodeBar, const vector<string> &strPoints, const vector<string> &strCmd, const vector<string> &strDetails, std::string &strRet)
{
    //外观 MES 上传
    //EL MES 上传
    if(strCodeBar.empty())
        return false;

    DefectBtnModel & df = DefectBtnModel::Instance();

    QString strMsg = "";
    QString strDetal = "";
    QString strP = "";
    QString strTranData = "";
    if(nCmd>0)
    {

        strTranData  =  QString("{'parameter':{'items':[");
         QString  strTemp;
        for(int i = 0; i < strCmd.size(); ++i)
        {
            strP = strPoints[i].c_str();
            if(!strTemp.isEmpty())
            {
                strTemp += ",";
            }

            QString  Temp = QString("{'lotId':'%1','parameterSeq':'0','parameterId':'FLD_GRADE','parameterValue':'A','reasonCode':'%2','reasonDetail':'%3','location':'%4'}").arg(strCodeBar.c_str()).arg(strCmd[i].c_str()).arg(strDetails[i].c_str()).arg(strP);
            strTemp += Temp;
        }
         strTranData += strTemp;
        strTranData += "],'collectionType':'BY_LOT'}}";
//
    }
    else
    {
        strTranData = QString("{'parameter':{'items':[{'lotId':'%1','parameterSeq':'0','parameterId':'FLD_GRADE','parameterValue':'A','reasonCode':'%2','reasonDetail':'%3','location':'%4'}],'collectionType':'BY_LOT'}}").arg(strCodeBar.c_str()).arg(strMsg).arg(strDetal).arg(strP);

    }


    qDebug()<<strTranData;
    QtSoapMessage msg;
    msg.setMethod("dispatchLot",df.m_NameSpace.c_str());
    msg.addMethodArgument("facilityId","",df.m_FacilityId.c_str());
    msg.addMethodArgument("userName","",m_strUser.c_str());
    msg.addMethodArgument("eqipId","",df.m_WGId.c_str());
    msg.addMethodArgument("lotIds","",QString("['%1']").arg(strCodeBar.c_str()));
    msg.addMethodArgument("transData","",strTranData);

    QString strUrl = df.m_Url.c_str();
    QString strMothed = strUrl + "/dispatchLot";
    QByteArray retMsg;
    QNetworkReply::NetworkError ret=WebServiceHelp::getInstance()->sendPostRequest(strUrl,strMothed,msg,retMsg,5000);
        if(ret==QNetworkReply::NoError)
    {
        qDebug()<<"OK";
        qDebug()<<retMsg;

        QDomDocument domDocument;
        if (!domDocument.setContent(retMsg, true))
        {
            strRet = "ERROR DOC:"+retMsg;
            return  false;
        }

        QDomElement tree      = domDocument.documentElement();
        QDomNode n = tree.firstChild();

        if (!n.isNull())
        {
            QDomElement e = n.toElement(); //将节点转换为元素
            if (!e.isNull())
            {
                QJsonParseError simp_json_error;
                QJsonDocument simp_parse_doucment = QJsonDocument::fromJson(e.text().toUtf8(), &simp_json_error);
                if (simp_parse_doucment.isObject())
                {
                    //开始解析json对象

                    QJsonObject obj = simp_parse_doucment.object();

                    bool bRet =  false;
                    if(obj.contains("msg"))
                    {
                      //  qDebug()<<obj.take("msg").toString();
                        strRet = obj.take("msg").toString().toStdString();
                    }

                    if(obj.contains("success"))
                    {
                        bRet = obj.take("success").toBool();
                      //  qDebug()<<obj.take("success").toBool();
                    }

                    return bRet;

                }
            }
            strRet = "NO body";
            return false;

        }
        strRet = retMsg;
        return false;
    }
    else
    {
        qDebug()<<"error";
        strRet = "timeout!";
        return false;
    }


    return false;
}


