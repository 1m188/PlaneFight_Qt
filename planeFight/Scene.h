#ifndef SCENE_H
#define SCENE_H

#include "Window.h"

//������
class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(Window *parent);
	virtual ~Scene();

	//�������¼���д��public�£�������Ϸ���ڵ��ô��ݰ����¼�
	virtual void keyPressEvent(QKeyEvent *event) override;
	virtual void keyReleaseEvent(QKeyEvent *event) override;

	//��ʼ������
	virtual void init();
};

#endif // SCENE_H
