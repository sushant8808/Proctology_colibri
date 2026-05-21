/****************************************************************************
** Meta object code from reading C++ file 'home.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../home.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'home.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN4HomeE_t {};
} // unnamed namespace

template <> constexpr inline auto Home::qt_create_metaobjectdata<qt_meta_tag_ZN4HomeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Home",
        "switchToLogin",
        "",
        "switchToSetting",
        "on_B2_980sub_clicked",
        "on_B2_980add_clicked",
        "on_B2_1470sub_clicked",
        "on_B2_1470add_clicked",
        "on_L2_980_show_linkActivated",
        "link",
        "on_L2_1470_show_linkActivated",
        "on_L2_energy_show_linkActivated",
        "updatePower1470Label",
        "updatePower980Label",
        "updateTimerLabel",
        "updateJouleLabel",
        "on_B2_timer_on_clicked",
        "on_B2_timer_off_clicked",
        "on_B2_timer_add_clicked",
        "on_B2_timer_sub_clicked",
        "on_L2_timer_show_linkActivated",
        "on_L2_tab_hide_linkActivated",
        "on_T2_home_currentChanged",
        "index",
        "on_B2_pulsemode_stateChanged",
        "arg1",
        "on_L2_on_pulse_show_linkActivated",
        "on_B2_on_time_sub_clicked",
        "on_B2_on_time_add_clicked",
        "on_L2_off_pulse_show_linkActivated",
        "on_B2_off_time_sub_clicked",
        "on_B2_off_time_add_clicked",
        "updatePulseLabels",
        "on_B2_audioalarm_stateChanged",
        "on_L2_alarm_sec_show_linkActivated",
        "on_B2_alarm_sec_sub_clicked",
        "on_B2_alarm_sec_add_clicked",
        "on_L2_alarm_joule_show_linkActivated",
        "on_B2_alarm_joule_sub_clicked",
        "on_B2_alarm_joule_add_clicked",
        "updateAlarmSecLabel",
        "updateAlarmJouleLabel",
        "on_B2_sec_alarm_toggled",
        "checked",
        "on_B2_joule_alarm_toggled",
        "on_B2_sound_clicked",
        "on_B2_brightness_clicked",
        "on_B2_aimingbeam_clicked",
        "on_B2_setting_clicked",
        "on_B2_ready_for_surgery_clicked",
        "updatedatabase",
        "on_L2_energy_linkActivated",
        "on_L2_joules_linkActivated",
        "on_L2_avg_power_linkActivated",
        "on_L2_avg_watts_linkActivated",
        "on_L2_avg_power_show_linkActivated",
        "updateAvgEnergyLabel",
        "on_B2_timer_reset_clicked",
        "on_B2_timer_noreset_clicked",
        "on_pushButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'switchToLogin'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToSetting'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_980sub_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_980add_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470sub_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470add_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_L2_980_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_1470_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_energy_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'updatePower1470Label'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatePower980Label'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateTimerLabel'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateJouleLabel'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_on_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_off_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_add_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_sub_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_L2_timer_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_tab_hide_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_T2_home_currentChanged'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'on_B2_pulsemode_stateChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
        // Slot 'on_L2_on_pulse_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_B2_on_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_on_time_add_clicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_L2_off_pulse_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(29, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_B2_off_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_off_time_add_clicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatePulseLabels'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_audioalarm_stateChanged'
        QtMocHelpers::SlotData<void(int)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
        // Slot 'on_L2_alarm_sec_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_B2_alarm_sec_sub_clicked'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_sec_add_clicked'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_L2_alarm_joule_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_B2_alarm_joule_sub_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_joule_add_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateAlarmSecLabel'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateAlarmJouleLabel'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_sec_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(42, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 43 },
        }}),
        // Slot 'on_B2_joule_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(44, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 43 },
        }}),
        // Slot 'on_B2_sound_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_brightness_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_aimingbeam_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_setting_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_ready_for_surgery_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatedatabase'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_L2_energy_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(51, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_joules_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(52, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_avg_power_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(53, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_avg_watts_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(54, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_L2_avg_power_show_linkActivated'
        QtMocHelpers::SlotData<void(const QString &)>(55, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'updateAvgEnergyLabel'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_reset_clicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_noreset_clicked'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Home, qt_meta_tag_ZN4HomeE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Home::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4HomeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4HomeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN4HomeE_t>.metaTypes,
    nullptr
} };

void Home::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Home *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->switchToLogin(); break;
        case 1: _t->switchToSetting(); break;
        case 2: _t->on_B2_980sub_clicked(); break;
        case 3: _t->on_B2_980add_clicked(); break;
        case 4: _t->on_B2_1470sub_clicked(); break;
        case 5: _t->on_B2_1470add_clicked(); break;
        case 6: _t->on_L2_980_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_L2_1470_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->on_L2_energy_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->updatePower1470Label(); break;
        case 10: _t->updatePower980Label(); break;
        case 11: _t->updateTimerLabel(); break;
        case 12: _t->updateJouleLabel(); break;
        case 13: _t->on_B2_timer_on_clicked(); break;
        case 14: _t->on_B2_timer_off_clicked(); break;
        case 15: _t->on_B2_timer_add_clicked(); break;
        case 16: _t->on_B2_timer_sub_clicked(); break;
        case 17: _t->on_L2_timer_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->on_L2_tab_hide_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->on_T2_home_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_B2_pulsemode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_L2_on_pulse_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->on_B2_on_time_sub_clicked(); break;
        case 23: _t->on_B2_on_time_add_clicked(); break;
        case 24: _t->on_L2_off_pulse_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_B2_off_time_sub_clicked(); break;
        case 26: _t->on_B2_off_time_add_clicked(); break;
        case 27: _t->updatePulseLabels(); break;
        case 28: _t->on_B2_audioalarm_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_L2_alarm_sec_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->on_B2_alarm_sec_sub_clicked(); break;
        case 31: _t->on_B2_alarm_sec_add_clicked(); break;
        case 32: _t->on_L2_alarm_joule_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->on_B2_alarm_joule_sub_clicked(); break;
        case 34: _t->on_B2_alarm_joule_add_clicked(); break;
        case 35: _t->updateAlarmSecLabel(); break;
        case 36: _t->updateAlarmJouleLabel(); break;
        case 37: _t->on_B2_sec_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->on_B2_joule_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 39: _t->on_B2_sound_clicked(); break;
        case 40: _t->on_B2_brightness_clicked(); break;
        case 41: _t->on_B2_aimingbeam_clicked(); break;
        case 42: _t->on_B2_setting_clicked(); break;
        case 43: _t->on_B2_ready_for_surgery_clicked(); break;
        case 44: _t->updatedatabase(); break;
        case 45: _t->on_L2_energy_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 46: _t->on_L2_joules_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 47: _t->on_L2_avg_power_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 48: _t->on_L2_avg_watts_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->on_L2_avg_power_show_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->updateAvgEnergyLabel(); break;
        case 51: _t->on_B2_timer_reset_clicked(); break;
        case 52: _t->on_B2_timer_noreset_clicked(); break;
        case 53: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Home::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Home::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4HomeE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Home::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 54;
    }
    return _id;
}
QT_WARNING_POP
