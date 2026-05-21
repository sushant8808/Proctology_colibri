/****************************************************************************
** Meta object code from reading C++ file 'changevalue.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../changevalue.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changevalue.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11changevalueE_t {};
} // unnamed namespace

template <> constexpr inline auto changevalue::qt_create_metaobjectdata<qt_meta_tag_ZN11changevalueE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "changevalue",
        "on_B2_980sub_clicked",
        "",
        "on_B2_980add_clicked",
        "on_B2_1470sub_clicked",
        "on_B2_1470add_clicked",
        "on_B2_timer_off_clicked",
        "on_B2_timer_on_clicked",
        "on_B2_timer_sub_clicked",
        "on_B2_timer_add_clicked",
        "on_B2_timer_reset_clicked",
        "on_B2_timer_noreset_clicked",
        "on_B2_pulsemode_stateChanged",
        "arg1",
        "on_B2_on_time_sub_clicked",
        "on_B2_on_time_add_clicked",
        "on_B2_off_time_sub_clicked",
        "on_B2_off_time_add_clicked",
        "on_B2_audioalarm_stateChanged",
        "on_B2_sec_alarm_toggled",
        "checked",
        "on_B2_joule_alarm_toggled",
        "on_B2_alarm_sec_sub_clicked",
        "on_B2_alarm_sec_add_clicked",
        "on_B2_alarm_joule_sub_clicked",
        "on_B2_alarm_joule_add_clicked",
        "update_B2_timer_on",
        "update_B2_timer_off",
        "getStepForValue",
        "valueUs",
        "getMaxLimit",
        "incrementPulseValue",
        "decrementPulseValue",
        "formatPulseTime",
        "getPulseUnit"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_B2_980sub_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_980add_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470sub_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_1470add_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_off_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_on_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_sub_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_add_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_reset_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_timer_noreset_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_pulsemode_stateChanged'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Slot 'on_B2_on_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_on_time_add_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_off_time_sub_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_off_time_add_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_audioalarm_stateChanged'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Slot 'on_B2_sec_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 20 },
        }}),
        // Slot 'on_B2_joule_alarm_toggled'
        QtMocHelpers::SlotData<void(bool)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 20 },
        }}),
        // Slot 'on_B2_alarm_sec_sub_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_sec_add_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_joule_sub_clicked'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B2_alarm_joule_add_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'update_B2_timer_on'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'update_B2_timer_off'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getStepForValue'
        QtMocHelpers::SlotData<int(int)>(28, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { QMetaType::Int, 29 },
        }}),
        // Slot 'getMaxLimit'
        QtMocHelpers::SlotData<int()>(30, 2, QMC::AccessPrivate, QMetaType::Int),
        // Slot 'incrementPulseValue'
        QtMocHelpers::SlotData<int(int)>(31, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { QMetaType::Int, 29 },
        }}),
        // Slot 'decrementPulseValue'
        QtMocHelpers::SlotData<int(int)>(32, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { QMetaType::Int, 29 },
        }}),
        // Slot 'formatPulseTime'
        QtMocHelpers::SlotData<QString(int)>(33, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::Int, 29 },
        }}),
        // Slot 'getPulseUnit'
        QtMocHelpers::SlotData<QString(int)>(34, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::Int, 29 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<changevalue, qt_meta_tag_ZN11changevalueE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject changevalue::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11changevalueE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11changevalueE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11changevalueE_t>.metaTypes,
    nullptr
} };

void changevalue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<changevalue *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_B2_980sub_clicked(); break;
        case 1: _t->on_B2_980add_clicked(); break;
        case 2: _t->on_B2_1470sub_clicked(); break;
        case 3: _t->on_B2_1470add_clicked(); break;
        case 4: _t->on_B2_timer_off_clicked(); break;
        case 5: _t->on_B2_timer_on_clicked(); break;
        case 6: _t->on_B2_timer_sub_clicked(); break;
        case 7: _t->on_B2_timer_add_clicked(); break;
        case 8: _t->on_B2_timer_reset_clicked(); break;
        case 9: _t->on_B2_timer_noreset_clicked(); break;
        case 10: _t->on_B2_pulsemode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_B2_on_time_sub_clicked(); break;
        case 12: _t->on_B2_on_time_add_clicked(); break;
        case 13: _t->on_B2_off_time_sub_clicked(); break;
        case 14: _t->on_B2_off_time_add_clicked(); break;
        case 15: _t->on_B2_audioalarm_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_B2_sec_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_B2_joule_alarm_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_B2_alarm_sec_sub_clicked(); break;
        case 19: _t->on_B2_alarm_sec_add_clicked(); break;
        case 20: _t->on_B2_alarm_joule_sub_clicked(); break;
        case 21: _t->on_B2_alarm_joule_add_clicked(); break;
        case 22: _t->update_B2_timer_on(); break;
        case 23: _t->update_B2_timer_off(); break;
        case 24: { int _r = _t->getStepForValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { int _r = _t->getMaxLimit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: { int _r = _t->incrementPulseValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 27: { int _r = _t->decrementPulseValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { QString _r = _t->formatPulseTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 29: { QString _r = _t->getPulseUnit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *changevalue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changevalue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11changevalueE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int changevalue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
