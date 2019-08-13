#ifndef SEEVIEWGRAPHIC_H
#define SEEVIEWGRAPHIC_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SeeViewGraphic : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SeeViewGraphic(QWidget *parent = 0);

    void  OnImage(QImage * pImg);
    void Set_Ruler_w(int,bool Ruler_w_b,bool Ruler_w_c);
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    void scaleView(qreal scaleFactor);
private:
    QGraphicsScene *m_pScene;
    QGraphicsItem  * m_pItem;
signals:

public slots:
private:
    QImage   m_Image;
    float   m_fScale;
};

#endif // SEEVIEWGRAPHIC_H
