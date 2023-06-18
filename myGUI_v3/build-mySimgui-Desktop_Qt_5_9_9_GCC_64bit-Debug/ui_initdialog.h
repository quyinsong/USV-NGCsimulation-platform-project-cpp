/********************************************************************************
** Form generated from reading UI file 'initdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITDIALOG_H
#define UI_INITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InitDialog
{
public:
    QPushButton *apply_btn;
    QPushButton *cancel_btn;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QDialog *InitDialog)
    {
        if (InitDialog->objectName().isEmpty())
            InitDialog->setObjectName(QStringLiteral("InitDialog"));
        InitDialog->resize(400, 300);
        apply_btn = new QPushButton(InitDialog);
        apply_btn->setObjectName(QStringLiteral("apply_btn"));
        apply_btn->setGeometry(QRect(200, 80, 89, 25));
        cancel_btn = new QPushButton(InitDialog);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setGeometry(QRect(200, 120, 89, 25));
        label = new QLabel(InitDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 71, 31));
        spinBox = new QSpinBox(InitDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 80, 131, 61));

        retranslateUi(InitDialog);

        QMetaObject::connectSlotsByName(InitDialog);
    } // setupUi

    void retranslateUi(QDialog *InitDialog)
    {
        InitDialog->setWindowTitle(QApplication::translate("InitDialog", "Dialog", Q_NULLPTR));
        apply_btn->setText(QApplication::translate("InitDialog", "apply", Q_NULLPTR));
        cancel_btn->setText(QApplication::translate("InitDialog", "cancel", Q_NULLPTR));
        label->setText(QApplication::translate("InitDialog", "Number", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InitDialog: public Ui_InitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITDIALOG_H
