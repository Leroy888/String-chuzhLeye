#ifndef JKMESCLIENT_H
#define JKMESCLIENT_H
#include <string>
using namespace std;

class JKMesClient
{
public:
    JKMesClient();

    void  OnInit(const string & strFtpAddr, const string & strWorkCenterID, const string & strTestData, const string & strWebAddr);

    string  OnCallELPictureAddress(string strCode);

    string OnCallELInfoMoveStd(string strCode, string strDefect, string & strRespone,const string & strLocalPath);

public:

    string  m_strFtpAddr;   //FTP地址
    string  m_strWorkCenterID;  //地址
    string m_strTestData;
    string  m_strWebAddr;   //WEB SERVSER



};

#endif // JKMESCLIENT_H
