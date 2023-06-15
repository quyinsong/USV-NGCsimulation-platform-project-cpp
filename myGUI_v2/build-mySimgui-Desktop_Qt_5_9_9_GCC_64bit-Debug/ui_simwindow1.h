/********************************************************************************
** Form generated from reading UI file 'simwindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMWINDOW1_H
#define UI_SIMWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimWindow1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *speed_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *other_widget;
    QGridLayout *gridLayout_2;
    QLabel *simtime_lab;
    QLineEdit *simtime_lne;
    QLabel *charge_lab;
    QLineEdit *charge_lne;
    QWidget *heading_widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QWidget *state_widget;
    QGridLayout *gridLayout;
    QLabel *n_lab;
    QLineEdit *north_lne;
    QLabel *e_lab;
    QLineEdit *east_lne;
    QLabel *angle_lab;
    QLineEdit *angle_lne;
    QLabel *surge_lab;
    QLineEdit *surge_lne;
    QLabel *way_lab;
    QLineEdit *sway_lne;
    QLabel *yaw_lab;
    QLineEdit *yaw_lne;
    QWidget *ctrpanel_widget;
    QGridLayout *gridLayout_4;
    QMenuBar *menubar;

    void setupUi(QMainWindow *SimWindow1)
    {
        if (SimWindow1->objectName().isEmpty())
            SimWindow1->setObjectName(QStringLiteral("SimWindow1"));
        SimWindow1->resize(800, 800);
        SimWindow1->setMinimumSize(QSize(800, 800));
        SimWindow1->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(SimWindow1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setFocusPolicy(Qt::NoFocus);
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        speed_widget = new QWidget(widget);
        speed_widget->setObjectName(QStringLiteral("speed_widget"));
        speed_widget->setMinimumSize(QSize(200, 200));
        speed_widget->setMaximumSize(QSize(200, 200));
        verticalLayout_2 = new QVBoxLayout(speed_widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_3->addWidget(speed_widget, 0, 0, 1, 1);

        other_widget = new QWidget(widget);
        other_widget->setObjectName(QStringLiteral("other_widget"));
        other_widget->setMinimumSize(QSize(200, 200));
        other_widget->setMaximumSize(QSize(200, 200));
        gridLayout_2 = new QGridLayout(other_widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        simtime_lab = new QLabel(other_widget);
        simtime_lab->setObjectName(QStringLiteral("simtime_lab"));

        gridLayout_2->addWidget(simtime_lab, 0, 0, 1, 1);

        simtime_lne = new QLineEdit(other_widget);
        simtime_lne->setObjectName(QStringLiteral("simtime_lne"));

        gridLayout_2->addWidget(simtime_lne, 0, 1, 1, 1);

        charge_lab = new QLabel(other_widget);
        charge_lab->setObjectName(QStringLiteral("charge_lab"));

        gridLayout_2->addWidget(charge_lab, 1, 0, 1, 1);

        charge_lne = new QLineEdit(other_widget);
        charge_lne->setObjectName(QStringLiteral("charge_lne"));

        gridLayout_2->addWidget(charge_lne, 1, 1, 1, 1);


        gridLayout_3->addWidget(other_widget, 0, 2, 1, 1);

        heading_widget = new QWidget(widget);
        heading_widget->setObjectName(QStringLiteral("heading_widget"));
        heading_widget->setMinimumSize(QSize(200, 200));
        heading_widget->setMaximumSize(QSize(200, 200));
        verticalLayout_3 = new QVBoxLayout(heading_widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_3->addWidget(heading_widget, 0, 1, 1, 1);


        gridLayout_6->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(800, 400));
        widget_2->setMaximumSize(QSize(800, 400));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        state_widget = new QWidget(widget_2);
        state_widget->setObjectName(QStringLiteral("state_widget"));
        state_widget->setMinimumSize(QSize(200, 300));
        state_widget->setMaximumSize(QSize(200, 300));
        gridLayout = new QGridLayout(state_widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        n_lab = new QLabel(state_widget);
        n_lab->setObjectName(QStringLiteral("n_lab"));

        gridLayout->addWidget(n_lab, 0, 0, 1, 1);

        north_lne = new QLineEdit(state_widget);
        north_lne->setObjectName(QStringLiteral("north_lne"));

        gridLayout->addWidget(north_lne, 0, 1, 1, 1);

        e_lab = new QLabel(state_widget);
        e_lab->setObjectName(QStringLiteral("e_lab"));

        gridLayout->addWidget(e_lab, 1, 0, 1, 1);

        east_lne = new QLineEdit(state_widget);
        east_lne->setObjectName(QStringLiteral("east_lne"));

        gridLayout->addWidget(east_lne, 1, 1, 1, 1);

        angle_lab = new QLabel(state_widget);
        angle_lab->setObjectName(QStringLiteral("angle_lab"));

        gridLayout->addWidget(angle_lab, 2, 0, 1, 1);

        angle_lne = new QLineEdit(state_widget);
        angle_lne->setObjectName(QStringLiteral("angle_lne"));

        gridLayout->addWidget(angle_lne, 2, 1, 1, 1);

        surge_lab = new QLabel(state_widget);
        surge_lab->setObjectName(QStringLiteral("surge_lab"));

        gridLayout->addWidget(surge_lab, 3, 0, 1, 1);

        surge_lne = new QLineEdit(state_widget);
        surge_lne->setObjectName(QStringLiteral("surge_lne"));

        gridLayout->addWidget(surge_lne, 3, 1, 1, 1);

        way_lab = new QLabel(state_widget);
        way_lab->setObjectName(QStringLiteral("way_lab"));

        gridLayout->addWidget(way_lab, 4, 0, 1, 1);

        sway_lne = new QLineEdit(state_widget);
        sway_lne->setObjectName(QStringLiteral("sway_lne"));

        gridLayout->addWidget(sway_lne, 4, 1, 1, 1);

        yaw_lab = new QLabel(state_widget);
        yaw_lab->setObjectName(QStringLiteral("yaw_lab"));

        gridLayout->addWidget(yaw_lab, 5, 0, 1, 1);

        yaw_lne = new QLineEdit(state_widget);
        yaw_lne->setObjectName(QStringLiteral("yaw_lne"));

        gridLayout->addWidget(yaw_lne, 5, 1, 1, 1);


        gridLayout_5->addWidget(state_widget, 0, 0, 1, 1);

        ctrpanel_widget = new QWidget(widget_2);
        ctrpanel_widget->setObjectName(QStringLiteral("ctrpanel_widget"));
        ctrpanel_widget->setMinimumSize(QSize(500, 300));
        ctrpanel_widget->setMaximumSize(QSize(500, 300));
        gridLayout_4 = new QGridLayout(ctrpanel_widget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));

        gridLayout_5->addWidget(ctrpanel_widget, 0, 1, 1, 1);


        gridLayout_6->addWidget(widget_2, 1, 0, 1, 1);

        SimWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimWindow1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        SimWindow1->setMenuBar(menubar);

        retranslateUi(SimWindow1);

        QMetaObject::connectSlotsByName(SimWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *SimWindow1)
    {
        SimWindow1->setWindowTitle(QApplication::translate("SimWindow1", "MainWindow", Q_NULLPTR));
        simtime_lab->setText(QApplication::translate("SimWindow1", "simTime", Q_NULLPTR));
        charge_lab->setText(QApplication::translate("SimWindow1", "charge", Q_NULLPTR));
        n_lab->setText(QApplication::translate("SimWindow1", "x", Q_NULLPTR));
        e_lab->setText(QApplication::translate("SimWindow1", "y", Q_NULLPTR));
        angle_lab->setText(QApplication::translate("SimWindow1", "psi", Q_NULLPTR));
        surge_lab->setText(QApplication::translate("SimWindow1", "u", Q_NULLPTR));
        way_lab->setText(QApplication::translate("SimWindow1", "v", Q_NULLPTR));
        yaw_lab->setText(QApplication::translate("SimWindow1", "r", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimWindow1: public Ui_SimWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMWINDOW1_H
