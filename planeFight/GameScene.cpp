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
	playerBulletImage.load(":/Resources/image/bullet1.png");

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
	player.rimageChangeFpsInterval() = 1000 / 60 * 13 / (1000 / fps);
	//����ÿ������֡����һ���ӵ�
	player.rproductBulletFpsInterval() = 1000 / 60 * 13 / (1000 / fps);
	//������ҷɻ�һ��ʼ��ͼƬ
	player.rimage() = player.normalImageVector()[0];
	//������ҷɻ����
	player.rwidth() = player.image().width();
	player.rheight() = player.image().height();
	//������ҷɻ���ʼ����
	player.rx() = width() / 2 - player.width() / 2;
	player.ry() = height() - player.height();
	//������ҷɻ�ÿ֡�������������н�����
	player.rdx() = 10 * 60 / fps;
	player.rdy() = 10 * 60 / fps;

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
		//��ҷɻ��ƶ�
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
		//����
		else if (event->key() == Qt::Key::Key_J)
		{
			player.risFiring() = true;
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
		else if (event->key() == Qt::Key::Key_J)
		{
			player.risFiring() = false;
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

	//��������ӵ�
	for (Bullet &playerBullet : playerBulletVector)
	{
		painter->drawPixmap(playerBullet.x(), playerBullet.y(), playerBullet.width(), playerBullet.height(), playerBullet.image());
	}

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

		//����
		player.rproductBulletFpsCounter()++;
		if (player.productBulletFpsCounter() == player.productBulletFpsInterval())
		{
			player.rproductBulletFpsCounter() = 0;
			if (player.isFiring())
			{
				//��ʼ������ӵ�
				Bullet bullet;
				//��������ӵ�ͼƬ
				bullet.rimage() = playerBulletImage;
				//��������ӵ����
				bullet.rwidth() = bullet.image().width();
				bullet.rheight() = bullet.image().height();
				//��������ӵ�����
				bullet.rx() = player.x() + player.width() / 2 - bullet.width() / 2;
				bullet.ry() = player.y() - bullet.y();
				//��������ӵ�ÿ֡�н�����
				bullet.rdy() = 10 * 60 / fps;
				//������ӵ�ѹ������ӵ�������ڹ������
				playerBulletVector.append(bullet);
			}
		}

		//�л���̬ͼƬ
		player.rnormalImageChangeFpsCounter()++;
		if (player.normalImageChangeFpsCounter() == player.imageChangeFpsInterval())
		{
			player.rnormalImageChangeFpsCounter() = 0;
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
		player.rdestroyImageChangeFpsCounter()++;
		if (player.destroyImageChangeFpsCounter() == player.imageChangeFpsInterval())
		{
			player.rdestroyImageChangeFpsCounter() = 0;
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

	//�����ӵ�״̬
	//����ӵ�
	//�ӵ��ƶ�
	for (int i = 0; i < playerBulletVector.size();)
	{
		playerBulletVector[i].ry() -= playerBulletVector[i].dy();
		if (playerBulletVector[i].y() + playerBulletVector[i].height() <= 0)
		{
			playerBulletVector.removeAt(i);
		}
		else
		{
			i++;
		}
	}

	//������Ϸ����
	update();
}