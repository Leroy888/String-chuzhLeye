#ifndef OPTRULER_H
#define OPTRULER_H

#include <QWidget>

class OptRuler : public QWidget
{
    Q_OBJECT
public:
    explicit OptRuler(QWidget *parent = 0);

    //判断的
    void  SetStage(int nStep, bool bNumber = true, bool bOrder = true,bool save_AB = true);

protected:
    void  paintEvent(QPaintEvent *);
    void  resizeEvent(QResizeEvent *event);
    void  drawRuleX(QPainter * painter);
    void  drawRuleY(QPainter * painter);
signals:

public slots:
private:
    QColor          m_lineColor;        //线段颜色
    QColor          m_RulerColor;       //标尺颜色
    QVector<QChar>  m_AsicRuler;        //字母标尺
    QVector<int>    m_IntRuler;         //数字标尺

    int             m_nWidget;
    int             m_nHeight;

    int             m_nStep;
    int             m_nBefore;
    int             m_nAfter;
    int             m_nLongHeight;

    bool            m_save_AB;    //AB串
    bool            m_bNumber;  //是否是数字
    bool            m_bOrder;   //是否按顺序
};

#endif // OPTRULER_H
