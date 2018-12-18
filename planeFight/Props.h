#ifndef PROPS_H
#define PROPS_H

#include "Sprite.h"

//������
class Props :public Sprite
{
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

	//��ȡÿ֡���н�����
	const int dy() const { return dy_; }
	//��ȡÿ֡���н����������
	int &rdy() { return dy_; }

	//��ȡ�������͵�id
	const Props::Type type() const { return type_; }
	//��ȡ�������͵�id������
	Props::Type &rtype() { return type_; }

private:
	//ÿ֡���н�����
	int dy_ = 0;

	//��ʶ���͵�id
	Props::Type type_ = Props::Type::None;
};

#endif // PROPS_H
