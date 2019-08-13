#ifndef WORKERORISAVE_H
#define WORKERORISAVE_H

#include <QThread>
class LogicController;
class WorkerOriSave : public QThread
{
    Q_OBJECT
public:
    explicit WorkerOriSave(LogicController * pLogic, bool bEL);
    virtual void run();

private:
    QString GetPath(bool EL);

private:
    LogicController * m_pLogic;
    bool              m_bEL;
    QString   strcode;
signals:

public slots:
};

#endif // WORKERORISAVE_H
