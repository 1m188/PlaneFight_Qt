#include "scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), backgroundImg(QPixmap(":/planeFight/Resources/background.png"))
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

	//�л�����

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
	EnemySolider *e = new EnemySolider(this);
	qDebug() << children().size();
}