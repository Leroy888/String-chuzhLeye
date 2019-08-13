#ifndef SAVEWOKER_H
#define SAVEWOKER_H
#include <QThread>
#include <QImage>
#include <QObject>

class SaveWoker : public QThread
{
    Q_OBJECT
public:
    explicit SaveWoker(QImage * pImage, QImage * pDrawImage, const std::string &strPath,QStringList  &cmdType, int nW, int nH, bool bEL);

    virtual  void run();


signals:
    void sig_Save_over(QString  str);
private:
    QImage *    m_pImage;
    QImage  *   m_pDrawImage;
    std::string m_strPath;
    int         m_nW;
    int         m_nH;
    bool        m_bEL;
    QStringList m_strList;
signals:
    void        sig_saveImage();
public slots:
};

#endif // SAVEWOKER_H
