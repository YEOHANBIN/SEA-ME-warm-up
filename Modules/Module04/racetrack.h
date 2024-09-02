#ifndef RACETRACK_H
#define RACETRACK_H

#include <QObject>

class RaceTrack : public QObject
{
    Q_OBJECT
private:
    int size;
    int finishLine;

public:
    explicit RaceTrack(QObject *parent = nullptr, int tSize = 0, int fLine = 0);

    int getSize() const;
    void setSize(int newSize);
    int getFinishLine() const;
    void setFinishLine(int newFinishLine);

signals:
    void finishLineChanged(int newFinishLine);
    void sizeChanged(int newSize);
};

#endif // RACETRACK_H
