//
// Created by bnkr on 25.10.2024.
//

#ifndef OBLIQUE_CROSS_H
#define OBLIQUE_CROSS_H

#include "shape.h"
#include "line.h"


// Косой крест
class ObliqueCross : public virtual Shape {
protected:
    Line *_first;
    Line *_second;

public:
    ObliqueCross(const Point &left, const Point &right);

    virtual void draw(Screen *screen) const;

    virtual void move(Point p);

    Point getLeftTop() const;

    Point getRightTop() const;

    Point getLeftBottom() const;

    Point getRightBottom() const;

    virtual ~ObliqueCross();
};


/*
 * p1/left  p2
 *    \    /
 *     \  /
 *      **
 *      **
 *     /  \
 *    /    \
 *   p4   p3/right
 */
ObliqueCross::ObliqueCross(const Point &left, const Point &right) {
    Point p1, p2;
    Point p3, p4;
    p1 = left;
    p2 = Point(right.getX(), left.getY());
    p3 = right;
    p4 = Point(left.getX(), right.getY());
    _first = new Line(p1, p3);
    _second = new Line(p2, p4);
}


void ObliqueCross::draw(Screen *screen) const {
    _first->draw(screen);
    _second->draw(screen);
}


void ObliqueCross::move(Point p) {
    _first->move(p);
    _second->move(p);
}


Point ObliqueCross::getLeftTop() const {
    return _first->getLeftTop();
}


Point ObliqueCross::getRightTop() const {
    return _second->getRightTop();
}


Point ObliqueCross::getLeftBottom() const {
    return _second->getLeftBottom();
}


Point ObliqueCross::getRightBottom() const {
    return _first->getRightBottom();
}


ObliqueCross::~ObliqueCross() {
    delete _first;
    delete _second;
}


#endif //OBLIQUE_CROSS_H
