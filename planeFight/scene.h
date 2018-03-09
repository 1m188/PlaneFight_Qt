#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "QApplication"
#include "QDeskTopWidget"
#include "player.h"

class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	~Scene();

private:
	QPixmap backgroundImg;
};

#endif // SCENE_H