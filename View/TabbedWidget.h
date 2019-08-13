#ifndef TABBEDWIDGET_H
#define TABBEDWIDGET_H
#include <string>
#include <QDialog>
#include <QPushButton>
#include <QSignalMapper>
#include <vector>
using namespace  std;
class TabbedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabbedWidget(QWidget *parent = 0);
    void  OnInitUI(int nRow, int nCol);
    void  OnClear();

    int  GetNum();

    void  OnGetState(vector<bool>& vState);
    void  OnShowState(std::vector<bool> & vState);

    string  GetTabbeds(std::vector<bool> &vState ); //A1,B1,C1

    vector<string> GetTabbedsXY(std::vector<bool> &vState); //X;Y


private:
    void    updateUI();
    void    updateState();
    void    onStateEnable(bool bEnable);
protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    int         m_nRow;
    int         m_nCol;
    QSignalMapper   * m_pSignalMap;
    QList<QPushButton *>  m_Buttons;
    std::vector<bool>     m_vBools;
    QVector<QString>  m_AsicRuler;        //字母标尺
    QVector<QString>  m_IntRuler;         //数字标尺
signals:
    void        sig_Click(int i);
public slots:
    void   OnClick(int nIndex);
};

#endif // TABBEDWIDGET_H
