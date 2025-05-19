#include "plansza.h"
#include <QPainter>
#include <QKeyEvent>

Plansza::Plansza(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus); // by reagować na klawisze
    setFixedSize(600, 400);
    setStyleSheet("background-color: black;");

    connect(&timer, &QTimer::timeout, this, &Plansza::updateGra);
    timer.start(150); // co 150 ms przesuwamy węża
    int cols = width() / poleSize;
    int rows = height() / poleSize;
    snake.setBoardSize(cols, rows);

}

void Plansza::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::green);

    for (const QPoint& segment : snake.getSegments()) {
        QRect rect(segment.x() * poleSize,
                   segment.y() * poleSize,
                   poleSize, poleSize);
        painter.drawRect(rect);
    }
}

void Plansza::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        snake.setDirection(Snake::Up);
        break;
    case Qt::Key_Down:
        snake.setDirection(Snake::Down);
        break;
    case Qt::Key_Left:
        snake.setDirection(Snake::Left);
        break;
    case Qt::Key_Right:
        snake.setDirection(Snake::Right);
        break;
    case Qt::Key_W:
        snake.setDirection(Snake::Up);
        break;
    case Qt::Key_S:
        snake.setDirection(Snake::Down);
        break;
    case Qt::Key_A:
        snake.setDirection(Snake::Left);
        break;
    case Qt::Key_D:
        snake.setDirection(Snake::Right);
        break;
    }
}

void Plansza::updateGra()
{
    snake.move();
    update(); // wymusza repaint
}
