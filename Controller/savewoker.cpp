#include "savewoker.h"
#include <QFile>
#include <QDebug>
#define EL_IMG_PATH  "el_chace.jpg"
#define EL_IMG_DR_PATH "el_chace_dr.jpg"

#define LOOK_IMG_PATH  "look_chace.jpg"
#define LOOK_IMG_DR_PATH "look_chace_dr.jpg"
#pragma execution_character_set("utf-8")

SaveWoker::SaveWoker(QImage *pImage, QImage *pDrawImage, const std::string &strPath,QStringList  &cmdType, int nW, int nH, bool bEL)
	:m_pDrawImage(nullptr)
{
    m_pImage = pImage;
    m_pDrawImage = pDrawImage;
    m_strPath = strPath;

    m_nW = nW;
    m_nH = nH;
    m_bEL = bEL;
    m_strList = cmdType;
}

void SaveWoker::run()
{

    QString  strChache = m_bEL ? EL_IMG_PATH:LOOK_IMG_PATH;
    QString  strChacheDr = m_bEL ? EL_IMG_DR_PATH:LOOK_IMG_DR_PATH;

    QFile file;
    file.remove(strChache);
    file.remove(strChacheDr);
    //删除文件
    if(m_pImage)
    {
        QImage  image;
        if(m_nW)
        {
            image = m_pImage->scaled(m_nW,m_nH);
        }
        else
        {
            image = *m_pImage;
        }


         image.save(strChache,"jpg");


         sleep(1);

         QFile imageFile(strChache);

        for(auto it:m_strList)
        {
            imageFile.copy(it);
        }

        //拷贝

      //  imageFile.rename( m_strPath.c_str());
        file.copy(strChache, m_strPath.c_str());
        delete m_pImage;
    }

   

    if (m_pDrawImage)
    {
        if(0)
        {
            QImage  image;
            if(m_nW)
            {
                image =   m_pDrawImage->scaled(m_nW,m_nH);
            }
            else
            {
                image = *m_pImage;
            }

            image.save(strChacheDr, "jpg");

            std::string strDr = m_strPath.substr(0, m_strPath.rfind(".jpg"));
            strDr += "_dr.jpg";
            file.copy(strChache, strDr.c_str());
        }
        delete  m_pDrawImage;
    }

    emit  sig_Save_over(m_strPath.c_str());
    emit  sig_saveImage();

}
