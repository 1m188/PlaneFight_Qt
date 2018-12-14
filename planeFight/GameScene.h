#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

//��Ϸ����
class GameScene : public Scene
{
	Q_OBJECT

private:
	//ͼƬ
	QPixmap backgroundImage;
	QPixmap againImage;
	QPixmap gameoverImage;

public:
	GameScene(Window *parent);
	~GameScene();

	void init() override; //��ʼ����Ϸ����

	//��д�����¼�
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMESCENE_H
