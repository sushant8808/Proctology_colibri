#ifndef DATABASEINITIALIZER_H
#define DATABASEINITIALIZER_H

#include <QString>
#include "global.h"

class DatabaseInitializer
{
public:
    // Initialize database (create tables)
    bool initialize();
    bool createTables();

    // Home table functions
    bool insertHomeData(
        double power980,
        double power1470,
        double timerSec,
        bool timer_reset,
        bool timer_flag,
        double pulseOnTimeMs,
        double pulseOffTimeMs,
        bool pulse_mode,
        const QString& protocol_name
        );

    void fetchHomeDataById(int id);
    bool updateHomeData(
        int id,
        double power980,
        double power1470,
        double timerSec,
        bool timer_reset,
        bool timer_flag,
        double pulseOnTimeMs,
        double pulseOffTimeMs,
        bool pulse_mode,
        const QString& protocol_name
        );

    // Generic Protocol table functions
    bool insertPresetProtocol(
        const QString& tableName,
        int id,
        const QString& name,
        double power980,
        double power1470,
        double timerSec,
        bool timer_reset,
        bool timer_flag,
        double pulseOnTimeMs,
        double pulseOffTimeMs,
        bool pulse_mode,
        double no_protocol_used
        );

    void fetchPresetProtocolById(const QString& tableName, int id);

    // Password table functions
    // Password functions
    bool insertPassword(const QString& loginPass,
                        const QString& userPass,
                        const QString& adminPass);

    void fetchPasswords();

    bool clearPasswordTable();

    bool updatePassword(int id,
                        const QString& newLoginPass,
                        const QString& newUserPass,
                        const QString& newAdminPass);
    bool deletePresetProtocol(const QString& tableName,
                              const QString& name);
    bool updatePresetProtocol(
        const QString& tableName,
        const QString& name,
        double power980,
        double power1470,
        double timerSec,
        bool timer_reset,
        bool timer_flag,
        double pulseOnTimeMs,
        double pulseOffTimeMs,
        bool pulse_mode,
        double no_protocol_used
        );


    void fetchProtocol(const QString& tableName, int id);

    bool addColumn(
        const QString& tableName,
        const QString& columnName,
        const QString& columnType,
        const QString& defaultValue /* optional */
        );
    bool deleteColumnsKeepOnly(
        const QString& tableName,
        const QStringList& keepColumns
        );
    bool renameTable(
        const QString& oldTableName,
        const QString& newTableName
        );
    void printSQLiteVersion();
    bool renameColumn(
        const QString& tableName,
        const QString& oldColumnName,
        const QString& newColumnName
        );
    bool updateSingleColumn(
        const QString& tableName,
        const QString& columnName,
        const QVariant& value,
        int id
        );
    bool saveDeviceSetting(
        int screen_brightness,
        int aiming_beam_intensity,
        int sound_intensity,
        int beep_intensity,
        bool password_enable,
        bool patient_data,
        bool interlock_key,
        bool persistence,
        bool theme,
        bool simpli_advan_mode,
        bool audio_mode,
        int alarm_sec,
        int alarm_joule);
    bool fetchDeviceSetting();

    // Power vs DAC table (CRUD)
    bool insertPowerVsDAC(
        double power,
        int dacA,
        int dacB
        );

    bool updatePowerVsDAC(
        int id,
        int dacA,
        int dacB
        );

    bool deletePowerVsDAC(
        int id
        );

    bool fetchPowerVsDACById(
        int id
        );

    // Optional helper: fetch DAC values using power
    bool fetchDACByPower(
        double power ,
        int diode
        );

    bool populatePowerVsDACTable();

    bool updateDACByPowerAndDiode(
        double power,
        int diode,
        int newDacValue
        );

    bool ensureSystemTimerRow();

    void fetchSystemTimer(int id);

    bool clearUsageNoSurgeryDone(int id);

    bool deletePresetProtocolById(
        const QString& tableName,
        int id);

    int getNextAvailableId(const QString& tableName);

    bool ensurePulseRangeRow();

    bool savePulseRanges();

    bool fetchPulseRanges();



};

#endif // DATABASEINITIALIZER_H
