#include <iostream>
#include <cmath>
#include <random>
#include <vector>
using namespace std;












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



