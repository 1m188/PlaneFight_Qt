#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include "QLabel"
#include "QPushButton"
#include "enemysolider.h"
#include "enemyleader.h"
#include "enemygeneral.h"

//��Ϸ����
class GameScene : public QWidget
{
	Q_OBJECT

public:
	GameScene(QWidget *parent);
	~GameScene();

private:
	//ͼƬ
	QPixmap backgroundImg;
	QPixmap againImg;
	QPixmap gameoverImg;

	//��Ϸ��������Ϣ��ǩ�͹���button
	QLabel *gameOverLabel;
	QPushButton *againButton;
	QPushButton *gameoverButton;

	//�л�ѡ������
	QVector<Enemy *(GameScene::*)(QWidget *)> enemyChoose;

	//����л���timer
	QTimer *productEnemyTimer;

	//��Ϸ�Ƿ����
	bool isGameOver;

	//�����л�ѡ����
	EnemySolider *productSolider(QWidget *parent) { return new EnemySolider(parent); }
	EnemyLeader *productLeader(QWidget *parent) { return new EnemyLeader(parent); }
	EnemyGeneral *productGeneral(QWidget *parent) { return new EnemyGeneral(parent); }

protected:
	void keyPressEvent(QKeyEvent *event) override; //��д�����¼�

	private slots:
	//����л�
	void productEnemy();
	//��Ϸ����
	void gameOver();
	//�������¿�ʼ��ť
	void againButtonClicked();
};

#endif // GAMESCENE_H