#include "TotalTableWidget.h"
#include <QHeaderView>
#pragma execution_character_set("utf-8")
TotalTableWidget::TotalTableWidget(QWidget *parent) : QTableWidget(parent)
{
    InitHeader();
}

void TotalTableWidget::AddRows(QStringList &strList)
{
    int nCount = strList.count();

    for(int i = 0; i < nCount; ++i)
    {
        this->insertRow(i);
        QTableWidgetItem * pName = new QTableWidgetItem;
        QTableWidgetItem * pValue = new QTableWidgetItem;
        this->setItem(i,0,pName);
        this->setItem(i,1, pValue);
        pName->setText(strList[i]);
        pValue->setText("0");
    }

}

void TotalTableWidget::SetValue(int nRow, int nValue)
{
    if(nRow >= this->rowCount())
        return;

    item(nRow,1)->setText(QString::number(nValue));
}
int  TotalTableWidget::Getnumber(QString data)
{
    for(int i=0;i< this->rowCount();i++)
    {
        if(data ==  item(i,0)->text())
        {
                return i;
        }
    }
}
void TotalTableWidget::InitHeader()
{
    this->setColumnCount(2);
    QStringList headers;
    headers<<"\347\274\272\351\231\267\347\261\273\345\236\213"<<"\346\225\260\351\207\217";
    QHeaderView * header= horizontalHeader();
    setHorizontalHeaderLabels(headers);
    header->setStretchLastSection(true);
   // verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    header->setDefaultSectionSize(15);
    this->setFrameShape(QFrame::NoFrame);
    verticalHeader()->setVisible(false);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    header->resizeSection(0,150);
    header->setFixedHeight(30);
    setStyleSheet("selection-background-color:lightblue;");
    header->setStyleSheet("QHeaderView::section{background:skyblue;}");


}
