#include "car.h"

Car::Car(QObject *parent, int pos, int spd, int dir) : QObject(parent), position(pos), speed(spd), direction(dir){

}

void Car::move(){
    position += speed * direction;
    emit positionChanged(position);
}

int Car::getPosition() const{
    return position;
}

void Car::setPosition(int newPosition){
    if(position != newPosition){
        position = newPosition;
        emit positionChanged(position);
    }
}

int Car::getSpeed() const{
    return speed;
}

void Car::setSpeed(int newSpeed){
    speed = newSpeed;
}

int Car::getDirection() const{
    return direction;
}

void Car::setDirection(int newDerection){
    direction = newDerection;
}
