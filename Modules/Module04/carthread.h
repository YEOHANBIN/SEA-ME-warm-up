#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "car.h"
#include "racetrack.h"

class CarThread : public QObject{
    Q_OBJECT

private:
    Car *car;
    RaceTrack *raceTrack;
    QMutex mutex;

public:
    explicit CarThread(QObject *parent = nullptr, Car *car = nullptr, RaceTrack *raceTrack = nullptr);
    ~CarThread();

public slots:
    void updatePosition(int newPosition);
    void run();

signals:
    void finished();
};

#endif // CARTHREAD_H
