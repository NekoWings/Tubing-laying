#pragma once

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Setting
{
public:
	Setting();

public:
	void paint(QPainter *painter, QPaintEvent *event);

private:
	QBrush background;
	QFont textFont;
	QPen textPen;

	int radius;
	QPainterPath bigCircle;
	QPainterPath smallCircle;
	QPainterPath path = bigCircle - smallCircle;

	QPoint tube[10];
};