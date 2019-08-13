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
    void updateMissJudgeRate();
    void updateErrorJudgeRate();
    void updateNGRate();
    void addMissNum();
    void addErrorNum();
    int getOkNum();
    int getNgNum();
    int getMissNum();
    int getErrorNum();
    void clearExcelData();

    void addYlNum();
    void addXhNum();
    void addYlAndXhNum();
    void addOtherNum();

    int getYlNum() const;

    int getXhNum() const;

    int getYlAndXhNum() const;

    int getOtherNum() const;

    void saveDute(QString dute);
    QString getDute();
protected:
    void changeEvent(QEvent *event);
private:
    void    InitData();
    void    SaveData();

public slots:
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
    float missJudgeRate;
    float errorJudgeRate;
    float ngRate;
    int ylNum;
    int xhNum;
    int ylAndXhNum;
    int otherNum;
    QString m_strDute;
};

#endif // TOTALACTION_H
