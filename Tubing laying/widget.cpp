#include "widget.h"
#include "setting.h"

#include <QPainter>
Widget::Widget(Setting *setting, QWidget *parent)
	: QWidget(parent), setting(setting)
{
	setFixedSize(500, 500);
}

void Widget::paintEvent(QPaintEvent *event)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	setting->paint(&painter, event);
	painter.end();
}
