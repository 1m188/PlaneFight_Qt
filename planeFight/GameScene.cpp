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
	//����������ͼƬ��ǰ���ص��ڴ�֮�У�����ߵ��õ�Ч��
	backgroundImage.load(":/Resources/image/background.png");
	backgroundImage = backgroundImage.scaled(size()); //������ͼƬ�������ʹ���һ���󣬱��ڻ���

	againImage.load(":/Resources/image/again.png");
	gameoverImage.load(":/Resources/image/gameover.png");

	pauseNorImage.load(":/Resources/image/pause_nor.png");
	pausePressedImage.load(":/Resources/image/pause_pressed.png");
	resumeNorImage.load(":/Resources/image/resume_nor.png");
	resumePressedImage.load(":/Resources/image/resume_pressed.png");
	pauseResumeImage = pauseNorImage;

	playerNormalImageVector.append(QPixmap(":/Resources/image/me1.png"));
	playerNormalImageVector.append(QPixmap(":/Resources/image/me2.png"));
	playerDestroyImageVector.append(QPixmap(":/Resources/image/me_destroy_1.png"));
	playerDestroyImageVector.append(QPixmap(":/Resources/image/me_destroy_2.png"));
	playerDestroyImageVector.append(QPixmap(":/Resources/image/me_destroy_3.png"));
	playerDestroyImageVector.append(QPixmap(":/Resources/image/me_destroy_4.png"));

	enemy1NormalImageVector.append(QPixmap(":/Resources/image/enemy1.png"));
	enemy1DestroyImageVector.append(QPixmap(":/Resources/image/enemy1_down1.png"));
	enemy1DestroyImageVector.append(QPixmap(":/Resources/image/enemy1_down2.png"));
	enemy1DestroyImageVector.append(QPixmap(":/Resources/image/enemy1_down3.png"));
	enemy1DestroyImageVector.append(QPixmap(":/Resources/image/enemy1_down4.png"));

	enemy2NormalImageVector.append(QPixmap(":/Resources/image/enemy2.png"));
	enemy2DestroyImageVector.append(QPixmap(":/Resources/image/enemy2_down1.png"));
	enemy2DestroyImageVector.append(QPixmap(":/Resources/image/enemy2_down2.png"));
	enemy2DestroyImageVector.append(QPixmap(":/Resources/image/enemy2_down3.png"));
	enemy2DestroyImageVector.append(QPixmap(":/Resources/image/enemy2_down4.png"));
	enemy2HitImageVector.append(QPixmap(":/Resources/image/enemy2_hit.png"));

	enemy3NormalImageVector.append(QPixmap(":/Resources/image/enemy3_n1.png"));
	enemy3NormalImageVector.append(QPixmap(":/Resources/image/enemy3_n2.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down1.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down2.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down3.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down4.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down5.png"));
	enemy3DestroyImageVector.append(QPixmap(":/Resources/image/enemy3_down6.png"));
	enemy3HitImageVector.append(QPixmap(":/Resources/image/enemy3_hit.png"));

	playerBulletImage.load(":/Resources/image/bullet1.png");
	enemyBulletImage.load(":/Resources/image/bullet2.png");

	lifeImage.load(":/Resources/image/life.png");

	bombImage.load(":/Resources/image/bomb.png");
	bombPropsImage.load(":/Resources/image/bomb_supply.png");

	//��ʼ��֡��
	fps = 60;

	//��ʼ���Ƿ���ͣ��־
	isPause = false;
	//û�б�����
	isPauseResumeClicked = false;

	//��ʼ����ҷɻ�
	//������ҷɻ���̬ͼƬ
	player.rnormalImageVector() = playerNormalImageVector;
	//������ҷɻ����ͼƬ
	player.rdestroyImageVector() = playerDestroyImageVector;
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

	//��ʼ�����߲���
	productPropsFpsCounter = 0;
	productPropsFpsInterval = 1000 / 60 * 1000 / (1000 / fps);

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
		//ʹ��ը����ȫͼ��ը
		else if (event->key() == Qt::Key::Key_B)
		{
			if (player.bombNum() > 0)
			{
				player.rbombNum()--;
				for (Enemy &enemy : enemyVector)
				{
					enemy.rlife() = 0;
				}
			}
		}
	}
	Scene::keyPressEvent(event);
}

void GameScene::mousePressEvent(QMouseEvent * event)
{
	//����ҷɻ�������ʱ�򣬼���Ϸ��δ������ʱ��
	if (player.life() > 0)
	{
		QPoint pos = event->pos();
		//��������ͣ/������ť
		if (pos.x() >= width() - pauseResumeImage.width() && pos.x() <= width() && pos.y() >= 0 && pos.y() <= pauseResumeImage.height())
		{
			if (isPause)
			{
				pauseResumeImage = resumePressedImage;
			}
			else
			{
				pauseResumeImage = pausePressedImage;
			}
		}
	}
	Scene::mousePressEvent(event);
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
	Scene::keyReleaseEvent(event);
}

