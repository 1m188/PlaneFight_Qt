#ifndef PROPS_H
#define PROPS_H

#include "Sprite.h"

//������
class Props :public Sprite
{
private:
	//ÿ֡���н�����
	int dy_ = 0;

public:
	Props();
	~Props();

	//��ʾ��������
	enum Type
	{
		//��
		None,
		//ը��
		Bomb,
		//��ҩ����
		Bullet,
	};

	//��ȡ�������͵�id
	const Props::Type type() const { return type_; }
	//��ȡ�������͵�id������
	Props::Type &rtype() { return type_; }

	//��ȡÿ֡���н�����
	const int dy() const { return dy_; }
	//��ȡÿ֡���н����������
	int &rdy() { return dy_; }

private:
	//��ʶ���͵�id
	Props::Type type_ = Props::Type::None;
};

#endif // PROPS_H
