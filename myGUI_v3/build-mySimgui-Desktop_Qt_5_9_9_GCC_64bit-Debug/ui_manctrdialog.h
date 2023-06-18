/********************************************************************************
** Form generated from reading UI file 'manctrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANCTRDIALOG_H
#define UI_MANCTRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManCtrDialog
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *up_btn;
    QPushButton *left_btn;
    QPushButton *right_btn;
    QPushButton *down_btn;
    QPushButton *up_btn_2;

    void setupUi(QDialog *ManCtrDialog)
    {
        if (ManCtrDialog->objectName().isEmpty())
            ManCtrDialog->setObjectName(QStringLiteral("ManCtrDialog"));
        ManCtrDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(ManCtrDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(ManCtrDialog);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        up_btn = new QPushButton(widget);
        up_btn->setObjectName(QStringLiteral("up_btn"));

        gridLayout->addWidget(up_btn, 0, 1, 1, 1);

        left_btn = new QPushButton(widget);
        left_btn->setObjectName(QStringLiteral("left_btn"));

        gridLayout->addWidget(left_btn, 1, 0, 1, 1);

        right_btn = new QPushButton(widget);
        right_btn->setObjectName(QStringLiteral("right_btn"));

        gridLayout->addWidget(right_btn, 1, 2, 1, 1);

        down_btn = new QPushButton(widget);
        down_btn->setObjectName(QStringLiteral("down_btn"));

        gridLayout->addWidget(down_btn, 2, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        up_btn_2 = new QPushButton(ManCtrDialog);
        up_btn_2->setObjectName(QStringLiteral("up_btn_2"));

        gridLayout_2->addWidget(up_btn_2, 1, 0, 1, 1);


        retranslateUi(ManCtrDialog);

        QMetaObject::connectSlotsByName(ManCtrDialog);
    } // setupUi

    void retranslateUi(QDialog *ManCtrDialog)
    {
        ManCtrDialog->setWindowTitle(QApplication::translate("ManCtrDialog", "Dialog", Q_NULLPTR));
        up_btn->setText(QApplication::translate("ManCtrDialog", "up", Q_NULLPTR));
        left_btn->setText(QApplication::translate("ManCtrDialog", "left", Q_NULLPTR));
        right_btn->setText(QApplication::translate("ManCtrDialog", "right", Q_NULLPTR));
        down_btn->setText(QApplication::translate("ManCtrDialog", "down", Q_NULLPTR));
        up_btn_2->setText(QApplication::translate("ManCtrDialog", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManCtrDialog: public Ui_ManCtrDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANCTRDIALOG_H
