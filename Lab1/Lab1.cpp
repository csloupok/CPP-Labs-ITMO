#include <iostream>
#include <vector>

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

class FigureMethods {
protected:
    virtual double getSquare() const = 0;

    virtual double getPerimeter() const = 0;
};

using PointList = std::vector<Point>;

class Polyline : public FigureMethods {
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
    return 0;
}
