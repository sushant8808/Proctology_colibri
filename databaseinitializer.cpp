#include "databaseinitializer.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "global.h"

bool DatabaseInitializer::initialize()
{
    return createTables();
}

bool DatabaseInitializer::createTables()
{
    QSqlQuery query(DatabaseManager::instance().db());

    // Password table
    QString createPasswordTable = R"(
    CREATE TABLE IF NOT EXISTS password (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        login_pass TEXT,
        user_pass TEXT,
        admin_pass TEXT
    )
    )";
    if (!query.exec(createPasswordTable)) {
        //qDebug() << "Failed to create password table:" << query.lastError().text();
    }

    // Home table
    QString createHomeTable = R"(
    CREATE TABLE IF NOT EXISTS home (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        "980_power" REAL,
        "1470_power" REAL,
        timer_sec REAL,
        timer_reset REAL,
        timer_flag REAL,
        pulse_on_time_ms REAL,
        pulse_off_time_ms REAL,
        pulse_mode REAL,
        protocol_name TEXT
    )
    )";

    if (!query.exec(createHomeTable)) {
        //qDebug() << "Failed to create home table:" << query.lastError().text();
    }

    // Preset protocol table
    QString createPresetProtocolTable = R"(
    CREATE TABLE IF NOT EXISTS preset_protocol_general (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        "980_power" REAL,
        "1470_power" REAL,
        timer_sec REAL,
        timer_reset REAL,
        timer_flag REAL,
        pulse_on_time_ms REAL,
        pulse_off_time_ms REAL,
        pulse_mode REAL,
        no_protocol_used REAL
    )
    )";

    if (!query.exec(createPresetProtocolTable)) {
        //qDebug() << "Failed to create preset_protocol_general table:" << query.lastError().text();
    }

    // Preset Protocol ENT
    QString createPresetProtocolENT = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_ent (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolENT)) {
        //qDebug() << "Failed to create preset_protocol_ent table:" << query.lastError().text();
    }

    // Preset Protocol Gynecology
    QString createPresetProtocolGynaecology = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_gynaecology (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolGynaecology)) {
        //qDebug() << "Failed to create preset_protocol_gynaecology table:" << query.lastError().text();
    }

    // Preset Protocol Neurology
    QString createPresetProtocolNeurology = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_neurology (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolNeurology)) {
        //qDebug() << "Failed to create preset_protocol_neurology table:" << query.lastError().text();
    }

    // Preset Protocol Therapy
    QString createPresetProtocolTherapy = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_therapy (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolTherapy)) {
        //qDebug() << "Failed to create preset_protocol_therapy table:" << query.lastError().text();
    }

    // Preset Protocol Urology
    QString createPresetProtocolUrology = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_urology (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolUrology)) {
        //qDebug() << "Failed to create preset_protocol_urology table:" << query.lastError().text();
    }

    // Preset Protocol Vascular
    QString createPresetProtocolVascular = R"(
CREATE TABLE IF NOT EXISTS preset_protocol_vascular (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL
)
)";
    if(!query.exec(createPresetProtocolVascular)) {
        //qDebug() << "Failed to create preset_protocol_vascular table:" << query.lastError().text();
    }

    // Protocol Custom
    QString createProtocolCustom = R"(
CREATE TABLE IF NOT EXISTS protocol_custom (
    id INTEGER PRIMARY KEY,
    name TEXT,
    "980_power" REAL,
    "1470_power" REAL,
    timer_sec REAL,
    timer_reset REAL,
    timer_flag REAL,
    pulse_on_time_ms REAL,
    pulse_off_time_ms REAL,
    pulse_mode REAL,
    no_protocol_used REAL,
    favourite REAL
)
)";
    if(!query.exec(createProtocolCustom)) {
        //qDebug() << "Failed to create protocol_custom table:" << query.lastError().text();
    }

    // Protocol Favourites
    QString createProtocolFavourites = R"(
CREATE TABLE IF NOT EXISTS protocol_favourites (
    id INTEGER,
    name TEXT,
    source_table TEXT,
    PRIMARY KEY (id, source_table)
)
)";
    if(!query.exec(createProtocolFavourites)) {
        //qDebug() << "Failed to create protocol_favourites table:" << query.lastError().text();
    }

    // Device Settings
    QString createDeviceSetting = R"(
