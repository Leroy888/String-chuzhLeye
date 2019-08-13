#include "woker.h"
#include "../Controller/LogicController.h"
#include <QTime>
#include <QPainter>
#include "EFComm/Unity/IOStruct.h"
#include <QMutex>
#pragma execution_character_set("utf-8")

QVector<QColor>  elColor = {Qt::white,Qt::red,Qt::darkGray,Qt::gray,Qt::darkYellow,Qt::yellow,Qt::darkGreen,Qt::green,Qt::blue,Qt::cyan,Qt::gray,Qt::darkYellow,Qt::yellow};

Woker::Woker(vector<void*> pVbuffer, Data *pData)
{

    m_pData = pData;
    m_pLog = (EFILogModule *)(void *)pData->GetAttribute("ModuleLog");
    m_vBuffers = pVbuffer;
    m_pImage = (QImage *)(void*)pData->GetAttribute("DrawImage");
    m_pPaintImage = (QImage*)(void*)pData->GetAttribute("PaintImage");
    m_pControaller =(LogicController*)(void*)pData->GetAttribute("Logic") ;

}

int Woker::m_nSHeight = 0;
QMutex mutex;

void Woker::run()
{
   int nRow  = m_pData->GetAttribute("row");

    //m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "StringEL draw:", nRow);
    QTime  time;
    time.start();
    bool bGet = m_pControaller->m_pAlg230->AlgLoadImags(m_vBuffers);

    if(bGet)
    {


        vector<EL_ChipStrut> * pVec = (vector<EL_ChipStrut> *) (void *)m_pData->GetAttribute("EL1");
        if (nRow == 1)
        {
            pVec = (vector<EL_ChipStrut> *)(void *)m_pData->GetAttribute("EL2");
        }
        else if (nRow == 2)
        {
            pVec = (vector<EL_ChipStrut> *) (void *)m_pData->GetAttribute("EL3");
        }

        pVec->clear();

        vector<EL_ChipStrut> vecs1, vecs2;

        try
        {
            //判断是否需要是否关闭EL自动识别
            bool bOpen = !strcmp(m_pData->GetValue(EL_TEST_CHECK).GetString(), "TRUE");
            m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,bOpen ? "action_EL230w Open " : "action_EL230w Close ", "");

            m_pControaller->m_pAlg230->AlgCrystalAction(m_pData, vecs1, vecs2, true);
        }
        catch (...)
        {
            m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "action_EL230w catch!", "");
        }

        //第一次
        //  if(m_pControaller->m_nELCurHeight == 0)
        //{
        m_pControaller->m_nELCurHeight = 45;

        //} //等比例缩放

        IplImage * pImage = (IplImage *)(void *)m_pData->GetAttribute("image");


        if(pImage)
        {

            QImage Qimg = QImage((const unsigned char*)(pImage->imageData), pImage->width, pImage->height, QImage::Format_Grayscale8);
//            QRect rect = Qimg.rect();
//            m_pImage = &Qimg.copy(rect);
//            emit resultReady(nRow);
//            return;


            //20190731
     //       m_pImage = &QImage(pImage->width, pImage->height, QImage::Format_RGB888);
     //       m_pImage.fill(QColor(0, 0, 0));


            QImage drawImg = Qimg.convertToFormat(QImage::Format_RGB888);
//            //标记区域
//            vector<EL_ChipStrut> Vecs = vecs1;

//            ostringstream  ss;
//            ss<<"VEC SIZE:"<<Vecs.size();
//            m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, ss);


//            QPainter painter_dr(&drawImg);

//            // painter_dr.setPen(QPen(clr,6));
//            for(int i = 0; i < Vecs.size(); ++i)
//            {

//                EL_CenterRG & ct = Vecs[i].m_Rg;
//                int nType = Vecs[i].m_nType;

//                ostringstream  ss;
//                ss<<"draw:"<<Vecs[i].m_nType;
//                m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, ss);

//                //if(nType >=1 && nType <=13 )
//                {
//                    ostringstream  ss;
//                    ss<<"draw on:"<<Vecs[i].m_nType;
//                    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, ss);

//                    QColor clr = elColor[nType];
//                    painter_dr.setPen(QPen(clr,10));
//                    painter_dr.drawRect(QRect(ct.m_EL_X - ct.m_EL_W,ct.m_EL_Y - ct.m_EL_H,ct.m_EL_W*2,ct.m_EL_H*2));
//                }
//            }

//            painter_dr.end();
//            //画显示EL
//      //       QRect rt(10,5,600*6,600*2);//20190510

      //      QRect rt(10,5, pImage->width, pImage->height);//20190730
            QRect rt(0, 0, pImage->width, pImage->height);//20190730

//            QRect rt(10,5,9900,600*2);
            // QRect rt(64,m_pControaller->m_nELCurHeight,Qimg.width(),Qimg.height());
            mutex.lock();

            QPainter painter_pin(m_pImage);
            painter_pin.drawImage(rt,drawImg);
            painter_pin.end();



            //            QPainter painter(m_pImage);
            //            painter.drawImage(rt,Qimg,Qimg.rect(),Qt::ThresholdDither);
            //            painter.end();
            mutex.unlock();
            // m_pControaller->m_nELCurHeight =  m_pControaller->m_nELCurHeight+1150;

            cvReleaseImage(&pImage);

            //新增20190510
//            if(m_pData->GetValue("AI_Open").GetString()==std::string("TRUE"))
//            {
//                emit send_img(Qimg_ai.scaled(1920*4.0-128,1150),nRow);
//            }


        }
        else //拼接失败
        {
            QPainter painter(m_pImage);
            for(int i =0 ; i < m_vBuffers.size(); ++i)
            {
                QImage  img = QImage((const unsigned char *)m_vBuffers[i],1920, 1200, QImage::Format_Grayscale8);
                painter.drawImage(i*1920,m_pControaller->m_nELCurHeight,img);
            }
//            for(int i =4 ; i < m_vBuffers.size(); ++i)
//            {
//                QImage  img = QImage((const unsigned char *)m_vBuffers[i],1920, 1200, QImage::Format_Grayscale8);
//                painter.drawImage(i*1920,1150,img);

//            }
            painter.end();
        }
    }

    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, " action_EL230w total time:", time.elapsed());


    emit resultReady(nRow);



}

