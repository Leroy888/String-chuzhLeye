#include "ELCmdAction.h"
#include "ui_ELCmdAction.h"
#include <QFileDialog>
#include "Controller/LogicController.h"
#include "Model/DefectBtnModel.h"
#include "QMessageBox"
#pragma execution_character_set("utf-8")
ELCmdAction::ELCmdAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ELCmdAction),
    m_pController(nullptr)
{
    ui->setupUi(this);

    //测试
    OK_buts.push_back(ui->pushButton_1);
    ui->pushButton_1->setShortcut(tr("1"));
    OK_buts.push_back(ui->pushButton_2);
    ui->pushButton_2->setShortcut(tr("2"));
    OK_buts.push_back(ui->pushButton_3);
    ui->pushButton_3->setShortcut(tr("3"));
    OK_buts.push_back(ui->pushButton_4);
    ui->pushButton_4->setShortcut(tr("4"));
    OK_buts.push_back(ui->pushButton_5);
    ui->pushButton_5->setShortcut(tr("5"));
    OK_buts.push_back(ui->pushButton_6);
    ui->pushButton_6->setShortcut(tr("6"));
    OK_buts.push_back(ui->pushButton_7);
    ui->pushButton_7->setShortcut(tr("7"));
    OK_buts.push_back(ui->pushButton_8);
    ui->pushButton_8->setShortcut(tr("8"));
    OK_buts.push_back(ui->pushButton_9);
    ui->pushButton_9->setShortcut(tr("9"));
    m_pSignalMap = new QSignalMapper(this);
    connect(m_pSignalMap, SIGNAL(mapped(int)),this, SLOT(OnClick(int)));
    DefectBtnModel &db = DefectBtnModel::Instance();
    vector<string>      OKtype;
    OKtype = db.m_EL_Titles;
    for(int i=0;i<OK_buts.size();i++)
    {
        OK_buts[i]->setText(OKtype.at(i).c_str());
        connect(OK_buts[i], SIGNAL(clicked()), m_pSignalMap, SLOT(map()));
        m_pSignalMap->setMapping(OK_buts[i],i);
    }

    OnEnableBtnOKNG(false);
    ui->pushButton_1->setShortcut(tr("1"));
    // m_NGDialog.InitUI(6,10, true);

}
void ELCmdAction::OnClick(int cmd)
{
    OnEnableBtnOKNG(false);
    DefectBtnModel &db = DefectBtnModel::Instance();
    QStringList strArgs;
    strArgs<<db.m_EL_Titles[cmd].c_str();

    emit sig_cmd(1,strArgs);
}
ELCmdAction::~ELCmdAction()
{
    delete ui;
}

void ELCmdAction::SetController(LogicController *pController)
{
    m_pController = pController;
    connect(this, SIGNAL(sig_cmd(int,QStringList)), m_pController, SLOT(slot_el_cmd(int,QStringList)));

}

void ELCmdAction::InitModel()
{
    if(m_pController)
    {
        ControlModel * pModel =  m_pController->OnGetModel();
        Data * pObj = pModel->GetObj();


        if(pObj)
        {
            ui->lineEdit_ELDIR->setText(pObj->GetValue("EL_SAVE_DIR").GetString());
            int nW = pObj->GetValue("RULER_W").GetInt();
            //   m_NGDialog.InitUI(6,nW, true);
        }
    }
}

void ELCmdAction::on_BTN_SAVE_EL_DIR_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty())
        return ;

    ui->lineEdit_ELDIR->setText(dir);

    if(m_pController)
    {
        ControlModel * pModel = m_pController->OnGetModel();
        Data * pObj = pModel->GetObj();
        pObj->SetValue("EL_SAVE_DIR",dir.toStdString().c_str());
        pModel->Save();
    }
}

void ELCmdAction::OnEnableBtnOKNG(bool bEnabel)
{
    ui->Btn_NG->setEnabled(bEnabel);
    ui->Btn_OK->setEnabled(bEnabel);
    ui->Btn_NG->setEnabled(bEnabel);
    ui->Btn_OK->setEnabled(bEnabel); 
//    ui->Btn_OK2->setEnabled(bEnabel);


    for(int i=0;i<OK_buts.size();i++)
    {
        OK_buts[i]->setEnabled(bEnabel);
    }
}

void ELCmdAction::GetParams(std::vector<string> &points, std::vector<std::string> &stdCmd, std::vector<std::string> &strDetails)
{
    //  m_NGDialog.GetTranCode(points, stdCmd, strDetails);
}

void ELCmdAction::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        QWidget::changeEvent(event);
    }
    DefectBtnModel &db = DefectBtnModel::Instance();
    vector<string>      OKtype;
    OKtype = db.m_EL_Titles;
    for(int i=0;i<OK_buts.size();i++)
    {
        OK_buts[i]->setText(OKtype.at(i).c_str());
        m_pSignalMap->setMapping(OK_buts[i],i);
    }
    ui->pushButton_1->setShortcut(tr("1"));
    ui->pushButton_2->setShortcut(tr("2"));
    ui->pushButton_3->setShortcut(tr("3"));
    ui->pushButton_4->setShortcut(tr("4"));
    ui->pushButton_5->setShortcut(tr("5"));
    ui->pushButton_6->setShortcut(tr("6"));
    ui->pushButton_7->setShortcut(tr("7"));
    ui->pushButton_8->setShortcut(tr("8"));
    ui->pushButton_9->setShortcut(tr("9"));
}
string ELCmdAction::GetJKParams()
{
    return "";
}

void ELCmdAction::on_Btn_NG_clicked()
{
    m_pController->slot_stopElCmdTimer();

    QPushButton * pBtn =ui->Btn_NG;
    QPoint pos = pBtn->pos();
    pos.setX(pos.x()+pBtn->width());
    pos.setY(pos.y()+pBtn->height()+40);
    QPoint grobal = this->mapToGlobal(pos);

    //NG判定
    OnEnableBtnOKNG(false);
    QStringList strArgs;
    strArgs<<"NG";
    emit sig_cmd(0+1, strArgs);

    FalseMissed=2;

    return ;
}

void ELCmdAction::on_Btn_OK_clicked()
{
    m_pController->slot_stopElCmdTimer();
    //OK判定
    OnEnableBtnOKNG(false);
    QStringList strArgs;
    strArgs<<"OK";
    emit sig_cmd(0, strArgs);
    FalseMissed=1;
}

//漏检图像收集
void ELCmdAction::on_BTN_SAVE_EL_DIR_2_clicked()
{
    QStringList strArgs;
    strArgs<<"LJ";
    if(m_pController)
    {
        m_pController->OnSaveWPEL(3,strArgs);
    }
}

//误检图像收集
void ELCmdAction::on_BTN_SAVE_EL_DIR_3_clicked()
{
    QStringList strArgs;
    strArgs<<"WJ";
    if(m_pController)
    {
        m_pController->OnSaveWPEL(4,strArgs);
//        QMessageBox::information(this, QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("有种"));
    }
}

void ELCmdAction::on_pushButton_1_clicked()
{//多余

}

//void ELCmdAction::on_Btn_OK_2_clicked()
//{


//}

void ELCmdAction::on_Btn_OK2_clicked()
{
    m_pController->slot_stopElCmdTimer();
    //OK判定
    OnEnableBtnOKNG(false);
    QStringList strArgs;
    strArgs<<"OK-";
    emit sig_cmd(0,strArgs);
    FalseMissed=1;
}