CREATE TABLE IF NOT EXISTS device_setting (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    screen_brightness INTEGER,
    aiming_beam_intensity INTEGER,
    sound_intensity INTEGER,
    beep_intensity INTEGER,
    password_enable INTEGER,
    patient_data INTEGER,
    interlock_key INTEGER,
    persistence INTEGER,
    theme INTEGER,
    simpli_advan_mode INTEGER,
    audio_mode INTEGER,
    alarm_sec INTEGER,
    alarm_joule INTEGER
)
)";
    if (!query.exec(createDeviceSetting)) {
        //qDebug() << "Failed to create device_setting table:"
        // << query.lastError().text();
    }

    QString createPowerVsDACTable = R"(
    CREATE TABLE IF NOT EXISTS Power_Vs_DAC_Table (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        power REAL NOT NULL,
        DAC_A INTEGER,
        DAC_B INTEGER
    )
)";

    if (!query.exec(createPowerVsDACTable)) {
        // qDebug() << "Failed to create Power_Vs_DAC_Table:"
        //          << query.lastError().text();
    }

    QString createTimerTable = R"(
    CREATE TABLE IF NOT EXISTS system_timer (
        id INTEGER PRIMARY KEY AUTOINCREMENT,

        total_system_minutes INTEGER DEFAULT 0,

        diode_1470_ms INTEGER DEFAULT 0,
        diode_980_ms INTEGER DEFAULT 0,

        total_no_surgery_done INTEGER DEFAULT 0,
        usage_no_surgery_done INTEGER DEFAULT 0
    )
)";

    if (!query.exec(createTimerTable)) {
        //qDebug() << "Failed to create system_timer table:" << query.lastError().text();
    }

    QString createPulseRangeTable = R"(
CREATE TABLE IF NOT EXISTS pulse_range_setting (
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    min_pulse_width INTEGER,
    max_pulse_width INTEGER
)
)";
    if (!query.exec(createPulseRangeTable)) {
        return false;
    }



    return true;
}

// Insert data into home table
bool DatabaseInitializer::insertHomeData(
    double power980,
    double power1470,
    double timerSec,
    bool timer_reset,
    bool timer_flag,
    double pulseOnTimeMs,
    double pulseOffTimeMs,
    bool pulse_mode,
    const QString& protocol_name
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        INSERT INTO home (
            "980_power","1470_power",
            timer_sec,timer_reset,timer_flag,
            pulse_on_time_ms,pulse_off_time_ms,pulse_mode,
            protocol_name
        ) VALUES (
            :power980,:power1470,
            :timerSec,:timerReset,:timerFlag,
            :pulseOnTimeMs,:pulseOffTimeMs,:pulseMode,
            :protocolName
        )
    )");

    query.bindValue(":power980", power980);
    query.bindValue(":power1470", power1470);
    query.bindValue(":timerSec", timerSec);
    query.bindValue(":timerReset", timer_reset ? 1 : 0);
    query.bindValue(":timerFlag", timer_flag ? 1 : 0);
    query.bindValue(":pulseOnTimeMs", pulseOnTimeMs);
    query.bindValue(":pulseOffTimeMs", pulseOffTimeMs);
    query.bindValue(":pulseMode", pulse_mode ? 1 : 0);
    query.bindValue(":protocolName", protocol_name);

    if (!query.exec()) {
        //qDebug() << "Insert into home failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseInitializer::insertPresetProtocol(
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
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = QString(R"(
    INSERT INTO %1 (
        id,
        name,"980_power","1470_power",
        timer_sec,timer_reset,timer_flag,
        pulse_on_time_ms,pulse_off_time_ms,
        pulse_mode,no_protocol_used
    ) VALUES (
        :id,
        :name,:power980,:power1470,
        :timerSec,:timerReset,:timerFlag,
        :pulseOnTimeMs,:pulseOffTimeMs,
        :pulseMode,:no_protocol_used
    )
)").arg(tableName);

    query.prepare(sql);
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":power980", power980);
    query.bindValue(":power1470", power1470);
    query.bindValue(":timerSec", timerSec);
    query.bindValue(":timerReset", timer_reset ? 1 : 0);
    query.bindValue(":timerFlag", timer_flag ? 1 : 0);
    query.bindValue(":pulseOnTimeMs", pulseOnTimeMs);
    query.bindValue(":pulseOffTimeMs", pulseOffTimeMs);
    query.bindValue(":pulseMode", pulse_mode ? 1 : 0);
    query.bindValue(":no_protocol_used", no_protocol_used);

    if(!query.exec()) {
        //qDebug() << "Insert into" << tableName << "failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Inserted protocol into" << tableName << ":" << name;
    return true;
}