void GameScene::mouseReleaseEvent(QMouseEvent * event)
{
	//����ҷɻ�������ʱ�򣬼���Ϸ��δ������ʱ��
	if (player.life() > 0)
	{
		QPoint pos = event->pos();
		//����ͣ/������ť���ͷ�
		if (pos.x() >= width() - pauseResumeImage.width() && pos.x() <= width() && pos.y() >= 0 && pos.y() <= pauseResumeImage.height())
		{
			if (isPause)
			{
				pauseResumeImage = pauseNorImage;
			}
			else
			{
				pauseResumeImage = resumeNorImage;
			}
			isPause = !isPause;
		}
	}
	Scene::mouseReleaseEvent(event);
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

	//���Ƶ���
	for (Props &props : propsVector)
	{
		painter->drawPixmap(props.x(), props.y(), props.width(), props.height(), props.image());
	}

	//������ͣ/������ť
	painter->drawPixmap(width() - pauseResumeImage.width(), 0, pauseResumeImage.width(), pauseResumeImage.height(), pauseResumeImage);

	//��������
	painter->drawPixmap(0, height() - lifeImage.height(), lifeImage.width(), lifeImage.height(), lifeImage);
	painter->setFont(QFont(u8"΢���ź�", 25, 10));
	painter->drawText(lifeImage.width(), height() - lifeImage.height(), lifeImage.width(), lifeImage.height(), Qt::AlignCenter, QString::number(player.life()));

	//����ը����Ŀ
	painter->drawPixmap(width() - bombImage.width() * 2, height() - bombImage.height(), bombImage.width(), bombImage.height(), bombImage);
	painter->setFont(QFont(u8"΢���ź�", 25, 10));
	painter->drawText(width() - bombImage.width(), height() - bombImage.height(), bombImage.width(), bombImage.height(), Qt::AlignCenter, QString::number(player.bombNum()));

	painter->end();
	Scene::paintEvent(event);
}

