Debug:TARGET = EFStringEL_d
Release:TARGET = EFStringEL

TEMPLATE = lib
#CONFIG += staticlib
CONFIG += c++11

QT += core gui xml network serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES   -= UNICODE
DEFINES  +=UMBCS
DEFINES  +=CURL_STATICLIB



QMAKE_LFLAGS_RELEASE    += /MAP
QMAKE_CFLAGS_RELEASE    += /Zi
QMAKE_LFLAGS_RELEASE    += /debug /opt:ref


Release:LIBS += -L$$PWD/../../_Out/Release
Debug:LIBS += -L$$PWD/../../_Out/Debug

INCLUDEPATH += ../../
INCLUDEPATH += $$PWD/../../Dependencies/
DEPENDPATH  +=  $$PWD/../../
DEPENDPATH += $$PWD/../../Dependencies/
DEPENDPATH += $$PWD/MesTool/
INCLUDEPATH += ../EFGuiLib


##
INCLUDEPATH += "$$(HALCONROOT)/include"
INCLUDEPATH += "$$(HALCONROOT)/include/halconcpp"

DEPENDPATH += "$$(HALCONROOT)/include"
DEPENDPATH += "$$(HALCONROOT)/include/halconcpp"

QMAKE_LIBDIR  += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
LIBS +=  -lhalconcpp


INCLUDEPATH += "$$PWD/../../Dependencies/opencv/include"
DEPENDPATH += "$$PWD/../../Dependencies/opencv/include"
##


INCLUDEPATH += "$$PWD/../../Dependencies/opencv/include"
DEPENDPATH += "$$PWD/../../Dependencies/opencv/include"





INCLUDEPATH += "$$PWD/../../Dependencies/libcurl/include"
DEPENDPATH += "$$PWD/../../Dependencies/libcurl/include"



QMAKE_LIBDIR  += "$$PWD/../../Dependencies/opencv/x64/vc14/lib"
LIBS += -lopencv_world320

QMAKE_LIBDIR += "$$PWD/../../Dependencies/libcurl/lib"
Release:LIBS += -llibcurl_a
Debug:LIBS += -llibcurl_a_debug


#锟斤拷锟斤拷目录
Release:DESTDIR+= $$PWD/../../_Out/Release
Debug:DESTDIR += $$PWD/../../_Out/Debug






RESOURCES += \
    resources.qrc

HEADERS += \
    EFStringEL_Module.h \
    EFStringEL_Plugin.h \
    Controller/DebugController.h \
    Controller/LogicController.h \
    Controller/savewoker.h \
    Controller/woker.h \
    Controller/WorkerOriSave.h \
    Controller/ai_save_work.h\
    Controller/ExcelThread.h \
    Model/ControlModel.h \
    Model/DefectBtnModel.h \
    Model/MesObj.h \
    Model/NetDataListenerThread.h \
    Model/qtsoap.h \
    Model/ScanCodeObj.h \
    Model/TotolModel.h \
    Model/WebEChartObj.h \
    Model/WebServiceHelp.h \
    Model/DLClientInterface.h\
    Model/sacsvstream.h\
    Model/NetDataAiListenerThread.h\
    View/CommandWidget.h \
    View/DebugItemWidget.h \
    View/DebugSelectCirc.h \
    View/DebugSelectView.h \
    View/EFDrawWidget.h \
    View/EFStateBar.h \
    View/ELCmdAction.h \
    View/ELMainWindowObj.h \
    View/FileNameDialog.h \
    View/Login.h \
    View/LookCmdAction.h \
    View/LookMainWindowObj.h \
    View/MesLogin.h \
    View/NGDialog.h \
    View/NXDockWidget.h \
    View/NXDockWidgetTabBar.h \
    View/NXDockWidgetTabButton.h \
    View/NXDockWidgetTitle.h \
    View/NXMainWindow.h \
    View/OptRuler.h \
    View/OPTView.h \
    View/SeeView.h \
    View/SeeWidget.h \
    View/StartAction.h \
    View/StateColor.h \
    View/SysSetAction.h \
    View/TabbedWidget.h \
    View/TestForm.h \
    View/TotalAction.h \
    View/SeeViewGraphic.h \
    View/SeeWidgetEL.h \
    MesTool/JKMesClient.h \
    MesTool/ServiceSoap.nsmap \
    MesTool/soapH.h \
    MesTool/soapStub.h \
    MesTool/stdsoap2.h \
    MesTool/CurlFtpHelper.h \
    View/MES_Dialog.h \
    View/ELTotal.h \
    View/TotalTableWidget.h \
    View/AuthorityMes.h \
    p123_STR_class.h \
    Controller/AiExcelThread.h

