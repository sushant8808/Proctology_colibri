/****************************************************************************
** Meta object code from reading C++ file 'surgery_data.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../surgery_data.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'surgery_data.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12Surgery_dataE_t {};
} // unnamed namespace

template <> constexpr inline auto Surgery_data::qt_create_metaobjectdata<qt_meta_tag_ZN12Surgery_dataE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Surgery_data",
        "on_B4_save_clicked",
        "",
        "on_B4_skip_clicked",
        "on_B4_back_to_home_clicked",
        "switchToHome",
        "on_B4_male_clicked",
        "on_B4_female_clicked",
        "loadSurgeonNames",
        "on_bt_patient_id_clicked",
        "on_bt_patient_name_clicked",
        "on_bt_patient_age_clicked",
        "on_bt_Surgeon_name_clicked",
        "on_bt_Surgery_name_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_B4_save_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B4_skip_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B4_back_to_home_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToHome'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B4_male_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B4_female_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'loadSurgeonNames'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_bt_patient_id_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_bt_patient_name_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_bt_patient_age_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_bt_Surgeon_name_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_bt_Surgery_name_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Surgery_data, qt_meta_tag_ZN12Surgery_dataE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Surgery_data::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12Surgery_dataE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12Surgery_dataE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12Surgery_dataE_t>.metaTypes,
    nullptr
} };

void Surgery_data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Surgery_data *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_B4_save_clicked(); break;
        case 1: _t->on_B4_skip_clicked(); break;
        case 2: _t->on_B4_back_to_home_clicked(); break;
        case 3: _t->switchToHome(); break;
        case 4: _t->on_B4_male_clicked(); break;
        case 5: _t->on_B4_female_clicked(); break;
        case 6: _t->loadSurgeonNames(); break;
        case 7: _t->on_bt_patient_id_clicked(); break;
        case 8: _t->on_bt_patient_name_clicked(); break;
        case 9: _t->on_bt_patient_age_clicked(); break;
        case 10: _t->on_bt_Surgeon_name_clicked(); break;
        case 11: _t->on_bt_Surgery_name_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Surgery_data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Surgery_data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12Surgery_dataE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Surgery_data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
