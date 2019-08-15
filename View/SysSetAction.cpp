#include "SysSetAction.h"
#include "ui_SysSetAction.h"
#include <QDir>
#include <QMessageBox>
#include "../Controller/LogicController.h"
#include  "../Model/ControlModel.h"
#include <QFileDialog>
#include <qpainter.h>
#include "MES_Dialog.h"
#include "AuthorityMes.h"
#pragma execution_character_set("utf-8")

SysSetAction::SysSetAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysSetAction),
    m_pController(nullptr),
    m_Set("SysAction.ini",QSettings::IniFormat)
{
    ui->setupUi(this);
    m_Model.OnLoad("cache.xml");

    delaySecs = m_Set.value("DelaySecs").toInt();
    isYl = m_Set.value("IsYl").toBool();
    isXh = m_Set.value("IsXh").toBool();
    isOther = m_Set.value("IsOther").toBool();

    ui->checkBox_other->setChecked(isOther);
    ui->checkBox_XH->setChecked(isXh);
    ui->checkBox_YL->setChecked(isYl);
    ui->spinBox->setValue(delaySecs);
}

SysSetAction::~SysSetAction()
{
    delete ui;
}

void SysSetAction::SetController(LogicController *pController)
{
    m_pController = pController;
    OnRefreshDir();

}

QString SysSetAction::GetIniFile() const
{
    return ui->comboBox_ini->currentData().toString();
}

void SysSetAction::OnEnable(bool bEnable)
{
    ui->comboBox_ini->setEnabled(bEnable);
    ui->Btn_SysSet->setEnabled(bEnable);
}

bool SysSetAction::getIsYl()
{
    return isYl;
}

bool SysSetAction::getIsXh()
{
    return isXh;
}

bool SysSetAction::getIsOther()
{
    return isOther;
}

int SysSetAction::getDelaySecs()
{
    return delaySecs;
}

void SysSetAction::OnRefreshDir()
{
    ui->comboBox_ini->clear();
    QDir dir("./ModuleConfig/formula");
    if(!dir.exists())
    {
        QMessageBox::information(NULL, "NO dir", "/ModuleConfig/formula!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    }

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    int file_count = list.count();
    if(file_count <= 0)
    {
        return;
    }

    QStringList string_list;
    for(int i=0; i < file_count; ++i)
    {
        QFileInfo file_info = list.at(i);
        QString suffix = file_info.suffix();
        if(QString::compare(suffix, QString("xml"), Qt::CaseInsensitive) == 0)
        {
            ui->comboBox_ini->addItem(file_info.baseName(),file_info.absoluteFilePath());
        }
    }
    Data * pData = m_Model.GetObj();
    std::string  strCur = pData->GetValue("LAST_INDEX").GetString();
    if(!strCur.empty())
    {
        ui->comboBox_ini->setCurrentText(strCur.c_str());
    }
    else
    {
        ui->comboBox_ini->setCurrentIndex(0);
    }
    m_pController->OnLoadFile(GetIniFile().toStdString());


}

void SysSetAction::on_Btn_SysSet_clicked()
{
    if(m_pController)
    {
        m_pController->OnShowDebugDlg(GetIniFile().toStdString().c_str());

    }
}

void SysSetAction::on_comboBox_ini_activated(const QString &arg1)
{
    if(m_pController)
    {
        Data * pData = m_Model.GetObj();
        pData->SetValue("LAST_INDEX",ui->comboBox_ini->currentText().toStdString().c_str());
        m_Model.Save();
        m_pController->OnLoadFile(GetIniFile().toStdString());
    }

}

void SysSetAction::on_pushButton_WG_SAVE_clicked()
{
    if(m_pController)
    {
        //  m_pController->OnSaveOriginalWG();
    }
}

void SysSetAction::on_pushButton_EL_SAVE_clicked()
{
    if(m_pController)
    {
        m_pController->OnSaveOriginalEL();
    }
}

void SysSetAction::on_pushButton_ClearBuffer_clicked()
{
    if(m_pController)
    {
        m_pController->OnDisableBtn();
    }
}

void SysSetAction::on_pushButton_ReSend_clicked()
{
    if(m_pController)
    {
        AuthorityMes  autorDlg;
        autorDlg.exec();

        if(autorDlg.m_bOK)
        {
            MES_Dialog Dlg;
            Dlg.OnController(m_pController);
            Dlg.exec();
        }
    }
}
bool caseInsensitiveLessTha(const QString &s1, const QString &s2)
{

    QStringList  sl1 = s1.split("_");
    QStringList  sl2 = s2.split("_");
    if(sl1.count()!=2 || sl2.count()!=2)
        return false;

    int i1 = sl1.at(1).split(".").at(0).toInt();
    int i2 = sl2.at(1).split(".").at(0).toInt();
    return i1 < i2;
}
void SysSetAction::on_pushButton_clicked()
{
    QStringList fileNameList = QFileDialog::getOpenFileNames(this, tr("open file"), " ",  tr("Allfile(*.*);;png(*.png);;jpg(*.jpg)"));
    if(fileNameList.count() != 4)
        return ;
    qSort(fileNameList.begin(), fileNameList.end(),caseInsensitiveLessTha);


    vector<void *>  buffer ;
    for(int j = 0; j < 4; ++j)
    {
        void * p = new uchar [1920*1200];
        QImage img(fileNameList[j]);
        memcpy(p,img.constBits(),1920*1200);
        buffer.push_back(p);
    }
    m_pController->TestDrawEL(buffer);

}

void SysSetAction::on_pushButton_6_clicked()
{
    m_pController->PLC_Reset();

    ui->pushButton_2->setText("左侧气缸下压");
    ui->pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                  "color: rgb(255, 255, 255);"));
    ui->pushButton_4->setText("右侧气缸下压");
    ui->pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                  "color: rgb(255, 255, 255);"));
    ui->pushButton_3->setText("左侧气缸夹紧");
    ui->pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                  "color: rgb(255, 255, 255);"));
    ui->pushButton_5->setText("右侧气缸夹紧");
    ui->pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                  "color: rgb(255, 255, 255);"));


}

