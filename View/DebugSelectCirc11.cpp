#include "DebugSelectCirc.h"
#include "ui_DebugSelectCirc.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <Windows.h>

#include "Tool/Data.h"
using namespace cv;

DebugSelectCirc::DebugSelectCirc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugSelectCirc)
{
    ui->setupUi(this);
    m_pItemWidget = new DebugItemWidget;
    m_pModel = nullptr;
    m_bEL = true;


}

void DebugSelectCirc::OnBGRtoRGB(void *pBuffer)
{
    IplImage* pImage =cvCreateImage(cvSize(5440,3648),IPL_DEPTH_8U,3);
    memcpy( pImage->imageData,pBuffer, 5440*3648*3);
    cvCvtColor(pImage,pImage,CV_BGR2RGB);
    memcpy(pBuffer, pImage->imageData, 5440*3648*3);
    cvReleaseImage(&pImage);
}

void DebugSelectCirc::OnInit(ControlModel *pModel, bool bEL)
{
    m_pModel = pModel;
    m_bEL = bEL;
     m_Imgs.resize(3);
    if(m_bEL)
    {
        m_Image = QImage(1920*4,1200*3,QImage::Format_Grayscale8);

        //创建内存
        for(int i = 0; i < 3; ++i)
        {
            vector<void *> buffers;
            buffers.resize(4);
            for(int j = 0; j <4; ++j)
            {
                buffers[j] = new uchar[19200*1200];
            }
            m_Imgs[i] = buffers;
        }
    }
    else
    {
        m_Image = QImage(5440*4,3648*3,QImage::Format_RGB888);
        for(int i = 0; i < 3; ++i)
        {
            vector<void *> buffers;
            buffers.resize(4);
            for(int j = 0; j <4; ++j)
            {
                buffers[j] = new uchar[5440*5440*3];
            }
            m_Imgs[i] = buffers;
        }
    }
}

void DebugSelectCirc::OnInitAlg(EFIAlg2000WModule *p2000, EFIAlg230WModule *p230)
{
        m_pAlg2000 = p2000;
        m_pAlg230 = p230;
}

void DebugSelectCirc::OnInitLoadImage(vector<void *> buffers, int nIndex)
{
    if(buffers.size() != 4)
        return;
    if(nIndex == 0)
    {
        if(m_bEL)
        {
            m_Image = QImage(1920*4,1200*3,QImage::Format_Grayscale8);
        }
        else
        {
            m_Image = QImage(5440*4,3648*3,QImage::Format_RGB888);
        }
    }

    if(m_bEL)
    {
        //内存拷贝
        vector<void *> & buffer = m_Imgs[nIndex];
        for(int i = 0; i < buffers.size(); ++i)
        {
            memcpy(buffer[i],buffers[i],1920*1200);
        }
        QImage *img1 = new QImage((uchar*)buffers[0],1920,1200,QImage::Format_Grayscale8);
        QImage *img2 = new QImage((uchar*)buffers[1],1920,1200,QImage::Format_Grayscale8);
        QImage *img3 = new QImage((uchar*)buffers[2],1920,1200,QImage::Format_Grayscale8);
        QImage *img4 = new QImage((uchar*)buffers[3],1920,1200,QImage::Format_Grayscale8);

	if(1)
	{
		//保存图片
		QString str1 = QString("CACHEIMAGE/EL_%1_0.png").arg(nIndex);
		img1->save(str1, "PNG");
		
		QString str2 = QString("CACHEIMAGE/EL_%1_1.png").arg(nIndex);
		img2->save(str2, "PNG");
		QString str3 = QString("CACHEIMAGE/EL_%1_2.png").arg(nIndex);
		img3->save(str3, "PNG");

		QString str4 = QString("CACHEIMAGE/EL_%1_3.png").arg(nIndex);
		img4->save(str4, "PNG");
   }


        QPainter painter(&m_Image);
        painter.drawImage(0, nIndex*1200,*img1);
        painter.drawImage(1920, nIndex*1200,*img2);
        painter.drawImage(1920*2, nIndex*1200,*img3);
        painter.drawImage(1920*3, nIndex*1200,*img4);
        painter.end();
        delete img1;
        delete img2;
        delete img3;
        delete img4;
    }
    else
    {

            OnBGRtoRGB(buffers[0]);
            OnBGRtoRGB(buffers[1]);
            OnBGRtoRGB(buffers[2]);
            OnBGRtoRGB(buffers[3]);

            vector<void *> & buffer = m_Imgs[nIndex];
            for(int i = 0; i < buffers.size(); ++i)
            {
                memcpy(buffer[i],buffers[i],5440*3648*3);
            }

            QImage  *img1 = new QImage((uchar*)buffers[0],5440,3648,QImage::Format_RGB888);
            QImage *img2  = new QImage((uchar*)buffers[1],5440,3648,QImage::Format_RGB888);
            QImage *img3 = new QImage((uchar*)buffers[2],5440,3648,QImage::Format_RGB888);
            QImage *img4 = new QImage((uchar*)buffers[3],5440,3648,QImage::Format_RGB888);

            if(1)
            {
                //保存图片
                QString str1 = QString("CACHEIMAGE/LOOK_%1_0.jpg").arg(nIndex);
                img1->save(str1, "JPG");

                QString str2 = QString("CACHEIMAGE/LOOK_%1_1.jpg").arg(nIndex);
                img2->save(str2, "JPG");
                QString str3 = QString("CACHEIMAGE/LOOK_%1_2.jpg").arg(nIndex);
                img3->save(str3, "JPG");

                QString str4 = QString("CACHEIMAGE/LOOK_%1_3.jpg").arg(nIndex);
                img4->save(str4, "JPG");
            }

            QPainter painter(&m_Image);
            painter.drawImage(0, nIndex*3648,*img1);
            painter.drawImage(5440, nIndex*3648,*img2);
            painter.drawImage(5440*2, nIndex*3648,*img3);
            painter.drawImage(5440*3, nIndex*3648,*img4);
            painter.end();

            delete img1;
            delete img2;
            delete img3;
            delete img4;
    }

    m_pItemWidget->OnUpDataImage(&m_Image);
    m_pItemWidget->OnSetRegs(m_bEL ? m_pModel->OnGetELRegs():m_pModel->OnGetLookRegs());
    ui->graphicsView->OnUpdateWidget(m_pItemWidget);

}

