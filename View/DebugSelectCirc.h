#ifndef DEBUGSELECTCIRC_H
#define DEBUGSELECTCIRC_H

#include <QWidget>
#include "DebugItemWidget.h"
#include "Model/ControlModel.h"
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
#include "EFComm/EFPluginModule/EFIAlg2000WModule.h"
namespace Ui {
class DebugSelectCirc;
}

class DebugSelectCirc : public QWidget
{
    Q_OBJECT

public:
    explicit DebugSelectCirc(QWidget *parent = 0);
    //初始化设置
    void    OnInit(ControlModel * pModel,bool bEL);
    //导入算法
    void    OnInitAlg( EFIAlg2000WModule * p2000, EFIAlg230WModule * p230);

    void    OnInitLoadImage(vector<void*> buffers,int nIndex);

    ~DebugSelectCirc();

private:
    void OnBGRtoRGB(void *pBuffer);
private slots:
    void on_Btn_Load_clicked();

    void on_Btn_Pre_clicked();

    void on_Btn_Edit_clicked();

private:
    DebugItemWidget *   m_pItemWidget;
    Ui::DebugSelectCirc *ui;
    ControlModel    *   m_pModel;
    bool                m_bEL;

    QImage              m_Image;
    QImage              m_PreImage;
    //算法
    EFIAlg2000WModule  *         m_pAlg2000;
    EFIAlg230WModule   *         m_pAlg230;


    //保存照片
    vector<vector<void*>>   m_Imgs;

};

#endif // DEBUGSELECTCIRC_H
