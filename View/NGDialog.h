#ifndef NGDIALOG_H
#define NGDIALOG_H

#include <QDialog>
#include <vector>

using namespace  std;

namespace Ui {
class NGDialog;
}

class NGDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NGDialog(QWidget *parent = 0);
    ~NGDialog();


    void  InitUI(int nRow, int nCol, bool bEL);
    void  OnParamClear();
    void   GetTranCode(vector<string> & vPoints, vector<string> & vCodes, vector<string> & vTitles);

    string GetJKCode();

    int     GetIndex() { return m_nIndex;}
private slots:
    void on_pushButton_clicked();
    void slot_click(int nIndex);

private:
    Ui::NGDialog *ui;
    vector<vector<bool>>    m_vPoints;
    int                 m_nIndex;

};

#endif // NGDIALOG_H
