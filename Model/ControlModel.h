#ifndef CONTROLMODEL_H
#define CONTROLMODEL_H
#include "Tool/IController.h"
#include <vector>

#include "EFComm/Unity/IOTPPublic.h"



class ControlModel:public IController
{
public:
    ControlModel();

    //获取相机参数
    bool  OnLoad(const std::string & strPath);

    Data * GetObj();

    //设置EL的坐标
    bool   OnSetELRegs(const std::vector<HALREG> & vecs);

    //获取EL的坐标
    std::vector<HALREG> OnGetELRegs();

    //设置外观坐标
    bool   OnSetLookRegs(const std::vector<HALREG> & vecs);

    //获取外观坐标
    std::vector<HALREG> OnGetLookRegs();

private:
    //设置坐标
    void   setRegs(const std::string &strPrex,const std::vector<HALREG> & vecs);

    //获取坐标
    std::vector<HALREG> getRegs(const std::string &strPrex);

private:
    Data *  m_pPropertyData;
};

#endif // CONTROLMODEL_H
