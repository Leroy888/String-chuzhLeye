#ifndef DEFECTBTNMODEL_H
#define DEFECTBTNMODEL_H

#include <QObject>
#include <QSettings>
#include <string>
#include <vector>
#include <string>
using namespace std;
class DefectBtnModel : public QObject
{
    Q_OBJECT
public:
    explicit DefectBtnModel(QObject *parent = 0);
    static DefectBtnModel & Instance();



    QSettings  m_Set;
private:
    void    InitData();

public:

    //晶科
    string      m_ftpAddr;
    string      m_TestData;
    string      m_strCenterWork;
    string      m_ftpUser;
    string      m_ftpPwd;
    //
    bool            m_bCheck;
    string          m_Url;
    string          m_NameSpace;   //命名空间
    string          m_FacilityId;
    string          m_ELId;
    string          m_WGId;

    vector<string>  m_EL_Titles;
    vector<string>  m_EL_CMDS;

    vector<string>  m_WG_Titles;
    vector<string>  m_WG_CMDS;
    vector<string> m_EL_OKtype;
    bool            m_bAICheck;
    QString         m_strAIUrl;
signals:

public slots:
};

#endif // DEFECTBTNMODEL_H