vector<Woker::total_ST> Woker::ActionTotal()
{
    vector<total_ST> retVecs;
    retVecs.resize(Em_End);
    for(int i = 0; i < Em_End; ++i)
    {
        retVecs[i].m_nType = i;
    }

    if(!m_pData)
        return retVecs;
    vector<EL_ChipStrut> allVecs;
    //1
    vector<EL_ChipStrut> * pVec1 = (vector<EL_ChipStrut> *) (void *)m_pData->GetAttribute("EL1");
    if(pVec1)
    {
        allVecs.insert(allVecs.end(),pVec1->begin(), pVec1->end());
    }
    //2
    vector<EL_ChipStrut> * pVec2 = (vector<EL_ChipStrut> *) (void *)m_pData->GetAttribute("EL2");
    if(pVec2)
    {
        allVecs.insert(allVecs.end(),pVec2->begin(), pVec2->end());
    }
    //3
    vector<EL_ChipStrut> * pVec3 = (vector<EL_ChipStrut> *) (void *)m_pData->GetAttribute("EL3");
    if(pVec3)
    {
        allVecs.insert(allVecs.end(),pVec3->begin(), pVec3->end());
    }

    for(int i = 0; i < allVecs.size(); ++i)
    {
        int nType = allVecs[i].m_nType;
        total_ST &st = retVecs[nType];
        EL_CenterRG &rg =  allVecs[i].m_Rg;
        st.m_nNumber++;
        st.m_fRg += rg.m_EL_W*rg.m_EL_H;
    }



    return retVecs;
}

vector<QString> Woker::TotalToStr(vector<Woker::total_ST> &vecs)
{
    vector<QString> retvecs;
    vector<QString> titals = {"no","hd","qhb","b_qhb","shb","b_shb","ds","max_ds","yl","Xl"};
    for(int i = 0; i < vecs.size(); ++i)
    {
        QString str= QString("%1 total:%2 area:%3").arg(titals[i]).arg(vecs[i].m_nNumber).arg(vecs[i].m_fRg);
        retvecs.push_back(str);
    }

    return retvecs;
}