void SysSetAction::on_pushButton_2_clicked()  //左侧气缸下压
{
    if(ui->pushButton_2->text() == "左侧气缸下压")
    {
        ui->pushButton_2->setText("左侧气缸抬起");
        ui->pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Left_Cylinder_down(true);
    }
    else
    {
        ui->pushButton_2->setText("左侧气缸下压");
        ui->pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Left_Cylinder_down(false);
    }
}

void SysSetAction::on_pushButton_4_clicked()  //右侧气缸下压
{
    if(ui->pushButton_4->text() == "右侧气缸下压")
    {
        ui->pushButton_4->setText("右侧气缸抬起");
        ui->pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Right_Cylinder_down(true);
    }
    else
    {
        ui->pushButton_4->setText("右侧气缸下压");
        ui->pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Right_Cylinder_down(false);
    }
}

void SysSetAction::on_pushButton_3_clicked()  //左侧气缸夹紧
{
    if(ui->pushButton_3->text() == "左侧气缸夹紧")
    {
        ui->pushButton_3->setText("左侧气缸放松");
        ui->pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Left_Cylinder_Clamp(true);
    }
    else
    {
        ui->pushButton_3->setText("左侧气缸夹紧");
        ui->pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Left_Cylinder_Clamp(false);
    }
}

void SysSetAction::on_pushButton_5_clicked()  //右侧气缸夹紧
{
    if(ui->pushButton_5->text() == "右侧气缸夹紧")
    {
        ui->pushButton_5->setText("右侧气缸放松");
        ui->pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Right_Cylinder_Clamp(true);
    }
    else
    {
        ui->pushButton_5->setText("右侧气缸夹紧");
        ui->pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Right_Cylinder_Clamp(false);
    }
}

void SysSetAction::on_pushButton_7_clicked()   //手动上电
{
    if(ui->pushButton_7->text() == "手动上电")
    {
        ui->pushButton_7->setText("手动上电解除");
        ui->pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Start_Up(true);
    }
    else
    {
        ui->pushButton_7->setText("手动上电");
        ui->pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                      "color: rgb(255, 255, 255);"));
        m_pController->PLC_Start_Up(false);
    }
}

void SysSetAction::on_pushButton_8_clicked()
{
    m_pController->PLC_start();

}

void SysSetAction::on_checkBox_YL_clicked()
{
    if(ui->checkBox_YL->isChecked())
    {
        isYl = true;
    }
    else
    {
        isYl = false;
    }
    m_Set.setValue("IsYl", isYl);
}

void SysSetAction::on_checkBox_XH_clicked()
{
    if(ui->checkBox_XH->isChecked())
    {
        isXh = true;
    }
    else
    {
        isXh = false;
    }
    m_Set.setValue("IsXh", isXh);
}

void SysSetAction::on_checkBox_other_clicked()
{
    if(ui->checkBox_other->isChecked())
    {
        isOther = true;
    }
    else
    {
        isOther = false;
    }
    m_Set.setValue("IsOther", isOther);
}

void SysSetAction::on_spinBox_valueChanged(int arg1)
{
    delaySecs = arg1;
    m_Set.setValue("DelaySecs", delaySecs);
}
