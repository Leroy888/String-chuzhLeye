#ifndef SEEWIDGETEL_H
#define SEEWIDGETEL_H

#include <QWidget>

namespace Ui {
class SeeWidgetEL;
}

class SeeWidgetEL : public QWidget
{
    Q_OBJECT

public:
    explicit SeeWidgetEL(QWidget *parent = 0);
    ~SeeWidgetEL();

    void    SetWRule(bool bShunX,bool bAsic, int nStep);
    void    SetHRule(bool bShunX,bool bAsic, int nStep);

    void    SetImage(QImage * pImage, bool Save_AB);
    int     m_nW;
    bool    Ruler_w_b;
   bool Ruler_w_c;
private:
    Ui::SeeWidgetEL *ui;
    QImage   m_Image;
};

#endif // SEEWIDGETEL_H
