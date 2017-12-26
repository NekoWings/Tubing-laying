#include "setting.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QString>

Setting::Setting()
{
	background = QBrush(QColor(255,255,255));
	
//Path
	radius = 25;
	bigCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);
	//radius = 23;
	//smallCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);
	path = bigCircle;// - smallCircle;
//Path END

//Pen
	textPen = QPen(Qt::white/*QColor(30, 176, 254)*/);
	textFont.setPixelSize(30);
	textFont.setFamily("Microsoft YaHei UI");
//Pen END

//Tubes
	tube[1] = QPoint(0, 0);
	tube[2] = QPoint(100, 100);
	tube[3] = QPoint(200, 200);
	tube[4] = QPoint(100, 300);
	tube[5] = QPoint(0, 400);
	tube[6] = QPoint(-100, 300);
	tube[7] = QPoint(-200, 200);
	tube[8] = QPoint(-100, 100);
//Tubes END
}

void Setting::paint(QPainter *painter, QPaintEvent *event)
{
	//painter->fillRect(event->rect(), background);
	painter->translate(250, 50);
	painter->save();

//Tubes
	painter->setPen(Qt::black);
	painter->drawLine(tube[1], tube[5]);
	painter->drawLine(tube[3], tube[2]);
	painter->drawLine(tube[5], tube[4]);
	painter->drawLine(tube[5], tube[7]);
	painter->drawLine(tube[5], tube[8]);
	painter->drawLine(tube[6], tube[3]);
	painter->drawLine(tube[7], tube[6]);
//Tubes END

//Tube circle
	painter->setPen(Qt::black);
	painter->setBrush(Qt::black);

	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 2; j++)
		{
			if (i == 1)
				painter->translate(100, 100);
			else if (i == 2)
				painter->translate(-100, 100);
			else if (i == 3)
				painter->translate(-100, -100);
			else
				painter->translate(100, -100);

			painter->drawPath(path);
		}
//Tubes circle END

//Tube number
	painter->setPen(textPen);
	painter->setFont(textFont);

	qint64 tube_num = 1;
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 2; j++)
		{
			if (i == 1)
				painter->translate(100, 100);
			else if (i == 2)
				painter->translate(-100, 100);
			else if (i == 3)
				painter->translate(-100, -100);
			else
				painter->translate(100, -100);

			QString s=QString::number(tube_num++%8+1);
			painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, s);
		}
//Tube number END

	painter->restore();
}