#include "MES_Dialog.h"
#include "ui_MES_Dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDirIterator>
#pragma execution_character_set("utf-8")

MES_Dialog::MES_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MES_Dialog),
    m_pController(nullptr)
{
    ui->setupUi(this);
     setWindowTitle(QString::fromLocal8Bit("手动上传条码"));
}

MES_Dialog::~MES_Dialog()
{
    delete ui;
}

void MES_Dialog::OnController(LogicController *pController)
{
    m_pController = pController;
}




void MES_Dialog::on_BtnPush_clicked()
{
    QString strImagePath =  ui->label->text();


    QString strCode = ui->lab_code->text();

    if(!strImagePath.size()|| !strCode.size())
    {
        QMessageBox::warning(NULL, QString::fromLocal8Bit(""),QString::fromLocal8Bit("输入为空"));
        return ;
    }

    m_pController->OnSetCode(strCode);
    m_pController->slot_Save_Over(strImagePath);

}

void MES_Dialog::on_BtnSelect_clicked()
{

    QString strPath = m_pController->OnGetELPath();

    //定义文件对话框类
      QFileDialog *fileDialog = new QFileDialog(this);
      //定义文件对话框标题
      fileDialog->setWindowTitle(QString::fromLocal8Bit("打开图片"));
      //设置默认文件路径
      fileDialog->setDirectory(strPath);
      //设置文件过滤器
      fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
      //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
      //设置视图模式
      fileDialog->setViewMode(QFileDialog::Detail);
      //打印所有选择的文件的路径
      QStringList fileNames;
      if(fileDialog->exec())
      {
          fileNames = fileDialog->selectedFiles();
      }

      if(fileNames.size())
      {
          ui->label->setText(fileNames[0]);

          QFileInfo file(fileNames[0]);
          QString strFileName = file.fileName();
          int nIndex = strFileName.indexOf("_");
          if(nIndex == -1)
          {
            nIndex = strFileName.indexOf(".");
          }
          QString strCode =  strFileName.mid(0,nIndex);
          ui->lab_code->setText(strCode);
      }


}


QString FindFile(const QString &strFilePath, const QString &strNameFilters)
{
 if (strFilePath.isEmpty() || strNameFilters.isEmpty())
 {
  return QString();
 }
 QDir dir;
 QStringList filters;
 filters << strNameFilters+"*.*";
 dir.setPath(strFilePath);
 dir.setNameFilters(filters);

 QDirIterator iter(dir,QDirIterator::Subdirectories);
 while (iter.hasNext())
 {
     iter.next();
     QFileInfo info=iter.fileInfo();
     if (info.isFile())
     {
         return info.absoluteFilePath();//.replace('/', '\\');
     }
 }
 return QString();
}

void MES_Dialog::on_BtnScan_clicked()
{

    ui->lab_code->setText("");
    ui->label->setText("");
    QString strText = ui->lineEdit_barCode->text();

    if(strText.size() <2)
        return ;

    //全局搜索
    QString strPath = m_pController->OnGetELPath();

    QString  str = FindFile(strPath,strText);
    if(str.size() ==0 )
    {

        return ;
    }

    ui->label->setText(str);

    QFileInfo file(str);
    QString strFileName = file.fileName();
    int nIndex = strFileName.indexOf("_");
    if(nIndex == -1)
    {
      nIndex = strFileName.indexOf(".");
    }
    QString strCode =  strFileName.mid(0,nIndex);
    ui->lab_code->setText(strCode);
}
