#ifndef AI_SAVE_WORK_H
#define AI_SAVE_WORK_H
#include <QThread>
#include <QImage>
#include <QObject>
#include <vector>
#include <QFile>
#include <QTimer>
#include <QDir>
#include <QDateTime>
#include "Model/sacsvstream.h"

using namespace std;
class Data;
class AI_save_work : public QThread
{
    Q_OBJECT
public:
    explicit AI_save_work(QImage * pImage,vector<string> m_ElDefect,vector<string> m_ElPosition,QString,bool AI_OK,int okNum,int ngNum,int errNum,int misNum,string strPath, int AI_EL_num,Data*);
    virtual  void run();
    void Set_CSVdode(bool bOK);
    //每日统计数据
    void Set_Total_CSV(bool bOK);
    void Set_Total_CSV();
private:
    QImage     m_pImage;
    QImage  *   m_pDrawImage;
    std::string m_strPath;
    QStringList m_strList;
    QString m_strFileName;
    QString  m_ngstrFileName;
    QString m_AI_NG_PATH;
    QString m_AI_NG_img_PATH;
    QString m_AI_Total_PATH;
    QString m_AI_img_path;
    QString m_AI_ngimg_path;
    QString m_SAB;
    vector<string> m_ElDefect;
    vector<string> m_ElPosition;
    Data* m_data;
    QString m_csv_path;
    int m_AI_EL_num = 0;
    int m_AI_EL_NGnum = 0;
    bool m_AI_OK = false;
    QFile                    *file;
    void mkdir_path(QString path);
    void initcsv(QString path);
    void Set_NG_CSV();

    int m_FalseMissed=0;

private:
    int okNum;
    int ngNum;
    int errorNum;
    int missNum;
   // QString m_AI_Total_PATH;
    QString csvTotalPath;

};

#endif // AI_SAVE_WORK_H
