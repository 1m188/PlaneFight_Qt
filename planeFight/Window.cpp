#include "Window.h"
#include "QApplication"
#include "QDeskTopWidget"

Window::Window()
	: QWidget()
{
	//��������
	setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_QuitOnClose, true);

	//���ڱ���ʹ�С
	setWindowTitle(tr(u8"�ɻ���ս"));
	setFixedSize(700, 940);

	//�ƶ�����Ļ����
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());
}

Window::~Window()
{

}

void Window::keyPressEvent(QKeyEvent * event)
{
}

void Window::keyReleaseEvent(QKeyEvent * event)
{
}

void Window::show()
{
	QWidget::show();
}