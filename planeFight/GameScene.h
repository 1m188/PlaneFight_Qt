#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QTimer.h"
#include "Player.h"
#include "Bullet.h"

//��Ϸ����
class GameScene : public Scene
{
	Q_OBJECT

private:
	//ͼƬ
	QPixmap backgroundImage; //����ͼƬ
	QPixmap againImage;
	QPixmap gameoverImage;
	QPixmap playerBulletImage; //����ӵ�ͼƬ

	//���
	Player player;
	//����ӵ�����
	QVector<Bullet> playerBulletVector;

	//֡��
	int fps;

	//��Ϸѭ����ʱ��
	QTimer *gameCycleTimer;

public:
	GameScene(Window *parent);
	~GameScene();

	//��ʼ����Ϸ����
	void init() override;

	//��д�����¼�
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;

protected:
	//��д�����¼�
	void paintEvent(QPaintEvent *event) override;

	private slots:
	//��Ϸѭ��
	void gameCycleSlot();
};

#endif // GAMESCENE_H
