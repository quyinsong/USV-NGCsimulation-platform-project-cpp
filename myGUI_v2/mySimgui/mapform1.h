#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>

namespace Ui {
class MapForm;
}

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr);
    ~MapForm();

private:
    Ui::MapForm *ui;
};

#endif // MAPFORM_H
