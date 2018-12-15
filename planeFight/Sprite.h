#ifndef SPRITE_H
#define SPRITE_H

#include "QPixmap"

//������
class Sprite
{
private:
	//���Ͻ�����
	int x_ = 0;
	int y_ = 0;

	//���
	int width_ = 0;
	int height_ = 0;

	//ͼƬ
	QPixmap image_;

	//��֡��
	int fpsCounter_ = 0;

public:
	Sprite();
	virtual ~Sprite();

	//��ȡ���Ͻ�����
	const int x() const { return x_; }
	const int y() const { return y_; }
	//��ȡ���Ͻ���������
	int &rx() { return x_; }
	int &ry() { return y_; }

	//��ȡ���
	const int width() const { return width_; }
	const int height() const { return height_; }
	//��ȡ�������
	int &rwidth() { return width_; }
	int &rheight() { return height_; }

	//��ȡͼƬ
	const QPixmap image() const { return image_; }
	//��ȡͼƬ����
	QPixmap &rimage() { return image_; }

	//��ȡ��֡��
	const int fpsCounter() const { return fpsCounter_; }
	//��ȡ��֡��������
	int &rfpsCounter() { return fpsCounter_; }

	//��ײ���
	const bool isCollided(Sprite s) const;
};

#endif // SPRITE_H
