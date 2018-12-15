#include "GameScene.h"
#include "QPainter"
#include "QKeyEvent"
#include "QTime"

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
	enemyBulletImage.load(":/Resources/image/bullet2.png");

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

	//��ʼ���л�����
	productEnemyFpsCounter = 0;
	productEnemyFpsInterval = 1000 / 60 * 100 / (1000 / fps);
	srand(QTime::currentTime().msec()); //��ʼ���������

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

	//���Ƶл�
	for (Enemy &enemy : enemyVector)
	{
		painter->drawPixmap(enemy.x(), enemy.y(), enemy.width(), enemy.height(), enemy.image());
	}

	//��������ӵ�
	for (Bullet &playerBullet : playerBulletVector)
	{
		painter->drawPixmap(playerBullet.x(), playerBullet.y(), playerBullet.width(), playerBullet.height(), playerBullet.image());
	}

	//���Ƶл��ӵ�
	for (Bullet &enemyBullet : enemyBulletVector)
	{
		painter->drawPixmap(enemyBullet.x(), enemyBullet.y(), enemyBullet.width(), enemyBullet.height(), enemyBullet.image());
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


	//����л�״̬
	//�л�����
	productEnemyFpsCounter++;
	if (productEnemyFpsCounter == productEnemyFpsInterval)
	{
		productEnemyFpsCounter = 0;

		//��ʼ���л�
		Enemy enemy1;
		//���õл��ĳ�̬ͼƬ
		enemy1.rnormalImageVector().append(QPixmap(":/Resources/image/enemy1.png"));
		//���õл������ͼƬ
		enemy1.rdestroyImageVector().append(QPixmap(":/Resources/image/enemy1_down1.png"));
		enemy1.rdestroyImageVector().append(QPixmap(":/Resources/image/enemy1_down2.png"));
		enemy1.rdestroyImageVector().append(QPixmap(":/Resources/image/enemy1_down3.png"));
		enemy1.rdestroyImageVector().append(QPixmap(":/Resources/image/enemy1_down4.png"));
		//���õл�ÿ������֡�л�һ��ͼƬ
		enemy1.rimageChangeFpsInterval() = 1000 / 60 * 13 / (1000 / fps);
		//���õл�ÿ������֡����һ���ӵ�
		enemy1.rproductBulletFpsInterval() = 1000 / 60 * 50 / (1000 / fps);
		//���õл�һ��ʼ��ͼƬ
		enemy1.rimage() = enemy1.normalImageVector()[0];
		//���õл�һ��ʼ�Ŀ��
		enemy1.rwidth() = enemy1.image().width();
		enemy1.rheight() = enemy1.image().height();
		//���õл�һ��ʼ���������
		enemy1.rx() = qrand() % (width() - enemy1.width() + 1);
		enemy1.ry() = -enemy1.height();
		//���õл�ÿ֡��y�����ϵ��н�����
		enemy1.rdy() = 3 * 60 / fps;

		//�л���������
		enemyVector.append(enemy1);
	}

	//����״̬
	for (int i = 0; i < enemyVector.size(); i++)
	{
		Enemy &enemy = enemyVector[i];

		//����л�����
		if (enemy.life() > 0)
		{
			//�ƶ�
			enemy.ry() += enemy.dy();
			//������ͼ�߽�����ڴ���ɾ��
			if (enemy.y() >= height())
			{
				enemyVector.removeAt(i);
				i--;
				continue;
			}

			//����
			enemy.rproductBulletFpsCounter()++;
			if (enemy.productBulletFpsCounter() == enemy.productBulletFpsInterval())
			{
				enemy.rproductBulletFpsCounter() = 0;

				//��ʼ���л��ӵ�
				Bullet bullet;
				//���õл��ӵ�ͼƬ
				bullet.rimage() = enemyBulletImage;
				//���õл��ӵ����
				bullet.rwidth() = bullet.image().width();
				bullet.rheight() = bullet.image().height();
				//���õл��ӵ�����
				bullet.rx() = enemy.x() + enemy.width() / 2 - bullet.width() / 2;
				bullet.ry() = enemy.y() + enemy.height();
				//���õл��ӵ�ÿ֡���н�����
				bullet.rdy() = 5 * 60 / fps;
				//ѹ��л��ӵ�����
				enemyBulletVector.append(bullet);
			}

			//�л���̬ͼƬ
			enemy.rnormalImageChangeFpsCounter()++;
			if (enemy.normalImageChangeFpsCounter() == enemy.imageChangeFpsInterval())
			{
				enemy.rnormalImageChangeFpsCounter() = 0;
				enemy.rimage() = enemy.normalImageVector()[enemy.nowNormalImageIndex()];
				enemy.rnowNormalImageIndex()++;
				if (enemy.nowNormalImageIndex() >= enemy.normalImageVector().size())
				{
					enemy.rnowNormalImageIndex() = 0;
				}
			}
		}
		//����չʾ���ͼƬ��չʾ����֮����������Ƴ�ȥ
		else
		{
			enemy.rdestroyImageChangeFpsCounter()++;
			if (enemy.destroyImageChangeFpsCounter() == enemy.imageChangeFpsInterval())
			{
				enemy.rdestroyImageChangeFpsCounter() = 0;
				enemy.rimage() = enemy.destroyImageVector()[enemy.nowDestroyImageIndex()];
				enemy.rnowDestroyImageIndex()++;
				if (enemy.nowDestroyImageIndex() >= enemy.destroyImageVector().size())
				{
					enemyVector.removeAt(i);
					i--;
					continue;
				}
			}
		}
	}


	//�����ӵ�״̬
	//����ӵ�
	//�ӵ��ƶ�
	for (int i = 0; i < playerBulletVector.size(); i++)
	{
		Bullet &bullet = playerBulletVector[i];
		bullet.ry() -= bullet.dy();
		//������ͼ�߽�����ڴ���ɾ��
		if (bullet.y() + bullet.height() <= 0)
		{
			playerBulletVector.removeAt(i);
			i--;
		}
	}

	//�л��ӵ�
	//�ӵ��ƶ�
	for (int i = 0; i < enemyBulletVector.size(); i++)
	{
		Bullet &bullet = enemyBulletVector[i];
		bullet.ry() += bullet.dy();
		if (bullet.y() + bullet.height() <= 0)
		{
			enemyBulletVector.removeAt(i);
			i--;
		}
	}


	//������Ϸ����
	update();
}