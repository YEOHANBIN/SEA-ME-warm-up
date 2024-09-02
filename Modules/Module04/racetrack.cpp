#include "racetrack.h"

RaceTrack::RaceTrack(QObject *parent, int tSize, int fLine) : QObject(parent), size(tSize), finishLine(fLine){

}

int RaceTrack::getSize() const{
    return size;
}

void RaceTrack::setSize(int newSize){
    if(size != newSize){
        size = newSize;
        emit sizeChanged(size);
    }
}

int RaceTrack::getFinishLine() const{
    return finishLine;
}

void RaceTrack::setFinishLine(int newFinishLine){
    if(finishLine != newFinishLine){
        finishLine = newFinishLine;
        emit finishLineChanged(finishLine);
    }
}
