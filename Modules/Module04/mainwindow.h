#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include <QMutex>
#include "racetrack.h"
#include "car.h"
#include "carthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startRace();
    void pauseRace();
    void exitGame();

private:
    Ui::MainWindow *ui;
    RaceTrack *raceTrack;
    QList<Car*> carList;
    QList<QThread*> threadList;
    QList<CarThread*> carThreadList;

    void setupConnections();
};

#endif // MAINWINDOW_H
