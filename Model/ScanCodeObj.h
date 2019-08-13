#ifndef SCANCODEOBJ_H
#define SCANCODEOBJ_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
class ScanCodeObj : public QObject
{
    Q_OBJECT
public:
    explicit ScanCodeObj(QObject *parent = 0);

    bool    OpenCom(const std::string & strSerailName);

    void   GetCode();

signals:
    void    Sig_Code(QString codeBar);
public slots:
    void  slot_Data();
    void  slot_TimeOut();

private:
    QSerialPort     m_Port;
    QTimer          m_Timer;
    QByteArray      m_ByteArray;
};

#endif // SCANCODEOBJ_H
