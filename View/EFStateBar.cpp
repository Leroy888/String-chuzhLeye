#include "EFStateBar.h"
#include "ui_EFStateBar.h"
#include "Tool/TranslationES.h"
#include "../Controller/LogicController.h"
#pragma execution_character_set("utf-8")

EFStateBar::EFStateBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EFStateBar),
    m_pController(nullptr)
{
    ui->setupUi(this);
    initStates();
    ui->lineEdit->setEnabled(false);
}

EFStateBar::~EFStateBar()
{
    delete ui;
}

void EFStateBar::SetController(LogicController *pController)
{
    m_pController = pController;
}

void EFStateBar::updateState(int nState)
{
  ui->widget_state->setState(nState);
}

//void EFStateBar::cameraState(bool bOpen)
//{
//    if(bOpen)
//    {
//        ui->camera_status->setText(QApplication::translate("EFStateBar", "\346\255\243\345\270\270", Q_NULLPTR));
//        ui->camera_status->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
//                                                       "color: rgb(255, 255, 255);"));
//    }
//    else
//    {
//        ui->camera_status->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));

//        ui->camera_status->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
//                                                       "color: rgb(255, 255, 255);"));
//    }

//}
void EFStateBar::AI_state(bool bOpen)
{
    if(bOpen)
    {

        ui->label->setText(QApplication::translate("EFStateBar", "\346\255\243\345\270\270", Q_NULLPTR));
        ui->label->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                        "color: rgb(255, 255, 255);"));
    }
    else
    {
        ui->label->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));
        ui->label->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                        "color: rgb(255, 255, 255);"));
    }
}
void EFStateBar::plcState(bool bOpen)
{
    if(bOpen)
    {
        ui->plc_status->setText(QApplication::translate("EFStateBar", "\346\255\243\345\270\270", Q_NULLPTR));
        ui->plc_status->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                    "color: rgb(255, 255, 255);"));
    }
    else
    {
        ui->plc_status->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));

        ui->plc_status->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                    "color: rgb(255, 255, 255);"));
    }
}

void EFStateBar::cameraELState(bool bOpen)
{
    if(bOpen)
    {

        ui->came_el_status->setText(QApplication::translate("EFStateBar", "\346\255\243\345\270\270", Q_NULLPTR));
        ui->came_el_status->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
                                                        "color: rgb(255, 255, 255);"));
    }
    else
    {
        ui->came_el_status->setText(QApplication::translate("EFStateBar", "\347\246\273\347\272\277", Q_NULLPTR));

        ui->came_el_status->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
                                                        "color: rgb(255, 255, 255);"));
    }
}

std::string EFStateBar::GetBarCode()
{
    return ui->lineEdit->text().toStdString();
}

void EFStateBar::SetBarCode(QString strCode)
{
    ui->lineEdit->setText(strCode);
}

void EFStateBar::EditBarCode()
{
    ui->lineEdit->clear();



//    ui->lineEdit->setEnabled(true);

//    ui->lineEdit->setFocus();
}

void EFStateBar::initStates()
{
     ui->widget_state->setState(-1);
    m_states.clear();
    auto & it = TranslationES::Instance();
    m_states.push_back(it.GetTr("StateNormal"));
    m_states.push_back(it.GetTr("StatePos"));
    m_states.push_back(it.GetTr("StatePhoto"));
    m_states.push_back(it.GetTr("StatePlc"));
    m_states.push_back(it.GetTr("StateDefect"));
}

//输入条码完毕
void EFStateBar::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().isEmpty())
        return ;
    //发送信号
    ui->lineEdit->setEnabled(false);
    if(m_pController)
    {
        m_pController->OnHasBarCode();
    }

}

void EFStateBar::on_btn_editCode_clicked()
{
    ui->lineEdit->setEnabled(true);
}
