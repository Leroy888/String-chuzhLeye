#include "TotolModel.h"
#include "Tool/Attribute.h"
#include "Tool/Data.h"
#include "Tool/Var.h"
#pragma execution_character_set("utf-8")


TotolModel::TotolModel()
    :m_pPropety(nullptr)
{

}

bool TotolModel::OnLoad(const char *path)
{
    if(!path)
        return false;

    this->SetFilePath(path,ET_UTF8);

    Load();

    Data * pData = this->GetData();
    if(!pData)
    {
        return false;
    }

    Data * pObject =  pData->GetFirstChild("Object");
    if(!pObject)
    {
        return false;
    }
    Data * pBtn = pObject->GetFirstChild("Btn");

    while(pBtn)
    {
        m_vDatas.push_back(pBtn);
        m_strNames.push_back(pBtn->GetValue("Name").GetString());
        m_nValues.push_back(pBtn->GetValue("Value").GetInt());

        pBtn = pBtn->GetNextSibling("Btn");
    }
    return  true;

}

std::vector<std::string> TotolModel::GetButtons()
{
    return m_strNames;
}

std::vector<int> TotolModel::GetValues()
{
    return m_nValues;
}

void TotolModel::AddValue(int nIndex)
{
    if(nIndex<0||nIndex>=m_nValues.size())
        return ;

    int nValue = m_nValues[nIndex];
    ++nValue;
    m_nValues[nIndex] = nValue;

    m_vDatas[nIndex]->SetValue("Value", nValue);

    //保存
    Save();

}
