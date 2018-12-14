#include "Director.h"

Director *Director::instance = nullptr; //��ʼ������ָ��

Director::Director() :window(nullptr)
{

}

Director::~Director()
{

}

Director * Director::getInstance()
{
	if (!instance)
	{
		instance = new Director();
	}
	return instance;
}

Window * Director::getWindow()
{
	return window;
}

void Director::setWindow(Window * window)
{
	this->window = window;
}

Scene * Director::getNowScene()
{
	return nowScene;
}

void Director::setNowScene(Scene * nowScene)
{
	this->nowScene = nowScene;
}