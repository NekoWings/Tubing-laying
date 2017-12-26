#pragma once
#include "setting.h"

#include <QWidget>

class Helper;
class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(Setting *setting, QWidget *parent);

	public slots:
	//

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	Setting *setting;
};