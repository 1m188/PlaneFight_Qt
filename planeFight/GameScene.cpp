#include "GameScene.h"
#include "QPainter"
#include "QKeyEvent"

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
	fps = 60;

	//��ʼ����ҷɻ�
	//������ҷɻ���̬ͼƬ
	player.rnormalImageVector().append(QPixmap(":/Resources/image/me1.png"));
	player.rnormalImageVector().append(QPixmap(":/Resources/image/me2.png"));
	//������ҷɻ����ͼƬ
	player.rdestroyImageVector().append(QPixmap(":/Resources/image/me_destroy_1.png"));
	player.rdestroyImageVector().append(QPixmap(":/Resources/image/me_destroy_2.png"));
	player.rdestroyImageVector().append(QPixmap(":/Resources/image/me_destroy_3.png"));
	player.rdestroyImageVector().append(QPixmap(":/Resources/image/me_destroy_4.png"));
	//����ÿ������֡�л�һ����ҷɻ�ͼƬ
	player.rimageChangeFps() = 1000 / 60 * 13 / (1000 / fps);
	//������ҷɻ�һ��ʼ��ͼƬ
	player.rimage() = player.normalImageVector()[0];
	//������ҷɻ����
	player.rwidth() = player.image().width();
	player.rheight() = player.image().height();
	//������ҷɻ���ʼ����
	player.rx() = width() / 2 - player.width() / 2;
	player.ry() = height() - player.height();
	//������ҷɻ�ÿ֡�������������н�����
	player.rdx() = 20 * 30 / fps;
	player.rdy() = 20 * 30 / fps;

	//������Ϸѭ��
	gameCycleTimer = new QTimer(this);
	connect(gameCycleTimer, &QTimer::timeout, this, &GameScene::gameCycleSlot);
	gameCycleTimer->setInterval(1000 / fps);
	gameCycleTimer->start();
}

void GameScene::keyPressEvent(QKeyEvent * event)
{
	if (!event->isAutoRepeat())
	{
		if (event->key() == Qt::Key::Key_W)
		{
			player.risUping() = true;
		}
		else if (event->key() == Qt::Key::Key_S)
		{
			player.risDowning() = true;
		}
		else if (event->key() == Qt::Key::Key_A)
		{
			player.risLefting() = true;
		}
		else if (event->key() == Qt::Key::Key_D)
		{
			player.risRighting() = true;
		}
	}
	QWidget::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent * event)
{
	if (!event->isAutoRepeat())
	{
		if (event->key() == Qt::Key::Key_W)
		{
			player.risUping() = false;
		}
		else if (event->key() == Qt::Key::Key_S)
		{
			player.risDowning() = false;
		}
		else if (event->key() == Qt::Key::Key_A)
		{
			player.risLefting() = false;
		}
		else if (event->key() == Qt::Key::Key_D)
		{
			player.risRighting() = false;
		}
	}
	QWidget::keyReleaseEvent(event);
}

void GameScene::paintEvent(QPaintEvent * event)
{
	QPainter *painter = new QPainter(this);

	//���Ʊ���
	painter->drawPixmap(frameGeometry(), backgroundImage);

	//�������
	painter->drawPixmap(player.x(), player.y(), player.width(), player.height(), player.image());

	painter->end();
	QWidget::paintEvent(event);
}

void GameScene::gameCycleSlot()
{
	//����״̬
	//�������״̬
	//�����Ҵ��
	if (player.life() > 0)
	{
		//�ƶ�
		player.move(0, height(), 0, width());

		//�л���̬ͼƬ
		player.rfpsCounter()++;
		if (player.fpsCounter() == player.imageChangeFps())
		{
			player.rfpsCounter() = 0;
			player.rimage() = player.normalImageVector()[player.nowNormalImageIndex()];
			player.rnowNormalImageIndex()++;
			//����һ��ͼƬ��ʾ����֮�󣬼�����ʾ��һ��ͼƬ
			if (player.nowNormalImageIndex() >= player.normalImageVector().size())
			{
				player.rnowNormalImageIndex() = 0;
			}
		}
	}
	//������ʾ��ٹ���
	else
	{
		//�л����ͼƬ
		player.rfpsCounter()++;
		if (player.fpsCounter() == player.imageChangeFps())
		{
			player.rfpsCounter() = 0;
			player.rimage() = player.destroyImageVector()[player.nowDestroyImageIndex()];
			player.rnowDestroyImageIndex()++;
			//����һ��ͼƬ��ʾ����֮��ֹͣ��Ϸ������£�������Ϸ�����׶�
			if (player.nowDestroyImageIndex() >= player.destroyImageVector().size())
			{
				gameCycleTimer->stop();

				//��Ϸ����
			}
		}
	}

	//������Ϸ����
	update();
}