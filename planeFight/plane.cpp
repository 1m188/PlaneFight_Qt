#include "plane.h"

Plane::Plane(QWidget *parent)
	: Game(parent), life(1), img({QVector<QPixmap>{}, 0}), destroyImg({QVector<QPixmap>{}, 0}), imgChangeTimer(new QTimer(this)), destroyImgChangeTimer(new QTimer(this)), productBulletTimer(new QTimer(this)), moveTimer(new QTimer(this))
{
	connect(imgChangeTimer, &QTimer::timeout, this, &Plane::imgChange);
	imgChangeTimer->start(100);
	connect(destroyImgChangeTimer, &QTimer::timeout, this, &Plane::destroyImgChange);
	destroyImgChangeTimer->start(120);
	connect(moveTimer, &QTimer::timeout, this, &Plane::move_);
	moveTimer->start(20);
	connect(productBulletTimer, &QTimer::timeout, this, &Plane::productBullet);
	productBulletTimer->start(500);
}

Plane::~Plane()
{

}

void Plane::imgChange()
{
	if (life > 0 && (!getPaused()))
	{
		if (img.first.size() > 0)
		{
			setPixmap(img.first.at(img.second));
			img.second++;
			if (img.second >= img.first.size())
			{
				img.second = 0;
			}
		}
	}
}

void Plane::destroyImgChange()
{
	if (life <= 0 && (!getPaused()))
	{
		if (destroyImg.first.size() > 0)
		{
			setPixmap(destroyImg.first.at(destroyImg.second));
			destroyImg.second++;
			if (destroyImg.second >= destroyImg.first.size())
			{
				deleteLater();
			}
		}
	}
}

void Plane::beCollided()
{
	life--;
}