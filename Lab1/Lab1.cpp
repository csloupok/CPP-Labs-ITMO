#include <iostream>
#include <vector>
#include <math.h>

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x{x}, y{y} {}       // конструктор
    Point(const Point &point) : x{point.x}, y{point.y} {}   // копирование
    Point &operator=(const Point &point) {                  // присваивание
        if (this == &point)
            return *this;
        x = point.x;
        y = point.x;
        return *this;
    }

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

//    Point &move(double x, double y) {
//        this->x += x;
//        this->y += y;
//        return *this;
//    }

};

class Perimeter {
protected:
    virtual double getPerimeter() const = 0;
};

class Area {
protected:
    virtual double getArea() const = 0;
};

using PointList = std::vector<Point>;

class Polyline : public Perimeter {
private:
    PointList points;
public:
    Polyline(const PointList &pointList) : points{pointList} {}     // конструктор
    Polyline(const Polyline &polyline) : points{polyline.points} {} // копирование
    Polyline &operator=(const Polyline &polyline) {                 // присваивание
        if (this == &polyline)
            return *this;
        points = polyline.points;
        return *this;
    }

    double getPerimeter() const override {
        double perimeter = 0;
        if (points.empty())
            return 0;
//        TODO не робит периметер!!!!!!!!!!!
//        for (int i = 0; i < points.size() - 1; i++) {
//            double dx = points[i].get_x() - points[i + 1].get_x();
//            double dy = points[i].get_y() - points[i + 1].get_y();
//            perimeter += sqrt(dx * dx + dy * dy);
//        }
    }
};

class Polygon {
};

class Triangle {
};

class Trapezoid {
};

class RegularPolygon {
};

int main() {
    PointList points{Point{0, 0}, Point{1, 0}};
    Polyline polyline{points};
    std::cout << polyline.getPerimeter();
    return 0;
}
