#ifndef LOOKMAINWINDOWOBJ_H
#define LOOKMAINWINDOWOBJ_H

#include <QObject>
#include "View/NXMainWindow.h"
#include "View/NXDockWidget.h"
#include "View/SeeWidget.h"
#include "EFComm/Unity/IOTPPublic.h"

class LogicController;
class LookMainWindowObj : public QObject
{
    Q_OBJECT
public:
    explicit LookMainWindowObj(QObject *parent = 0);

    //显示
    void    Show();

    void    InitModel();

    void    SetController(LogicController * pLogic);

    void  OnUpDateImage(QImage * pImage);

    void  OnUpDateVecs(int nIndex, std::vector<ChipStrut> &vecs);
private:

    //初始化UI
    void    InitUI();
    //显示工具栏
    void    ShowToolBar();
    void    HideToolBar();

    void    InitToolBar();
    void    InitStateBar();
private:
    NXMainWindow  m_MainW;
    SeeWidget     m_SeeW;
    LogicController *   m_pLogic;
signals:

public slots:
};

#endif // ELMAINWINDOWOBJ_H
