#include "mainwindow.h"
#include "thememanager.h"
#include "databasemanager.h"
#include "databaseinitializer.h"
#include "userdatabaseinitializer.h"
#include "userdatabasemanager.h"
#include "global.h"
#include <QApplication>
#include "runtime_manager.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // SYSTEM DB
    QString systemDbPath =
        "/home/root/laserData/system.db";

    if (!DatabaseManager::instance().connect(systemDbPath)) {
       qDebug() << "SYSTEM DB failed";
        return -1;
    }

    DatabaseInitializer systemInit;
    systemInit.initialize();
    systemInit.fetchDeviceSetting();

    // USER DB
    QString userDbPath =
        "/home/root/laserData/user.db";

    if (!UserDatabaseManager::instance().connect(userDbPath)) {
       qDebug() << "USER DB failed";
        return -1;
    }

    UserDatabaseInitializer userInit;
    userInit.initialize();

    systemInit.ensureSystemTimerRow();
    systemInit.fetchSystemTimer(1);

    g_runtimeManager = new RuntimeManager();
    g_runtimeManager->start();

    // systemInit.insertPassword("1100","4321", "1234");

    // dbinit.insertHomeData(
    //     10.0,                 // 980 nm power
    //     12.0,                 // 1470 nm power
    //     60.0,                 // timer seconds
    //     false,                // timer_reset
    //     true,                 // timer_flag
    //     100.0,                // pulse on time
    //     200.0,                // pulse off time
    //     true,                 // pulse mode
    //     "Home"                // name
    //     );

    // dbinit.insertHomeData(
    //     0.0,                 // 980 nm power
    //     0.0,                 // 1470 nm power
    //     0.0,                 // timer seconds
    //     false,                // timer_reset
    //     false,                 // timer_flag
    //     0.0,                // pulse on time
    //     0.0,                // pulse off time
    //     false,                 // pulse mode
    //     "Default"                // name
    //     );

    // // Insert
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Hemorrhoids Grade 2",
    //     10,
    //     10,
    //     6,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Hemorrhoids Grade 3",
    //     10,
    //     10,
    //     6,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Hemorrhoids Grade 4",
    //     10,
    //     10,
    //     6,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Anal Fistula",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Anal Fissure",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Pilonidal Sinus",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "External Polyp",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_general",
    //     "Corn Excision",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );

    // dbinit.insertPresetProtocol(
    //     "preset_protocol_ent",
    //     "Tonsillectomy",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_ent",
    //     "Cysts",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_ent",
    //     "Nasal Polyp",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_ent",
    //     "Tumors Excision",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_gynaecology",
    //     "LVR",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_gynaecology",
    //     "Vaginal Wart",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_neurology",
    //     "PLDD",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_therapy",
    //     "Wound Healing",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_therapy",
    //     "Diabetic Ulcer",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_therapy",
    //     "Post Operative Pain",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_therapy",
    //     "Diabetic Foot",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_urology",
    //     "Circumcision",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // dbinit.insertPresetProtocol(
    //     "preset_protocol_vascular",
    //     "EVLT (Above the knees)",
    //     10,
    //     10,
    //     60,
    //     true,
    //     false,
    //     100,
    //     200,
    //     true,
    //     0
    //     );
    // // dbinit.insertPresetProtocol(
    // //     "protocol_custom",
    // //     "ENT Protocol 1",
    // //     10,
    // //     10,
    // //     60,
    // //     true,
    // //     false,
    // //     100,
    // //     200,
    // //     true,
    // //     0
    // //     );
    // // dbinit.insertPresetProtocol(
    // //     "protocol_favourites",
    // //     "ENT Protocol 1",
    // //     10,
    // //     10,
    // //     60,
    // //     true,
    // //     false,
    // //     100,
    // //     200,
    // //     true,
    // //     0
    // //     );

    // Fetch
    // fetchPresetProtocolById("preset_protocol_ent", 1);

    // dbinit.addColumn(
    //     "password",
    //     "pass_unable",
    //     "INTEGER",
    //     "1"
    //     );


    // dbinit.printSQLiteVersion();
    // QStringList keepColumns = {
    //     "id",
    //     "name",
    //     "980_power"
    //     "1470_power",
    //     "timer_sec",
    //     "timer_reset",
    //     "timer_flag",
    //     "pulse_on_time_ms",
    //     "pulse_off_time_ms",
    //     "pulse_mode"
    // };

    // dbinit.deleteColumnsKeepOnly("password",keepColumns);


    // dbinit.addColumn("preset_protocol_general","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_ent","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_gynaecology","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_neurology","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_therapy","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_urology","favourite","INTEGER",0);
    // dbinit.addColumn("preset_protocol_vascular","favourite","INTEGER",0);
    // dbinit.addColumn("protocol_custom","favourite","INTEGER",0);

    // systemInit.populatePowerVsDACTable();


    // systemInit.saveDeviceSetting(4,3,1,1,1,1,1,1,1,0,0,0,0);

    systemInit.fetchDeviceSetting();

    simpliAdvanMode = false;

    systemInit.fetchPasswords();

    systemInit.ensurePulseRangeRow();
    systemInit.fetchPulseRanges();

    if(persistence_data == 1)
        systemInit.fetchHomeDataById(1);
    if(persistence_data == 0)
        systemInit.fetchHomeDataById(2);

    QFont appFont("Roboto");
    a.setFont(appFont);


    ThemeManager theme;
    if(dark)
    {
        theme.applyDarkTheme();
    }else
    {
        theme.applyLightTheme();
    }
    dark = !dark;
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));


    MainWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}

