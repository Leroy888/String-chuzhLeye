#ifndef DEBUGITEMWIDGET_H
#define DEBUGITEMWIDGET_H
#include <vector>

#include <QWidget>
#include "Model/ControlModel.h"

using namespace std;

class DebugItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DebugItemWidget(QWidget *parent = 0);

    void    OnUpDataImage(QImage * pImage);

    void    OnClear();

    //获取当前圈选坐标
    vector<HALREG> OnGetRegs() const;

    //设置当前圈选坐标
    void    OnSetRegs(const vector<HALREG> &vecs);


private:
    //标准坐标转本地坐标
    void    RegsToLocalRegs(const vector<HALREG> &vecs);
    //本地坐标转标准坐标
    vector<HALREG> LocalRegsToRegs() const;
protected:
    void  paintEvent(QPaintEvent *event);
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);
    void  resizeEvent(QResizeEvent *event);


private:


    QVector<QRectF>    m_localRegs;

    QRectF            m_CurSelect;
    int               m_nBeginIndex;
    int               m_nIndex;
    QVector<QRectF>   m_SelectRegs;
     QImage         * m_pImage;

signals:

public slots:
};

#endif // DEBUGITEMWIDGET_H
