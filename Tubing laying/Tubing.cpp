#include "Tubing.h"
#include "widget.h"

#include <QGridLayout>
#include <QLabel>

Tubing::Tubing()
{
	setWindowTitle(tr("Tubing laying"));

	Widget *tubes = new Widget(&setting, this);
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(tubes, 0, 0);

	setLayout(layout);
}
