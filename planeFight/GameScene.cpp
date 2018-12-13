#include "GameScene.h"
#include "QApplication"
#include "QDeskTopWidget"
#include "QBitMap"
#include "QTime"
#include "QTimer"
#include "QKeyEvent"
#include "player.h"

GameScene::GameScene(QWidget *parent)
	: QWidget(parent), backgroundImg(QPixmap(":/planeFight/Resources/background.png")), againImg(":/planeFight/Resources/again.png"), gameoverImg(":/planeFight/Resources/gameover.png"), gameOverLabel(new QLabel(this)), againButton(new QPushButton(this)), gameoverButton(new QPushButton(this)), enemyChoose(QVector<Enemy *(GameScene::*)(QWidget *)>{}), productEnemyTimer(new QTimer(this)), isGameOver(false)
{
	//����ʹ�С
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);

	//�ƶ�����������
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());

	//���ñ���
	QPalette p = palette();
	p.setBrush(QPalette::Background, QBrush(backgroundImg));
	setPalette(p);

	//������Ϸ��������Ͱ�ť
	gameOverLabel->setAlignment(Qt::AlignCenter);
	gameOverLabel->setFont(QFont(u8"΢���ź�", 20));
	QPalette pa = QPalette();
	pa.setColor(QPalette::WindowText, Qt::blue);
	gameOverLabel->setPalette(pa);
	gameOverLabel->setText(tr(u8"ʤ���˱��ҳ��£���������������"));
	gameOverLabel->resize(gameOverLabel->sizeHint());
	gameOverLabel->move(width() / 2 - gameOverLabel->width() / 2, height() / 2 - gameOverLabel->height() / 2 - 200);
	gameOverLabel->hide();

	againButton->setFocusPolicy(Qt::NoFocus);
	againButton->setIcon(QIcon(againImg));
	againButton->setIconSize(againImg.size());
	againButton->setStyleSheet("QPushButton{border:0px}");
	againButton->resize(againButton->iconSize());
	againButton->move(width() / 2 - againButton->width() / 2, gameOverLabel->y() + gameOverLabel->height() + 50);
	againButton->hide();
	connect(againButton, &QPushButton::clicked, this, &GameScene::againButtonClicked);

	gameoverButton->setFocusPolicy(Qt::NoFocus);
	gameoverButton->setIcon(QIcon(gameoverImg));
	gameoverButton->setIconSize(gameoverImg.size());
	gameoverButton->setStyleSheet("QPushButton{border:0px}");
	gameoverButton->resize(gameoverButton->iconSize());
	gameoverButton->move(width() / 2 - gameoverButton->width() / 2, againButton->y() + againButton->height() + 50);
	gameoverButton->hide();
	connect(gameoverButton, &QPushButton::clicked, &QApplication::quit);

	//���������ʽ
	setCursor(Qt::BlankCursor);

	//��ʼ�����������
	qsrand(QTime::currentTime().msec());

	//��ʼ���л�����ѡ��
	enemyChoose.push_back(reinterpret_cast<Enemy *(GameScene::*)(QWidget *)>(&GameScene::productSolider));
	enemyChoose.push_back(reinterpret_cast<Enemy *(GameScene::*)(QWidget *)>(&GameScene::productLeader));
	enemyChoose.push_back(reinterpret_cast<Enemy *(GameScene::*)(QWidget *)>(&GameScene::productGeneral));

	//��ʼ�����
	Player *player = new Player(this);
	connect(player, &Player::planeDestroyed, this, &GameScene::gameOver);
	player->show();

	//�����л��Ķ�ʱ��
	connect(productEnemyTimer, &QTimer::timeout, this, &GameScene::productEnemy);
	productEnemyTimer->start(1000);
}

GameScene::~GameScene()
{

}

void GameScene::productEnemy()
{
	auto solider = (this->*enemyChoose[rand() % (enemyChoose.size())])(this);
}

//�ۣ����������ͣ����д�ĺö��İ���������ͣ���ֱ�����Ӧ����ȫ�ֵ�Ψһ�Ա�����������ô�ܹ���ÿһ
//���̳���Game����඼��һ������������
//Ȼ�������ø��ˣ�����
//���������Űɣ��Ժ�ʲôʱ���Ҹ�ʱ������дһ������ɻ���ս������
void GameScene::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Space)
	{
		if (!isGameOver)
		{
			for (QObject *i : children())
			{
				Game *g = dynamic_cast<Game *>(i);
				if (g)
				{
					if (!g->getPaused() && productEnemyTimer->isActive())
					{
						productEnemyTimer->stop();
						setCursor(Qt::ArrowCursor);
					}
					else if (g->getPaused() && !productEnemyTimer->isActive())
					{
						productEnemyTimer->start(1000);
						setCursor(Qt::BlankCursor);
					}
					break;
				}
			}
			for (QObject *i : children())
			{
				Game *j = dynamic_cast<Game *>(i);
				if (j)
				{
					j->setPaused(!j->getPaused());
				}
			}
		}
	}
	return QWidget::keyPressEvent(event);
}

void GameScene::gameOver()
{
	keyPressEvent(new QKeyEvent(QEvent::Type::KeyPress, Qt::Key_Space, Qt::KeyboardModifier::NoModifier));
	isGameOver = true;
	gameOverLabel->show();
	gameOverLabel->raise();
	againButton->show();
	againButton->raise();
	gameoverButton->show();
	gameoverButton->raise();
}

//��������������ͣ�����������ȫ�ֵĶ����ģ�������
//�������д�ļ��䲻˳��������
//��ʼ��˳�����߰��㣬������
void GameScene::againButtonClicked()
{
	//���ؽ�������
	gameOverLabel->hide();
	againButton->hide();
	gameoverButton->hide();

	//������е�Enemy��Bullet�༰�����������
	for (QObject *i : children())
	{
		Enemy *e = dynamic_cast<Enemy *>(i);
		if (e)
		{
			e->deleteLater();
		}
		else
		{
			Bullet *b = dynamic_cast<Bullet *>(i);
			if (b)
			{
				b->deleteLater();
			}
		}
	}

	isGameOver = false;

	//ȡ����ͣ״̬
	keyPressEvent(new QKeyEvent(QEvent::Type::KeyPress, Qt::Key_Space, Qt::KeyboardModifier::NoModifier));

	//��ʼ�����
	Player *player = new Player(this);
	connect(player, &Player::planeDestroyed, this, &GameScene::gameOver);
	player->show();
}