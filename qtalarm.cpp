#include "qtalarm.h"
#include "ui_qtalarm.h"
#include <QDebug>
#include <QDateTime>
#include <QTimer>

qtAlarm::qtAlarm(QWidget *parent) :
    QMainWindow(parent),
		ui(new Ui::qtAlarm)
{
	QPalette p;
	QTimer *timer = new QTimer(this);
	cSet = new QSettings("JFO Soft","qtAlarm");

	connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
	timer->start(1 * 1000);

	ui->setupUi(this);
	ui->label->setAlignment(Qt::AlignCenter);

	setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	p = ui->label->palette();
	p.setColor(QPalette::Background, QColor("#CCFFCC"));
	//p.setColor(QPalette::Foreground, QColor("#000000"));
	setPalette(p);

	readConfig();

	if(!oldPos.isNull()){
		qDebug() << "Moving window to" << oldPos;
		this->move(oldPos);
	}

	createMenu();
	showTime();
}

qtAlarm::~qtAlarm() {
	delete ui;
}

void qtAlarm::on_actionQuit_triggered() {
	saveConfig();
	qDebug() << "Quitting!";
	close();
	QApplication::quit();
}

void qtAlarm::createMenu() {
	QList<QAction*> a;

	QAction *s = new QAction(this);
	s->setSeparator(true);

	a += ui->actionSaveConfig;
	a += s;
	a += ui->actionQuit;
	addActions(a);
}

void qtAlarm::readConfig() {
	QVariant sValue;

	cSet->sync();
	cSet->beginGroup("main");
	if((sValue = cSet->value("winPos")).isValid()){
		oldPos = sValue.toPoint();
		qDebug() << "Setting pos to" << oldPos;
	}
	cSet->endGroup();

}

void qtAlarm::saveConfig() {
	cSet->sync();
	cSet->beginGroup("main");
	cSet->setValue("winPos",this->pos());
	cSet->endGroup();
	cSet->sync();
}

void qtAlarm::showTime() {
	QDateTime dt(QDateTime::currentDateTime());

	ui->label->setText(dt.toString("HH:mm"));
}

void qtAlarm::on_actionSaveConfig_triggered() {
	saveConfig();
}
