#include "Window.h"
#include "Director.h"
#include "GameScene.h"
#include "QApplication"
#include "QDeskTopWidget"
#include "QStyle"

Window::Window()
	: QWidget()
{
	//��������
	setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_QuitOnClose, true);

	//��ȡ��������֮�����Ļ����
	QRect screenWithoutTaskBar = QApplication::desktop()->availableGeometry();

	//���ڱ���ʹ�С
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(900, screenWithoutTaskBar.height() - style()->pixelMetric(QStyle::PM_TitleBarHeight));

	//�ƶ�����Ļ����
	move(screenWithoutTaskBar.width() / 2 - width() / 2, 0);
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