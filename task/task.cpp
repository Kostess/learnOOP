#include <iostream>
#include <cmath>

class Figure {
public:
    virtual void print() = 0;
};

class Point : public Figure {
protected:
    int x;
public:
    Point(int x) : x(x) {}

    void print() override {
        std::cout << "Point (" << x << ")" << std::endl;
    }
    int getX() {
        return x;
    }
};

class Point2D : public Point {
protected:
    int y;
public:
    Point2D(int x, int y) : Point(x), y(y) {}
    void print() override {
        std::cout << "Point2D (" << x << ", " << y << ")" << std::endl;
    }
    int getY() {
        return y;
    }
};

class Point3D : public Point2D {
protected:
    int z;
public:
    Point3D(int x, int y, int z) : Point2D(x, y), z(z) {}
    void print() override {
        std::cout << "Point3D (" << x << ", " << y << ", " << z << ")" << std::endl;
    }
    int getZ() {
        return z;
    }
};

class Section : public Figure {
protected:
    Point* startPoint;
    Point* endPoint;
public:
    Section(Point* startPoint, Point* endPoint) : startPoint(startPoint), endPoint(endPoint) {}
    void print() override {
        std::cout << "Section ";
        startPoint->print();
        endPoint->print();
    }
};

class FlatFigure : public Figure {
public:
    virtual float getArea() = 0;
};

class Triangle : public FlatFigure {
protected:
    Point3D* point1;
    Point3D* point2;
    Point3D* point3;
public:
    Triangle(Point3D* point1, Point3D* point2, Point3D* point3) : point1(point1), point2(point2), point3(point3) {}
    void print() override {
        std::cout << "Triangle ";
        point1->print();
        point2->print();
        point3->print();
    }
    float getArea() override {
        // Реализация вычисления площади треугольника
        float a = calculateDistance(point2, point3);
        float b = calculateDistance(point1, point3);
        float c = calculateDistance(point1, point2);
        float p = (a + b + c) / 2;
        float area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }
    float calculateDistance(Point3D* point1, Point3D* point2) {
        float distance = sqrt(pow(point2->getX() - point1->getX(), 2) + pow(point2->getY() - point1->getY(), 2) + pow(point2->getZ() - point1->getZ(), 2));
        return distance;
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
    void print() override {
        std::cout << "Tetragon ";
        point1->print();
        point2->print();
        point3->print();
        point4->print();
    }
    float getArea() override {
        // Реализация вычисления площади четырехугольника
        float area = 0.0; // Замените на фактический расчет площади
        return area;
    }
};

int main() {
    Point p1(1);
    Point2D p2(2, 3);
    Point3D p3(4, 5, 6);
    Section s1(&p1, &p2);
    Triangle t1(&p3);
    Tetragon t2(&p1, &p2, &p3, &p3); // Обратите внимание: point4 должен быть присвоен &p4, а не &p3
    p1.print();
    p2.print();
    p3.print();
    s1.print();
    t1.print();
    t2.print();
    return 0;
}