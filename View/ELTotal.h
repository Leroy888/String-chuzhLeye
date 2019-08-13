#ifndef ELTOTAL_H
#define ELTOTAL_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class ELTotal;
}

class ELTotal : public QWidget
{
    Q_OBJECT

public:
    explicit ELTotal(QWidget *parent = 0);
    ~ELTotal();

    void  InitHeaders(QStringList & lists);

    void  AddValue(int nRow);
    void  AddValue(QString);


public slots:
    void on_Btn_Clear_clicked();
protected:
    void changeEvent(QEvent * event);
private:

    void  initData();
private:
    Ui::ELTotal *ui;
    QSettings   m_Set;
    int         m_nNum;
    std::vector<int>    m_vTotal;



};

#endif // ELTOTAL_H
