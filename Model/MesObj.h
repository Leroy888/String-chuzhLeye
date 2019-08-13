#ifndef MESOBJ_H
#define MESOBJ_H

#include <QObject>
#include <string>
#include <vector>
using namespace  std;

class MesObj : public QObject
{
    Q_OBJECT
public:
    explicit MesObj(QObject *parent = 0);

    void    Login(const std::string & strUser);

    bool    OnLogin(const std::string & strUser, const std::string & strPassword, std::string & strRet);

    bool    OnDispatchLotEL(int nCmd, const std::string & strCodeBar, const vector<std::string> & strPoints, const vector<std::string> &strCmd, const vector<std::string> &strDetails,  std::string &strRet);

    bool    OnDispatchLotLook(int nCmd,const std::string & strCodeBar, const vector<std::string> &strPoints, const vector<std::string> &strCmd, const vector<std::string> &strDetails, std::string & strRet);

private:
    std::string     m_strUser;


signals:

public slots:
};

#endif // MESOBJ_H
