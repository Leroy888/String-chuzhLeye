#include "EFDrawWidget.h"
#include <QPoint>
#pragma execution_character_set("utf-8")

EFDrawWidget::EFDrawWidget(QWidget *parent) : QWidget(parent)
  ,m_backImage("://Resources/Image/LOGO.png")
  ,m_pBuffer(nullptr)
{


}

void EFDrawWidget::OnDrawImg(QImage &img)
{
    m_Image = img;
    update();
}

void EFDrawWidget::OnDrawImg(uchar *pImage, int nW, int nH, int nFormat)
{
    if(!pImage)
        return ;

    if(m_pBuffer)
    {
        delete m_pBuffer;
        m_pBuffer = nullptr;
    }

    m_pBuffer = new uchar[nW*nH];

    memcpy(m_pBuffer, pImage, nW*nH);

    QImage img(m_pBuffer, nW, nH,QImage::Format(nFormat));
    m_Image =  img;

    update();
}

QImage EFDrawWidget::OnGetImg()
{
//    if(m_Image.isNull())
//    {
//        return m_backImage;
//    }
    return m_Image;
}

void EFDrawWidget::OnClearImg()
{
    if(m_pBuffer)
    {
        delete m_pBuffer;
        m_pBuffer = nullptr;
    }
    m_Image= QImage();
    update();
}

void EFDrawWidget::paintEvent(QPaintEvent *event)
{
    if(m_Image.isNull())
    {

        QPainter pp(this);
        QRect temp(0,0, this->width(), this->height());
        pp.setBrush(QColor("#8896b1"));
        pp.drawRect(temp);

        int nW = m_backImage.width();
        int nH = m_backImage.height();
        QPoint c = temp.center();

        QRect Temp(c.x()-nW/2, c.y()-nH/2,nW,nH);
        pp.drawImage(Temp,m_backImage);
    }
    else
    {
        QPainter pp(this);
        QRect Temp(0,0,this->width(),this->height());
        pp.drawImage(Temp,m_Image);
    }
}
