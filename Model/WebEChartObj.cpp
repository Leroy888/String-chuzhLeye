#include "WebEChartObj.h"
#include <QDebug>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#pragma execution_character_set("utf-8")

WebEChartObj::WebEChartObj(QObject *parent) : QObject(parent)
{

}



void WebEChartObj::build_json(const std::vector<std::string> &names, const std::vector<int> &values)
{
    if(names.size() != values.size())
        return ;

    QJsonArray datacategories;	// 数据类别
    for(int i = 0; i < names.size(); ++i)
    {
        datacategories.push_back(names[i].c_str());
    }



    QJsonObject title{
        {"trigger","item"},
        {"formatter",  "{a} <br/>{b}: {c} ({d}%)"}
    };

    QJsonObject textStyle{
            {"color", "#fff"}
        };


    QJsonObject legend{
        {"orient", "vertical"},
         {"x", "right"},
        {"itemWidth",14},
         {"itemHeight", 14},
        {"align", "left"},
        {"data", datacategories },
        {"textStyle",textStyle}
    };


    QJsonArray radius;
    radius.push_back("40%");
    radius.push_back("55%");
    QJsonArray colors;
    colors.push_back("#9AFF9A");
    colors.push_back("#21b6b9");
    colors.push_back("#d74e67");
    colors.push_back("#0092ff");
    colors.push_back("#eba954");
    colors.push_back("#BA55D3");
    colors.push_back("#525252");
    colors.push_back("#eba954");

    QJsonArray datas;

    for(int i = 0; i < names.size(); ++i)
    {
        QJsonObject data1{
            {"value",values.at(i)},
            {"name",names.at(i).c_str()}
        };
        datas.push_back(data1);
    }


    QJsonObject normal{
        {"formatter","{b}\n{d}%"}
    };
    QJsonObject label{
            {"normal", normal}
        };

    QJsonObject serieData{
        {"name", QStringLiteral("CellTest")},
        {"type", "pie"},
        {"radius",radius},
        {"color", colors},
        {"label", label},
        {"data", datas }
    };
    QJsonArray series; series.push_back(serieData);


    QJsonObject option
    {
        {"backgroundColor","#424956"},
        {"tooltip", title },
        {"legend", legend },
        {"series", series }
    };

    QJsonDocument jsonDoc(option);
    QString str = jsonDoc.toJson().toStdString().c_str();

    emit sig_optionChanged(option);
}

void WebEChartObj::slot_debug()
{
  //  QStringList
    //    build_json();
}
