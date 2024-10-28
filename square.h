//
// Created by bnkr on 25.10.2024.
//

#ifndef SQUARE_H
#define SQUARE_H

#include "line.h"

class Square : public virtual Shape {
public:
    Square(const Point &leftTop, const Point &rightBottom);

    virtual void draw(Screen *screen) const;

    virtual void move(Point p);

    Point getLeftTop() const;

    Point getRightTop() const;

    Point getLeftBottom() const;

    Point getRightBottom() const;

    virtual ~Square();

protected:
    Line *_left, *_top, *_right, *_bottom;
};

Square::Square(const Point &leftTop, const Point &rightBottom) {
    _left = new Line(leftTop, Point(leftTop.getX(), rightBottom.getY()));
    _top = new Line(leftTop, Point(rightBottom.getX(), leftTop.getY()));
    _right = new Line(Point(rightBottom.getX(), leftTop.getY()), rightBottom);
    _bottom = new Line(Point(leftTop.getX(), rightBottom.getY()), rightBottom);
}

void Square::draw(Screen *screen) const {
    _left->draw(screen);
    _top->draw(screen);
    _right->draw(screen);
    _bottom->draw(screen);
}

void Square::move(Point p) {
    _left->move(p);
    _top->move(p);
    _right->move(p);
    _bottom->move(p);
}

Point Square::getLeftTop() const {
    return _left->getLeftTop();
}

Point Square::getRightTop() const {
    return _right->getRightTop();
}

Point Square::getLeftBottom() const {
    return _left->getLeftBottom();
}

Point Square::getRightBottom() const {
    return _right->getRightBottom();
}

Square::~Square() {
    delete _left;
    delete _top;
    delete _right;
    delete _bottom;
}

#endif //SQUARE_H
