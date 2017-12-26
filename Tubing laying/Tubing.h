#pragma once

#include <QtWidgets/QMainWindow>
#include "setting.h"
#include "widget.h"

#include <QWidget>

class Tubing : public QWidget
{
	Q_OBJECT

public:
	Tubing();

private:
	Setting setting;
};
