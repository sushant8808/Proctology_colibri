/****************************************************************************
** Meta object code from reading C++ file 'calibration_screen.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../calibration_screen.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibration_screen.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18Calibration_screenE_t {};
} // unnamed namespace

template <> constexpr inline auto Calibration_screen::qt_create_metaobjectdata<qt_meta_tag_ZN18Calibration_screenE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Calibration_screen",
        "on_pre_power_1470_clicked",
        "",
        "on_next_power_1470_clicked",
        "on_DAC_sub_1470_clicked",
        "on_DAC_add_1470_clicked",
        "on_pre_power_980_clicked",
        "on_next_power_980_clicked",
        "on_DAC_sub_980_clicked",
        "on_DAC_add_980_clicked",
        "on_save_1470_clicked",
        "on_save_980_clicked",
        "on_back_to_service_engineer_area_clicked",
        "switchToServiceEngArea",
        "on_test_1470_clicked",
        "on_test_980_clicked",
        "on_back_to_home_clicked",
        "switchToHome"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_pre_power_1470_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_next_power_1470_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DAC_sub_1470_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DAC_add_1470_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pre_power_980_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_next_power_980_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DAC_sub_980_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DAC_add_980_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_save_1470_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_save_980_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_back_to_service_engineer_area_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToServiceEngArea'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_test_1470_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_test_980_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_back_to_home_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToHome'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Calibration_screen, qt_meta_tag_ZN18Calibration_screenE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Calibration_screen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Calibration_screenE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Calibration_screenE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18Calibration_screenE_t>.metaTypes,
    nullptr
} };

void Calibration_screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Calibration_screen *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pre_power_1470_clicked(); break;
        case 1: _t->on_next_power_1470_clicked(); break;
        case 2: _t->on_DAC_sub_1470_clicked(); break;
        case 3: _t->on_DAC_add_1470_clicked(); break;
        case 4: _t->on_pre_power_980_clicked(); break;
        case 5: _t->on_next_power_980_clicked(); break;
        case 6: _t->on_DAC_sub_980_clicked(); break;
        case 7: _t->on_DAC_add_980_clicked(); break;
        case 8: _t->on_save_1470_clicked(); break;
        case 9: _t->on_save_980_clicked(); break;
        case 10: _t->on_back_to_service_engineer_area_clicked(); break;
        case 11: _t->switchToServiceEngArea(); break;
        case 12: _t->on_test_1470_clicked(); break;
        case 13: _t->on_test_980_clicked(); break;
        case 14: _t->on_back_to_home_clicked(); break;
        case 15: _t->switchToHome(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Calibration_screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calibration_screen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Calibration_screenE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Calibration_screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
