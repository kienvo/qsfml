/*!
 * \file    qsfml.h
 * \brief   A tool for creating frame file using led p10 module
 * \author  kienvo (kienlab.com)
 * \version 0.1
 * \date    Aug-14-2021
 */
#ifndef __QSFML__H_
#define __QSFML__H_

#include <QtWidgets>
#include <SFML/Graphics.hpp>

class QSFML : public QWidget, public sf::RenderWindow
{
	//Q_OBJECT
public:
	QSFML(QWidget* parent, const QPoint& position, uint frameTimeMs = 1000/60) ;
	QSFML(QWidget* parent, const QPoint& position, const QSize& size, uint frameTimeMs = 1000/60):
	QSFML(parent, position, frameTimeMs)
	{
		QWidget::resize(size);
	}
	virtual ~QSFML();
private:
	virtual void OnInit() =0; // implement this function doing stuff on initialize
	virtual void OnUpdate() =0; // SFML code
	virtual QPaintEngine* paintEngine() const;
	virtual void showEvent(QShowEvent*);
	virtual void paintEvent(QPaintEvent*);
	QTimer refreshTimer;
	bool initialized;
};

#endif //__QSFML__H_

/* example

class canvas: public QSFML
{
public:
	canvas(QWidget* parent, const QPoint& position, const QSize& size) :
	QSFML(parent, position, size) {

	}
private:
	void OnInit() {
		circle.setRadius(5.f);
		circle.setPosition(10.f, 10.f);
		circle.setOrigin(circle.getRadius()/2.f, circle.getRadius()/2.f);
		return;
	}
	void OnUpdate() {
		RenderWindow::clear();
		circle.setPosition(circle.getPosition()+sf::Vector2f(1.f, 1.f));
		RenderWindow::draw(circle);
	}
	sf::CircleShape circle;
};

*/