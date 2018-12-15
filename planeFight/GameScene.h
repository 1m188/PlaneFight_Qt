#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QTimer.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

//��Ϸ����
class GameScene : public Scene
{
	Q_OBJECT

private:
	//ͼƬ
	QPixmap backgroundImage; //����ͼƬ
	QPixmap againImage;
	QPixmap gameoverImage;

	QVector<QPixmap> playerNormalImageVector; //��ҳ�̬ͼƬ
	QVector<QPixmap> playerDestroyImageVector; //������ͼƬ

	QVector<QPixmap> enemy1NormalImageVector; //�л�1��̬ͼƬ
	QVector<QPixmap> enemy1DestroyImageVector; //�л�1���ͼƬ

	QVector<QPixmap> enemy2NormalImageVector; //�л�2��̬ͼƬ
	QVector<QPixmap> enemy2DestroyImageVector; //�л�2���ͼƬ

	QVector<QPixmap> enemy3NormalImageVector; //�л�3��̬ͼƬ
	QVector<QPixmap> enemy3DestroyImageVector; //�л�3���ͼƬ

	QPixmap playerBulletImage; //����ӵ�ͼƬ
	QPixmap enemyBulletImage; //�л��ӵ�ͼƬ

	//���
	Player player;
	//����ӵ�����
	QVector<Bullet> playerBulletVector;
	//�л�����
	QVector<Enemy> enemyVector;
	//�л��ӵ�����
	QVector<Bullet> enemyBulletVector;

	//�л�������֡��
	int productEnemyFpsCounter;
	//ÿ������֡����һ�ܵл�
	int productEnemyFpsInterval;

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
