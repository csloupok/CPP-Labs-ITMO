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

class Triangle : public Polygon {
public:
    Triangle(const PointList &points) : Polygon{points} {
        if (points.size() != 3) {
            throw std::logic_error{"Not a triangle!"};
        }
    }

    Triangle(const Triangle &triangle) : Triangle{triangle.points} {}

    Triangle &operator=(const Triangle &triangle) {
        if (this == &triangle)
            return *this;
        points = triangle.points;
        return *this;
    }

    double getArea() const override {
        std::vector<double> sides(3);
        double dx1 = points[0].get_x() - points[1].get_x();
        double dy1 = points[0].get_y() - points[1].get_y();
        sides[0] = sqrt(dx1 * dx1 + dy1 * dy1);
        double dx2 = points[1].get_x() - points[2].get_x();
        double dy2 = points[1].get_y() - points[2].get_y();
        sides[1] = sqrt(dx2 * dx2 + dy2 * dy2);
        double dx3 = points[0].get_x() - points[2].get_x();
        double dy3 = points[0].get_y() - points[2].get_y();
        sides[2] = sqrt(dx3 * dx3 + dy3 * dy3);
        double perimeter = this->getPerimeter() / 2;
        return sqrt(perimeter * (perimeter - sides[0]) * (perimeter - sides[1]) * (perimeter - sides[2]));
    }
};

class Trapezoid : public Polygon {  // check for slope:  (y2-y1)/(x2-x1)
public:                             // if two slopes are same and other two not -> trapezoid
    Trapezoid(const PointList &points) : Polygon{points} {
        if (points.size() != 4)
            throw std::logic_error{"Not a trapezoid!"};

        int checkTrapezoid = 0;
        double checkSlope1 = (points[1].get_y() - points[0].get_y()) / (points[1].get_x() - points[0].get_x());
        double checkSlope2 = (points[3].get_y() - points[2].get_y()) / (points[3].get_x() - points[2].get_x());
        if (checkSlope1 != checkSlope2)
            checkTrapezoid++;
        checkSlope1 = (points[2].get_y() - points[1].get_y()) / (points[2].get_x() - points[1].get_x());
        checkSlope2 = (points[4].get_y() - points[3].get_y()) / (points[4].get_x() - points[3].get_x());
        if (checkSlope1 != checkSlope2)
            checkTrapezoid++;

        if (checkTrapezoid != 1)
            throw std::logic_error{"Not a trapezoid!"};

    }

    Trapezoid(const Trapezoid &trapezoid) : Trapezoid{trapezoid.points} {}

    Trapezoid &operator=(const Trapezoid &trapezoid) {
        if (this == &trapezoid)
            return *this;
        points = trapezoid.points;
        return *this;
    }

    double getArea() const override {
        double area = 0;
        area += Triangle{PointList{points.begin(), points.begin() + 3}}.getArea();
        area += Triangle{PointList{points[0], points[3], points[2]}}.getArea();
        return area;
    }
};

class RegularPolygon {
};

int main() {
    PointList points{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{0, 1}};
    Polyline polyline{points};
    ClosedPolyline closedPolyline{points};
    Polygon polygon{points};
    PointList triPoints{Point{1, 0}, Point{3.5, 0}, Point{1.847, 2.375}};
    Triangle triangle{triPoints};
    PointList trapPoints{Point{-3, -3}, Point{5, 1}, Point{10, -2}, Point{-4, -9}};
    Trapezoid trapezoid{trapPoints};
    std::cout << polyline.getPerimeter() << closedPolyline.getPerimeter() << polygon.getArea()
              << polygon.getPerimeter() << "trianglep" << triangle.getPerimeter() << "triangles"
              << triangle.getArea() << "trappppp" << trapezoid.getPerimeter() << "trapssss" << trapezoid.getArea();
    return 0;
}
