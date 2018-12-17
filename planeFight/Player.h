#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

//�����
class Player :public Sprite
{
private:
	//ÿ֡�����������ϵķ��о���
	int dx_ = 0;
	int dy_ = 0;

	//�Ƿ���/��/��/���ƶ�
	bool isUping_ = false;
	bool isDowning_ = false;
	bool isLefting_ = false;
	bool isRighting_ = false;

	//�Ƿ񿪻�
	bool isFiring_ = false;

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

	//ը����Ŀ
	int bombNum_ = 1;

public:
	Player();
	~Player();

	//��ȡÿ֡�����������ϵķ��о���
	const int dx() const { return dx_; }
	const int dy() const { return dy_; }
	//��ȡÿ֡�����������ϵķ��о��������
	int &rdx() { return dx_; }
	int &rdy() { return dy_; }

	//��ȡ�Ƿ���/��/��/���ƶ�
	const bool isUping() const { return isUping_; }
	const bool isDowning() const { return isDowning_; }
	const bool isLefting() const { return isLefting_; }
	const bool isRighting() const { return isRighting_; }
	//��ȡ�Ƿ���/��/��/���ƶ�������
	bool &risUping() { return isUping_; }
	bool &risDowning() { return isDowning_; }
	bool &risLefting() { return isLefting_; }
	bool &risRighting() { return isRighting_; }

	//��ȡ�Ƿ񿪻�
	const bool isFiring() const { return isFiring_; }
	bool &risFiring() { return isFiring_; }

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
	//��ȡ������Ŀ����
	int &rlife() { return life_; }

	//��ȡը����Ŀ
	const int bombNum() const { return bombNum_; }
	//��ȡը����Ŀ������
	int &rbombNum() { return bombNum_; }

	//��ҷɻ��ƶ�
	void move(int up, int down, int left, int right);
};

#endif // PLAYER_H
