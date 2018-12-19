#include "Player.h"

Player::Player() :Sprite()
{

}

Player::~Player()
{

}

void Player::move(int up, int down, int left, int right)
{
	//���շ����ƶ�
	if (isUping_)
	{
		ry() = y() - dy_;
	}
	if (isDowning_)
	{
		ry() = y() + dy_;
	}
	if (isLefting_)
	{
		rx() = x() - dx_;
	}
	if (isRighting_)
	{
		rx() = x() + dx_;
	}

	//ײǽ
	if (y() < up)
	{
		ry() = up;
	}
	else if (y() + height() > down)
	{
		ry() = down - height();
	}
	if (x() < left)
	{
		rx() = left;
	}
	else if (x() + width() > right)
	{
		rx() = right - width();
	}
}

bool Player::changeImage()
{
	//�����ҷɻ��������л���̬ͼƬ
	if (life_ > 0)
	{
		normalImageChangeFpsCounter_++;
		if (normalImageChangeFpsCounter_ == imageChangeFpsInterval_)
		{
			normalImageChangeFpsCounter_ = 0;
			rimage() = normalImageVector_[nowNormalImageIndex_];
			nowNormalImageIndex_++;
			//����һ��ͼƬ��ʾ����֮�󣬼�����ʾ��һ��ͼƬ
			if (nowNormalImageIndex_ >= normalImageVector_.size())
			{
				nowNormalImageIndex_ = 0;
			}
		}
	}
	//�����л����ͼƬ
	else
	{
		destroyImageChangeFpsCounter_++;
		if (destroyImageChangeFpsCounter_ == imageChangeFpsInterval_)
		{
			destroyImageChangeFpsCounter_ = 0;
			//����һ��ͼƬ��ʾ����֮�󣬽�����Ϸ�����׶�
			if (nowDestroyImageIndex_ >= destroyImageVector_.size())
			{
				return false;
			}
			//������ʾ��һ��ͼƬ
			else
			{
				rimage() = destroyImageVector_[nowDestroyImageIndex_];
				nowDestroyImageIndex_++;
			}
		}
	}
	return true;
}