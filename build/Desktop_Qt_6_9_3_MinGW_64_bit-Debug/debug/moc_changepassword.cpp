/****************************************************************************
** Meta object code from reading C++ file 'changepassword.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../changepassword.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changepassword.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14changepasswordE_t {};
} // unnamed namespace

template <> constexpr inline auto changepassword::qt_create_metaobjectdata<qt_meta_tag_ZN14changepasswordE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "changepassword",
        "appendDigit",
        "",
        "digit",
        "on_B1_pass_1_clicked",
        "on_B1_pass_2_clicked",
        "on_B1_pass_3_clicked",
        "on_B1_pass_4_clicked",
        "on_B1_pass_5_clicked",
        "on_B1_pass_6_clicked",
        "on_B1_pass_7_clicked",
        "on_B1_pass_8_clicked",
        "on_B1_pass_9_clicked",
        "on_B1_pass_c_clicked",
        "on_B1_pass_0_clicked",
        "on_B1_pass_ok_clicked",
        "switchToSetting",
        "on_B3_back_to_setting_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'appendDigit'
        QtMocHelpers::SlotData<void(const QString &)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'on_B1_pass_1_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_2_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_3_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_4_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_5_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_6_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_7_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_8_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_9_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_c_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_0_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B1_pass_ok_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'switchToSetting'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_B3_back_to_setting_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<changepassword, qt_meta_tag_ZN14changepasswordE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject changepassword::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14changepasswordE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14changepasswordE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14changepasswordE_t>.metaTypes,
    nullptr
} };

void changepassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<changepassword *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->appendDigit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_B1_pass_1_clicked(); break;
        case 2: _t->on_B1_pass_2_clicked(); break;
        case 3: _t->on_B1_pass_3_clicked(); break;
        case 4: _t->on_B1_pass_4_clicked(); break;
        case 5: _t->on_B1_pass_5_clicked(); break;
        case 6: _t->on_B1_pass_6_clicked(); break;
        case 7: _t->on_B1_pass_7_clicked(); break;
        case 8: _t->on_B1_pass_8_clicked(); break;
        case 9: _t->on_B1_pass_9_clicked(); break;
        case 10: _t->on_B1_pass_c_clicked(); break;
        case 11: _t->on_B1_pass_0_clicked(); break;
        case 12: _t->on_B1_pass_ok_clicked(); break;
        case 13: _t->switchToSetting(); break;
        case 14: _t->on_B3_back_to_setting_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *changepassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changepassword::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14changepasswordE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int changepassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
