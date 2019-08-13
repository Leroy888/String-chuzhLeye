#ifndef EFDRAWWIDGET_H
#define EFDRAWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>

class EFDrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EFDrawWidget(QWidget *parent = 0);



    void     OnDrawImg(uchar * pImage, int nW, int nH, int nFormat);

    QImage   OnGetImg() ;

    void     OnClearImg();

    void     OnDrawImg(QImage & img);
protected:
    virtual void  paintEvent(QPaintEvent *event);
signals:


public slots:
private:
    QImage   m_Image;
    QImage   m_backImage;
    uchar *  m_pBuffer;
};

#endif // EFDRAWWIDGET_H
