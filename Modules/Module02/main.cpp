#include <iostream>
#include <string>

using namespace std;

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void print() override {
        cout << "Engine part\n";
    }
};

class Wheel : public Part {
public:
    void print() override {
        cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        cout << "Transmission part\n";
    }
};

class Suspension : public Part {
public:
    void print() override {
        cout << "Suspension part\n";
    }
};

class Steering : public Part {
public:
    void print() override {
        cout << "Steering part\n";
    }
};

class Seat : public Part {
public:
    void print() override {
        cout << "Seat part\n";
    }
};

class Car {
public:
    Car() {
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
        suspensions_ = new Suspension[4];
        steering_ = new Steering();
        seats_ = new Seat[6];
    }

    void printParts() {
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].print();
            brakes_[i].print();
            suspensions_[i].print();
        }
        transmission_->print();
    }

    ~Car() {
        delete engine_;
        delete [] wheels_;
        delete [] brakes_;
        delete transmission_;
        delete [] suspensions_;
        delete steering_;
        delete [] seats_;
    }

private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
    Suspension* suspensions_;
    Steering* steering_;
    Seat* seats_;
};

int main() {
    Car myCar;
    myCar.printParts();

    return 0;
}
