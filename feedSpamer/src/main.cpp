#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	translator.load("../ts/feedspamer_ru.qm", QApplication::applicationDirPath());
	a.installTranslator(&translator);

	MainWindow w;
	w.show();
	return a.exec();
}
