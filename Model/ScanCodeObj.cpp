#include "ScanCodeObj.h"
#pragma execution_character_set("utf-8")


ScanCodeObj::ScanCodeObj(QObject *parent) : QObject(parent)
{
    connect(&m_Port, &QSerialPort::readyRead, this, &ScanCodeObj::slot_Data);
    connect(&m_Timer, &QTimer::timeout, this, &ScanCodeObj::slot_TimeOut);
}

bool ScanCodeObj::OpenCom(const std::string &strSerailName)
{
    m_Port.setPortName(strSerailName.c_str());
    m_Port.setDataBits(QSerialPort::Data8);
    m_Port.setStopBits(QSerialPort::OneStop);
    m_Port.setParity(QSerialPort::NoParity);
    m_Port.setBaudRate(QSerialPort::Baud115200);
    return m_Port.open(QSerialPort::ReadWrite);
}

void ScanCodeObj::GetCode()
{
    //发送扫条码信号

    QByteArray sendData;
    sendData.push_back(char(0x16));
    sendData.push_back(char(0x54));
    sendData.push_back(char(0x0D));
    m_Port.write(sendData);
}

void ScanCodeObj::slot_Data()
{
    m_ByteArray.append(m_Port.readAll());

    QString str = m_ByteArray;
    int index = str.indexOf(char(0x40));
    if(index == -1)
        return;
    QString strApp = str.mid(0,str.indexOf(char(0x40)));
    emit Sig_Code(strApp);
    //解析
    m_ByteArray.clear();
  //  if (!m_Timer.isActive())
    //    m_Timer.start(5);
}
#include <QDebug>
void ScanCodeObj::slot_TimeOut()
{
   m_Timer.stop();

    QString  str = m_ByteArray;
    QString strApp = str.mid(0,str.indexOf(char(0x40)));
    emit Sig_Code(strApp);
    //解析
    m_ByteArray.clear();

}