DebugSelectCirc::~DebugSelectCirc()
{
    delete ui;
}
#include <QDebug>
bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{

    QStringList  sl1 = s1.split("_");
    QStringList  sl2 = s2.split("_");
    if(sl1.count()!=2 || sl2.count()!=2)
        return false;

    int i1 = sl1.at(1).split(".").at(0).toInt();
    int i2 = sl2.at(1).split(".").at(0).toInt();
    return i1 < i2;
}

void DebugSelectCirc::on_Btn_Load_clicked()
{
    QStringList fileNameList = QFileDialog::getOpenFileNames(this, tr("open file"), " ",  tr("Allfile(*.*);;png(*.png);;jpg(*.jpg)"));

    if(fileNameList.count() != 12)
        return ;

    qSort(fileNameList.begin(), fileNameList.end(),caseInsensitiveLessThan);
    qDebug()<<fileNameList;

    if(m_bEL)
    {
         m_Image = QImage(1920*4,1200*3,QImage::Format_Grayscale8);
        for(int i = 0; i < 3;++i)
        {
            vector<void *> & buffer = m_Imgs[i];
            for(int j = 0; j < 4; ++j)
            {
                QImage img(fileNameList[i*4+j]);
                memcpy(buffer[j],img.constBits(),1920*1200);
                QPainter painter(&m_Image);
                painter.drawImage(1920*j, i*1200,img);
                painter.end();
            }
        }
    }
    else
    {
         m_Image = QImage(5440*4,3648*3,QImage::Format_RGB888);
         for(int i = 0; i < 3;++i)
         {
             vector<void *> & buffer = m_Imgs[i];
             for(int j = 0; j < 4; ++j)
             {
                 QImage img(fileNameList[i*4+j]);
                 QImage  fromImg = img.convertToFormat(QImage::Format_RGB888);

                 memcpy(buffer[j],fromImg.constBits(),5440*3648*3);
                 QPainter painter(&m_Image);
                 painter.drawImage(5440*j, i*3648,img);
                 painter.end();

             }
         }
    }
 //   QImage * pImage = new QImage(fileName);
    m_pItemWidget->OnUpDataImage(&m_Image);

    m_pItemWidget->OnSetRegs(m_bEL ? m_pModel->OnGetELRegs():m_pModel->OnGetLookRegs());
    ui->graphicsView->OnUpdateWidget(m_pItemWidget);


}

