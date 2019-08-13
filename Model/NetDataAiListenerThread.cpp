#include "NetDataAiListenerThread.h"
#include <QTimer>
#include <QTime>
#include <QBuffer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QPainter>
#include <QDebug>
#include <QEventLoop>
#include <vector>
#include <QMessageBox>
#pragma execution_character_set("utf-8")


NetDataAiListenerThread::NetDataAiListenerThread(Data *data,int index,QNetworkAccessManager *manager, const QImage &image, const QByteArray& baImage, const QString &strUrl, int timeoutms, int w_num, QObject *parent)
    :QThread(parent),mManager(manager),m_TimeOutms(timeoutms),m_reply(NULL),m_strUrl(strUrl),m_num(w_num)
{
    m_nIndex = index;
    m_isTimeOut = false;
    m_Image = image;
    m_BaImage = baImage;
    m_num = w_num/2;
    m_data = data;
//    m_Maps[1] = QString::fromUtf8("小叉隐");//
//    m_Maps[2] = QString::fromUtf8("线隐");
//    m_Maps[3] =QString::fromUtf8("大隐");
//    m_Maps[4] = QString::fromUtf8("片隐");
//    m_Maps[5] = QString::fromUtf8("破片");
//    m_Maps[6] = QString::fromUtf8("隐裂不");
//    m_Maps[7] = QString::fromUtf8("点隐");
//    m_Maps[8] = QString::fromUtf8("虚焊");
//    m_Maps[9] = QString::fromUtf8("轻虚");
//    m_Maps[10] = QString::fromUtf8("非虚");
//    m_Maps[11] = QString::fromUtf8("虚焊不");
//    m_Maps[12] = QString::fromUtf8("边虚");
//    m_Maps[13] = QString::fromUtf8("黑角边");
//    m_Maps[14] = QString::fromUtf8("明暗片");//
//    m_Maps[15] = QString::fromUtf8("不上电");//

//    m_Maps[16] = QString::fromUtf8("明暗突变");
//    m_Maps[17] = QString::fromUtf8("明暗渐变");
//    m_Maps[18] = QString::fromUtf8("短路");
//    m_Maps[19] = QString::fromUtf8("黑边");
//    m_Maps[20] = QString::fromUtf8("断栅快");
//    m_Maps[21] = QString::fromUtf8("断栅");
//    m_Maps[22] = QString::fromUtf8("划伤");
//    m_Maps[23] = QString::fromUtf8("吸盘印");
//    m_Maps[24] = QString::fromUtf8("黑角");//
//    m_Maps[25] = QString::fromUtf8("污染");

        m_Maps[1] = QString::fromUtf8("隐裂");//
        m_Maps[2] = QString::fromUtf8("隐裂");
        m_Maps[3] =QString::fromUtf8("隐裂");
        m_Maps[4] = QString::fromUtf8("隐裂");
        m_Maps[5] = QString::fromUtf8("隐裂");
        m_Maps[6] = QString::fromUtf8("隐裂");
        m_Maps[7] = QString::fromUtf8("虚焊");
        m_Maps[8] = QString::fromUtf8("虚焊");
        m_Maps[9] = QString::fromUtf8("虚焊");
        m_Maps[10] = QString::fromUtf8("虚焊");
        m_Maps[11] = QString::fromUtf8("其他");
        m_Maps[12] = QString::fromUtf8("其他");
        m_Maps[13] = QString::fromUtf8("其他");
        m_Maps[14] = QString::fromUtf8("其他");//
        m_Maps[15] = QString::fromUtf8("其他");//

        m_Maps[16] = QString::fromUtf8("其他");
        m_Maps[17] = QString::fromUtf8("其他");
        m_Maps[18] = QString::fromUtf8("其他");
        m_Maps[19] = QString::fromUtf8("其他");
        m_Maps[20] = QString::fromUtf8("其他");
        m_Maps[21] = QString::fromUtf8("其他");
        m_Maps[22] = QString::fromUtf8("其他");
        m_Maps[23] = QString::fromUtf8("其他");
        m_Maps[24] = QString::fromUtf8("其他");//
        m_Maps[25] = QString::fromUtf8("其他");

}

NetDataAiListenerThread::~NetDataAiListenerThread()
{

}

