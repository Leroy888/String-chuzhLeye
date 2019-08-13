#ifndef DLCLIENTINTERFACE_H
#define DLCLIENTINTERFACE_H
#include "NetDataAiListenerThread.h"
#include <QNetworkAccessManager>
#include <QObject>
#include <QImage>
#include <string>
#include <vector>
#include "Tool/Data.h"
class DLClientInterface : public QObject
{
    Q_OBJECT
public:
    explicit DLClientInterface(QObject *parent = 0);

    static  DLClientInterface & Instance();

    void   OnPostImage(Data *data,int index, const QImage &image2, const QString &strUrl, int w_num);

    void   OnPostImageBa(const QImage & image,const QByteArray & ba_image, const QString & strUrl,const QString &w_num );


public slots:
    void slot_Image(const QImage & Image,bool bOK,vector<string> m_ElDefect,vector<string> m_ElPosition,int index);
    void slot_Ai_error();
signals:
    void sig_Img(const QImage &image,bool bOK,vector<string> m_ElDefect,vector<string> m_ElPosition,int index);
    void sig_Ai_error();
private:
   QNetworkAccessManager * m_pNetMgr;
   QImage                  m_Image;
   vector<string>          m_ElDefect;
   Data *m_data;
};


#endif // DLCLIENTINTERFACE_H
