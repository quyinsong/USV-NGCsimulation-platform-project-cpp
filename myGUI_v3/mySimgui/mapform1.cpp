#include "mapform1.h"
#include "ui_mapform1.h"

MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    ui->setupUi(this);
}

MapForm::~MapForm()
{
    delete ui;
}
