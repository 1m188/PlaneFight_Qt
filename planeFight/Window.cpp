#include "Window.h"
#include "Director.h"
#include "GameScene.h"
#include "QApplication"
#include "QDeskTopWidget"

Window::Window()
	: QWidget()
{
	//��������
	setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_QuitOnClose, true);

	//���ڱ���ʹ�С
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);

	//�ƶ�����Ļ����
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());
}

Window::~Window()
{

}

void Window::keyPressEvent(QKeyEvent * event)
{
	Director::getInstance()->getNowScene()->keyPressEvent(event);
}

void Window::keyReleaseEvent(QKeyEvent * event)
{
	Director::getInstance()->getNowScene()->keyReleaseEvent(event);
}

void Window::show()
{
	GameScene *gameScene = new GameScene(this);
	Director::getInstance()->setNowScene(gameScene);
	gameScene->init();
	gameScene->show();
	QWidget::show();
}