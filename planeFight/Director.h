#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Window.h"
#include "Scene.h"

//������
class Director
{
private:
	Director(); //��ֹ�Զ�Ĭ�Ϲ���

	static Director *instance; //����ָ��

	Window *window; //��Ϸ����
	Scene *nowScene; //��ǰ��Ӧ����

public:
	Director(const Director &) = delete;
	Director &operator=(const Director &) = delete;
	~Director();

	static Director *getInstance(); //��ȡ����ָ��

	//��ȡ��Ϸ����ָ��
	Window *getWindow();
	//������Ϸ����ָ��
	void setWindow(Window *window);

	//��ȡ��ǰ��Ӧ����
	Scene *getNowScene();
	//���õ�ǰ��Ӧ����
	void setNowScene(Scene *nowScene);
};

#endif // DIRECTOR_H
