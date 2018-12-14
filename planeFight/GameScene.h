#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QLabel"
#include "QPushButton"

//��Ϸ����
class GameScene : public Scene
{
	Q_OBJECT

private:
	//ͼƬ
	QPixmap backgroundImg;
	QPixmap againImg;
	QPixmap gameoverImg;

	//��Ϸ��������Ϣ��ǩ�͹���button
	QLabel *gameOverLabel;
	QPushButton *againButton;
	QPushButton *gameoverButton;

	//����л���timer
	QTimer *productEnemyTimer;

	//��Ϸ�Ƿ����
	bool isGameOver;

public:
	GameScene(Window *parent);
	~GameScene();

	void init() override; //��ʼ����Ϸ����
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
