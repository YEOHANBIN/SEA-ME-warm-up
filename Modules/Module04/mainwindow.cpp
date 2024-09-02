#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QMessageBox>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , raceTrack(new RaceTrack(this)) {

    ui->setupUi(this);

    // Example setup: create 3 cars with different speeds
    for (int i = 0; i < 3; ++i) {
        Car *car = new Car(this, 0, 5 + i, 1);  // Cars with different speeds
        carList.append(car);

        CarThread *carThread = new CarThread(this, car, raceTrack);
        carThreadList.append(carThread);
    }

    // Setup button connections
    setupConnections();
}

// Destructor
MainWindow::~MainWindow() {
    // Clean up all threads and cars
    for (auto thread : threadList) {
        thread->quit();
        thread->wait();
        delete thread;
    }
    for (auto carThread : carThreadList) {
        delete carThread;
    }
    for (auto car : carList) {
        delete car;
    }
    delete raceTrack;
    delete ui;
}

// Setup UI button connections
void MainWindow::setupConnections() {
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startRace);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::pauseRace);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);
}

// Start race
void MainWindow::startRace() {
    foreach (Car *car, carList) {
        QThread *thread = new QThread();
        CarThread *carThread = carThreadList[carList.indexOf(car)];
        carThread->moveToThread(thread);

        connect(car, &Car::positionChanged, carThread, &CarThread::updatePosition);
        connect(thread, &QThread::started, carThread, &CarThread::run);
        connect(carThread, &CarThread::finished, thread, &QThread::quit);
        connect(carThread, &CarThread::finished, carThread, &CarThread::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        threadList.append(thread);
        thread->start();
    }
}

// Pause race
void MainWindow::pauseRace() {
    for (auto thread : threadList) {
        thread->quit(); // Stop the thread
        thread->wait();
    }
}

// Exit game
void MainWindow::exitGame() {
    close();
}
