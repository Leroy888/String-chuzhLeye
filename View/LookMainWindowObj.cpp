#include "LookMainWindowObj.h"
#include "Tool/TranslationES.h"
#include "Controller/LogicController.h"
#pragma execution_character_set("utf-8")
LookMainWindowObj::LookMainWindowObj(QObject *parent) : QObject(parent)
  ,m_pLogic(nullptr)
{

}

void LookMainWindowObj::Show()
{
    InitUI();

    m_MainW.show();
}

void LookMainWindowObj::InitModel()
{
    if(m_pLogic)
    {
       ControlModel * pModel =  m_pLogic->OnGetModel();
         Data * pObj = pModel->GetObj();
        m_SeeW.SetWRule(pObj->GetValue("RULER_W_B").GetString() == std::string("TRUE"),false,pObj->GetValue("RULER_W"));
        m_SeeW.SetHRule(pObj->GetValue("RULER_H_B").GetString() == std::string("TRUE") ,true,6);
    }
}

void LookMainWindowObj::SetController(LogicController *pLogic)
{
    m_pLogic = pLogic;
}

void LookMainWindowObj::OnUpDateImage(QImage *pImage)
{
     m_SeeW.SetImage(pImage);
}

void LookMainWindowObj::OnUpDateVecs(int nIndex, std::vector<ChipStrut> &vecs)
{
     m_SeeW.SetVecs(nIndex,vecs);
}

void LookMainWindowObj::InitUI()
{
    m_MainW.setCentralWidget(&m_SeeW);
    auto & Tr = TranslationES::Instance();
    m_MainW.setWindowTitle(Tr.GetTr("PicW2"));
}

void LookMainWindowObj::ShowToolBar()
{

}

void LookMainWindowObj::HideToolBar()
{

}

void LookMainWindowObj::InitToolBar()
{

}

void LookMainWindowObj::InitStateBar()
{

}