bool DatabaseInitializer::updatePresetProtocol(
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
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = QString(R"(
        UPDATE %1 SET
            "980_power" = :power980,
            "1470_power" = :power1470,
            timer_sec = :timerSec,
            timer_reset = :timerReset,
            timer_flag = :timerFlag,
            pulse_on_time_ms = :pulseOnTimeMs,
            pulse_off_time_ms = :pulseOffTimeMs,
            pulse_mode = :pulseMode,
            no_protocol_used = :no_protocol_used
        WHERE name = :name
    )").arg(tableName);

    query.prepare(sql);

    query.bindValue(":name", name);
    query.bindValue(":power980", power980);
    query.bindValue(":power1470", power1470);
    query.bindValue(":timerSec", timerSec);
    query.bindValue(":timerReset", timer_reset ? 1 : 0);
    query.bindValue(":timerFlag", timer_flag ? 1 : 0);
    query.bindValue(":pulseOnTimeMs", pulseOnTimeMs);
    query.bindValue(":pulseOffTimeMs", pulseOffTimeMs);
    query.bindValue(":pulseMode", pulse_mode ? 1 : 0);
    query.bindValue(":no_protocol_used", no_protocol_used);

    if (!query.exec()) {
        //qDebug() << "Update failed for" << tableName << ":" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        //qDebug() << "⚠ No protocol updated (name not found):" << name;
        return false;
    }

    //qDebug() << "✅ Updated protocol in" << tableName << ":" << name;
    return true;
}

bool DatabaseInitializer::deletePresetProtocol(
    const QString& tableName,
    const QString& name
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = QString(R"(
        DELETE FROM %1 WHERE name = :name
    )").arg(tableName);

    query.prepare(sql);
    query.bindValue(":name", name);

    if (!query.exec()) {
        //qDebug() << "Delete failed from" << tableName << ":" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        //qDebug() << "⚠ No protocol deleted (name not found):" << name;
        return false;
    }

    //qDebug() << "🗑 Deleted protocol from" << tableName << ":" << name;
    return true;
}

bool DatabaseInitializer::deletePresetProtocolById(
    const QString& tableName,
    int id
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = QString(R"()
                      "DELETE FROM %1 WHERE id = :id"
                      )").arg(tableName);

    query.prepare(sql);
    query.bindValue(":id", id);

    if (!query.exec())
        return false;

    return query.numRowsAffected() > 0;
}



void DatabaseInitializer::fetchPresetProtocolById(const QString& tableName, int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(QString("SELECT * FROM %1 WHERE id = :id").arg(tableName));
    query.bindValue(":id", id);

    if(!query.exec()) {
        //qDebug() << "Fetch from" << tableName << "by ID failed:" << query.lastError().text();
        return;
    }

    if(query.next()) {
        protocolName = query.value("name").toString();
        power980 = query.value("980_power").toDouble();
        power1470 = query.value("1470_power").toDouble();
        TimerSec = query.value("timer_sec").toDouble();
        timer_reset = query.value("timer_reset").toBool();
        timerFlag = query.value("timer_flag").toBool();
        pulseOnTime = query.value("pulse_on_time_ms").toDouble();
        pulseOffTime = query.value("pulse_off_time_ms").toDouble();
        pulseMode = query.value("pulse_mode").toBool();
        no_protocol_used = query.value("no_protocol_used").toDouble();

        //qDebug() << "Fetched from" << tableName << "ID:" << id
        // << "| Name:" << protocolName
        // << "| 980_power:" << power980
        // << "| 1470_power:" << power1470
        // << "| Timer(sec):" << TimerSec
        // << "| Timer Reset:" << timer_reset
        // << "| Timer Flag:" << timerFlag
        // << "| Pulse ON(ms):" << pulseOnTime
        // << "| Pulse OFF(ms):" << pulseOffTime
        // << "| Pulse Mode:" << pulseMode
        // << "| no_protocol_used:" << no_protocol_used;
    } else {
        //qDebug() << "No record found in" << tableName << "with ID:" << id;
    }
}


