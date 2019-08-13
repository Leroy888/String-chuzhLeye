/********************************************************************************
** Form generated from reading UI file 'NXMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NXMAINWINDOW_H
#define UI_NXMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NXMainWindow
{
public:
    QAction *start;
    QAction *stop;
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NXMainWindow)
    {
        if (NXMainWindow->objectName().isEmpty())
            NXMainWindow->setObjectName(QStringLiteral("NXMainWindow"));
        NXMainWindow->resize(960, 720);
        NXMainWindow->setStyleSheet(QStringLiteral("background-color: rgb(159, 159, 159);"));
        start = new QAction(NXMainWindow);
        start->setObjectName(QStringLiteral("start"));
        start->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Image/start_0.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/Resources/Image/start_0.png"), QSize(), QIcon::Normal, QIcon::On);
        start->setIcon(icon);
        stop = new QAction(NXMainWindow);
        stop->setObjectName(QStringLiteral("stop"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Image/stop_0.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/Resources/Image/stop_0.png"), QSize(), QIcon::Normal, QIcon::On);
        stop->setIcon(icon1);
        action = new QAction(NXMainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Image/sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon2);
        centralWidget = new QWidget(NXMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NXMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NXMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 26));
        NXMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(NXMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NXMainWindow->setStatusBar(statusBar);

        retranslateUi(NXMainWindow);

        QMetaObject::connectSlotsByName(NXMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NXMainWindow)
    {
        NXMainWindow->setWindowTitle(QApplication::translate("NXMainWindow", "DockTest", Q_NULLPTR));
        start->setText(QApplication::translate("NXMainWindow", "\345\274\200\345\220\257", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        start->setToolTip(QApplication::translate("NXMainWindow", "\345\274\200\345\247\213\345\220\257\345\212\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        start->setShortcut(QApplication::translate("NXMainWindow", "Backspace", Q_NULLPTR));
        stop->setText(QApplication::translate("NXMainWindow", "View File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        stop->setToolTip(QApplication::translate("NXMainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action->setText(QApplication::translate("NXMainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("NXMainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class NXMainWindow: public Ui_NXMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NXMAINWINDOW_H
