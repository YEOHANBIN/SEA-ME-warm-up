#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject
{
    Q_OBJECT

private:
    int position;
    int speed;
    int direction;

public:
    explicit Car(QObject * parent = nullptr, int pos = 0, int spd = 0, int dir = 1);

    void move();

    int getPosition() const;
    void setPosition(int newPosition);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getDirection() const;
    void setDirection(int newDerection);

signals:
    void positionChanged(int newPosition);
};

#endif // CAR_H
