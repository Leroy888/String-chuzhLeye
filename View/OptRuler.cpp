#include "OptRuler.h"
#include <QPainter>
#pragma execution_character_set("utf-8")

OptRuler::OptRuler(QWidget *parent) : QWidget(parent)
{
    m_AsicRuler = {'A','B','C','D','E','F','G','H','I','J','L','M','N'};
    m_IntRuler  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

    m_nBefore = 10;
    m_nAfter = 10;
    m_nLongHeight = 30;
}

void OptRuler::SetStage(int nStep, bool bNumber, bool bOrder,bool save_AB)
{
    m_nStep = nStep;
    m_bNumber = bNumber;
    m_bOrder = bOrder;
    m_save_AB = save_AB;
    m_nWidget = this->width();
    m_nHeight = this->height();
    update();
}

void OptRuler::paintEvent(QPaintEvent *)
{
    //绘制准备工作，启动反锯齿
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(m_nHeight > m_nWidget)
    {
         drawRuleY(&painter);
    }
    else
    {
        drawRuleX(&painter);
    }
}

void OptRuler::resizeEvent(QResizeEvent *event)
{
    m_nWidget = this->width();
    m_nHeight = this->height();

    if(m_nHeight > m_nWidget)
    {
        m_nBefore = m_nHeight/80;
        m_nAfter = m_nHeight/40;
    }
    else
    {
        m_nBefore = m_nWidget/120;
        m_nAfter = m_nWidget/120;
    }
}

void OptRuler::drawRuleX(QPainter *painter)
{
    painter->save();
    painter->setPen(m_lineColor);
    QFont ft;
    ft.setPixelSize(40);
    painter->setFont(ft);

    double  fInitX = m_nBefore;
    double  fInitY = m_nHeight;
    //画线
    QPointF  lineLeft(fInitX, fInitY);
    QPointF  lineRight(m_nWidget-m_nBefore, fInitY);

    painter->drawLine(lineLeft, lineRight);

    //画间隔
    double  fLen = m_nWidget - m_nBefore - m_nAfter;

    double  fStepLong = fLen*1.0/m_nStep;
    for(int i = 0; i <= m_nStep; ++i)
    {
        QPointF topPoint(fInitX, fInitY-m_nLongHeight);
        QPointF bottomPoint(fInitX, fInitY);
        painter->drawLine(topPoint, bottomPoint);

        //写文本
        if(i != 0)
        {
            QString  strValue;
            if(m_bNumber)
            {
               int nNumber = m_bOrder ? m_IntRuler[i-1]:m_IntRuler[m_nStep  -i];
                strValue = QString("%1").arg(nNumber);
            }
            else
            {
                strValue = m_bOrder ? m_AsicRuler[i-1]:m_AsicRuler[m_nStep  -i ];
            }

            double  textW = fontMetrics().width(strValue);
            double  textH = fontMetrics().height();

            QPointF  textTop(fInitX-fStepLong/2-textW/2, fInitY - textH);
            painter->setPen(Qt::green);
            painter->drawText(textTop, strValue);
            painter->setPen(m_lineColor);
        }
        fInitX += fStepLong;
    }


    painter->restore();
}

void OptRuler::drawRuleY(QPainter *painter)
{
    painter->save();
    painter->setPen(m_lineColor);
    QFont ft;
    ft.setPixelSize(40);
    painter->setFont(ft);

    double  fInitY = m_nBefore;
    double  fInitX = m_nWidget;
    //画线
    QPointF  lineLeft(fInitX, fInitY);
    QPointF  lineRight(fInitX, m_nHeight - m_nBefore);

    painter->drawLine(lineLeft, lineRight);

    //画间隔
    double  fLen = m_nHeight - m_nBefore - m_nAfter;

    double  fStepLong = fLen*1.0/m_nStep;
    for(int i = 0; i <= m_nStep; ++i)
    {
        QPointF topPoint(fInitX, fInitY);
        QPointF bottomPoint(fInitX-m_nLongHeight, fInitY);
        painter->drawLine(topPoint, bottomPoint);

        //写文本
        if(i != 0)
        {
            QString  strValue;
            if(m_bNumber)
            {
               int nNumber = m_bOrder ? m_IntRuler[i-1]:m_IntRuler[m_nStep  -i];
                strValue = QString("%1").arg(nNumber);
            }
            else
            {
                if(m_save_AB)
                {
                    strValue ="A";
                }
                else
                {
                   strValue = "B";
                }
            }

            double  textW = fontMetrics().width(strValue);
            double  textH = fontMetrics().height();

            QPointF  textTop(fInitX-textW-20, fInitY - fStepLong/2 + textH/2);
            painter->setPen(Qt::red);
            painter->drawText(textTop, strValue);
            painter->setPen(m_lineColor);
        }
        fInitY += fStepLong;
    }



    painter->restore();
}
