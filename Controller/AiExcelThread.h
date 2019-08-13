#ifndef AiExcelThread_H
#define AiExcelThread_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <vector>

using namespace std;

class AiExcelThread : public QThread
{
public:
    AiExcelThread(QImage * pImage,bool isOk,vector<string> elDefect,vector<string> elPosition,string strCode, QString ngPath, QString okNgPath,
                QString totalPath, int okNum, int ngNum, int ylNum,int xhNum,int ylAndXhNum,int otherNum);

    void setSAB(QString strSAB);
    void setStringNum(QString stringNum);
    void run();

protected:
    void initcsv(QString path);
    void mkdir_path(QString path);
private:
    void saveNgExcel();
    void saveOkExcel();
    void saveTotalExcel();
private:
    QImage m_pImage;
    bool m_bAi_Ok;
    QString m_okNgPath;
    QString m_ngPath;
    QString m_totalPath;
    int m_okNum;
    int m_ngNum;
    int m_ylNum;
    int m_xhNum;
    int m_ylAndXhNum;
    int m_otherNum;
    QString m_strCode;
    vector<string> m_ElDefect;
    vector<string> m_ElPosition;
    QString m_SAB;
    QString m_stringNum;


};

#endif // AiExcelThread_H
