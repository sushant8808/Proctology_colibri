QT += core gui sql svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lgpiod
CONFIG += release
QMAKE_CXXFLAGS_RELEASE += -g

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aimingbeampopupdialog.cpp \
    brightnesspopupdialog.cpp \
    calibration_screen.cpp \
    changepassword.cpp \
    changevalue.cpp \
    circularoverlay.cpp \
    clickablelabel.cpp \
    colibri_adc.cpp \
    customkeyboard.cpp \
    dac8552.cpp \
    databaseinitializer.cpp \
    databasemanager.cpp \
    datetime_manager.cpp \
    error_popup.cpp \
    global.cpp \
    hardwaremanager.cpp \
    hardwaremanagerprovider.cpp \
    home.cpp \
    home_button.cpp \
    keyboard_bt.cpp \
    main.cpp \
    mainwindow.cpp \
    mqs_audio.cpp \
    newcustomprotocol.cpp \
    protocolitemwidget.cpp \
    protocolselect.cpp \
    pulsemode.cpp \
    readyforsurgery.cpp \
    rental_info.cpp \
    runtime_manager.cpp \
    service_engineer_area.cpp \
    set_date_time.cpp \
    setting.cpp \
    soundpopupdialog.cpp \
    surgery_data.cpp \
    surgerycontext.cpp \
    system_usages.cpp \
    thememanager.cpp \
    tickedslider.cpp \
    timerring.cpp \
    usage_area.cpp \
    userdatabaseinitializer.cpp \
    userdatabasemanager.cpp \
    userlogin.cpp

HEADERS += \
    aimingbeampopupdialog.h \
    brightnesspopupdialog.h \
    calibration_screen.h \
    changepassword.h \
    changevalue.h \
    circularoverlay.h \
    clickablelabel.h \
    colibri_adc.h \
    customkeyboard.h \
    dac8552.h \
    databaseinitializer.h \
    databasemanager.h \
    datetime_manager.h \
    error_popup.h \
    global.h \
    hardwaremanager.h \
    hardwaremanagerprovider.h \
    home.h \
    home_button.h \
    keyboard_bt.h \
    mainwindow.h \
    mqs_audio.h \
    newcustomprotocol.h \
    pageindex.h \
    protocolitemwidget.h \
    protocolselect.h \
    pulsemode.h \
    readyforsurgery.h \
    rental_info.h \
    runtime_manager.h \
    service_engineer_area.h \
    set_date_time.h \
    setting.h \
    soundpopupdialog.h \
    surgery_data.h \
    surgerycontext.h \
    system_usages.h \
    thememanager.h \
    tickedslider.h \
    timerring.h \
    usage_area.h \
    userdatabaseinitializer.h \
    userdatabasemanager.h \
    userlogin.h

FORMS += \
    calibration_screen.ui \
    changepassword.ui \
    changevalue.ui \
    customkeyboard.ui \
    home.ui \
    mainwindow.ui \
    newcustomprotocol.ui \
    protocolselect.ui \
    pulsemode.ui \
    readyforsurgery.ui \
    rental_info.ui \
    service_engineer_area.ui \
    set_date_time.ui \
    setting.ui \
    surgery_data.ui \
    system_usages.ui \
    usage_area.ui \
    userlogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
