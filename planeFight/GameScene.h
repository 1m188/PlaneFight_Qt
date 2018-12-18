#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QTimer.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Props.h"

//��Ϸ����
class GameScene : public Scene
{
	Q_OBJECT

private:
	//ͼƬ
	QPixmap backgroundImage; //����ͼƬ

	QPixmap againImage; //����һ����Ϸ��ť
	QPixmap gameOverImage; //��Ϸ������ť

	QPixmap pauseNorImage; //��ͣ��ť��û����ʱ��
	QPixmap pausePressedImage; //��ͣ��ť������ʱ��
	QPixmap resumeNorImage; //������ť��û����ʱ��
	QPixmap resumePressedImage; //������ť������ʱ��
	QPixmap pauseResumeImage; //ʵ�ʱ����Ƶ���ͣ/������ť

	QVector<QPixmap> playerNormalImageVector; //��ҳ�̬ͼƬ
	QVector<QPixmap> playerDestroyImageVector; //������ͼƬ

	QVector<QPixmap> enemy1NormalImageVector; //�л�1��̬ͼƬ
	QVector<QPixmap> enemy1DestroyImageVector; //�л�1���ͼƬ

	QVector<QPixmap> enemy2NormalImageVector; //�л�2��̬ͼƬ
	QVector<QPixmap> enemy2DestroyImageVector; //�л�2���ͼƬ
	QVector<QPixmap> enemy2HitImageVector; //�л�2��̬ͼƬ

	QVector<QPixmap> enemy3NormalImageVector; //�л�3��̬ͼƬ
	QVector<QPixmap> enemy3DestroyImageVector; //�л�3���ͼƬ
	QVector<QPixmap> enemy3HitImageVector; //�л�3��̬ͼƬ

	QPixmap playerBulletImage; //����ӵ�ͼƬ
	QPixmap enemyBulletImage; //�л��ӵ�ͼƬ

	QPixmap lifeImage; //����ͼƬ

	QPixmap bombImage; //ը��ͼƬ
	QPixmap bombPropsImage; //ը������ͼƬ
	QPixmap bulletPropsImage; //��ҩ����ͼƬ

	//���
	Player player;
	//����ӵ�����
	QVector<Bullet> playerBulletVector;
	//�л�����
	QVector<Enemy> enemyVector;
	//�л��ӵ�����
	QVector<Bullet> enemyBulletVector;
	//��������
	QVector<Props> propsVector;

	//�л�������֡��
	int productEnemyFpsCounter;
	//ÿ������֡����һ�ܵл�
	int productEnemyFpsInterval;

	//���߲�����֡��
	int productPropsFpsCounter;
	//ÿ������֡����һ���������
	int productPropsFpsInterval;

	//��ҩ������֡��
	int bulletPropsLastFpsCounter;
	//��ҩ�������߳���֡��
	int bulletPropsLastFps;

	//��ǰ����
	int score;

	//֡��
	int fps;

	//�Ƿ���ͣ
	bool isPause;
	//��ͣ/������ť�Ƿ񱻰���
	bool isPauseResumeClicked;
	//���һ��ʼ���µ�ʱ��������Ƿ�����ͣ/������ť��
	bool isClickedInPuaseButton;

	//��Ϸ�Ƿ����
	bool isGameOver;
	//��Ϸ������ص���Ϣ��ť�İڷŵ�λ��
	QRect gameEndTextRect;
	QRect againRect;
	QRect gameOverRect;

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
	//��д��갴���¼�
	void mousePressEvent(QMouseEvent *event) override;
	//��д����ͷ��¼�
	void mouseReleaseEvent(QMouseEvent *event) override;
	//��д��갴ס����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *event) override;

	private slots:
	//��Ϸѭ��
	void gameCycleSlot();
};

#endif // GAMESCENE_H
