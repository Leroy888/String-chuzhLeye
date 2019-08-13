#ifndef DEBUGSELECTVIEW_H
#define DEBUGSELECTVIEW_H

#include <QGraphicsView>
#include <QGraphicsProxyWidget>

class DebugSelectView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DebugSelectView(QWidget *parent = 0);

    void    OnUpdateWidget(QWidget * pW);


protected:
    void wheelEvent(QWheelEvent *event) override;
private:
    void scaleView(qreal scaleFactor);

private:
    QGraphicsProxyWidget    m_Item;

signals:

public slots:
};

#endif // DEBUGSELECTVIEW_H
