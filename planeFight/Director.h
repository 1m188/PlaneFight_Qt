#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Window.h"

//������
class Director
{
private:
	Director(); //��ֹ�Զ�Ĭ�Ϲ���

	static Director *instance; //����ָ��

	Window *window; //��Ϸ����

public:
	Director(const Director &) = delete;
	Director &operator=(const Director &) = delete;
	~Director();

	static Director *getInstance(); //��ȡ����ָ��

	//��ȡ��Ϸ����ָ��
	Window *getWindow();
	//������Ϸ����ָ��
	void setWindow(Window *window);
};

#endif // DIRECTOR_H
