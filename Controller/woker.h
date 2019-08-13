#ifndef WOKER_H
#define WOKER_H
#include <QThread>
#include <QImage>
#include <vector>
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
#include "EFComm/EFPluginModule/EFILogModule.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
//using namespace cv;

using namespace std;

class Data;
class LogicController;

class Woker : public QThread
{
    Q_OBJECT
    struct total_ST
    {
        total_ST():m_nType(0),m_nNumber(0),m_fRg(0.0f){}
        int m_nType;    //类型
        int m_nNumber;  //数量
        double m_fRg;   //总面积
    };
    friend class LogicController;

public:
    Woker(vector<void*> pVbuffer, Data * pData);

    virtual  void run();


private:
    vector<total_ST> ActionTotal();
    vector<QString>  TotalToStr(vector<total_ST>& vecs);

private:
    static    int   m_nSHeight;
    QImage  *       m_pImage;
    QImage  *       m_pPaintImage;
    vector<void*>   m_vBuffers;
    Data *          m_pData;
    LogicController    * m_pControaller;
    EFILogModule    *  m_pLog;



signals:
    void resultReady(int nRow);
};

#endif // WOKER_H
