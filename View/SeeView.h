#ifndef SEEVIEW_H
#define SEEVIEW_H

#include <QWidget>
#include "EFComm/Unity/IOTPPublic.h"
#include <vector>
using namespace  std;

class SeeView:public QWidget
{
    Q_OBJECT
public:
    SeeView(QWidget * parent  = 0);
    void SetRowCol(int nRow, int nCol);
    void OnDrawImage(QImage & img);
    void OnDrawPoints(vector<ChipStrut> & vecs, int nIndex);
    void OnDrawELPoints(vector<EL_ChipStrut> & vecs, int nIndex);


private:
    void drawPoint_Look( QPainter &painter);
    void drawPoint_EL(QPainter & painter);

protected:
    void  paintEvent(QPaintEvent *event);
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);
    void  resizeEvent(QResizeEvent *event);

private:
    void  resetVecs();
    void  resetPoint_Look();
    void  resetPoint_EL();
private:
    QVector<QRect>      m_vecRects;

    vector<ChipStrut>   m_vecs;
    vector<ChipStrut>   m_localVecs;

    vector<EL_ChipStrut>   m_el_vecs;
    vector<EL_ChipStrut>   m_el_localVecs;

    QImage              m_BgImage;
    QImage              m_BgPaintImage;
    QImage              m_Image;
    int                 m_nRow;
    int                 m_nCol;
    QRect               m_curRect;
    bool                m_bZoom;

};

#endif // SEEVIEW_H
