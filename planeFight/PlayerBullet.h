#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"

//����ӵ���
class PlayerBullet :public Bullet
{
public:
	PlayerBullet();
	~PlayerBullet();

	//�ƶ�
	//����һ���߽�
	//û�����߽緵��true�����򷵻�false
	bool move(int border);
};

#endif // !PLAYERBULLET_H
