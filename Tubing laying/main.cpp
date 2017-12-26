#include "Tubing.h"
#include <QtWidgets/QApplication>
#include <QSurface>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSurfaceFormat fmt;
	fmt.setSamples(4);
	QSurfaceFormat::setDefaultFormat(fmt);

	Tubing w;
	w.show();
	return a.exec();
}
