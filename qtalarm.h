#ifndef QTALARM_H
#define QTALARM_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class qtAlarm;
}

class qtAlarm : public QMainWindow
{
    Q_OBJECT

public:
    explicit qtAlarm(QWidget *parent = 0);
    ~qtAlarm();

	private slots:
		void on_actionQuit_triggered();
		void on_actionSaveConfig_triggered();
		void showTime();

	private:
    Ui::qtAlarm *ui;
		void createMenu();
		void readConfig();
		void saveConfig();
		QSettings *cSet;
		QPoint oldPos;
		bool toggle;
};

#endif // QTALARM_H
