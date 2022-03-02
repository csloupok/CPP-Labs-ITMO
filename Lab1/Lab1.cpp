#include <iostream>
#include <vector>

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x{x}, y{y} {}

    Point(const Point &point) = default;

    Point &operator=(const Point &point) {
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

class FigureMethods {
public:
    virtual double getSquare() const = 0;

    virtual double getPerimeter() const = 0;
};

using PointList = std::vector<Point>;

class Polyline {
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
