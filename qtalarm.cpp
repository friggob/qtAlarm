#include "qtalarm.h"
#include "ui_qtalarm.h"

qtAlarm::qtAlarm(QWidget *parent) :
    QMainWindow(parent),
		ui(new Ui::qtAlarm)
{
	ui->setupUi(this);
}

qtAlarm::~qtAlarm() {
	delete ui;
}
