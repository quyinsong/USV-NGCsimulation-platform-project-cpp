/********************************************************************************
** Form generated from reading UI file 'connectdialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG1_H
#define UI_CONNECTDIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QLabel *ip_lab;
    QLineEdit *port_lnedit;
    QPushButton *connect_btn;
    QLabel *port_lab;
    QLineEdit *ip_lneidt;
    QLineEdit *constate_lnedit;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QStringLiteral("ConnectDialog"));
        ConnectDialog->resize(400, 300);
        ip_lab = new QLabel(ConnectDialog);
        ip_lab->setObjectName(QStringLiteral("ip_lab"));
        ip_lab->setGeometry(QRect(60, 110, 67, 17));
        port_lnedit = new QLineEdit(ConnectDialog);
        port_lnedit->setObjectName(QStringLiteral("port_lnedit"));
        port_lnedit->setGeometry(QRect(140, 160, 151, 41));
        connect_btn = new QPushButton(ConnectDialog);
        connect_btn->setObjectName(QStringLiteral("connect_btn"));
        connect_btn->setGeometry(QRect(0, 220, 401, 81));
        port_lab = new QLabel(ConnectDialog);
        port_lab->setObjectName(QStringLiteral("port_lab"));
        port_lab->setGeometry(QRect(60, 170, 67, 17));
        ip_lneidt = new QLineEdit(ConnectDialog);
        ip_lneidt->setObjectName(QStringLiteral("ip_lneidt"));
        ip_lneidt->setGeometry(QRect(140, 100, 151, 41));
        constate_lnedit = new QLineEdit(ConnectDialog);
        constate_lnedit->setObjectName(QStringLiteral("constate_lnedit"));
        constate_lnedit->setGeometry(QRect(0, 0, 401, 81));

        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Dialog", Q_NULLPTR));
        ip_lab->setText(QApplication::translate("ConnectDialog", "IP", Q_NULLPTR));
        port_lnedit->setText(QApplication::translate("ConnectDialog", "80000", Q_NULLPTR));
        connect_btn->setText(QApplication::translate("ConnectDialog", "connect", Q_NULLPTR));
        port_lab->setText(QApplication::translate("ConnectDialog", "port", Q_NULLPTR));
        ip_lneidt->setText(QApplication::translate("ConnectDialog", "192.168.2.127", Q_NULLPTR));
        constate_lnedit->setText(QApplication::translate("ConnectDialog", "\347\255\211\345\276\205\347\275\221\347\273\234\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG1_H
