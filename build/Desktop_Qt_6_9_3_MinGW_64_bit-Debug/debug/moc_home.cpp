/****************************************************************************
** Meta object code from reading C++ file 'home.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../home.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'home.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
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
        "switchTosurgerydata",
        "on_B2_980sub_clicked",
        "on_B2_980add_clicked",
        "on_B2_1470sub_clicked",
        "on_B2_1470add_clicked",
        "updatePower1470Label",
        "updatePower980Label",
        "updateTimerLabel",
        "updateJouleLabel",
        "on_B2_timer_on_clicked",
        "on_B2_timer_off_clicked",
        "on_B2_timer_add_clicked",
        "on_B2_timer_sub_clicked",
        "on_B2_pulsemode_stateChanged",
        "arg1",
        "on_B2_on_time_sub_clicked",
        "on_B2_on_time_add_clicked",
        "on_B2_off_time_sub_clicked",
        "on_B2_off_time_add_clicked",
        "updatePulseLabels",
        "on_B2_audioalarm_stateChanged",
        "on_B2_alarm_sec_sub_clicked",
        "on_B2_alarm_sec_add_clicked",
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
        "updateAvgEnergyLabel",
        "on_B2_timer_reset_clicked",
        "on_B2_timer_noreset_clicked",
        "setTimerResetState",
        "reset",
        "updateFromGlobals",
        "openProtocolSelection",
        "update_B2_timer_on",
        "update_B2_timer_off",
        "on_B2_modify_protocol_clicked",
        "switchTonewprotocol",
        "markProtocolModified",
        "fromFunction",
        "updateProtocolLabel",
        "getMaxLimit"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'switchToLogin'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToSetting'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchTosurgerydata'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_980sub_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_980add_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470sub_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470add_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatePower1470Label'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatePower980Label'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateTimerLabel'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateJouleLabel'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_on_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_off_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_add_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_sub_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_pulsemode_stateChanged'
        QtMocHelpers::SlotData<void(int)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Slot 'on_B2_on_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_on_time_add_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_off_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_off_time_add_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatePulseLabels'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_audioalarm_stateChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Slot 'on_B2_alarm_sec_sub_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_sec_add_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_joule_sub_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_joule_add_clicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateAlarmSecLabel'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateAlarmJouleLabel'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_sec_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 32 },
        }}),
        // Slot 'on_B2_joule_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 32 },
        }}),
        // Slot 'on_B2_sound_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_brightness_clicked'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_aimingbeam_clicked'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_setting_clicked'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_ready_for_surgery_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updatedatabase'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateAvgEnergyLabel'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_reset_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_noreset_clicked'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setTimerResetState'
        QtMocHelpers::SlotData<void(bool)>(43, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 44 },
        }}),
        // Slot 'updateFromGlobals'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'openProtocolSelection'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'update_B2_timer_on'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'update_B2_timer_off'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_modify_protocol_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchTonewprotocol'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'markProtocolModified'
        QtMocHelpers::SlotData<void(QString)>(51, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 52 },
        }}),
        // Slot 'updateProtocolLabel'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getMaxLimit'
        QtMocHelpers::SlotData<int()>(54, 2, QMC::AccessPrivate, QMetaType::Int),
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
        case 2: _t->switchTosurgerydata(); break;
        case 3: _t->on_B2_980sub_clicked(); break;
        case 4: _t->on_B2_980add_clicked(); break;
        case 5: _t->on_B2_1470sub_clicked(); break;
        case 6: _t->on_B2_1470add_clicked(); break;
        case 7: _t->updatePower1470Label(); break;
        case 8: _t->updatePower980Label(); break;
        case 9: _t->updateTimerLabel(); break;
        case 10: _t->updateJouleLabel(); break;
        case 11: _t->on_B2_timer_on_clicked(); break;
        case 12: _t->on_B2_timer_off_clicked(); break;
        case 13: _t->on_B2_timer_add_clicked(); break;
        case 14: _t->on_B2_timer_sub_clicked(); break;
        case 15: _t->on_B2_pulsemode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_B2_on_time_sub_clicked(); break;
        case 17: _t->on_B2_on_time_add_clicked(); break;
        case 18: _t->on_B2_off_time_sub_clicked(); break;
        case 19: _t->on_B2_off_time_add_clicked(); break;
        case 20: _t->updatePulseLabels(); break;
        case 21: _t->on_B2_audioalarm_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_B2_alarm_sec_sub_clicked(); break;
        case 23: _t->on_B2_alarm_sec_add_clicked(); break;
        case 24: _t->on_B2_alarm_joule_sub_clicked(); break;
        case 25: _t->on_B2_alarm_joule_add_clicked(); break;
        case 26: _t->updateAlarmSecLabel(); break;
        case 27: _t->updateAlarmJouleLabel(); break;
        case 28: _t->on_B2_sec_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 29: _t->on_B2_joule_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->on_B2_sound_clicked(); break;
        case 31: _t->on_B2_brightness_clicked(); break;
        case 32: _t->on_B2_aimingbeam_clicked(); break;
        case 33: _t->on_B2_setting_clicked(); break;
        case 34: _t->on_B2_ready_for_surgery_clicked(); break;
        case 35: _t->updatedatabase(); break;
        case 36: _t->updateAvgEnergyLabel(); break;
        case 37: _t->on_B2_timer_reset_clicked(); break;
        case 38: _t->on_B2_timer_noreset_clicked(); break;
        case 39: _t->setTimerResetState((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->updateFromGlobals(); break;
        case 41: _t->openProtocolSelection(); break;
        case 42: _t->update_B2_timer_on(); break;
        case 43: _t->update_B2_timer_off(); break;
        case 44: _t->on_B2_modify_protocol_clicked(); break;
        case 45: _t->switchTonewprotocol(); break;
        case 46: _t->markProtocolModified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 47: _t->updateProtocolLabel(); break;
        case 48: { int _r = _t->getMaxLimit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 49;
    }
    return _id;
}
QT_WARNING_POP
