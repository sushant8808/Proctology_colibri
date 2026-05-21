#ifndef USERDATABASEINITIALIZER_H
#define USERDATABASEINITIALIZER_H

#include <QSqlDatabase>
#include <QVariantMap>
#include <QString>

class UserDatabaseInitializer
{
public:
    bool initialize();

    bool deleteAllUserData();

    bool insertSurgerySummary(
        qint64 surgery_id,
        const QString &protocol_name,
        const QString &start_time,
        double surgery_duration,
        double laser_duration,
        double total_energy,
        double effective_power,
        int fiber_disconnect_count);

    QVariantMap getSurgerySummary(int surgery_id);

    bool deleteSurgerySummary(int surgery_id);

    bool deleteAllSurgerySummary();

private:
    bool createTables();
};


#endif // USERDATABASEINITIALIZER_H
