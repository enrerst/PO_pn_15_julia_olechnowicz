#ifndef SNAKE_H
#define SNAKE_H

#include <QVector>
#include <QPoint>

class Snake
{
public:
    enum Direction { Up, Down, Left, Right };

    Snake();                  // konstruktor
    ~Snake();                 // destruktor

    void move();              // ruch węża
    void grow();              // powiększenie (po zjedzeniu jedzenia)
    void setDirection(Direction dir);
    Direction getDirection() const;

    QVector<QPoint> getSegments() const; // zwraca segmenty węża
    void setBoardSize(int width, int height);


private:
    QVector<QPoint> segments;  // segmenty węża, każdy punkt to pole na planszy
    Direction currentDirection;
    int boardWidth;
    int boardHeight;

};

#endif // SNAKE_H