// Fetch home data by ID
void DatabaseInitializer::fetchHomeDataById(int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare("SELECT * FROM home WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        //qDebug() << "Fetch home by ID failed:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        power980 = query.value("980_power").toDouble();
        power1470 = query.value("1470_power").toDouble();
        TimerSec = query.value("timer_sec").toDouble();
        timer_reset = query.value("timer_reset").toBool();
        timerFlag = query.value("timer_flag").toBool();
        pulseOnTime = query.value("pulse_on_time_ms").toDouble();
        pulseOffTime = query.value("pulse_off_time_ms").toDouble();
        pulseMode = query.value("pulse_mode").toBool();
        protocolName = query.value("protocol_name").toString();

        //qDebug() << "Fetched Home ID:" << id
        // << "| 980_power:" << power980
        // << "| 1470_power:" << power1470
        // << "| Timer(sec):" << TimerSec
        // << "| Timer Reset:" << timer_reset
        // << "| Timer Flag:" << timerFlag
        // << "| Pulse ON(ms):" << pulseOnTime
        // << "| Pulse OFF(ms):" << pulseOffTime
        // << "| Pulse Mode:" << pulseMode
        // << "| Protocol Name:" << protocolName;
    } else {
        //qDebug() << "No home record found with ID:" << id;
    }
}


// Update home data
bool DatabaseInitializer::updateHomeData(
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
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        UPDATE home SET
            "980_power" = :power980,
            "1470_power" = :power1470,
            timer_sec = :timerSec,
            timer_reset = :timerReset,
            timer_flag = :timerFlag,
            pulse_on_time_ms = :pulseOnTimeMs,
            pulse_off_time_ms = :pulseOffTimeMs,
            pulse_mode = :pulseMode,
            protocol_name = :protocolName
        WHERE id = :id
    )");

    query.bindValue(":power980", power980);
    query.bindValue(":power1470", power1470);
    query.bindValue(":timerSec", timerSec);
    query.bindValue(":timerReset", timer_reset ? 1 : 0);
    query.bindValue(":timerFlag", timer_flag ? 1 : 0);
    query.bindValue(":pulseOnTimeMs", pulseOnTimeMs);
    query.bindValue(":pulseOffTimeMs", pulseOffTimeMs);
    query.bindValue(":pulseMode", pulse_mode ? 1 : 0);
    query.bindValue(":protocolName", protocol_name);
    query.bindValue(":id", id);

    if (!query.exec()) {
        //qDebug() << "Update home failed:" << query.lastError().text();
        return false;
    }

    return true;
}

void DatabaseInitializer::fetchProtocol(const QString& tableName, int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(QString("SELECT * FROM %1 WHERE id = :id").arg(tableName));
    query.bindValue(":id", id);

    if(!query.exec()) {
        //qDebug() << "Fetch from" << tableName << "failed:" << query.lastError().text();
        return;
    }

    if(query.next()) {
        protocolName = query.value("name").toString();
        power980 = query.value("980_power").toDouble();
        power1470 = query.value("1470_power").toDouble();
        TimerSec = query.value("timer_sec").toInt();
        timer_reset = query.value("timer_reset").toBool();
        timerFlag = query.value("timer_flag").toBool();
        pulseOnTime = query.value("pulse_on_time_ms").toInt();
        pulseOffTime = query.value("pulse_off_time_ms").toInt();
        pulseMode = query.value("pulse_mode").toBool();

        //qDebug() << "Loaded protocol:" << protocolName;
    }
}

// Password functions
bool DatabaseInitializer::insertPassword(const QString& loginPass,
                                         const QString& userPass,
                                         const QString& adminPass)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        INSERT INTO password (login_pass, user_pass, admin_pass)
        VALUES (:login_pass, :userPass, :adminPass)
    )");

    query.bindValue(":login_pass", loginPass);
    query.bindValue(":userPass", userPass);
    query.bindValue(":adminPass", adminPass);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool DatabaseInitializer::clearPasswordTable()
{
    QSqlQuery query(DatabaseManager::instance().db());

    // Delete all rows
    if (!query.exec("DELETE FROM password")) {
        qDebug() << "Delete failed:"
                 << query.lastError().text();
        return false;
    }

    // Reset autoincrement counter
    if (!query.exec("DELETE FROM sqlite_sequence WHERE name='password'")) {
        qDebug() << "Reset sequence failed:"
                 << query.lastError().text();
        return false;
    }

    qDebug() << "Table cleared and ID reset";
    return true;
}

void DatabaseInitializer::fetchPasswords()
{
    QSqlQuery query(DatabaseManager::instance().db());

    if (!query.exec("SELECT * FROM password")) {
        return;
    }

    while (query.next()) {
        int id = query.value("id").toInt();
        loginpass = query.value("login_pass").toString();
        userpass  = query.value("user_pass").toString();
        adminpass = query.value("admin_pass").toString();
    }
}

