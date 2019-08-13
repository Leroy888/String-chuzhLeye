#include "DebugItemWidget.h"
#include <QResizeEvent>
#include <QPainter>
#pragma execution_character_set("utf-8")

DebugItemWidget::DebugItemWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    m_pImage = nullptr;
    m_nIndex = -1;
    m_nBeginIndex = 0;
    m_localRegs.resize(4);
    this->resize(QSize( this->width(), this->height()/3 ));

}

void DebugItemWidget::OnUpDataImage(QImage *pImage)
{
    m_pImage = pImage;
    update();
}

void DebugItemWidget::OnClear()
{
    m_pImage = nullptr;
    m_localRegs.clear();
    update();
}

vector<HALREG> DebugItemWidget::OnGetRegs() const
{
    //本地坐标转标准坐标
   return LocalRegsToRegs();
}

void DebugItemWidget::OnSetRegs(const vector<HALREG> &vecs)
{
    //坐标转本地坐标
    RegsToLocalRegs(vecs);

    update();
}

void DebugItemWidget::RegsToLocalRegs(const vector<HALREG> &vecs)
{
//    if(!m_pImage)
//        return ;

////    if(vecs.size() != 12)
////        return ;

    int nW = this->width();
    int nH = this->height();


    int nImgW = m_pImage->width();
    int nImgH = m_pImage->height();

    m_localRegs.resize(4);
    for(int i = 0; i <4;++i)
    {
        int nBaseW = i%4*nW/4;
        int nBaseH = i/4*nH
                ;
        m_localRegs[i].setX(nBaseW+vecs[i].x1*nW/nImgW);
        m_localRegs[i].setY(nBaseH+vecs[i].y1*nH/nImgH);
        m_localRegs[i].setWidth((vecs[i].x2 -vecs[i].x1)*nW/nImgW);
        m_localRegs[i].setHeight((vecs[i].y2-vecs[i].y1)*nH/nImgH);
    }

}

vector<HALREG> DebugItemWidget::LocalRegsToRegs() const
{
    vector<HALREG>  retVecs;

    if(m_localRegs.size() != 4 || !m_pImage)
        return retVecs;

    float   fW = m_pImage->width()*1.0/this->width();
    float   fH = m_pImage->height()*1.0/this->height();

    int   nW = this->width()/4;
    int   nH = this->height();

    for(int i = 0; i < m_localRegs.size(); ++i)
    {
        HALREG rg;
        const QRectF  &rf = m_localRegs[i];

        if(rf.width()>0)
        {
            rg.x1 = (int(rf.x())%nW)*fW;
            rg.x2 = (int(rf.x())%nW+rf.width())*fW;
        }
        else
        {
            rg.x1 = (int(rf.x())%nW+rf.width())*fW;
            rg.x2 = (int(rf.x())%nW)*fW;
        }


        if(rf.height()>0)
        {
            rg.y1 = (int(rf.y())%nH)*fH;
            rg.y2 = (int(rf.y())%nH+rf.height())*fH;
        }
        else
        {
            rg.y1 = (int(rf.y())%nH+rf.height())*fH;
            rg.y2 = (int(rf.y())%nH)*fH;
        }
        retVecs.push_back(rg);
    }


    return retVecs;
}

void DebugItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.save();

    //有图可以画
    if(m_pImage)
    {
        //画图
        QRect Temp(0,0,this->width(),this->height());
        painter.drawImage(Temp,*m_pImage);
        //画区域


        painter.setPen(QPen(Qt::yellow,2,Qt::DashLine));//设置画笔形式
        painter.drawRect(QRect(m_CurSelect.x()-2,m_CurSelect.y()-2,m_CurSelect.width()+4,m_CurSelect.height()+4));

//        //画线
        painter.setPen(QPen(Qt::red,0.2,Qt::SolidLine));
        painter.drawRects(m_localRegs);
    }

    painter.restore();

}

void DebugItemWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos =  event->pos();
    if(m_CurSelect.contains(pos))
        return ;



    //转化成图片坐标
    for(int i = 0; i< m_SelectRegs.size(); ++i)
    {
        QRectF& rt = m_SelectRegs[i];
        if(rt.contains(pos))
        {
            m_CurSelect = rt;
            m_nIndex = i;
            update();
            return ;
        }
    }

    m_nIndex = -1;
}

void DebugItemWidget::mousePressEvent(QMouseEvent *event)
{
    if(m_nIndex == -1)
        return ;

	if (m_localRegs.isEmpty())
		return;
    if(event->button() == Qt::LeftButton)
    {
        m_nBeginIndex = m_nIndex;
        QPointF pBegn = event->pos();
        QRectF & rt = m_localRegs[m_nIndex];
        rt.setX(pBegn.x());
        rt.setY(pBegn.y());

    }
}

void DebugItemWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_nIndex == -1)
        return ;

	if (m_localRegs.isEmpty())
		return;

    if(m_nBeginIndex != m_nIndex)
        return ;
    if(event->button() == Qt::LeftButton)
    {
          QPointF pEnd = event->pos();
          QRectF & rt = m_localRegs[m_nIndex];
          rt.setWidth(pEnd.x() - rt.x());
          rt.setHeight(pEnd.y() - rt.y());
          update();
    }
}

void DebugItemWidget::resizeEvent(QResizeEvent *event)
{
    //坐标转化根据原始坐标转化
    m_SelectRegs.clear();
    int nLocalW = this->width()/4;
    int nLocalH = this->height();
    for(int i = 0; i<4; ++i)
    {
        QRect rt(i%4*nLocalW,i/4*nLocalH,nLocalW,nLocalH);

        m_SelectRegs.push_back(rt);
    }

    if(m_nIndex != -1)
    {
        m_CurSelect = m_SelectRegs[m_nIndex];
    }

    //等距离变化
    QSize oldSize = event->oldSize();
    QSize  newSize = event->size();

    float  fW = newSize.width()*1.0/oldSize.width();
    float  fH = newSize.height()*1.0/oldSize.height();

    for(int i = 0; i<m_localRegs.size(); ++i)
    {
        QRectF rf = m_localRegs[i];
        m_localRegs[i].setX(rf.x()*fW);
        m_localRegs[i].setWidth(rf.width()*fW);
        m_localRegs[i].setY(rf.y()*fH);
        m_localRegs[i].setHeight(rf.height()*fH);
    }


}
