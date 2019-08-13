#include "ControlModel.h"
#include "Tool/VarType.h"
#include "Tool/Data.h"
#include "Tool/Utility.h"
#pragma execution_character_set("utf-8")

ControlModel::ControlModel()
    :m_pPropertyData(nullptr)
{

}

bool ControlModel::OnLoad(const std::string &strPath)
{

  //路径转化
    std::string strOutPath;
   Utility:: Utf8ToGbk(strOutPath,strPath.c_str());
    if(strOutPath.empty())
        return false;

    this->SetFilePath(strOutPath.c_str(),ET_UTF8);
    //先关闭
    Close();

    Load();

    Data * pData = this->GetData();
    if(!pData)
    {
        return false;
    }

    Data * pObject =  pData->GetFirstChild("Object");
    if(!pObject)
    {
        pObject = new Data("Object");
        pData->AddChild(pObject);
    }
    m_pPropertyData = pObject->GetFirstChild("Property");

    if(!m_pPropertyData)
    {
        m_pPropertyData = new Data("Property");
        pObject->AddChild(m_pPropertyData);
    }
    return  true;
}

Data *ControlModel::GetObj()
{
    return m_pPropertyData;
}

bool ControlModel::OnSetELRegs(const std::vector<HALREG> &vecs)
{
//    if(vecs.size() != 4)
//        return false;

    setRegs("EL_RECT_",vecs);
    return true;
}

std::vector<HALREG> ControlModel::OnGetELRegs()
{
    return getRegs("EL_RECT_");
}

bool ControlModel::OnSetLookRegs(const std::vector<HALREG> &vecs)
{
//    if(vecs.size() != 12)
//        return false;

    setRegs("LOOK_RECT_",vecs);
    return true;
}

std::vector<HALREG> ControlModel::OnGetLookRegs()
{
     return getRegs("LOOK_RECT_");
}

void ControlModel::setRegs(const std::string &strPrex, const std::vector<HALREG> &vecs)
{
    if(vecs.size() != 4)
        return;

    Data  *  pRect = m_pPropertyData->GetFirstChild("RECT");
    if(!pRect)
    {
        pRect = new Data("RECT");
        m_pPropertyData->AddChild(pRect);
    }

    for(int i = 0; i< 4; ++i)
    {
        char buf[64];
        sprintf(buf,"%d",i);
        std::string strName = strPrex+buf;
        Data * pData = pRect->GetFirstChild(strName.c_str());
        if(!pData)
        {
            pData = new Data(strName.c_str());
            pRect->AddChild(pData);
        }

        pData->SetValue("x1",vecs[i].x1);
        pData->SetValue("x2",vecs[i].x2);
        pData->SetValue("y1",vecs[i].y1);
        pData->SetValue("y2",vecs[i].y2);

    }
}

std::vector<HALREG> ControlModel::getRegs(const std::string &strPrex)
{
    std::vector<HALREG> vec;
    Data  *  pRect = m_pPropertyData->GetFirstChild("RECT");
    if(!pRect)
        return vec;

    for(int i = 0; i< 4; ++i)
    {
        char buf[64];
        sprintf(buf,"%d",i);
        std::string strName = strPrex+buf;
        Data * pData = pRect->GetFirstChild(strName.c_str());
        HALREG  rg;
        if(pData)
        {
            rg.x1 = pData->GetValue("x1");
            rg.x2 = pData->GetValue("x2");
            rg.y1 = pData->GetValue("y1");
            rg.y2 = pData->GetValue("y2");
        }

        vec.push_back(rg);

    }
    return vec;
}