bool DatabaseInitializer::updatePassword(int id,
                                         const QString& newLoginPass,
                                         const QString& newUserPass,
                                         const QString& newAdminPass)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        UPDATE password SET
            login_pass = :loginPass,
            user_pass  = :userPass,
            admin_pass = :adminPass
        WHERE id = :id
    )");

    query.bindValue(":loginPass", newLoginPass);
    query.bindValue(":userPass", newUserPass);
    query.bindValue(":adminPass", newAdminPass);
    query.bindValue(":id", id);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool DatabaseInitializer::addColumn(
    const QString& tableName,
    const QString& columnName,
    const QString& columnType,
    const QString& defaultValue /* optional */
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql;

    if (defaultValue.isEmpty()) {
        sql = QString("ALTER TABLE %1 ADD COLUMN %2 %3")
        .arg(tableName, columnName, columnType);
    } else {
        sql = QString("ALTER TABLE %1 ADD COLUMN %2 %3 DEFAULT %4")
        .arg(tableName, columnName, columnType, defaultValue);
    }

    if (!query.exec(sql)) {
        //qDebug() << "Add column failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Column added:" << columnName;
    return true;
}

bool DatabaseInitializer::deleteColumnsKeepOnly(
    const QString& tableName,
    const QStringList& keepColumns
    )
{
    QSqlDatabase db = DatabaseManager::instance().db();
    QSqlQuery query(db);


    if (!db.transaction())
        return false;

    // Step 1: Read schema
    query.exec(QString("PRAGMA table_info(%1)").arg(tableName));

    struct Column {
        QString name;
        QString type;
        bool notNull;
        QString defValue;
        bool pk;
    };

    QList<Column> columns;

    while (query.next()) {
        Column c;
        c.name = query.value("name").toString();
        c.type = query.value("type").toString();
        c.notNull = query.value("notnull").toInt();
        c.defValue = query.value("dflt_value").toString();
        c.pk = query.value("pk").toInt();
        columns << c;
    }

    // Step 2: Build CREATE TABLE
    QString tempTable = tableName + "_temp";
    QStringList defs;

    for (const Column& c : columns) {
        if (!keepColumns.contains(c.name)) continue;

        QString d = c.name + " " + c.type;
        if (c.notNull) d += " NOT NULL";
        if (!c.defValue.isEmpty()) d += " DEFAULT " + c.defValue;
        if (c.pk) d += " PRIMARY KEY";

        defs << d;
    }

    if (defs.isEmpty()) {
        db.rollback();
        return false;
    }

    if (!query.exec(
            QString("CREATE TABLE %1 (%2)")
                .arg(tempTable, defs.join(","))))
    {
        //qDebug() << query.lastError();
        db.rollback();
        return false;
    }

    // Step 3: Copy data
    QString cols = keepColumns.join(",");
    if (!query.exec(
            QString("INSERT INTO %1 (%2) SELECT %2 FROM %3")
                .arg(tempTable, cols, tableName)))
    {
        //qDebug() << query.lastError();
        db.rollback();
        return false;
    }

    // Step 4: Replace table
    query.exec(QString("DROP TABLE %1").arg(tableName));
    query.exec(QString("ALTER TABLE %1 RENAME TO %2")
                   .arg(tempTable, tableName));

    db.commit();
    return true;
}


bool DatabaseInitializer::renameTable(
    const QString& oldTableName,
    const QString& newTableName
    )
{
    QSqlQuery query(DatabaseManager::instance().db());


    QString sql = QString(
                      "ALTER TABLE %1 RENAME TO %2"
                      ).arg(oldTableName, newTableName);

    if (!query.exec(sql)) {
        //qDebug() << "Rename table failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Table renamed from"
    // << oldTableName
    // << "to"
    // << newTableName;

    return true;
}

void DatabaseInitializer::printSQLiteVersion()
{
    QSqlQuery query(DatabaseManager::instance().db());
    query.exec("SELECT sqlite_version()");

    if (query.next()) {
        //qDebug() << "SQLite version:" << query.value(0).toString();
    }
}

bool DatabaseInitializer::renameColumn(
    const QString& tableName,
    const QString& oldColumnName,
    const QString& newColumnName
    )
{
    QSqlQuery query(DatabaseManager::instance().db());


    QString sql = QString(
                      "ALTER TABLE %1 RENAME COLUMN %2 TO %3"
                      ).arg(tableName, oldColumnName, newColumnName);

    if (!query.exec(sql)) {
        //qDebug() << "Rename column failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Column renamed in"
    // << tableName
    // << ":"
    // << oldColumnName
    // << "→"
    // << newColumnName;

    return true;
}

bool DatabaseInitializer::updateSingleColumn(
    const QString& tableName,
    const QString& columnName,
    const QVariant& value,
    int id
    )
{
    QSqlQuery query(DatabaseManager::instance().db());


    QString sql = QString(
                      "UPDATE %1 SET %2 = :value WHERE id = :id"
                      ).arg(tableName, columnName);

    query.prepare(sql);
    query.bindValue(":value", value);
    query.bindValue(":id", id);

    if (!query.exec()) {
        //qDebug() << "❌ Update failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Updated" << columnName << "in" << tableName;
    return true;
}

bool DatabaseInitializer::saveDeviceSetting(
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
    int alarm_joule
    )
{
    QSqlQuery query(DatabaseManager::instance().db());


    query.exec("SELECT COUNT(*) FROM device_setting");
    query.next();
    bool exists = query.value(0).toInt() > 0;

    if (exists) {
        query.prepare(R"(
            UPDATE device_setting SET
                screen_brightness      = :screen_brightness,
                aiming_beam_intensity  = :aiming_beam_intensity,
                sound_intensity        = :sound_intensity,
                beep_intensity         = :beep_intensity,
                password_enable        = :password_enable,
                patient_data           = :patient_data,
                interlock_key          = :interlock_key,
                persistence            = :persistence,
                theme                  = :theme,
                simpli_advan_mode      = :simpli_advan_mode,
                audio_mode             = :audio_mode,
                alarm_sec              = :alarm_sec,
                alarm_joule            = :alarm_joule
            WHERE id = 1
        )");
    } else {
        query.prepare(R"(
            INSERT INTO device_setting (
                screen_brightness,
                aiming_beam_intensity,
                sound_intensity,
                beep_intensity,
                password_enable,
                patient_data,
                interlock_key,
                persistence,
                theme,
                simpli_advan_mode,
                audio_mode,
                alarm_sec,
                alarm_joule
            ) VALUES (
                :screen_brightness,
                :aiming_beam_intensity,
                :sound_intensity,
                :beep_intensity,
                :password_enable,
                :patient_data,
                :interlock_key,
                :persistence,
                :theme,
                :simpli_advan_mode,
                :audio_mode,
                :alarm_sec,
                :alarm_joule
            )
        )");
    }

    query.bindValue(":screen_brightness", screen_brightness);
    query.bindValue(":aiming_beam_intensity", aiming_beam_intensity);
    query.bindValue(":sound_intensity", sound_intensity);
    query.bindValue(":beep_intensity", beep_intensity);
    query.bindValue(":password_enable", password_enable);
    query.bindValue(":patient_data", patient_data);
    query.bindValue(":interlock_key", interlock_key);
    query.bindValue(":persistence", persistence);
    query.bindValue(":theme", theme);
    query.bindValue(":simpli_advan_mode", simpli_advan_mode);
    query.bindValue(":audio_mode", audio_mode);
    query.bindValue(":alarm_sec", alarm_sec);
    query.bindValue(":alarm_joule", alarm_joule);

    if (!query.exec()) {
        //qDebug() << "❌ Save device_setting failed:" << query.lastError().text();
        return false;
    }

    //qDebug() << "✅ Device settings saved";
    return true;
}


bool DatabaseInitializer::fetchDeviceSetting()
{
    QSqlQuery query(DatabaseManager::instance().db());


    if (!query.exec("SELECT * FROM device_setting LIMIT 1")) {
        //qDebug() << "❌ Fetch device_setting failed:"
        // << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        //qDebug() << "⚠ No device_setting row found";
        return false;
    }

    brightnessIntensity   = query.value("screen_brightness").toInt();
    aimingbeamIntensity   = query.value("aiming_beam_intensity").toInt();
    soundIntensity   = query.value("sound_intensity").toInt();
    beepIntensity   = query.value("beep_intensity").toInt();

    password_enable       = query.value("password_enable").toBool();
    patient_data          = query.value("patient_data").toBool();
    interlock_key         = query.value("interlock_key").toBool();
    persistence_data      = query.value("persistence").toBool();

    dark                  = query.value("theme").toBool();
    simpliAdvanMode       = query.value("simpli_advan_mode").toBool();
    audioMode             = query.value("audio_mode").toBool();

    alarmSeconds          = query.value("alarm_sec").toInt();
    alarmJoules           = query.value("alarm_joule").toInt();

    //qDebug() << "✅ Device settings loaded into globals";
    return true;
}

bool DatabaseInitializer::insertPowerVsDAC(
    double power,
    int dacA,
    int dacB
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = R"(
        INSERT INTO Power_Vs_DAC_Table (power, DAC_A, DAC_B)
        VALUES (:power, :dacA, :dacB)
    )";

    query.prepare(sql);
    query.bindValue(":power", power);
    query.bindValue(":dacA", dacA);
    query.bindValue(":dacB", dacB);

    if (!query.exec()) {
        // qDebug() << "Insert PowerVsDAC failed:" << query.lastError().text();
        return false;
    }

    return true;
}
bool DatabaseInitializer::updatePowerVsDAC(
    int id,
    int dacA,
    int dacB
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = R"(
        UPDATE Power_Vs_DAC_Table
        SET DAC_A = :dacA,
            DAC_B = :dacB
        WHERE id = :id
    )";

    query.prepare(sql);
    query.bindValue(":dacA", dacA);
    query.bindValue(":dacB", dacB);
    query.bindValue(":id", id);

    if (!query.exec()) {
        // qDebug() << "Update PowerVsDAC failed:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        // qDebug() << "No row updated for ID:" << id;
        return false;
    }

    return true;
}
bool DatabaseInitializer::deletePowerVsDAC(int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = R"(
        DELETE FROM Power_Vs_DAC_Table
        WHERE id = :id
    )";

    query.prepare(sql);
    query.bindValue(":id", id);

    if (!query.exec()) {
        // qDebug() << "Delete PowerVsDAC failed:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        // qDebug() << "No row deleted for ID:" << id;
        return false;
    }

    return true;
}
bool DatabaseInitializer::fetchPowerVsDACById(int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        SELECT power, DAC_A, DAC_B
        FROM Power_Vs_DAC_Table
        WHERE id = :id
    )");

    query.bindValue(":id", id);

    if (!query.exec()) {
        // qDebug() << "Fetch PowerVsDAC failed:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        // qDebug() << "No PowerVsDAC found for ID:" << id;
        return false;
    }

    powerValue = query.value("power").toDouble();
    dacAValue  = query.value("DAC_A").toInt();
    dacBValue  = query.value("DAC_B").toInt();

    return true;
}
bool DatabaseInitializer::fetchDACByPower(double power, int diode)
{
    QSqlQuery query(DatabaseManager::instance().db());

    // Fetch the row for the given power
    query.prepare(R"(
        SELECT DAC_A, DAC_B
        FROM Power_Vs_DAC_Table
        WHERE power = :power
    )");

    query.bindValue(":power", power);

    if (!query.exec() || !query.next())
        return false;

    // Only update the DAC value for the requested diode
    if(diode == 1470)
        dacAValue = query.value("DAC_A").toInt();  // 1470 nm
    else if(diode == 980)
        dacBValue = query.value("DAC_B").toInt();  // 980 nm
    else
        return false;  // unknown diode

    return true;
}


