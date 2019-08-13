#ifndef SYSSETACTION_H
#define SYSSETACTION_H

#include <QWidget>
#include "Model/ControlModel.h"
#include "DebugItemWidget.h"
#include "Model/ControlModel.h"
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
#include "EFComm/EFPluginModule/EFIAlg2000WModule.h"
#include <QSettings>

namespace Ui {
class SysSetAction;
}
class LogicController;
class SysSetAction : public QWidget
{
    Q_OBJECT

public:
    explicit SysSetAction(QWidget *parent = 0);
    ~SysSetAction();

    void    SetController(LogicController * pController);

    QString  GetIniFile() const;

    void     OnEnable(bool bEnable);

    bool getIsYl();
    bool getIsXh();
    bool getIsOther();
private:

    void    OnRefreshDir();
private slots:
    void on_Btn_SysSet_clicked();

    void on_comboBox_ini_activated(const QString &arg1);

    void on_pushButton_WG_SAVE_clicked();

    void on_pushButton_EL_SAVE_clicked();

    void on_pushButton_ClearBuffer_clicked();

    void on_pushButton_ReSend_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_checkBox_YL_clicked();

    void on_checkBox_XH_clicked();

    void on_checkBox_other_clicked();

private:
    Ui::SysSetAction *ui;
    LogicController *   m_pController;
    ControlModel        m_Model;

    //测试
    QImage              m_Image;
    vector<vector<void*>>   m_Imgs;

    bool isYl;
    bool isXh;
    bool isOther;
    QSettings m_Set;
};

#endif // SYSSETACTION_H
