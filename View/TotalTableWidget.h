#ifndef TOTALTABLEWIDGET_H
#define TOTALTABLEWIDGET_H

#include <QTableWidget>

class TotalTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TotalTableWidget(QWidget *parent = 0);
    void    AddRows(QStringList & strList);
    void    SetValue(int nRow, int nValue);
    int     Getnumber(QString data);
private:
    void    InitHeader();
signals:

public slots:
};

#endif // TOTALTABLEWIDGET_H
