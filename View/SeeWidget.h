#ifndef SEEWIDGET_H
#define SEEWIDGET_H

#include <QWidget>
#include "EFComm/Unity/IOTPPublic.h"
namespace Ui {
class SeeWidget;
}

class SeeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SeeWidget(QWidget *parent = 0);
    ~SeeWidget();

    void    SetWRule(bool bShunX,bool bAsic, int nStep);
    void    SetHRule(bool bShunX,bool bAsic, int nStep);

    void    SetImage(QImage * pImage);
    void    SetVecs(int nIndex, std::vector<ChipStrut> &vecs);
    void    SetELVecs(int nIndex, std::vector<EL_ChipStrut> & vecs);
    //设置画的点
  //  void    SetVectors();

private:
    Ui::SeeWidget *ui;
};

#endif // SEEWIDGET_H
