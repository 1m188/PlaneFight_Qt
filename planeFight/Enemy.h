#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"

//�л�
class Enemy :public Sprite
{
private:
	//ÿ����y�������ƶ��ľ���
	int dy_ = 0;

	//��̬ͼƬ����
	QVector<QPixmap> normalImageVector_;
	//��ǰ��ʾ��̬ͼƬ����
	int nowNormalImageIndex_ = 0;

	//���ͼƬ����
	QVector<QPixmap> destroyImageVector_;
	//��ǰ��ʾ���ͼƬ����
	int nowDestroyImageIndex_ = 0;

	//��̬ͼƬ�л���֡��
	int normalImageChangeFpsCounter_ = 0;
	//���ͼƬ�л���֡��
	int destroyImageChangeFpsCounter_ = 0;
	//�ӵ�������֡��
	int productBulletFpsCounter_ = 0;

	//ÿ������֡�л�һ�ų�̬/���ͼƬ
	int imageChangeFpsInterval_ = 0;
	//ÿ������֡�����ӵ�
	int productBulletFpsInterval_ = 0;

	//������Ŀ
	int life_ = 1;

public:
	Enemy();
	~Enemy();

	//��ʾ�л����͵�ö��
	enum Type
	{
		//��
		None,
		//ʿ������һ��л���
		Soldier,
		//�쵼���ڶ���л���
		Leader,
		//������������л���
		General,
	};

	//��ȡ�л������ʶ
	const Enemy::Type type() const { return type_; }
	//��ȡ�л������ʶ������
	Enemy::Type &rtype() { return type_; }

	//��ȡÿ����y�������ƶ��ľ���
	const int dy() const { return dy_; }
	//��ȡÿ����y�������ƶ��ľ��������
	int &rdy() { return dy_; }

	//��ȡ��̬/���ͼƬ����
	QVector<QPixmap> normalImageVector() { return normalImageVector_; }
	QVector<QPixmap> destroyImageVector() { return destroyImageVector_; }
	//��ȡ��̬/���ͼƬ���������
	QVector<QPixmap> &rnormalImageVector() { return normalImageVector_; }
	QVector<QPixmap> &rdestroyImageVector() { return destroyImageVector_; }

	//��ȡ��ǰ��ʾ��̬ͼƬ����
	const int nowNormalImageIndex() const { return nowNormalImageIndex_; }
	//��ȡ��ǰ��ʾ��̬ͼƬ����������
	int &rnowNormalImageIndex() { return nowNormalImageIndex_; }
	//��ȡ��ǰ��ʾ���ͼƬ����
	const int nowDestroyImageIndex() const { return nowDestroyImageIndex_; }
	//��ȡ��ǰ��ʾ���ͼƬ����������
	int &rnowDestroyImageIndex() { return nowDestroyImageIndex_; }

	//��ȡ��̬ͼƬ�л���֡��
	const int normalImageChangeFpsCounter() const { return normalImageChangeFpsCounter_; }
	//��ȡ��̬ͼƬ�л���֡��������
	int &rnormalImageChangeFpsCounter() { return normalImageChangeFpsCounter_; }

	//��ȡ���ͼƬ�л���֡��
	const int destroyImageChangeFpsCounter() const { return destroyImageChangeFpsCounter_; }
	//��ȡ���ͼƬ�л���֡��������
	int &rdestroyImageChangeFpsCounter() { return destroyImageChangeFpsCounter_; }

	//��ȡÿ������֡�л�һ�ų�̬/���ͼƬ
	const int imageChangeFpsInterval() const { return imageChangeFpsInterval_; }
	//��ȡÿ������֡�л�һ�ų�̬/���ͼƬ������
	int &rimageChangeFpsInterval() { return imageChangeFpsInterval_; }

	//��ȡ�ӵ�������֡��
	const int productBulletFpsCounter() const { return productBulletFpsCounter_; }
	//��ȡ�ӵ�������֡��������
	int &rproductBulletFpsCounter() { return productBulletFpsCounter_; }

	//��ȡÿ������֡�����ӵ�
	const int productBulletFpsInterval() const { return productBulletFpsInterval_; }
	//��ȡÿ������֡�����ӵ�������
	int &rproductBulletFpsInterval() { return productBulletFpsInterval_; }

	//��ȡ������Ŀ
	const int life() const { return life_; }
	int &rlife() { return life_; }

private:
	//��ʶ�л�����
	Enemy::Type type_ = Enemy::Type::None;
};

#endif // ENEMY_H
