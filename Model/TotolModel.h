#ifndef TOTOLMODEL_H
#define TOTOLMODEL_H
#include "Tool/IController.h"
#include <vector>
#include <string>

class TotolModel:public IController
{
public:
    TotolModel();

    //加载
    bool  OnLoad(const char * path);

    std::vector<std::string> GetButtons();
    std::vector<int>         GetValues();

    void                     AddValue(int nIndex);
private:

    std::vector<int>         m_nValues;
    std::vector<std::string> m_strNames;
    std::vector<Data*>       m_vDatas;
    Data *                   m_pPropety;

};

#endif // TOTOLMODEL_H
