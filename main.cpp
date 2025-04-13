#include <iostream>
#include <cmath>
#include <random>
#include <vector>
using namespace std;

class Process {
public:
    string name;
    string status;
    int time;
public:
    virtual void printInfo(){}
    virtual ~Process(){}
};

class Machining : public Process {
public:
    void printInfo() override {
        cout << "Process: " << name << endl;
        cout << "Process status: " << status << endl;
        cout << "Process time: " << time << endl;
    }
    Machining() {
        this->name = "Machining";
        this->status = "running";
        this->time = 10000;
    }
};

class Diagnostics : public Process {
public:
    void printInfo() override {
        cout << "Process: " << name << endl;
        cout << "Process status: " << status << endl;
        cout << "Process time: " << time << endl;
    }
    Diagnostics() {
        this->name = "Diagnostics";
        this->status = "running";
        this->time = 10000;
    }
};

class QualityCheck : public Process {
public:
    void printInfo() override {
        cout << "Process: " << name << endl;
        cout << "Process status: " << status << endl;
        cout << "Process time: " << time << endl;
    }
    QualityCheck() {
        this->name = "Quality Check";
        this->status = "running";
        this->time = 10000;
    }
};

class Repair : public Process {
public:
    void printInfo() override {
        cout << "Process: " << name << endl;
        cout << "Process status: " << status << endl;
        cout << "Process time: " << time << endl;
    }
    Repair() {
        this->name = "Repair";
        this->status = "running";
        this->time = 10000;
    }
};

class MonitoringSystem {
private:
    vector<Process*> processes;
public:
    void addProcess(Process* process) {
        processes.push_back(process);
    }

    void setVectorSize(int size) {
        processes.reserve(size);
    }
    void removeProcess(int i) {
        if (i >= 0 and i < processes.size()) {
            processes[i]->status = {"Removed"};
            cout << "Process removed." << endl;
        } else {
            cout << "Invalid index!" << endl;
        }
    }



    void setTime(int i, int time) {
        if (i >= 0 and i < processes.size()) {
            processes[i]->time = {time};
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void showAllProcess() {
        if (processes.size() > 0) {
            for (int i = 0; i < processes.size(); i++) {
                processes[i]->printInfo();
                cout << endl;
            }
        } else {
            cout << "Array is empty..." << endl;
        }
    };

    ~MonitoringSystem() {
        for (int i = 0; i < processes.size(); i++) {
            delete processes[i];
        }
    }
};








class Figure {
public:
    virtual void print() {}
    virtual ~Figure() {}
};
class Rectangle : public Figure {
private:
    float width;
    float height;
public:
    Rectangle(float width,  float height) : width(width), height(height) {}
    void print() override {
        cout << "This is rectangle with square: " << width*height << endl;
    }
};
class Circle : public Figure {
private:
    float radius;
public:
    Circle(float radius) : radius(radius) {}
    void print() override {
        cout << "This is circle with square: " << M_PI * radius * radius << endl;
    }
};
class Triangle : public Figure {
private:
    float base;
    float height;
public:
    Triangle(float base, float height) : base(base), height(height) {}
    void print() override {
        cout << "This is triangle with square: " << base * height * 0.5 << endl;
    }
};
int main() {

    while (true) {
        int number;
        cout << "Please enter a number of exersice: ";
        cin >> number;
        if (number == 1) {
            srand(time(NULL));
            cout << "Enter the number of figures you want to enter: ";
            int n;
            cin >> n;
            vector<Figure*> figures;
            figures.reserve(n);
            for (int i = 0; i < n; i++) {
                switch (rand() % 3) {
                    case 0:
                        figures.push_back(new Circle(1+ rand() % 10));
                    break;
                    case 1:
                        figures.push_back(new Rectangle(1 + rand() % 10,1+ rand() % 10));
                    break;
                    case 2:
                        figures.push_back(new Triangle(1 + rand() % 10,1 + rand() % 10));
                    break;
                }
            }

            for (int i = 0; i < figures.size(); i++) {
                figures[i]->print();
            }
            for (int i = 0; i < figures.size(); i++) {
                delete figures[i];
            }
        }
        if (number == 2) {
            MonitoringSystem monitoringSystem;

            int n_1;
            cout << "Enter the number of processes you want to enter: ";
            cin >> n_1;
            monitoringSystem.setVectorSize(n_1);
            srand(time(NULL));
            for (int i = 0; i < n_1; i++) {
                switch (rand() % 4) {
                    case 0:
                        monitoringSystem.addProcess(new Machining);
                    break;
                    case 1:
                        monitoringSystem.addProcess(new Diagnostics);
                    break;
                    case 2:
                        monitoringSystem.addProcess(new Repair);
                    break;
                    case 3:
                        monitoringSystem.addProcess(new Repair);
                    break;
                }
            }
            bool ix{true};
            while (ix) {
                int choice;
                cout << "What you want: 1 - set time to process 2 - remove process" << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter the number of processes you want to set time: ";
                        int q;
                        cin >> q;
                        cout << "Enter the time: ";
                        int time;
                        cin >> time;
                        monitoringSystem.setTime(q, time);
                    break;
                    case 2:
                        cout << "Enter the number of processes you want to set time: ";
                        int q_1;
                        cin >> q_1;
                        monitoringSystem.removeProcess(q_1);
                    break;
                }
                string input_1;
                cout << endl << "Stop y/n";
                cin >> input_1;
                if (input_1 == "y" or input_1 == "Y") ix = false;
            }
            monitoringSystem.showAllProcess();



            }








        if (number != 1 and number != 2) {
            cout << "Error! Enter a valid number!" << endl;
        }

        string input;
        cout << endl << "Stop y/n";
        cin >> input;
        if (input == "y" or input == "Y") break;
        }

}



