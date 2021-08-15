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