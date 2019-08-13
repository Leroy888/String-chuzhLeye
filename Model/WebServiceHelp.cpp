#include "WebServiceHelp.h"
#include "NetDataListenerThread.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QTimer>
#include <QThread>
#include <QEventLoop>
#include <QVariantMap>
#include <iterator>
#include <QJsonParseError>
#include <QJsonDocument>
#pragma execution_character_set("utf-8")


WebServiceHelp * WebServiceHelp::serverHelp = NULL;
WebServiceHelp::Dispose WebServiceHelp::disp;

WebServiceHelp::WebServiceHelp(QObject *parent):QObject(parent)
{
    manager = new QNetworkAccessManager();
    m_errCode= QNetworkReply::NoError;
}

WebServiceHelp::~WebServiceHelp()
{
    manager->deleteLater();

}

WebServiceHelp *WebServiceHelp::getInstance()
{
    if(serverHelp==NULL)
    {
        serverHelp = new WebServiceHelp();
    }
    return serverHelp;
}






QNetworkReply::NetworkError WebServiceHelp::sendGetRequest(QString urlStr, QByteArray & ba,int timeOutms)
{
    QNetworkReply::NetworkError retError = QNetworkReply::NoError;
    m_errCode= QNetworkReply::NoError;
    QNetworkRequest request;
    QUrl url(urlStr);
    request.setUrl(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply,static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&WebServiceHelp::slot_error);


    QEventLoop eventLoop;
    NetDataListenerThread * thread = new NetDataListenerThread(manager,reply,timeOutms);
    connect(thread, &NetDataListenerThread::finished,&eventLoop,&QEventLoop::quit);
    thread->start();
    eventLoop.exec();
    if(thread->getIsWaitTimeOut())
    {
        ba = reply->readAll();
    }
    else
    {
        m_errCode=QNetworkReply::TimeoutError;
    }
    thread->deleteLater();
    delete reply;
    delete thread;
    thread = NULL;
    retError = m_errCode;
    m_errCode= QNetworkReply::NoError;
    return retError;
}





QNetworkReply::NetworkError WebServiceHelp::sendPostRequest(QString website, const QByteArray &postBa, QByteArray &retBa, int timeOutms)
{
    QString urlStr =website;

    QNetworkReply::NetworkError retError = QNetworkReply::NoError;
    m_errCode= QNetworkReply::NoError;
    QNetworkRequest request;
    QUrl url(urlStr);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader,postBa.length());
    QNetworkReply *reply = manager->post(request,postBa);

    connect(reply,static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&WebServiceHelp::slot_error);


    QEventLoop eventLoop;
    NetDataListenerThread * thread = new NetDataListenerThread(manager,reply,timeOutms);
    connect(thread, &NetDataListenerThread::finished,&eventLoop,&QEventLoop::quit);
    thread->start();
    eventLoop.exec();

    if(thread->getIsWaitTimeOut())
    {
        retBa = reply->readAll();
    }
    else
    {
        m_errCode=QNetworkReply::TimeoutError;
    }
    thread->deleteLater();
    delete reply;
    delete thread;
    thread = NULL;
    retError = m_errCode;
    m_errCode= QNetworkReply::NoError;
    return retError;


}

QNetworkReply::NetworkError WebServiceHelp::sendPostRequest( QString website, QString methodName, const QtSoapMessage &postMessage, QByteArray & ret, int timeOutms)
{
    QString urlStr =website;

    QNetworkReply::NetworkError retError = QNetworkReply::NoError;
    m_errCode= QNetworkReply::NoError;
    QNetworkRequest request;
    QUrl url(urlStr);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QLatin1String("text/xml;charset=utf-8"));
    request.setRawHeader("SOAPAction", methodName.toLatin1());

    QNetworkReply *reply = manager->post(request,postMessage.toXmlString().toUtf8().constData());

    connect(reply,static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&WebServiceHelp::slot_error);


    QEventLoop eventLoop;
    NetDataListenerThread * thread = new NetDataListenerThread(manager,reply,timeOutms);
    connect(thread, &NetDataListenerThread::finished,&eventLoop,&QEventLoop::quit);
    thread->start();
    eventLoop.exec();

    if(thread->getIsWaitTimeOut())
    {

        m_errCode= reply->error();
        switch (reply->error()) {
        case QNetworkReply::NoError:
        case QNetworkReply::ContentAccessDenied:
        case QNetworkReply::ContentOperationNotPermittedError:
        case QNetworkReply::ContentNotFoundError:
        case QNetworkReply::UnknownContentError:
            {
                //retMessage.setContent(reply->readAll());
                ret = reply->readAll();
//                int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
//                if (httpStatus != 200 && httpStatus != 100) {
//                    if (retMessage.faultCode() == QtSoapMessage::Other)
//                        retMessage.setFaultCode(QtSoapMessage::Client);
//                    /*
//                    QString httpReason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
//                    soapResponse.setFaultString(QString("HTTP status %2 (%3).\n%1").arg(soapResponse.faultString().toString()).arg(httpStatus).arg(httpReason));
//                    */
//                }
            }
            break;
        default:
            {
                //retMessage.setFaultCode(QtSoapMessage::Client);
               // retMessage.setFaultString(QString("Network transport error (%1): %2").arg(reply->error()).arg(reply->errorString()));
            }
            break;
        }
            qDebug()<<"ERROR:"<<reply->error();
    }
    else
    {
        m_errCode=QNetworkReply::TimeoutError;
    }
    thread->deleteLater();
    delete reply;
    delete thread;
    thread = NULL;
    retError = m_errCode;

    return retError;
}




void WebServiceHelp::slot_error(QNetworkReply::NetworkError code)
{
    m_errCode = code;
}

WebServiceHelp::Dispose::~Dispose()
{
    if(WebServiceHelp::serverHelp!=NULL)
    {
        delete WebServiceHelp::serverHelp;
        WebServiceHelp::serverHelp=NULL;
    }
}
