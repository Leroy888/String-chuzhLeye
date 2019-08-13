
#include "TotalAction.h"
#include "ui_TotalAction.h"
#include <QDateTime>
#include <QTextCodec>
TotalAction::TotalAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotalAction),
    m_nNG(0),
    m_nOK(0),
    m_Set("total.data",QSettings::IniFormat)
{
    m_Set.setIniCodec(QTextCodec::codecForName("GBK"));
    ui->setupUi(this);
    InitData();
}

TotalAction::~TotalAction()
{
    delete ui;
}
void TotalAction::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        QWidget::changeEvent(event);
    }
}
void TotalAction::AddOK()
{
    ++m_nOK;
    ++excelOk;
    ui->lcdNumber_OK->display(m_nOK);
    m_Set.setValue("OK",m_nOK);
    m_Set.setValue("excelOk",excelOk);
}

void TotalAction::AddNG()
{
    ++m_nNG;
    ++excelNg;
    ui->lcdNumber_NG->display(m_nNG);
    m_Set.setValue("NG",m_nNG);
    m_Set.setValue("excelNg", excelNg);
}

void TotalAction::InitData()
{
    m_nNG = m_Set.value("NG").toInt();
    m_nOK = m_Set.value("OK").toInt();

    missNum = m_Set.value("missNum").toInt();
    errorNum = m_Set.value("errorNum").toInt();
    excelNg = m_Set.value("excelNg").toInt();
    excelOk = m_Set.value("excelOk").toInt();
    errorJudgeRate = m_Set.value("errorJudgeRate").toFloat();
    missJudgeRate = m_Set.value("missJudgeRate").toFloat();
    ngRate = m_Set.value("ngRate").toFloat();

    ylNum = m_Set.value("YlNum").toInt();
    xhNum = m_Set.value("XhNum").toInt();
    ylAndXhNum = m_Set.value("YlAndXhNum").toInt();
    otherNum = m_Set.value("OtherNum").toInt();

    ui->lcdNumber_OK->display(m_nOK);
    ui->lcdNumber_NG->display(m_nNG);
    ui->lcdNumber_Error->display(errorNum);
    ui->lcdNumber_Miss->display(missNum);
    ui->lcdNumber_ErrorJudge_Rate->display(errorJudgeRate);
    ui->lcdNumber_MissJudge_Rate->display(missJudgeRate);
    ui->lcdNumber_NG_Rate->display(ngRate);
}

void TotalAction::addMissNum()
{
    ++missNum;
    m_Set.setValue("missNum",missNum);
    ui->lcdNumber_Miss->display(missNum);
}

void TotalAction::addErrorNum()
{
    ++errorNum;
    m_Set.setValue("errorNum",errorNum);
    ui->lcdNumber_Error->display(errorNum);
}

int TotalAction::getOkNum()
{
    return excelOk;
}

int TotalAction::getNgNum()
{
    return excelNg;
}

int TotalAction::getMissNum()
{
    return missNum;
}

int TotalAction::getErrorNum()
{
    return errorNum;
}

void TotalAction::updateErrorJudgeRate()
{
    errorJudgeRate = errorNum*1.0/(m_nNG*1.0+m_nOK*1.0)*100.0;
    m_Set.setValue("errorJudgeRate", errorJudgeRate);
    ui->lcdNumber_ErrorJudge_Rate->display(errorJudgeRate);
}

void TotalAction::updateMissJudgeRate()
{
    missJudgeRate = missNum*1.0/(m_nNG*1.0+m_nOK*1.0)*100.0;
    m_Set.setValue("missJudgeRate", missJudgeRate);
    ui->lcdNumber_MissJudge_Rate->display(missJudgeRate);
}

void TotalAction::updateNGRate()
{
    ngRate = (m_nNG*1.0)/(m_nNG*1.0 + m_nOK*1.0)*100.0;
    m_Set.setValue("ngRate", ngRate);
    ui->lcdNumber_NG_Rate->display(ngRate);
}

void TotalAction::SaveData()
{
    QString str = QString("OK:[%1] NG:[%2] total:[%3] missNum:[%4] errorNum:[%5] missJudgeRate:[%6] errorJudgeRate:[%7] ngRate:[%8]").arg(m_nOK).arg(m_nNG).arg(m_nOK+m_nNG).arg(missNum).arg(errorNum).arg(missNum/(m_nOK+m_nNG)).arg(errorNum/(m_nOK+m_nNG)).arg(ngRate/(m_nOK+m_nNG));
    QString data = QDateTime::currentDateTime().toString("yyyyMMddhhMMss");
    m_Set.setValue(data, str);
}


void TotalAction::clearExcelData()
{
    excelNg = 0;
    excelOk = 0;
    missNum = 0;
    errorNum = 0;
    errorJudgeRate = 0.0;
    missJudgeRate = 0.0;
    ngRate = 0.0;
    ylNum = 0;
    xhNum = 0;
    ylAndXhNum = 0;
    otherNum = 0;

    m_Set.setValue("excelOk",0);
    m_Set.setValue("excelNg",0);
    m_Set.setValue("missJudgeRate", 0.0);
    m_Set.setValue("errorJudgeRate", 0.0);
    m_Set.setValue("ngRate", 0.0);
   // m_Set.setValue("errorNum",errorNum);

    m_Set.setValue("YlNum", 0);
    m_Set.setValue("XhNum", 0);
    m_Set.setValue("YlAndXhNum", 0);
    m_Set.setValue("OtherNum", 0);
}

void TotalAction::addYlNum()
{
    ++ylNum;
    m_Set.setValue("YlNum", ylNum);
}

void TotalAction::addXhNum()
{
    ++xhNum;
    m_Set.setValue("XhNum", xhNum);
}

void TotalAction::addYlAndXhNum()
{
    ++ylAndXhNum;
    m_Set.setValue("YlAndXhNum", ylAndXhNum);
}

void TotalAction::addOtherNum()
{
    ++otherNum;
    m_Set.setValue("OtherNum", otherNum);
}

void TotalAction::on_pushButton_Clear_clicked()
{

    //保存之前的
 //   SaveData();
    m_nOK = 0;
    m_nNG = 0;
    ngRate = 0.0f;

    missNum = 0;
    missJudgeRate= 0.0f;

    errorNum = 0;
    errorJudgeRate = 0.0f;

    ui->lcdNumber_OK->display(0);
    ui->lcdNumber_NG->display(0);
    ui->lcdNumber_NG_Rate->display(0);

    ui->lcdNumber_Error->display(0);
    ui->lcdNumber_ErrorJudge_Rate->display(0);

    ui->lcdNumber_Miss->display(0);
    ui->lcdNumber_MissJudge_Rate->display(0);

    m_Set.setValue("NG", 0);
    m_Set.setValue("OK", 0);


}

int TotalAction::getOtherNum() const
{
    return otherNum;
}

int TotalAction::getYlAndXhNum() const
{
    return ylAndXhNum;
}

int TotalAction::getXhNum() const
{
    return xhNum;
}

int TotalAction::getYlNum() const
{
    return ylNum;
}

void TotalAction::saveDute(QString dute)
{
    m_strDute = dute;
    m_Set.setValue("Dute", m_strDute);
}

QString TotalAction::getDute()
{
    return m_strDute;
}

