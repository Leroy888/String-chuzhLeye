#include "LookCmdAction.h"
#include "ui_LookCmdAction.h"
#include "Controller/LogicController.h"
#include <QFileDialog>
#include "Model/DefectBtnModel.h"
#include "NGDialog.h"
#pragma execution_character_set("utf-8")

LookCmdAction::LookCmdAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LookCmdAction),
    m_pController(nullptr)
{
    ui->setupUi(this);

   //测试
    OnEnableBtnOKNG(false);
    m_NGDialog.InitUI(6,10, false);

}

LookCmdAction::~LookCmdAction()
{
    delete ui;
}

void LookCmdAction::SetController(LogicController *pController)
{
    m_pController = pController;
     connect(this, SIGNAL(sig_cmd(int)), m_pController,SLOT(slot_look_cmd(int)));
}

void LookCmdAction::InitModel()
{
    if(m_pController)
    {
        ControlModel * pModel =  m_pController->OnGetModel();
        Data * pObj = pModel->GetObj();
        if(pObj)
        {
            ui->lineEdit_LOOKDIR->setText(pObj->GetValue("LOOK_SAVE_DIR").GetString());
        }
    }
}

void LookCmdAction::OnEnableBtnOKNG(bool bEnabel)
{
    ui->Btn_NG->setEnabled(bEnabel);
    ui->Btn_OK->setEnabled(bEnabel);
}

void LookCmdAction::GetParams(vector<string> &points, vector<std::string> &stdCmd, vector<std::string> &strDetails)
{
    m_NGDialog.GetTranCode(points, stdCmd, strDetails);
}







void LookCmdAction::on_Btn_LOOKDIR_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty())
        return ;

    ui->lineEdit_LOOKDIR->setText(dir);
    if(m_pController)
    {
        ControlModel * pModel = m_pController->OnGetModel();
        Data * pObj = pModel->GetObj();
        pObj->SetValue("LOOK_SAVE_DIR",dir.toStdString().c_str());
        pModel->Save();
    }
}





void LookCmdAction::on_Btn_OK_clicked()
{
    OnEnableBtnOKNG(false);
    emit sig_cmd(0);


}


void LookCmdAction::on_Btn_NG_clicked()
{
    QPushButton * pBtn =ui->Btn_NG;
    QPoint pos = pBtn->pos();
    pos.setX(pos.x()+pBtn->width());
    pos.setY(pos.y()+pBtn->height()+40);
    QPoint grobal = this->mapToGlobal(pos);

    m_NGDialog.OnParamClear();

    m_NGDialog.setGeometry(grobal.x(),grobal.y(),m_NGDialog.width(),m_NGDialog.height());

    m_NGDialog.exec();
    OnEnableBtnOKNG(false);
    //提交MES

    //获取发送
    emit  sig_cmd(1);

}
