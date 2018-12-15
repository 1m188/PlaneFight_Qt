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

	//��̬ͼƬ����
	QVector<QPixmap> normalImageVector_;
	//��ǰ��ʾ��̬ͼƬ����
	int nowNormalImageIndex_ = 0;

	//���ͼƬ����
	QVector<QPixmap> destroyImageVector_;
	//��ǰ��ʾ���ͼƬ����
	int nowDestroyImageIndex_ = 0;

	//ÿ������֡�л�һ�ų�̬/���ͼƬ
	int imageChangeFps_ = 0;

	//������Ŀ
	int life_ = 1;

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

	//��ȡÿ������֡�л�һ�ų�̬/���ͼƬ
	const int imageChangeFps() const { return imageChangeFps_; }
	//��ȡÿ������֡�л�һ�ų�̬/���ͼƬ������
	int &rimageChangeFps() { return imageChangeFps_; }

	//��ȡ������Ŀ
	const int life() const { return life_; }
	//��ȡ������Ŀ����
	int &rlife() { return life_; }

	//��ҷɻ��ƶ�
	void move(int up, int down, int left, int right);
};

#endif // PLAYER_H
