#include "SeeView.h"
#include <QPainter>
#include <QMouseEvent>
#pragma execution_character_set("utf-8")

SeeView::SeeView(QWidget *parent)
    :QWidget(parent),m_nRow(6),m_nCol(6),m_bZoom(false),
      m_BgImage("://Resources/Image/bg.png")
{
     setMouseTracking(true);
     setStyleSheet("QWidget{background-color: rgb(0, 0, 0);}");
}

void SeeView::SetRowCol(int nRow, int nCol)
{
    m_nRow = nRow;
    m_nCol = nCol;
    resetVecs();
}

void SeeView::OnDrawImage(QImage &img)
{
    m_Image = img;
	m_bZoom = false;
    update();
}

void SeeView::OnDrawPoints(vector<ChipStrut> &vecs, int nIndex)
{
    if(vecs.empty())
        return ;

    if(nIndex == 0)
    {
          m_vecs = vecs;
    }
    else
    {
        int nHeight = 3200*nIndex;
        //坐标转换
        vector<ChipStrut> local_vecrs ;
        for(int i = 0; i < vecs.size(); ++i)
        {
            ChipStrut & cs = vecs[i];
            cs.m_Rg.m_fCY += nHeight;
            local_vecrs.push_back(cs);
        }
        m_vecs.insert(m_vecs.end(),local_vecrs.begin(), local_vecrs.end());
    }

    resetPoint_Look();
    update();
}

void SeeView::OnDrawELPoints(vector<EL_ChipStrut> &vecs, int nIndex)
{
    if(vecs.empty())
        return ;

   if(nIndex == 0)
    {
          m_el_vecs = vecs;
    }
    else
    {
        int nHeight = 1100*nIndex;
        //坐标转换
        vector<EL_ChipStrut> local_vecrs ;
        for(int i = 0; i < vecs.size(); ++i)
        {
            EL_ChipStrut & cs = vecs[i];
            cs.m_Rg.m_EL_Y += nHeight;
            local_vecrs.push_back(cs);
        }
        m_el_vecs.insert(m_el_vecs.end(),local_vecrs.begin(), local_vecrs.end());
    }
	

    resetPoint_EL();
    update();
}

void SeeView::drawPoint_Look(QPainter &painter)
{
    if(m_localVecs.empty())
        return ;
    for(int i = 0; i < m_localVecs.size(); ++i)
    {
       ChipStrut &cS = m_localVecs[i];
         painter.setPen(QPen(Qt::red,1));
       if(cS.m_dValue >1.0f)
       {

        painter.drawText(QPointF(cS.m_Rg.m_fCX, cS.m_Rg.m_fCY),QString::number(cS.m_dValue,'f',1));

       }

       if(cS.m_Rg.m_fW > 1)
       {
           painter.setPen(QPen(Qt::red,1));
           painter.drawRect(QRect(cS.m_Rg.m_fCX - cS.m_Rg.m_fW/4,cS.m_Rg.m_fCY - cS.m_Rg.m_fH/4,cS.m_Rg.m_fW/2,cS.m_Rg.m_fH/2));
       }
    }
}

void SeeView::drawPoint_EL(QPainter &painter)
{
    if(m_el_localVecs.empty())
        return ;
    for(int i = 0; i < m_el_localVecs.size(); ++i)
    {
       EL_ChipStrut &cS = m_el_localVecs[i];
        /* painter.setPen(QPen(Qt::red,1));
       if(cS.m_dValue >1.0f)
       {

        painter.drawText(QPointF(cS.m_Rg.m_EL_X, cS.m_Rg.m_EL_Y),QString::number(cS.m_dValue,'f',1));

       }
	   */
       if(cS.m_Rg.m_EL_W > 1)
       {
           painter.setPen(QPen(Qt::red,1));
           painter.drawRect(QRect(cS.m_Rg.m_EL_X - cS.m_Rg.m_EL_W/4,cS.m_Rg.m_EL_Y - cS.m_Rg.m_EL_H/4,cS.m_Rg.m_EL_W/2,cS.m_Rg.m_EL_H/2));
       }
    }
}

