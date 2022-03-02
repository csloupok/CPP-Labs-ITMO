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
protected:
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
        for (int i = 0; i < points.size() - 1; i++) {
            double dx = points[i].get_x() - points[i + 1].get_x();
            double dy = points[i].get_y() - points[i + 1].get_y();
            perimeter += sqrt(dx * dx + dy * dy);
        }
        return perimeter;
    }
};

class ClosedPolyline : public Polyline {
public:
    ClosedPolyline(const PointList &points) : Polyline{points} {}

    ClosedPolyline(const ClosedPolyline &closedPolyline) : Polyline{closedPolyline.points} {}

    ClosedPolyline &operator=(const ClosedPolyline &closedPolyline) {
        if (this == &closedPolyline)
            return *this;
        points = closedPolyline.points;
        return *this;
    }

    double getPerimeter() const override {
        double perimeter;
        if (points.empty())
            return 0;
        for (int i = 0; i < points.size() - 1; i++) {
            double dx = points[i].get_x() - points[i + 1].get_x();
            double dy = points[i].get_y() - points[i + 1].get_y();
            perimeter += sqrt(dx * dx + dy * dy);
        }
        return perimeter + sqrt((points.front().get_x() - points.back().get_x()) *
                                (points.front().get_x() - points.back().get_x()) +
                                (points.front().get_y() - points.back().get_y()) *
                                (points.front().get_y() - points.back().get_y()));
    }
};

class Polygon : public ClosedPolyline, public Area {
public:
    Polygon(const PointList &points) : ClosedPolyline{points} {}

    Polygon(const Polygon &polygon) : Polygon{polygon.points} {}

    Polygon &operator=(const Polygon &polygon) {
        if (this == &polygon)
            return *this;
        points = polygon.points;
        return *this;
    }

    double getArea() const override {
        double res1, res2;
        for (int i = 0; i < points.size() - 1; i++) {
            res1 += points[i].get_x() * points[i + 1].get_y();
            res2 += points[i + 1].get_x() * points[i].get_y();
        }
        return (abs(res1 - res2)) / 2;
    }
};

class Triangle {
};

class Trapezoid {
};

class RegularPolygon {
};

int main() {
    PointList points{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{0, 1}};
    Polyline polyline{points};
    ClosedPolyline closedPolyline{points};
    Polygon polygon{points};
    std::cout << polyline.getPerimeter() << closedPolyline.getPerimeter() << polygon.getArea();
    return 0;
}
