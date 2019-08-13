#include "OPTView.h"
#include <QWheelEvent>
#pragma execution_character_set("utf-8")

OPTView::OPTView(QWidget *parent) : QGraphicsView(parent)
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

void OPTView::OnUpDataImg(const QImage &img)
{
    m_Img = img;
    m_Item.setPixmap(QPixmap::fromImage(m_Img));
    QRect rt = this->rect();
    QRectF rf = m_Item.boundingRect();
    float f = (rt.height()-10)/rf.height();
    m_Item.setPos(0,0);
    m_Item.setScale(f);


}

void OPTView::OnClear()
{
    m_Item.setPixmap(QPixmap());
}

void OPTView::wheelEvent(QWheelEvent *event)
{
     scaleView(pow((double)2, -event->delta() / 240.0));
}

void OPTView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.25 || factor > 1000)
        return;

    scale(scaleFactor, scaleFactor);
}
