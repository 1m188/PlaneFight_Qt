#include "GameScene.h"
#include "QPainter"

GameScene::GameScene(Window *parent)
	: Scene(parent)
{

}

GameScene::~GameScene()
{

}

void GameScene::init()
{
	//��ʼ����ϷԪ��
	backgroundImage.load(":/Resources/image/background.png");
	backgroundImage = backgroundImage.scaled(size()); //������ͼƬ�������ʹ���һ���󣬱��ڻ���
	againImage.load(":/Resources/image/again.png");
	gameoverImage.load(":/Resources/image/gameover.png");

	//��ʼ��֡��
	fps = 30;

	//������Ϸѭ��
	gameCycleTimer = new QTimer(this);
	connect(gameCycleTimer, &QTimer::timeout, this, &GameScene::gameCycleSlot);
	gameCycleTimer->setInterval(1000 / fps);
	gameCycleTimer->start();
}

void GameScene::keyPressEvent(QKeyEvent * event)
{
	QWidget::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent * event)
{
	QWidget::keyReleaseEvent(event);
}

void GameScene::paintEvent(QPaintEvent * event)
{
	QPainter *painter = new QPainter(this);

	painter->drawPixmap(0, 0, width(), height(), backgroundImage);

	painter->end();
	QWidget::paintEvent(event);
}

void GameScene::gameCycleSlot()
{
	//������Ϸ����
	update();
}