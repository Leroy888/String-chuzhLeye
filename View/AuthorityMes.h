#ifndef AUTHORITYMES_H
#define AUTHORITYMES_H

#include <QDialog>

namespace Ui {
class AuthorityMes;
}

class AuthorityMes : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorityMes(QWidget *parent = 0);
    ~AuthorityMes();

    bool    m_bOK;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AuthorityMes *ui;
};

#endif // AUTHORITYMES_H
