#include "NGDialog.h"
#include "ui_NGDialog.h"
#pragma execution_character_set("utf-8")

NGDialog::NGDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NGDialog),
    m_nIndex(-1)
{
    ui->setupUi(this);

}

NGDialog::~NGDialog()
{
    delete ui;
}

void NGDialog::InitUI(int nRow, int nCol, bool bEL)
{
    ui->w_xy->OnInitUI(nRow,nCol);
    ui->w_cmd->InitUI(bEL);


    connect(ui->w_cmd, SIGNAL(sig_Click(int)), this, SLOT(slot_click(int)));
    //初始化数组
    int nXYs = ui->w_xy->GetNum();
    int nCmds = ui->w_cmd->GetNum();
    m_vPoints.resize(nCmds);

    for(int i = 0; i < m_vPoints.size(); ++i)
    {

        m_vPoints[i].resize(nXYs,false);
    }

}

void NGDialog::OnParamClear()
{
    //初始化数组
    int nXYs = ui->w_xy->GetNum();
    int nCmds = ui->w_cmd->GetNum();

    ui->w_xy->OnClear();
    ui->w_cmd->OnClear();

    //m_vPoints.resize(nCmds);

    m_nIndex = -1;

    for(int i = 0; i < m_vPoints.size(); ++i)
    {
        for (int j = 0; j < nXYs; ++j)
        {
            m_vPoints[i][j] = false;
        }

    }
}

void NGDialog::GetTranCode(vector<string> &vPoints, vector<string> &vCodes, vector<string> &vTitles)
{
    vPoints.clear();
    //先获取 code
    vector<bool> vBools;
    vPoints.clear();
    ui->w_cmd->GetCmd(vCodes, vTitles);

    if(m_nIndex != -1)
    {
        vector<bool> vStates;
        ui->w_xy->OnGetState(vStates);
        m_vPoints[m_nIndex] = vStates;
    }

   for(int i = 0 ; i < vBools.size(); ++i)
   {
        if(vBools[i])
        {
            string strPonit = ui->w_xy->GetTabbeds(m_vPoints[i]);
            vPoints.push_back(strPonit);
        }
   }

}

string NGDialog::GetJKCode()
{
    vector<string> vTitles;
    vector<string> vCodes;
    vector<bool> vBools;
    ui->w_cmd->GetCmd(vCodes, vTitles);

    string strResulCode;
    int n  = 0;

    for(int i = 0 ; i < vBools.size(); ++i)
    {
         if(vBools[i])
         {
             vector<string> vPonits = ui->w_xy->GetTabbedsXY(m_vPoints[i]);
             strResulCode+=vTitles[n];
             strResulCode+="[";
             for(int j =0; j < vPonits.size(); ++j)
             {

                 if(j!=0)
                 {
                     strResulCode += ",";
                 }

                 strResulCode+= vPonits[j];
             }

             strResulCode+="];";
             ++n;
         }
    }
    return strResulCode;
}


void NGDialog::on_pushButton_clicked()
{
    done(0);
}

void NGDialog::slot_click(int nIndex)
{
    //切换
    //保存当前
    if(m_nIndex != -1)
    {
        vector<bool> vStates;
        ui->w_xy->OnGetState(vStates);
        m_vPoints[m_nIndex] = vStates;
    }
    //设置
    ui->w_xy->OnShowState(m_vPoints[nIndex]);
    m_nIndex = nIndex;

}