bool DatabaseInitializer::populatePowerVsDACTable()
{
    QSqlDatabase db = DatabaseManager::instance().db();
    QSqlQuery query(db);

    db.transaction();   // faster + safer

    QString sql = R"(
        INSERT INTO Power_Vs_DAC_Table (power, DAC_A, DAC_B)
        VALUES (:power, :dacA, :dacB)
    )";
    query.prepare(sql);

    auto insertRow = [&](double power)
    {
        int dac = static_cast<int>((power / 15.0) * 35000.0);

        query.bindValue(":power", power);
        query.bindValue(":dacA", dac);
        query.bindValue(":dacB", dac);

        if (!query.exec()) {
            // qDebug() << "Insert failed at power:" << power << query.lastError();
            return false;
        }
        return true;
    };

    // 0.0 → 1.0 (step 0.1)
    for (double p = 0.0; p <= 1.0001; p += 0.1) {
        if (!insertRow(p)) goto rollback;
    }

    // 1.0 → 3.0 (step 0.2)
    for (double p = 1.2; p <= 3.0001; p += 0.2) {
        if (!insertRow(p)) goto rollback;
    }

    // 3.0 → 15.0 (step 0.5)
    for (double p = 3.5; p <= 15.0001; p += 0.5) {
        if (!insertRow(p)) goto rollback;
    }

    db.commit();
    return true;