void DebugSelectCirc::on_Btn_Pre_clicked()
{
    if(m_bEL)
    {
        m_pModel->OnSetELRegs(m_pItemWidget->OnGetRegs());
    }
    else
    {
        m_pModel->OnSetLookRegs(m_pItemWidget->OnGetRegs());
    }

    //加载算法测试
    ui->Btn_Pre->setEnabled(false);
    ui->Btn_Edit->setEnabled(false);

    if(m_bEL)
    {
		int   nELCurHeight = 0;
		m_PreImage = QImage(1920 * 4, 1200 * 3, QImage::Format_Grayscale8);
		std::vector<HALREG> rects = m_pModel->OnGetELRegs();
		for (int i = 0; i < m_Imgs.size(); ++i)
		{
			vector<void *> & buffer = m_Imgs[i];

			Data  data;
			data.SetAttribute("row", i);

			data.SetAttribute("rects", &rects);

			if (nELCurHeight == 0)
			{
				nELCurHeight = 45;
			}
			try {
				m_pAlg230->AlgLoadImags(buffer);
                vector<EL_ChipStrut>  Vecs,Vecs2;
                 //bool bOpen = !strcmp(pData->GetValue(EL_TEST_CHECK).GetString(),"TRUE");
                m_pAlg230->AlgCrystalAction(&data, Vecs,Vecs2,true);
			}
			catch (...)
			{

			}
			IplImage * pImage = (IplImage *)(void *)data.GetAttribute("image");

			QImage Qimg = QImage((const unsigned char*)(pImage->imageData), pImage->width, pImage->height, QImage::Format_Grayscale8);
			QPainter painter(&m_PreImage);
			QRect rt(64, nELCurHeight, 1920 * 4.0 - 128, 1150);
			painter.drawImage(rt, Qimg);
			painter.end();

			nELCurHeight += 1150;

			cvReleaseImage(&pImage);

		}
		m_pItemWidget->OnClear();
		m_pItemWidget->OnUpDataImage(&m_PreImage);
    }
    else
    {


        int   nLookCurHeight = 0;
        m_PreImage = QImage(5440*4,3648*3,QImage::Format_RGB888);
		std::vector<HALREG> rects = m_pModel->OnGetLookRegs();
        for(int i = 0; i < m_Imgs.size(); ++i)
        {
            vector<void *> & buffer = m_Imgs[i];

            Data  data;
            data.SetAttribute("row",i);
			
            data.SetAttribute("rects",&rects);


            EFIAlg2000W * pAlg = m_pAlg2000->Create();
            bool bGet = pAlg->AlgLoadImags(buffer);
            vector<ChipStrut> vecs;
			pAlg->SetRow(i);
            pAlg->AlgAction(&data,vecs);

            //拿出图片
            IplImage * pImage = (IplImage *)(void *)data.GetAttribute("image");

            CvSize czSize;
            czSize.width = 5440 * 4-362;
            czSize.height = 3474; //3648*3

            //图片缩放
            IplImage * pDstImage = cvCreateImage(czSize, pImage->depth, pImage->nChannels);
            cvResize(pImage, pDstImage, CV_INTER_AREA);
            QImage Qimg = QImage((const unsigned char*)(pDstImage->imageData), pDstImage->width, pDstImage->height, QImage::Format_RGB888);

            if(nLookCurHeight == 0)
            {
                nLookCurHeight = 137;
            }

            QPainter painter(&m_PreImage);

            painter.drawImage(181, nLookCurHeight, Qimg);
            /*QRect rt(0,m_pControaller->m_nLookCurHeight,5440*4,3200);
            painter.drawImage(rt,Qimg);*/
            painter.end();
            nLookCurHeight += 3474;

            cvReleaseImage(&pImage);
            cvReleaseImage(&pDstImage);
			m_pAlg2000->Release(pAlg);

        }
        m_pItemWidget->OnClear();
        m_pItemWidget->OnUpDataImage(&m_PreImage);
    }


    ui->Btn_Pre->setEnabled(true);
    ui->Btn_Edit->setEnabled(true);
}

void DebugSelectCirc::on_Btn_Edit_clicked()
{
    //返回原来的模式
    m_pItemWidget->OnClear();
    m_pItemWidget->OnUpDataImage(&m_Image);
    m_pItemWidget->OnSetRegs(m_bEL ? m_pModel->OnGetELRegs():m_pModel->OnGetLookRegs());
    ui->graphicsView->OnUpdateWidget(m_pItemWidget);
}