void SeeView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();
    int  nW = this->width();
    int  nH = this->height();

    if(m_Image.isNull())
    {
        int IntX = nW*1.0/2;
        int IntY = nH*1.0/2;

        float W = m_BgImage.width();
        float h = m_BgImage.height();

        QRect Temp(IntX-W/2, IntY - h/2,W,h);
        painter.drawImage(Temp,m_BgImage);

    }
    else
    {
        if(m_bZoom)
        {
            int nImageW = m_Image.width();
            int nImageH = m_Image.height();

            //
            float  fW = nImageW*1.0/nW;
            float  fH = nImageH*1.0/nH;

            QRect rect(m_curRect.x()* fW, m_curRect.y()*fH, m_curRect.width()*fW, m_curRect.height()*fH);
            QRect Temp(0,0,nW,nH);
            painter.drawImage(Temp,m_Image, rect);

        }
        else
        {
            //画图
            QRect Temp(0,0,nW,nH);
            QRect Src(0,0,m_Image.width(),m_Image.height());
            painter.drawImage(Temp,m_Image,Src,Qt::NoFormatConversion);


            drawPoint_Look(painter);

            drawPoint_EL(painter);
            //画区域
           // painter.setPen(QPen(Qt::green,2,Qt::DashLine));//设置画笔形式
            //painter.drawRect(QRect(m_curRect.x()-1,m_curRect.y()-1,m_curRect.width()+2,m_curRect.height()+2));
        }
    }
    painter.restore();
}

void SeeView::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bZoom)
		return;
     QPoint pos =  event->pos();

     //计算m_curRect;
     int nLocalW = this->width()/m_nRow*2;
     int nLocalH = this->height()/m_nCol*2;

     int x = pos.x()-nLocalW/2;
     int y = pos.y()-nLocalH/2;

     if(x < 0)
     {
         x = 0;
     }
     if(x > this->width()-nLocalW)
     {
         x = this->width()-nLocalW;
     }


     if(y < 0)
     {
         y = 0;
     }
     if(y > this->height()-nLocalH)
     {
         y = this->height()-nLocalH;
     }

     m_curRect.setX(x);
     m_curRect.setY(y);
     m_curRect.setWidth(nLocalW);
     m_curRect.setHeight(nLocalH);
//     if(m_curRect.contains(pos))
//         return ;

//     for(int i = 0; i < m_vecRects.size();++i)
//     {
//         QRect &rt = m_vecRects[i];
//         if(rt.contains(pos))
//         {
//             m_curRect = rt;
//             update();
//             return ;
//         }
//     }
}

void SeeView::mousePressEvent(QMouseEvent *event)
{
     if(event->button() == Qt::LeftButton)
     {
         //if(m_curRect.isValid())
         {
             //区域放大
             m_bZoom = !m_bZoom;
             update();
         }
     }
}

void SeeView::mouseReleaseEvent(QMouseEvent *event)
{
	return;
    if(event->button() == Qt::LeftButton)
    {

        m_bZoom = false;
        update();
    }
}

void SeeView::resizeEvent(QResizeEvent *event)
{


    resetVecs();

    resetPoint_Look();

    resetPoint_EL();
}

void SeeView::resetVecs()
{
    int nLocalW = this->width()/m_nRow*2;
    int nLocalH = this->height()/m_nCol*2;
    m_vecRects.clear();
    m_curRect.setWidth(nLocalW);
    m_curRect.setHeight(nLocalH);
//    for(int i = 0; i<m_nRow*m_nCol; ++i)
//    {
//        QRect rt(i%m_nRow*nLocalW,i/m_nCol*nLocalH,nLocalW,nLocalH);

//        m_vecRects.push_back(rt);
//    }
}

//坐标转化
void SeeView::resetPoint_Look()
{
    m_localVecs.clear();
    int nW = m_Image.width();
    int nH = m_Image.height();

    //坐标转化
    int nLocalW = this->width();
    int nLocalH = this->height();

    float  fW = nLocalW*1.0/(nW-362);
    float  fH = nLocalH*1.0/ (3474*3);

	float dFw = 362.0 / nW*nLocalW;
	float dFH = (1.0f - 3474.0 * 3 / nH)*nLocalH;
    for(int i = 0 ; i < m_vecs.size(); ++i)
    {
            ChipStrut rt = m_vecs[i];
            rt.m_Rg.m_fCX = rt.m_Rg.m_fCX*fW+dFw;
            rt.m_Rg.m_fCY = rt.m_Rg.m_fCY*fH+dFH;
            m_localVecs.push_back(rt);
    }

}

void SeeView::resetPoint_EL()
{
    m_el_localVecs.clear();
    int nW = m_Image.width();
    int nH = m_Image.height();

    //坐标转化
    int nLocalW = this->width();
    int nLocalH = this->height();

    float  fW = nLocalW*1.0/nW;
    float  fH = nLocalH*1.0/nH;

    for(int i = 0 ; i < m_el_vecs.size(); ++i)
    {
            EL_ChipStrut rt = m_el_vecs[i];
            rt.m_Rg.m_EL_X = rt.m_Rg.m_EL_X*fW;
            rt.m_Rg.m_EL_Y = rt.m_Rg.m_EL_Y*fH;
            m_el_localVecs.push_back(rt);
    }
}
