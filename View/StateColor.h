#ifndef STATECOLOR_H
#define STATECOLOR_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QLabel>
namespace Ui {
class StateColor;
}

class StateColor : public QWidget
{
    Q_OBJECT

public:
    explicit StateColor(QWidget *parent = 0);
    ~StateColor();

    void  setState(int nIndex);

private:
    Ui::StateColor *ui;
    QVector<QString>    m_colors;
    QVector<QLabel*>    m_labels;
    QString             m_clearColor;
};

#endif // STATECOLOR_H
