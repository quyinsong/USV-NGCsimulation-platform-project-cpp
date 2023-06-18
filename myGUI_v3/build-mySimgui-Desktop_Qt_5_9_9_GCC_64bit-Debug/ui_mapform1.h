/********************************************************************************
** Form generated from reading UI file 'mapform1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPFORM1_H
#define UI_MAPFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapForm
{
public:

    void setupUi(QWidget *MapForm)
    {
        if (MapForm->objectName().isEmpty())
            MapForm->setObjectName(QStringLiteral("MapForm"));
        MapForm->resize(664, 542);

        retranslateUi(MapForm);

        QMetaObject::connectSlotsByName(MapForm);
    } // setupUi

    void retranslateUi(QWidget *MapForm)
    {
        MapForm->setWindowTitle(QApplication::translate("MapForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MapForm: public Ui_MapForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPFORM1_H
