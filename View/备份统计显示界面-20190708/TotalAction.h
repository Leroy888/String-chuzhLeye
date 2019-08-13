#ifndef TOTALACTION_H
#define TOTALACTION_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class TotalAction;
}

class TotalAction : public QWidget
{
    Q_OBJECT

public:
    explicit TotalAction(QWidget *parent = 0);
    ~TotalAction();

    void    AddOK();
    void    AddNG();

    int getOkNum();
    int getNgNum();
    int getMissNum();
    int getErrorNum();

    void addErrorNum();
    void addMissNum();
    void clearExcelData();
private:
    void    InitData();
    void    SaveData();

private slots:
    void on_pushButton_Clear_clicked();

private:
    Ui::TotalAction *ui;
    int         m_nOK;
    int         m_nNG;
    QSettings   m_Set;
    int missNum;
    int errorNum;
    int excelOk;
    int excelNg;
};

#endif // TOTALACTION_H
