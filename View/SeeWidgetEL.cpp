#include "SeeWidgetEL.h"
#include "ui_SeeWidgetEL.h"
#pragma execution_character_set("utf-8")

SeeWidgetEL::SeeWidgetEL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeeWidgetEL)
{
    ui->setupUi(this);
    m_nW = 12;
}

SeeWidgetEL::~SeeWidgetEL()
{
    delete ui;
}

void SeeWidgetEL::SetWRule(bool bShunX, bool bAsic, int nStep)
{
     //ui->ruler_w->SetStage(nStep, !bAsic, bShunX);
    Ruler_w_b = bShunX;
    Ruler_w_c = bAsic;
     m_nW = nStep;
}

void SeeWidgetEL::SetHRule(bool bShunX, bool bAsic, int nStep)
{
     ui->ruler_h->SetStage(1, !bAsic, bShunX);
}

void SeeWidgetEL::SetImage(QImage *pImage,bool Save_AB)
{

 //   ui->ruler_h->SetStage(1, false, 6, Save_AB);

    // ui->graphicsView->OnImage(pImage);
    //     if((m_nW == 10 || m_nW == 20)&& pImage)
    //     {
    //         int w =  pImage->width();
    //         int h =  pImage->height();
    //         m_Image = pImage->scaled(w*10/12, h,Qt::IgnoreAspectRatio);
    //         ui->graphicsView->OnImage(&m_Image);
    //     }
    //     else
    //     {
  //  ui->graphicsView->Set_Ruler_w(m_nW);
    ui->graphicsView->OnImage(pImage);
    ui->graphicsView->Set_Ruler_w(m_nW, Ruler_w_b, Ruler_w_c);
    //    }
}