SOURCES += \
    dllmain.cpp \
    EFStringEL_Module.cpp \
    EFStringEL_Plugin.cpp \
    Controller/DebugController.cpp \
    Controller/LogicController.cpp \
    Controller/savewoker.cpp \
    Controller/woker.cpp \
    Controller/ai_save_work.cpp\
    Controller/WorkerOriSave.cpp \
    Controller/ExcelThread.cpp \
    Model/ControlModel.cpp \
    Model/DefectBtnModel.cpp \
    Model/MesObj.cpp \
    Model/NetDataListenerThread.cpp \
    Model/qtsoap.cpp \
    Model/ScanCodeObj.cpp \
    Model/TotolModel.cpp \
    Model/WebEChartObj.cpp \
    Model/WebServiceHelp.cpp \
    Model/DLClientInterface.cpp\
    Model/sacsvstream.cpp\
    Model/NetDataAiListenerThread.cpp\
    View/CommandWidget.cpp \
    View/DebugItemWidget.cpp \
    View/DebugSelectCirc.cpp \
    View/DebugSelectView.cpp \
    View/EFDrawWidget.cpp \
    View/EFStateBar.cpp \
    View/ELCmdAction.cpp \
    View/ELMainWindowObj.cpp \
    View/FileNameDialog.cpp \
    View/Login.cpp \
    View/LookCmdAction.cpp \
    View/LookMainWindowObj.cpp \
    View/MesLogin.cpp \
    View/NGDialog.cpp \
    View/NXDockWidget.cpp \
    View/NXDockWidgetTabBar.cpp \
    View/NXDockWidgetTabButton.cpp \
    View/NXDockWidgetTitle.cpp \
    View/NXMainWindow.cpp \
    View/OptRuler.cpp \
    View/OPTView.cpp \
    View/SeeView.cpp \
    View/SeeWidget.cpp \
    View/StartAction.cpp \
    View/StateColor.cpp \
    View/SysSetAction.cpp \
    View/TabbedWidget.cpp \
    View/TestForm.cpp \
    View/TotalAction.cpp \
    View/SeeViewGraphic.cpp \
    View/SeeWidgetEL.cpp \
    MesTool/JKMesClient.cpp \
    MesTool/soapC.cpp \
    MesTool/soapClient.cpp \
    MesTool/stdsoap2.cpp \
    MesTool/CurlFtpHelper.cpp \
    View/MES_Dialog.cpp \
    View/ELTotal.cpp \
    View/TotalTableWidget.cpp \
    View/AuthorityMes.cpp \
    p123_STR_class.cpp \
    Controller/AiExcelThread.cpp

FORMS += \
    View/DebugSelectCirc.ui \
    View/EFStateBar.ui \
    View/ELCmdAction.ui \
    View/FileNameDialog.ui \
    View/Login.ui \
    View/LookCmdAction.ui \
    View/MesLogin.ui \
    View/NGDialog.ui \
    View/NXMainWindow.ui \
    View/SeeWidget.ui \
    View/StartAction.ui \
    View/StateColor.ui \
    View/SysSetAction.ui \
    View/TestForm.ui \
    View/TotalAction.ui \
    View/SeeWidgetEL.ui \
    View/MES_Dialog.ui \
    View/ELTotal.ui \
    View/AuthorityMes.ui






