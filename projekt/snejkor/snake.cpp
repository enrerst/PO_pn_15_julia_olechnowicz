#include "snake.h"

Snake::Snake()
{
    // start: 3 segmenty, poziomo, zaczynamy w punkcie (5,5)
    segments.append(QPoint(5, 5));
    segments.append(QPoint(4, 5));
    segments.append(QPoint(3, 5));
    currentDirection = Right;
}

Snake::~Snake()
{
    boardWidth = 30;
    boardHeight = 20;

}

void Snake::setBoardSize(int width, int height)
{
    boardWidth = width;
    boardHeight = height;
}


void Snake::move()
{
    QPoint head = segments.first();

    switch (currentDirection) {
    case Up:    head.ry() -= 1; break;
    case Down:  head.ry() += 1; break;
    case Left:  head.rx() -= 1; break;
    case Right: head.rx() += 1; break;
    }

    // ✨ Wrapowanie — teleportacja przez krawędzie
    if (head.x() < 0) head.setX(boardWidth - 1);
    if (head.x() >= boardWidth) head.setX(0);
    if (head.y() < 0) head.setY(boardHeight - 1);
    if (head.y() >= boardHeight) head.setY(0);

    segments.prepend(head);
    segments.removeLast();
}


void Snake::grow()
{
    // dodaj nowy segment na końcu, tak jak obecny ogon
    QPoint tail = segments.last();
    segments.append(tail);
}

void Snake::setDirection(Direction dir)
{
    // nie pozwól na zawracanie (np. prawo -> lewo)
    if ((currentDirection == Up && dir == Down) ||
        (currentDirection == Down && dir == Up) ||
        (currentDirection == Left && dir == Right) ||
        (currentDirection == Right && dir == Left)) {
        return;
    }
    currentDirection = dir;
}

Snake::Direction Snake::getDirection() const
{
    return currentDirection;
}

QVector<QPoint> Snake::getSegments() const
{
    return segments;
}
