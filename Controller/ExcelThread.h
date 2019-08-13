#ifndef EXCELTHREAD_H
#define EXCELTHREAD_H

#include <QObject>
#include "Model/sacsvstream.h"
#include <QThread>

class ExcelThread : public QThread
{
public:
    ExcelThread(bool AI_OK, int okNum, int ngNum, int errNum, int misNum, QString strPath);

    void run();

    void mkdir_path(QString path);

    void saveTotalExcel();

private:
    bool aiOk;
    int okNum;
    int ngNum;
    int errorNum;
    int missNum;
    QString strPath;
};

#endif // EXCELTHREAD_H