void GameScene::gameCycleSlot()
{
	//���û����ͣ�������״̬
	if (!isPause)
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

			//���ײ�ϵл�
			for (int i = 0; i < enemyVector.size(); i++)
			{
				Enemy &enemy = enemyVector[i];
				if (player.isCollided(enemy) && enemy.life() > 0)
				{
					player.rlife() = 0;
					enemy.rlife() = 0;
				}
			}

			//���ײ�ϵ���
			for (int i = 0; i < propsVector.size(); i++)
			{
				Props &props = propsVector[i];
				if (player.isCollided(props))
				{
					if (props.type() == Props::Type::Bomb)
					{
						player.rbombNum()++;
					}
					propsVector.removeAt(i);
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
				//����һ��ͼƬ��ʾ����֮��ֹͣ��Ϸ������£�������Ϸ�����׶�
				if (player.nowDestroyImageIndex() >= player.destroyImageVector().size())
				{
					gameCycleTimer->stop();

					//��Ϸ����
				}
				//������ʾ��һ��ͼƬ
				else
				{
					player.rimage() = player.destroyImageVector()[player.nowDestroyImageIndex()];
					player.rnowDestroyImageIndex()++;
				}
			}
		}


		//����л�״̬
		//�л�����
		productEnemyFpsCounter++;
		if (productEnemyFpsCounter == productEnemyFpsInterval)
		{
			productEnemyFpsCounter = 0;

			int enemyIndex = qrand() % 13;

			//��ʼ���л�
			Enemy enemy;
			if (enemyIndex >= 0 & enemyIndex <= 8)
			{
				//���õл��ĳ�̬ͼƬ
				enemy.rnormalImageVector() = enemy1NormalImageVector;
				//���õл������ͼƬ
				enemy.rdestroyImageVector() = enemy1DestroyImageVector;
				//���õл�ÿ������֡����һ���ӵ�
				enemy.rproductBulletFpsInterval() = 1000 / 60 * 50 / (1000 / fps);
				//���õл�ÿ֡��y�����ϵ��н�����
				enemy.rdy() = 3 * 60 / fps;
			}
			else if (enemyIndex >= 9 && enemyIndex <= 11)
			{
				//���õл��ĳ�̬ͼƬ
				enemy.rnormalImageVector() = enemy2NormalImageVector;
				//���õл������ͼƬ
				enemy.rdestroyImageVector() = enemy2DestroyImageVector;
				//���õл�ÿ������֡����һ���ӵ�
				enemy.rproductBulletFpsInterval() = 1000 / 60 * 45 / (1000 / fps);
				//���õл�ÿ֡��y�����ϵ��н�����
				enemy.rdy() = 2 * 60 / fps;
				//���õл�����
				enemy.rlife() = 6;
			}
			else if (enemyIndex == 12)
			{
				//���õл��ĳ�̬ͼƬ
				enemy.rnormalImageVector() = enemy3NormalImageVector;
				//���õл������ͼƬ
				enemy.rdestroyImageVector() = enemy3DestroyImageVector;
				//���õл�ÿ������֡����һ���ӵ�
				enemy.rproductBulletFpsInterval() = 1000 / 60 * 40 / (1000 / fps);
				//���õл�ÿ֡��y�����ϵ��н�����
				enemy.rdy() = 1 * 60 / fps;
				//���õл�����
				enemy.rlife() = 16;
			}
			//���õл�ÿ������֡�л�һ��ͼƬ
			enemy.rimageChangeFpsInterval() = 1000 / 60 * 13 / (1000 / fps);
			//���õл�һ��ʼ��ͼƬ
			enemy.rimage() = enemy.normalImageVector()[0];
			//���õл�һ��ʼ�Ŀ��
			enemy.rwidth() = enemy.image().width();
			enemy.rheight() = enemy.image().height();
			//���õл�һ��ʼ���������
			enemy.rx() = qrand() % (width() - enemy.width() + 1);
			enemy.ry() = -enemy.height();

			//�л���������
			enemyVector.append(enemy);
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
					//�������ͼƬ��չʾ��������������Ƴ�ȥ
					if (enemy.nowDestroyImageIndex() >= enemy.destroyImageVector().size())
					{
						enemyVector.removeAt(i);
						i--;
						continue;
					}
					//�������չʾ��һ��ͼƬ
					else
					{
						enemy.rimage() = enemy.destroyImageVector()[enemy.nowDestroyImageIndex()];
						enemy.rnowDestroyImageIndex()++;
					}
				}
			}
		}


		//�����ӵ�״̬
		//����ӵ�
		for (int i = 0; i < playerBulletVector.size(); i++)
		{
			//�ӵ��ƶ�
			Bullet &bullet = playerBulletVector[i];
			bullet.ry() -= bullet.dy();
			//������ͼ�߽�����ڴ���ɾ��
			if (bullet.y() + bullet.height() <= 0)
			{
				playerBulletVector.removeAt(i);
				i--;
			}
			//�����ж��Ƿ�ײ���˴��л�
			else
			{
				for (int j = 0; j < enemyVector.size(); j++)
				{
					Enemy &enemy = enemyVector[j];
					//���ײ����
					if (bullet.isCollided(enemy) && enemy.life() > 0)
					{
						//�л�����ֵ�ۼ�
						enemy.rlife()--;
						//�л�����̬ͼƬ
						if (enemy.life() <= 4 && enemy.normalImageVector()[0].cacheKey() == enemy2NormalImageVector[0].cacheKey())
						{
							enemy.rnormalImageVector() = enemy2HitImageVector;
							enemy.rnowNormalImageIndex() = 0;
						}
						else if (enemy.life() <= 8 && enemy.normalImageVector()[0].cacheKey() == enemy3NormalImageVector[0].cacheKey())
						{
							enemy.rnormalImageVector() = enemy3HitImageVector;
							enemy.rnowNormalImageIndex() = 0;
						}
						//�ӵ�ɾ��
						playerBulletVector.removeAt(i);
						i--;
						break;
					}
				}
			}
		}

		//�л��ӵ�
		//�ӵ��ƶ�
		for (int i = 0; i < enemyBulletVector.size(); i++)
		{
			Bullet &bullet = enemyBulletVector[i];
			bullet.ry() += bullet.dy();
			//����ӵ�������ͼ�߽�
			if (bullet.y() >= height())
			{
				enemyBulletVector.removeAt(i);
				i--;
			}
			//�����ж��Ƿ������ҷɻ�
			else
			{
				if (bullet.isCollided(player) && player.life() > 0)
				{
					player.rlife()--;
					enemyBulletVector.removeAt(i);
					i--;
				}
			}
		}

		//�������
		//���߲���
		productPropsFpsCounter++;
		if (productPropsFpsCounter == productPropsFpsInterval)
		{
			productPropsFpsCounter = 0;

			//��ʼ������
			Props props;
			//��������
			props.rtype() = Props::Type::Bomb;
			//����ͼƬ
			props.rimage() = bombPropsImage;
			//���ÿ��
			props.rwidth() = props.image().width();
			props.rheight() = props.image().height();
			//��������
			props.rx() = qrand() % (width() - props.width() + 1);
			props.ry() = -props.height();
			//����ÿ֡�ƶ�����
			props.rdy() = 2 * 60 / fps;
			//�������鷽��ͳһ����
			propsVector.append(props);
		}

		//�����ƶ�
		for (int i = 0; i < propsVector.size(); i++)
		{
			Props &props = propsVector[i];
			props.ry() += props.dy();
			if (props.y() >= height())
			{
				propsVector.removeAt(i);
				i--;
			}
		}
	}


	//������Ϸ����
	update();
}