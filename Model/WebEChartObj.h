#ifndef WEBECHARTOBJ_H
#define WEBECHARTOBJ_H

#include <QObject>
#include <QJsonObject>

class WebEChartObj : public QObject
{
    Q_OBJECT
  //  Q_PROPERTY(QString option MEMBER m_strOption NOTIFY sig_optionChanged)

public:
    explicit WebEChartObj(QObject *parent = 0);


    void    build_json(const std::vector<std::string> & names, const std::vector<int> & values);

signals:
    void    sig_optionChanged(const QJsonObject & option);

public slots:
    //供网页 JS 调用
    void slot_debug();
private:
    QJsonObject   m_option;
    QString       m_strOption;
};

#endif // WEBECHARTOBJ_H
