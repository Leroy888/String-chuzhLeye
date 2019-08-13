#ifndef FILENAMEDIALOG_H
#define FILENAMEDIALOG_H

#include <QDialog>

namespace Ui {
class FileNameDialog;
}

class FileNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileNameDialog(QWidget *parent = 0);
    ~FileNameDialog();
    void   SetFileString(std::string * pStr);
private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::FileNameDialog *ui;
    std::string *   m_pStr;
};

#endif // FILENAMEDIALOG_H
