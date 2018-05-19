#ifndef QTALARM_H
#define QTALARM_H

#include <QMainWindow>

namespace Ui {
class qtAlarm;
}

class qtAlarm : public QMainWindow
{
    Q_OBJECT

public:
    explicit qtAlarm(QWidget *parent = 0);
    ~qtAlarm();

private:
    Ui::qtAlarm *ui;
};

#endif // QTALARM_H
