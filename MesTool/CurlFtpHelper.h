#pragma once
/*
	Desc: ftp �ϴ���
*/

#include <string>
#include <curl/curl.h>

using namespace  std;

class CurlFtpHelper
{
public:
	CurlFtpHelper();

	~CurlFtpHelper();


	//��ʼ��
	bool  OnInit();

	//�ϴ�
	bool  OnUpLoad(const string & strRemotePath, const string & strLocalPath,const string & strUser, const string & strPwd, int nTimeOut = 5, int nTricks = 3);

	//����
	bool  OnDownLoad(const string & strRemotePath, const string &strLocalPath, int nTimeOut = 5, int nTricks = 3);


private:
	bool	OnDownInit();

	bool	OnUpLoadInit();

private:

	CURL  *		m_pCurlUpHandle;
	CURL  *		m_pCurlDownHandle;


};

