#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

//�����
class Player :public Sprite
{
private:
	//ÿ֡�����������ϵķ��о���
	int dx_;
	int dy_;

	//�Ƿ���/��/��/���ƶ�
	bool isUping_;
	bool isDowning_;
	bool isLefting_;
	bool isRighting_;

	//��̬ͼƬ����
	QVector<QPixmap> normalImageVector_;

	//���ͼƬ����
	QVector<QPixmap> destroyImageVector_;

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

	//��ҷɻ��ƶ�
	void move(int up, int down, int left, int right);
};

#endif // PLAYER_H
