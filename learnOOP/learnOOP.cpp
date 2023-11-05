#include <iostream>
#include <iomanip>

using namespace std;

class Figure {
public:
    void print() {}
};

class Point : public Figure {
protected:
    double _x{ 0.0 };

public:
    Point(double x) : _x(x) {};

    ~Point() {
        _x = 0.0;
    }

public:
    void print() {
        cout << "Point (" << _x << ")" << endl;
    }

    double getX() {
        return this->_x;
    }
};

class Point2D : public Point {
protected:
    double _y{ 0.0 };

public:
    Point2D(double x, double y) : Point(x), _y(y) {};

    ~Point2D() {
        _y = 0.0;
    }

public:
    void print() {
        cout << "Point2D (" << _x << ", " << _y << ")" << endl;
    }

    double getY() {
        return this->_y;
    }
};

class Point3D : public Point2D {
protected:
    double _z{ 0.0 };

public:
    Point3D(double x, double y) : Point2D(x, y) {};

    Point3D(double x, double y, double z) : Point3D(x, y)  {
        _z = z;
    };

    ~Point3D() {
        _z = 0.0;
    }

public:
    void print() {
        cout << "Point3D (" << _x << ", " << _y << ", " << _z << ")" << endl;
    }

    double getZ() {
        return this->_z;
    }
};

class Section : public Figure {
private:
    Point3D* startPoint;
    Point3D* endPoint;

public:
    Section(Point3D* startPoint, Point3D* endPoint) : startPoint(startPoint), endPoint(endPoint) {}

    ~Section() {

    }

public:
    void print() {
        cout << "Section ";
        startPoint->print();
        endPoint->print();
    }   
};

class FlatFigure : public Figure {
public:
    double area() {
        return 0.0;
    }
};

class Triangle : public FlatFigure {
protected:
    Point3D* point1;
    Point3D* point2;
    Point3D* point3;

public:
    Triangle(Point3D* point1, Point3D* point2, Point3D* point3) : point1(point1), point2(point2), point3(point3) {}

    ~Triangle() {

    }

public:
    void print() {
        cout << "Triangle ";
        point1->print();
        point2->print();
        point3->print();
    }
    

    double sideA() {
        return sqrt(pow(point2->getX() - point1->getX(), 2) + pow(point2->getY() - point1->getY(), 2) + pow(point2->getZ() - point1->getZ(), 2));
    }

    double sideB() {
        return sqrt(pow(point3->getX() - point1->getX(), 2) + pow(point3->getY() - point1->getY(), 2) + pow(point3->getZ() - point1->getZ(), 2));
    }

    double sideC() {
        return sqrt(pow(point3->getX() - point2->getX(), 2) + pow(point3->getY() - point2->getY(), 2) + pow(point3->getZ() - point2->getZ(), 2));
    }

    double area() {
        double p = (sideA() + sideB() + sideC()) / 2;

        return sqrt(p * (p - sideA()) * (p - sideB()) * (p - sideC()));
    }

};

class Tetragon : public FlatFigure {
protected:
    Section* side1;
    Section* side2;

public:
    Tetragon(Section* side1, Section* side2) : side1(side1), side2(side2) {}
    void print() {
        cout << "Tetragon ";
        side1->print();
        side1->print();
    }

    double area() {
        // Реализация вычисления площади четырехугольника
        double area = 0.0; // Замените на фактический расчет площади
        return area;
    }

};

int main() {
    setlocale(LC_ALL, "Rus");

    Point3D a(-3, -8, -8);
    Point3D b(4, -2, -1);
    Point3D c(10, 8, 5);

    Triangle s(&a, &b, &c);
    cout << fixed << setprecision(6) << s.area();

    return 0;
}


