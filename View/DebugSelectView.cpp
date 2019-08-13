#include "DebugSelectView.h"
#include <QWheelEvent>
#pragma execution_character_set("utf-8")

DebugSelectView::DebugSelectView(QWidget *parent) : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));

    m_Item.setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    m_Item.setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(&m_Item);
}

void DebugSelectView::OnUpdateWidget(QWidget *pW)
{
    m_Item.setWidget(pW);
    QRect rt = this->rect();
    QRectF rf = m_Item.boundingRect();
    float f = (rt.height()-10)/rf.height();
    m_Item.setPos(0,0);
    m_Item.setScale(f);
}

void DebugSelectView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void DebugSelectView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.25 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
