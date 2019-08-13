#ifndef WEBSERVICEHELP_H
#define WEBSERVICEHELP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "qtsoap.h"

/**
 * @brief The WebServiceHelp class webservice调用帮助类
 * @author yangff
 */
class  WebServiceHelp:public QObject
{
    Q_OBJECT
private:
    class Dispose
    {
    public:
        ~Dispose();
    };
public:
    static WebServiceHelp * getInstance();

public:
    /**
     * @brief sendGetRequest 发送Get请求
     * @param urlStr  url
     * @param ba      返回数据
     * @param timeOutms 超时时间
     * @return  返回错误代码
     */
    QNetworkReply::NetworkError sendGetRequest(QString urlStr, QByteArray & ba, int timeOutms=3000);


    QNetworkReply::NetworkError sendPostRequest(QString website,const QByteArray & postBa, QByteArray& retBa, int timeOutms=3000);

    /**
     * @brief sendPostRequest 发送post请求
     * @param website  网址
     * @param methodName 方法名称
     * @param sendMessage 发送数据
     * @param retMessage   返回信息
     * @param timeOutms 超时时间
     * @return 返回错误代码
     */
        QNetworkReply::NetworkError sendPostRequest(QString website, QString methodName, const QtSoapMessage &postMessage, QByteArray & ret/*QtSoapMessage &retMessage*/, int timeOutms =500);
protected slots:
    void slot_error(QNetworkReply::NetworkError code);
private:
    static WebServiceHelp * serverHelp;
    static WebServiceHelp::Dispose disp;
    QNetworkAccessManager *manager;
    QNetworkReply::NetworkError m_errCode;
private:
    WebServiceHelp(QObject *parent=0);
    ~WebServiceHelp();
};

#endif // WEBSERVICEHELP_H
