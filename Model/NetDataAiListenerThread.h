#ifndef NETDATAAILISTENERTHREAD_H
#define NETDATAAILISTENERTHREAD_H
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QImage>
#include <vector>
#include "Tool/Data.h"
using namespace std;

struct DATA
{
    int nClassID;
    float fScore;
    int x1;
    int x2;
    int y1;
    int y2;
    int nLen;

};


class NetDataAiListenerThread:public QThread
{
    Q_OBJECT
public:
    NetDataAiListenerThread(Data *data,int index,QNetworkAccessManager *manager,const QImage & image, const QByteArray& baImage, const QString & strUrl,int timeoutms,int w_num,QObject *parent = 0);
    ~NetDataAiListenerThread();

    QByteArray getBa() const;
    bool getIsWaitTimeOut() const;
    int      m_num;
protected:
    virtual void run();

    void drawImage(const vector<DATA> & vList);
    bool OnCheckData(const DATA & nData);
private:
    bool waitForConnect();
protected slots:
    void slot_waitTimeout();

signals:
    void sig_waitTimeout();
    void sig_Image(const QImage & img,bool bOK,vector<string> m_ElDefect,vector<string> m_ElPosition,int index, vector<string> resDefect);
    void sig_Ai_error();
private:
    QNetworkAccessManager *mManager;
    int m_TimeOutms;
    bool m_isTimeOut;
    QNetworkReply * m_reply;
    QImage      m_Image;
    QByteArray  m_BaImage;
    QString     m_strUrl;
    vector<string> m_ElDefect;
    vector<string> m_ElPosition;
    vector<string> m_resDefect;
    QMap<int,QString>    m_Maps;
    int         m_nIndex;
    Data *m_data;
    void Ai_error();
};

#endif // NETDATALISTENERTHREAD_H
