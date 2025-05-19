#ifndef PLANSZA_H
#define PLANSZA_H

#include <QWidget>
#include <QTimer>
#include "snake.h"

class Plansza : public QWidget
{
    Q_OBJECT

public:
    explicit Plansza(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateGra();

private:
    Snake snake;
    QTimer timer;
    int poleSize = 20;
};

#endif // PLANSZA_H
