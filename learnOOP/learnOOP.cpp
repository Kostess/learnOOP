#include <iostream>

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
    Point3D(double x, double y, double z) : Point2D(x, y), _z(z) {};

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
    Point2D* startPoint;
    Point2D* endPoint;

public:
    Section(Point2D* startPoint, Point2D* endPoint) : startPoint(startPoint), endPoint(endPoint) {}


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
    Point2D* point2D_1;
    Point2D* point2D_2;
    Point2D* point2D_3;

    Point3D* point3D_1;
    Point3D* point3D_2;
    Point3D* point3D_3;

public:
    Triangle(Point2D* point1, Point2D* point2, Point2D* point3) : point2D_1(point1), point2D_2(point2), point2D_3(point3) {}
    Triangle(Point3D* point1, Point3D* point2, Point3D* point3) : point3D_1(point1), point3D_2(point2), point3D_3(point3) {}

public:
    void print() {
        cout << "Triangle ";
        point2D_1->print();
        point2D_2->print();
        point2D_3->print();
    }
    
    double sideA_2D() {
        return sqrt(pow(point2D_2->getX() - point2D_1->getX(), 2) + pow(point2D_2->getY() - point2D_1->getY(), 2));
    }

    double sideB_2D() {
        return sqrt(pow(point2D_3->getX() - point2D_1->getX(), 2) + pow(point2D_3->getY() - point2D_1->getY(), 2));
    }

    double sideC_2D() {
        return sqrt(pow(point2D_3->getX() - point2D_2->getX(), 2) + pow(point2D_3->getY() - point2D_2->getY(), 2));
    }

    double area_2D() {
        double p = (sideA_2D() + sideB_2D() + sideC_2D()) / 2;

        return sqrt(p * (p - sideA_2D()) * (p - sideB_2D()) * (p - sideC_2D()));
    }

    double sideA_3D() {
        return sqrt(pow(point3D_2->getX() - point3D_1->getX(), 2) + pow(point3D_2->getY() - point3D_1->getY(), 2) + pow(point3D_2->getZ() - point3D_1->getZ(), 2));
    }

    double sideB_3D() {
        return sqrt(pow(point3D_3->getX() - point3D_1->getX(), 2) + pow(point3D_3->getY() - point3D_1->getY(), 2) + pow(point3D_3->getZ() - point3D_1->getZ(), 2));
    }

    double sideC_3D() {
        return sqrt(pow(point3D_3->getX() - point3D_2->getX(), 2) + pow(point3D_3->getY() - point3D_2->getY(), 2) + pow(point3D_3->getZ() - point3D_2->getZ(), 2));
    }

    double area_3D() {
        double p = (sideA_2D() + sideB_2D() + sideC_2D()) / 2;

        return sqrt(p * (p - sideA_2D()) * (p - sideB_2D()) * (p - sideC_2D()));
    }

    double height() {
        return ( 2 * area()) / 2;
    }

};

class Tetragon : public FlatFigure {
protected:
    Point* point1;
    Point* point2;
    Point* point3;
    Point* point4;

public:
    Tetragon(Point* point1, Point* point2, Point* point3, Point* point4) : point1(point1), point2(point2), point3(point3), point4(point4) {}
    void print() {
        std::cout << "Tetragon ";
        point1->print();
        point2->print();
        point3->print();
        point4->print();
    }

    double area() {
        // Реализация вычисления площади четырехугольника
        double area = 0.0; // Замените на фактический расчет площади
        return area;
    }

};

int main() {
    setlocale(LC_ALL, "Rus");

    Point2D a(1, 2);
    Point2D b(3, 4);
    Point2D c(1, 3);

    Triangle s(&a, &b, &c);

    s.print();

    return 0;
}


