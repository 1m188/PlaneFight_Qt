#include "scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), backgroundImg(QPixmap(":/planeFight/Resources/background.png")), enemyChoose(QVector<Enemy *(Scene::*)(QWidget *)>{})
{
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());
	//���ñ���
	QPalette p = palette();
	p.setBrush(QPalette::Background, QBrush(backgroundImg));
	setPalette(p);
	//���������ʽ
	setCursor(Qt::BlankCursor);

	//��ʼ�����������
	qsrand(QTime::currentTime().msec());

	//��ʼ���л�����ѡ��
	enemyChoose.push_back(reinterpret_cast<Enemy *(Scene::*)(QWidget *)>(&Scene::productSolider));
	enemyChoose.push_back(reinterpret_cast<Enemy *(Scene::*)(QWidget *)>(&Scene::productLeader));
	enemyChoose.push_back(reinterpret_cast<Enemy *(Scene::*)(QWidget *)>(&Scene::productGeneral));

	//��ʼ�����
	Player *player = new Player(this);

	//�����л��Ķ�ʱ��
	QTimer *productEnemyTimer = new QTimer(this);
	connect(productEnemyTimer, &QTimer::timeout, this, &Scene::productEnemy);
	productEnemyTimer->start(1000);

	show();
}

Scene::~Scene()
{

}

void Scene::productEnemy()
{
	auto solider = (this->*enemyChoose[rand() % (enemyChoose.size())])(this);
}