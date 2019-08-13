#include "CurlFtpHelper.h"
#include <stdlib.h>
#include <stdio.h>
#include "Windows.h"
#pragma execution_character_set("utf-8")

std::string UTF8ToGB(const char* str)
{
    std::string result;
    WCHAR *strSrc;
    TCHAR *szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new TCHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

size_t  cbGetContentFunc(void * ptr, size_t size, size_t nmemb, void * stream)
{
	int r;
	long len = 0;
	r = sscanf((const char *)ptr, "Content-Length:%ld\n", &len);
	if (r)
	{
		*((long *)stream) = len;
	}
	return size*nmemb;
}

/* read data to upload */
size_t cbReadFunc(void * ptr, size_t size, size_t nmemb, void * stream)
{
	FILE * f = (FILE *)stream;
	
	if (ferror(f))
		return CURL_READFUNC_ABORT;
	size_t n = fread(ptr, size, nmemb, f) *size;
	return n;

}


CurlFtpHelper::CurlFtpHelper()
	:m_pCurlDownHandle(NULL),m_pCurlUpHandle(NULL)
{
}


CurlFtpHelper::~CurlFtpHelper()
{

	if (m_pCurlDownHandle)
	{
		curl_easy_cleanup(m_pCurlDownHandle);
		m_pCurlDownHandle = NULL;
	}

	if (m_pCurlUpHandle)
	{
		curl_easy_cleanup(m_pCurlUpHandle);
		m_pCurlUpHandle = NULL;
	}

	curl_global_cleanup();

}

bool CurlFtpHelper::OnInit()
{
	curl_global_init(CURL_GLOBAL_ALL);

	//上传初始化
	OnUpLoadInit();

	//下载初始化
	OnDownInit();

	return true;
}

#include <iostream>
using namespace std;

bool CurlFtpHelper::OnUpLoad(const string & strRemotePath, const string & strLocalPath, const string & strUser, const string & strPwd, int nTimeOut /*= 5*/, int nTricks /*= 3*/)
{
	if (!m_pCurlUpHandle)
		return false;

	CURLcode nRet = CURLE_GOT_NOTHING;
    string  strGBLocal = UTF8ToGB(strLocalPath.c_str());
    string strGBRemote = UTF8ToGB(strRemotePath.c_str());
    FILE * pFile = fopen(strGBLocal.c_str(), "rb");
	if (pFile == NULL)
	{
		cout << "open file:" << strLocalPath << " error" << endl;
		return false;
	}

	cout << "repath:" << strRemotePath << endl;
	cout << "user:" << strUser << endl;
	cout << "pwd:" << strPwd << endl;
	//long nUpLoadLen = 0;

	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(m_pCurlUpHandle, CURLOPT_URL, strRemotePath.c_str());
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_USERNAME, strUser.c_str());
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_PASSWORD, strPwd.c_str());
	//超时
	if (nTimeOut != -1)
	{
		curl_easy_setopt(m_pCurlUpHandle, CURLOPT_FTP_RESPONSE_TIMEOUT, nTimeOut);
	}

// 	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_HEADERFUNCTION, cbGetContentFunc);
// 	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_HEADERDATA, &nUpLoadLen);
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_READFUNCTION, cbReadFunc);
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_READDATA, pFile);
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_FTPPORT, "-");
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);
	curl_easy_setopt(m_pCurlUpHandle, CURLOPT_VERBOSE, 1L);


	for (int i = 0; i < nTricks; ++i)
	{
		nRet = curl_easy_perform(m_pCurlUpHandle);
		if(nRet == CURLE_OK)
			break;
	}

	fclose(pFile);

	if (nRet != CURLE_OK)
	{
		fprintf(stderr, "%s\n", curl_easy_strerror(nRet));
		return false;
	}

	return true;
}

bool CurlFtpHelper::OnDownLoad(const string & strRemotePath, const string &strLocalPath, int nTimeOut /*= 5*/, int nTricks /*= 3*/)
{
	if (!m_pCurlDownHandle)
		return false;


	return true;
}

bool CurlFtpHelper::OnDownInit()
{
	if (m_pCurlDownHandle)
		return false;

	m_pCurlDownHandle = curl_easy_init();



	return true;

}

bool CurlFtpHelper::OnUpLoadInit()
{
	if (m_pCurlUpHandle)
		return false;

	m_pCurlUpHandle = curl_easy_init();


	return true;
}