rollback:
    db.rollback();
    return false;
}


bool DatabaseInitializer::updateDACByPowerAndDiode(
    double power,
    int diode,
    int newDacValue
    )
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql;

    // Decide which column to update
    if (diode == 1470)
    {
        sql = R"(
            UPDATE Power_Vs_DAC_Table
            SET DAC_A = :dacValue
            WHERE power = :power
        )";
    }
    else if (diode == 980)
    {
        sql = R"(
            UPDATE Power_Vs_DAC_Table
            SET DAC_B = :dacValue
            WHERE power = :power
        )";
    }
    else
    {
        return false; // invalid diode
    }

    query.prepare(sql);
    query.bindValue(":dacValue", newDacValue);
    query.bindValue(":power", power);

    if (!query.exec())
    {
        // qDebug() << "Update DAC by power failed:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0)
    {
        // qDebug() << "No row found for power:" << power;
        return false;
    }

    return true;
}

bool DatabaseInitializer::ensureSystemTimerRow()
{
    QSqlQuery query(DatabaseManager::instance().db());

    if (!query.exec("SELECT COUNT(*) FROM system_timer"))
        return false;

    if (query.next() && query.value(0).toInt() == 0)
    {
        QSqlQuery insertQuery(DatabaseManager::instance().db());

        insertQuery.prepare(R"(
            INSERT INTO system_timer (
                total_system_minutes,
                diode_1470_ms,
                diode_980_ms
            ) VALUES (
                0, 0, 0
            )
        )");

        if (!insertQuery.exec())
            return false;
    }

    return true;
}


