#include "JKMesClient.h"

#include "stdsoap2.h"
#include "soapH.h"
#include "ServiceSoap.nsmap"

#pragma execution_character_set("utf-8")
JKMesClient::JKMesClient()
{

}

void JKMesClient::OnInit(const string &strFtpAddr, const string &strWorkCenterID, const string &strTestData, const string &strWebAddr)
{
    m_strFtpAddr = "ftp://172.16.0.32";
    m_strWorkCenterID = "MS0001";
    m_strTestData = "PCPath;172.16.7.176,PCName;pc001,FtpPath;ftp://172.16.0.32:21,IPAddress;127.0.0.1,CheckType; ELCCheck,TestResult; 2,OperatorId; admin,Equipment;SR-5C-01CJ-A-CYHEL02,TestDate;2018/03/30";
    m_strWebAddr = strWebAddr;

}

string JKMesClient::OnCallELPictureAddress(string strCode)
{
    struct soap   OnELPictureAddress;
    soap_init(&OnELPictureAddress);
    _ns1__ELPictureAddress reqPicAddr;
    _ns1__ELPictureAddressResponse  respPicAddr;

  //  reqPicAddr.LotSn
   // reqPicAddr.FtpAddr = &m_strFtpAddr;
    reqPicAddr.LotSn = &strCode;
    //reqPicAddr.WorkCenterId = &m_strWorkCenterID;
    //172.16.7.176
    //"http://172.16.7.176/MESWebService/MESWebService.asmx"
    int nRet = soap_call___ns1__ELPictureAddress(&OnELPictureAddress,  m_strWebAddr.c_str(), "", &reqPicAddr, respPicAddr);
    string strResult = "";
    if (nRet == SOAP_OK)
    {
        strResult = *respPicAddr.ELPictureAddressResult;
    }
    soap_destroy(&OnELPictureAddress);
    soap_end(&OnELPictureAddress);
    soap_done(&OnELPictureAddress);

    return strResult;


}

string JKMesClient::OnCallELInfoMoveStd(string strCode, string strDefect, string &strRespone,const string & strLocalPath)
{
    struct soap OnELInfoMoveStd;
    soap_init(&OnELInfoMoveStd);

    _ns1__ELInfoMoveStd  reqData;
    reqData.LotSN = &strCode;
    reqData.TestData = &m_strTestData;
    reqData.lstDefectInfo = &strDefect;

    _ns1__ELInfoMoveStdResponse respData;
    //172.16.7.176
    int nRet = soap_call___ns1__ELInfoMoveStd(&OnELInfoMoveStd, m_strWebAddr.c_str(), "", &reqData, respData);

    string strRetCode = "-1";
    if (nRet == SOAP_OK)
    {
         strRetCode = *respData.ELInfoMoveStdResult->ResultCode;
         strRespone = *respData.ELInfoMoveStdResult->ResultMsg;

    }

    soap_destroy(&OnELInfoMoveStd);
    soap_end(&OnELInfoMoveStd);
    soap_done(&OnELInfoMoveStd);

    return strRetCode;
}
