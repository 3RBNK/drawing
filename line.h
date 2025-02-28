//
// Created by bnkr on 25.10.2024.
//

#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "screen.h"
#include <algorithm>

class Line : public Shape {
protected:
    Point _a;
    Point _b;

public:
    Line(const Point &a, const Point &b);

    Line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

    Line(const Line &source);

    void draw(Screen *screen) const;

    void move(Point p);

    Point getLeftTop() const;

    Point getRightTop() const;

    Point getLeftBottom() const;

    Point getRightBottom() const;

    Point getFirstPoint() const;

    Point getSecondPoint() const;
};

Line::Line(const Point &a, const Point &b) {
    _a = a;
    _b = b;
}

Line::Line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1) {
    _a = Point(x0, y0);
    _b = Point(x1, y1);
}

Line::Line(const Line &source) {
    _a = source._a;
    _b = source._b;
}

void Line::draw(Screen *screen) const {
    screen->putLine(_a.getY(), _a.getX(), _b.getY(), _b.getX());
}

void Line::move(Point p) {
    _a.setX(_a.getX() + p.getX());
    _a.setY(_a.getY() + p.getY());
    _b.setX(_b.getX() + p.getX());
    _b.setY(_b.getY() + p.getY());
}

Point Line::getLeftTop() const {
    return Point(std::min(_a.getX(), _b.getX()), std::min(_a.getY(), _b.getY()));
}

Point Line::getRightTop() const {
    return Point(std::max(_a.getX(), _b.getX()), std::min(_a.getY(), _b.getY()));
}

Point Line::getLeftBottom() const {
    return Point(std::min(_a.getX(), _b.getX()), std::max(_a.getY(), _b.getY()));
}

Point Line::getRightBottom() const {
    return Point(std::max(_a.getX(), _b.getX()), std::max(_a.getY(), _b.getY()));
}

Point Line::getFirstPoint() const {
    return _a;
}

Point Line::getSecondPoint() const {
    return _b;
}

#endif //LINE_H
