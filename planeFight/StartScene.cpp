#include "StartScene.h"
#include "Director.h"
#include "QLabel"
#include "QPushButton"
#include "QGridLayout"
#include "QApplication"

StartScene::StartScene(Window *parent)
	: Scene(parent)
{

}

StartScene::~StartScene()
{

}

void StartScene::init()
{
	//�ؼ�
	QLabel *infoLabel = new QLabel(this);
	infoLabel->setAlignment(Qt::AlignCenter);
	infoLabel->setFont(QFont(u8"΢���ź�", 40));
	infoLabel->setText(tr(u8"��  ��  ��  ս"));

	QPushButton *newGameButton = new QPushButton(this);
	newGameButton->setFont(QFont(u8"΢���ź�", 15));
	newGameButton->setText(tr(u8"��ʼ����Ϸ"));

	QPushButton *highestScoreButton = new QPushButton(this);
	highestScoreButton->setFont(QFont(u8"΢���ź�", 15));
	highestScoreButton->setText(tr(u8"��߷�"));

	QPushButton *settingButton = new QPushButton(this);
	settingButton->setFont(QFont(u8"΢���ź�", 15));
	settingButton->setText(tr(u8"����"));

	QPushButton *quitButton = new QPushButton(this);
	quitButton->setFont(QFont(u8"΢���ź�", 15));
	quitButton->setText(u8"�˳�");
	connect(quitButton, &QPushButton::clicked, this, &QApplication::quit);

	//����
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(infoLabel, 0, 0, 10, 15);
	layout->addWidget(newGameButton, 10, 5, 2, 5);
	layout->addWidget(highestScoreButton, 12, 5, 2, 5);
	layout->addWidget(settingButton, 14, 5, 2, 5);
	layout->addWidget(quitButton, 16, 5, 2, 5);
}