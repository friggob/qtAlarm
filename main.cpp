#include "qtalarm.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	qtAlarm w;

	QCommandLineParser *cp = new QCommandLineParser();
	cp->addHelpOption();
	cp->addVersionOption();
	a.setApplicationName("qtAlarm");
	a.setApplicationVersion(APP_VERSION);

	cp->process(a);

	delete cp;

	w.show();

	return a.exec();
}
