#include "carthread.h"

CarThread::CarThread(QObject *parent, Car *car, RaceTrack *raceTrack) : QObject(parent), car(car), raceTrack(raceTrack){
}

CarThread::~CarThread(){
}

void CarThread::updatePosition(int newPosition){
}

void CarThread::run(){
    while(car->getPosition() < raceTrack->getFinishLine()){
        mutex.lock();
        car->move();
        mutex.unlock();
        QThread::msleep(10);
    }
    emit finished();
}
