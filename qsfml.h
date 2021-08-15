#ifndef __QSFML__H_
#define __QSFML__H_

#include <QtWidgets>
#include <SFML/Graphics.hpp>

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
	Q_OBJECT
public:
	QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, uint frameTimeMs = 1000/60) ;
	virtual ~QSFMLCanvas();
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

class canvas: public QSFMLCanvas 
{
public:
	canvas(QWidget* parent, const QPoint& position, const QSize& size) :
	QSFMLCanvas(parent, position, size) {

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