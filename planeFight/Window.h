#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

//��Ϸ������
class Window : public QWidget
{
	Q_OBJECT

public:
	Window();
	~Window();

	void show(); //��дԭ����show������ʹ��show��ʱ���ܹ����ֳ�ʼ����

protected:
	//��д�����¼��������͵����ڵİ����¼����͵���Ӧ������
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // WINDOW_H
