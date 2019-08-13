#include "DLClientInterface.h"
#pragma execution_character_set("utf-8")


DLClientInterface::DLClientInterface(QObject *parent)
{
     m_pNetMgr = new QNetworkAccessManager(this);
}

DLClientInterface &DLClientInterface::Instance()
{
    static  DLClientInterface * s_interface = new DLClientInterface;
    return *s_interface;
}

void DLClientInterface::OnPostImage(Data *data,int index, const QImage &image2, const QString &strUrl, int w_num)
{

   // m_Image = image2.copy();
    qRegisterMetaType<vector<string>>("vector<string>");
    QByteArray ba;
    NetDataAiListenerThread * thread = new NetDataAiListenerThread(data, index, m_pNetMgr, image2, ba, strUrl, 18000, w_num);
    connect(thread, SIGNAL(sig_Image(QImage, bool, vector<string>, vector<string>, int, vector<string>)), this,
            SLOT(slot_Image(QImage, bool, vector<string>, vector<string>, int, vector<string>)), Qt::QueuedConnection);
    //20190710
    connect(thread, SIGNAL(sig_Ai_error()), this, SLOT(slot_Ai_error()), Qt::QueuedConnection);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
void DLClientInterface::slot_Ai_error()
{
    emit sig_Ai_error();
}

void DLClientInterface::slot_Image(const QImage &Image, bool bOK, vector<string> m_ElDefect, vector<string> m_ElPosition, int index,vector<string> resDefect)
{
    m_Image = Image.copy();
    emit sig_Img(m_Image, bOK, m_ElDefect, m_ElPosition, index, resDefect);
}

