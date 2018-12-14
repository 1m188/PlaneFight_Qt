#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

//�����
class Player :public Sprite
{
private:
	//ÿ֡�����������ϵķ��о���
	int dx;
	int dy;

	//�Ƿ���/��/��/���ƶ�
	bool isUping;
	bool isDowning;
	bool isLefting;
	bool isRighting;

public:
	Player();
	~Player();

	void move(int up, int down, int left, int right);
};

#endif // PLAYER_H
