#include "scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), backgroundImg(QPixmap(":/planeFight/Resources/background.png"))
{
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());

	QPalette p = palette();
	p.setBrush(QPalette::Background, QBrush(backgroundImg));
	setPalette(p);

	show();
}

Scene::~Scene()
{

}
