#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"

//�ӵ���
class Bullet :public Sprite
{
private:
	//ÿ֡��y�������ƶ��ľ���
	int dy_ = 0;

public:
	Bullet();
	~Bullet();

	//��ȡÿ֡��y�������ƶ��ľ���
	const int dy() const { return dy_; }
	//��ȡÿ֡��y�������ƶ��ľ��������
	int &rdy() { return dy_; }
};

#endif // BULLET_H
