#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Bullet.h"

//�л��ӵ���
class EnemyBullet :public Bullet
{
public:
	EnemyBullet();
	~EnemyBullet();

	//�ƶ�
	//����һ���ƶ��߽�
	//�����߽緵��false�����򷵻�true
	bool move(int border);
};

#endif // !ENEMYBULLET_H