void DatabaseInitializer::fetchSystemTimer(int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare("SELECT * FROM system_timer WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec())
    {
        qDebug() << "fetchSystemTimer failed:" << query.lastError().text();
        return;
    }

    if (query.next())
    {
        g_totalSystemMinutes = query.value("total_system_minutes").toInt();

        g_diode1470Ms = query.value("diode_1470_ms").toLongLong();
        g_diode980Ms  = query.value("diode_980_ms").toLongLong();

        // ✅ NEW FIELDS
        g_totalNoSurgeryDone = query.value("total_no_surgery_done").toInt();
        g_usageNoSurgeryDone = query.value("usage_no_surgery_done").toInt();
    }
}

bool DatabaseInitializer::clearUsageNoSurgeryDone(int id)
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        UPDATE system_timer
        SET usage_no_surgery_done = 0
        WHERE id = :id
    )");

    query.bindValue(":id", id);

    if (!query.exec())
    {
        qDebug() << "clearUsageNoSurgeryDone failed:"
                 << query.lastError().text();
        return false;
    }

    qDebug() << "Rows affected:"
             << query.numRowsAffected();

    // Optional: also reset global variable
    g_usageNoSurgeryDone = 0;

    return true;
}

int DatabaseInitializer::getNextAvailableId(const QString& tableName)
{
    QSqlQuery query(DatabaseManager::instance().db());

    QString sql = QString(
                      "SELECT MIN(t1.id + 1) AS next_id "
                      "FROM %1 t1 "
                      "LEFT JOIN %1 t2 ON t1.id + 1 = t2.id "
                      "WHERE t2.id IS NULL"
                      ).arg(tableName);

    if (!query.exec(sql))
        return 1;

    if (query.next())
    {
        int nextId = query.value(0).toInt();

        if (nextId == 0)
            return 1;

        return nextId;
    }

    return 1;
}

bool DatabaseInitializer::ensurePulseRangeRow()
{
    QSqlQuery query(DatabaseManager::instance().db());

    if (!query.exec("SELECT COUNT(*) FROM pulse_range_setting"))
        return false;

    if (query.next() && query.value(0).toInt() == 0)
    {
        QSqlQuery insert(DatabaseManager::instance().db());

        insert.prepare(R"(
            INSERT INTO pulse_range_setting (
                min_pulse_width,
                max_pulse_width
            ) VALUES (
                50,
                12000000
            )
        )");

        return insert.exec();
    }

    return true;
}

bool DatabaseInitializer::savePulseRanges()
{
    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(R"(
        UPDATE pulse_range_setting SET
            min_pulse_width = :minPulse,
            max_pulse_width = :maxPulse
        WHERE id = 1
    )");

    query.bindValue(":minPulse", pulseMinLimit);
    query.bindValue(":maxPulse", pulseMaxLimit);

    return query.exec();
}

bool DatabaseInitializer::fetchPulseRanges()
{
    QSqlQuery query(DatabaseManager::instance().db());

    if (!query.exec("SELECT * FROM pulse_range_setting WHERE id = 1"))
        return false;

    if (!query.next())
        return false;

    pulseMinLimit = query.value("min_pulse_width").toInt();
    pulseMaxLimit = query.value("max_pulse_width").toInt();

    return true;
}

