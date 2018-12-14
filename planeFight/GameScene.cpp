#include "GameScene.h"

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
	againImage.load(":/Resources/image/again.png");
	gameoverImage.load(":/Resources/image/gameover.png");

	//���ñ���
	setAutoFillBackground(true);
	QPalette p = palette();
	p.setBrush(QPalette::Background, QBrush(backgroundImage));
	setPalette(p);
}

void GameScene::keyPressEvent(QKeyEvent * event)
{
	QWidget::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent * event)
{
	QWidget::keyReleaseEvent(event);
}