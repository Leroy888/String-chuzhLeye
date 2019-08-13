#include "SeeWidget.h"
#include "ui_SeeWidget.h"
#pragma execution_character_set("utf-8")

SeeWidget::SeeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeeWidget)
{
    ui->setupUi(this);
}

SeeWidget::~SeeWidget()
{
    delete ui;
}

void SeeWidget::SetWRule(bool bShunX, bool bAsic, int nStep)
{
    ui->ruler_w->SetStage(nStep, !bAsic, bShunX);
}

void SeeWidget::SetHRule(bool bShunX, bool bAsic, int nStep)
{
    ui->ruler_h->SetStage(1, !bAsic, bShunX);
}



void SeeWidget::SetImage(QImage *pImage)
{
    if(pImage)
    {
        ui->widget_img->OnDrawImage(*pImage);
    }
    else
    {
         ui->widget_img->OnDrawImage(QImage());
    }
}

void SeeWidget::SetVecs(int nIndex, std::vector<ChipStrut> &vecs)
{
    ui->widget_img->OnDrawPoints(vecs, nIndex);
}

void SeeWidget::SetELVecs(int nIndex, std::vector<EL_ChipStrut> &vecs)
{
	ui->widget_img->OnDrawELPoints(vecs, nIndex);
}
