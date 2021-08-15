#include <qsfml.h>

QSFMLCanvas::QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, uint frameTimeMs) :
QWidget(parent), initialized(false)
{
	QWidget::setAttribute(Qt::WA_PaintOnScreen);
	QWidget::setAttribute(Qt::WA_OpaquePaintEvent);
	QWidget::setAttribute(Qt::WA_NoSystemBackground);

	QWidget::setFocusPolicy(Qt::StrongFocus);
	QWidget::move(position);
	QWidget::resize(size);

	refreshTimer.setInterval(frameTimeMs);
}
QSFMLCanvas::~QSFMLCanvas() {

}

QPaintEngine* QSFMLCanvas::paintEngine() const {
	return 0;
}

// Will be called after QWidget::show() and window restore
void QSFMLCanvas::showEvent(QShowEvent*) {
	if(!initialized) { // ignore window restore
		RenderWindow::create(QWidget::winId());
		
		OnInit();
		QWidget::connect(&refreshTimer, SIGNAL(timeout()),this, SLOT(repaint()));
		refreshTimer.start();

		initialized = true;
	}
}
void QSFMLCanvas::paintEvent(QPaintEvent*) {
	OnUpdate();
	// Just like window.display() in while loop main
	RenderWindow::display();
}
