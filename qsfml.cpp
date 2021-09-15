/*!
 * \file    qsfml.cpp
 * \brief   A tool for creating frame file using led p10 module
 * \author  kienvo (kienlab.com)
 * \version 0.1
 * \date    Aug-14-2021
 */
#include <qsfml/qsfml.h>

QSFML::QSFML(QWidget* parent, const QPoint& position, uint frameTimeMs) :
QWidget(parent), initialized(false)
{
	QWidget::setAttribute(Qt::WA_PaintOnScreen);
	QWidget::setAttribute(Qt::WA_OpaquePaintEvent);
	QWidget::setAttribute(Qt::WA_NoSystemBackground);

	QWidget::setFocusPolicy(Qt::StrongFocus);
	QWidget::move(position);

	refreshTimer.setInterval(frameTimeMs);
}


QSFML::~QSFML() {

}

QPaintEngine* QSFML::paintEngine() const {
	return 0;
}

// Will be called after QWidget::show() and window restore
void QSFML::showEvent(QShowEvent*) {
	if(!initialized) { // ignore window restore
		RenderWindow::create(QWidget::winId());
		
		OnInit();
		// C++11 lambda
		// https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
		QWidget::connect(&refreshTimer, &QTimer::timeout, [=](){this->repaint();});
		refreshTimer.start();

		initialized = true;
	}
}
void QSFML::paintEvent(QPaintEvent*) {
	OnUpdate(); 
	// RenderWindow::display() should be call in OnUpdate function
}
