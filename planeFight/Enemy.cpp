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

bool Enemy::changImage()
{
	//�����������0�л���̬ͼƬ
	if (life_ > 0)
	{
		//�л���̬ͼƬ
		normalImageChangeFpsCounter_++;
		if (normalImageChangeFpsCounter_ == imageChangeFpsInterval_)
		{
			normalImageChangeFpsCounter_ = 0;
			rimage() = normalImageVector_[nowNormalImageIndex_];
			nowNormalImageIndex_++;
			if (nowNormalImageIndex_ >= normalImageVector_.size())
			{
				nowNormalImageIndex_ = 0;
			}
		}
	}
	//����չʾ���ͼƬ
	else
	{
		destroyImageChangeFpsCounter_++;
		if (destroyImageChangeFpsCounter_ == imageChangeFpsInterval_)
		{
			destroyImageChangeFpsCounter_ = 0;
			//�������ͼƬ��չʾ��������������Ƴ�ȥ
			if (nowDestroyImageIndex_ >= destroyImageVector_.size())
			{
				return false;
			}
			//�������չʾ��һ��ͼƬ
			else
			{
				rimage() = destroyImageVector_[nowDestroyImageIndex_];
				nowDestroyImageIndex_++;
			}
		}
	}
	return true;
}