#include "Enemy.h"

Enemy::Enemy() :Sprite()
{

}

Enemy::~Enemy()
{

}

bool Enemy::move(int down)
{
	ry() += dy_;
	//�����л���ȫ������ͼ�߽緵��false
	//���򷵻�true
	return !(y() >= down);
}