#include "scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());

	show();
}

Scene::~Scene()
{

}
