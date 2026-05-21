/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../setting.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7SettingE_t {};
} // unnamed namespace

template <> constexpr inline auto Setting::qt_create_metaobjectdata<qt_meta_tag_ZN7SettingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Setting",
        "switchToHome",
        "",
        "on_B3_back_to_home_clicked",
        "on_B3_simplified_clicked",
        "on_B3_advanced_clicked",
        "on_B3_pulse_mode_clicked",
        "on_B3_custom_clicked",
        "on_B3_pass_enable_clicked",
        "on_B3_pass_change_clicked",
        "on_B3_interlockkey_enable_clicked",
        "on_B3_dark_light_clicked",
        "on_B3_usage_area_clicked",
        "on_B3_service_engineer_area_clicked",
        "update_simp_adva_mode",
        "switchTonewprotocol",
        "toggle_pass_enable",
        "toggle_interlockkey_enable",
        "switchTonewPulseMode",
        "on_B3_clear_data_clicked",
        "on_B3_patientdata_export_clicked",
        "on_B3_patientdata_enable_clicked",
        "clear_data_form_userdb",
        "export_status",
        "ex_st",
        "exportPatientDataToCSV",
        "exportPatientWiseCSV",
        "toggle_patientdata_enable"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'switchToHome'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_back_to_home_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_simplified_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_advanced_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_pulse_mode_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_custom_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_pass_enable_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_pass_change_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_interlockkey_enable_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_dark_light_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_usage_area_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_service_engineer_area_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'update_simp_adva_mode'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchTonewprotocol'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'toggle_pass_enable'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'toggle_interlockkey_enable'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchTonewPulseMode'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_clear_data_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_patientdata_export_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_patientdata_enable_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clear_data_form_userdb'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'export_status'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Slot 'exportPatientDataToCSV'
        QtMocHelpers::SlotData<bool()>(25, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'exportPatientWiseCSV'
        QtMocHelpers::SlotData<bool()>(26, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'toggle_patientdata_enable'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Setting, qt_meta_tag_ZN7SettingE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7SettingE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7SettingE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7SettingE_t>.metaTypes,
    nullptr
} };

void Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Setting *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->switchToHome(); break;
        case 1: _t->on_B3_back_to_home_clicked(); break;
        case 2: _t->on_B3_simplified_clicked(); break;
        case 3: _t->on_B3_advanced_clicked(); break;
        case 4: _t->on_B3_pulse_mode_clicked(); break;
        case 5: _t->on_B3_custom_clicked(); break;
        case 6: _t->on_B3_pass_enable_clicked(); break;
        case 7: _t->on_B3_pass_change_clicked(); break;
        case 8: _t->on_B3_interlockkey_enable_clicked(); break;
        case 9: _t->on_B3_dark_light_clicked(); break;
        case 10: _t->on_B3_usage_area_clicked(); break;
        case 11: _t->on_B3_service_engineer_area_clicked(); break;
        case 12: _t->update_simp_adva_mode(); break;
        case 13: _t->switchTonewprotocol(); break;
        case 14: _t->toggle_pass_enable(); break;
        case 15: _t->toggle_interlockkey_enable(); break;
        case 16: _t->switchTonewPulseMode(); break;
        case 17: _t->on_B3_clear_data_clicked(); break;
        case 18: _t->on_B3_patientdata_export_clicked(); break;
        case 19: _t->on_B3_patientdata_enable_clicked(); break;
        case 20: _t->clear_data_form_userdb(); break;
        case 21: _t->export_status((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: { bool _r = _t->exportPatientDataToCSV();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->exportPatientWiseCSV();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->toggle_patientdata_enable(); break;
        default: ;
        }
    }
}

const QMetaObject *Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7SettingE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}
QT_WARNING_POP