void NetDataAiListenerThread::run()
{

    QImage image = m_Image;//.scaled(m_Image.width()/2, m_Image.height()/2);
    QTime    time;
    time.start();
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf,"JPG");
    QByteArray hexed = ba.toBase64();
    QJsonObject obj;
    obj.insert("img",hexed.toStdString().c_str());
    qDebug()<<QString("%1").arg(time.elapsed());

    QJsonDocument document;
    document.setObject(obj);

    QByteArray simpbyte_array = document.toJson(QJsonDocument::Compact);

    QNetworkRequest request;
    request.setUrl(QUrl(m_strUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

    m_reply= mManager->post(request,simpbyte_array);

    waitForConnect();
    bool bOK = true;
    //没有超时
    if(!m_isTimeOut&&  m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();  // bytes


        QJsonDocument d = QJsonDocument::fromJson(QString::fromUtf8(bytes).toLatin1());

        qDebug()<< QString::fromUtf8(bytes).toLatin1();
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("result"));

        if (value.isArray())
        {  // Version 的 value 是数组
            QJsonArray array = value.toArray();
            int nSize = array.size();
            vector<DATA> vData;
            for (int i = 0; i < nSize; ++i)
            {
                QJsonObject  obj = array.at(i).toObject();

                int classID =  obj.value("class_id").toInt();
                float fScore = obj.value("score").toDouble();
                int  x1 = obj.value("x1").toInt();
                int  x2 = obj.value("x2").toInt();
                int  y1 = obj.value("y1").toInt();
                int  y2 = obj.value("y2").toInt();
                DATA  data;
                data.nClassID = classID;
                data.fScore = fScore;
                data.x1 = x1;
                data.x2 = x2;
                data.y1 = y1;
                data.y2 = y2;
                data.nLen = sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                bOK =  false;
                if(classID > 15)
                    continue;
                vData.push_back(data);

            }

            drawImage(vData);

            emit sig_Image(m_Image, bOK, m_ElDefect, m_ElPosition, m_nIndex);
        }
    }
    else
    {
        emit sig_Ai_error();
    }

    delete m_reply;
    m_reply = NULL;



}
void NetDataAiListenerThread::Ai_error()
{
    QMessageBox::StandardButton reply;
    QMessageBox msgBox;
    msgBox.setStyleSheet(
                "QPushButton {"
                "background-color:#89AFDE;"
                " border-style: outset;"
                " border-width: 200px;"
                " border-radius: 1000px;"
                " border-color: beige;"
                " font: bold 24px;"
                " min-width: 10em;"
                " min-height: 5em;"
                "}"
                "QLabel { min-width: 20em;min-height:10em;font:24px;background-color:#f0f0f0;}"
                );
    msgBox.resize(200,200);

    reply =  msgBox.information(NULL, "警告","服务器未响应", QMessageBox::Yes, QMessageBox::Yes);
}

void NetDataAiListenerThread::drawImage(const vector<DATA> &vList)
{
   m_Image= m_Image.convertToFormat(QImage::Format_RGB888);
    QPainter painter(&m_Image);
    for(int i = 0; i < vList.size(); ++i)
    {
        const DATA &data = vList[i];

//        if(data.nClassID != 1 && data.nClassID != 4 && data.nClassID !=7)
//            continue;

//        if(data.fScore<0.1)
//            continue;

//        if(data.nClassID == 4 && data.fScore !=1)
//            continue;

//       if(!OnCheckData(data))
//            continue;

       // float n = rand()/360;
        QColor clr=QColor::fromHsv(data.nClassID,255,255);

//        if(data.nClassID == 1 )
//            clr = QColor(255,0,0);


        QPen pen(clr,6);
//        QVector<qreal> dashes;
//        qreal space = 3;
//        dashes << 5 << space << 5 <<space;

//        pen.setDashPattern(dashes);
        painter.setPen(pen);

        QFont font;
        font.setPointSize(24);
        painter.setFont(font);


        QRect rt(data.x1-10, data.y1-10, data.x2-data.x1+20, data.y2-data.y1+20);
        painter.drawRect(rt);

        int x = (data.x1-10+data.x2+20)/2;
        int y = (data.y1-10+data.y2+20)/2;
        int x_min = (m_Image.width()-20)/m_num;
        int y_min = (1200-20)/2;
        int a = x/x_min;
        int b = y/y_min;
        if(b>=1)
        {
            a = a+m_num;
        }
        m_ElDefect.push_back(m_Maps[data.nClassID].toStdString());
        m_ElPosition.push_back(QString("[%1]").arg(QString::number(a+1)).toStdString());

        QString strText = m_Maps[data.nClassID];
        strText+="(";
        strText+=QString::number(data.fScore,'g',6);
        strText +=") --";
        strText += QString::number(data.nLen);

    //    painter.drawText(QPoint(data.x1-30,data.y1 -30), strText);

    }

    painter.end();
}

bool NetDataAiListenerThread::OnCheckData(const DATA &nData)
{


    if(nData.nClassID == 1)
    {
        if(nData.fScore*100< m_data->GetValue("AI_Yinlie").GetInt())
            return false;
    }
    else if(nData.nClassID == 2)
    {
        if(nData.fScore*100 < m_data->GetValue("AI_Xuhan").GetInt())
            return false;
    }
//    else if(nData.nClassID == 3)
//    {
//        if(nData.fScore*100 < 99.8)
//            return false;
//    }
    return true;
}

bool NetDataAiListenerThread::waitForConnect()
{
    QEventLoop eventLoop;
    QTimer * timer = NULL;
    m_isTimeOut = false;

    if (m_TimeOutms > 0)
    {
        timer = new QTimer;
        connect(timer, SIGNAL(timeout()), this, SLOT(slot_waitTimeout()));
        timer->setSingleShot(true);
        timer->start(m_TimeOutms);

        connect(this, SIGNAL(sig_waitTimeout()), &eventLoop, SLOT(quit()));
    }
    connect(mManager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    if (m_reply != NULL)
    {
        connect(m_reply, SIGNAL(readyRead()), &eventLoop, SLOT(quit()));
    }

     eventLoop.exec();

    if (timer != NULL)
    {
        timer->stop();
        delete timer;
        timer = NULL;
    }

    return true;
}

void NetDataAiListenerThread::slot_waitTimeout()
{

    qDebug()<<"time out.....";

    m_isTimeOut = true;
    emit sig_waitTimeout();
}


bool NetDataAiListenerThread::getIsWaitTimeOut() const
{
    return m_isTimeOut;
}
