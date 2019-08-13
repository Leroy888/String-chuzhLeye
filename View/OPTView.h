#ifndef OPTVIEW_H
#define OPTVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class OPTView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit OPTView(QWidget *parent = 0);

    void    OnUpDataImg(const QImage & img);

    void    OnClear();

protected:
    void wheelEvent(QWheelEvent *event) override;
private:
    void scaleView(qreal scaleFactor);

signals:

public slots:

private:
    QGraphicsPixmapItem    m_Item;

    QImage                  m_Img;
};

#endif // OPTVIEW_H
