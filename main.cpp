#include <iostream>
#include <vector>
#include <memory>

#include "screen.h"
#include "line.h"
#include "square.h"
#include "oblique_cross.h"


int main() {
    system("color F1");
    const auto screen = std::make_unique<Screen>(50, 33);
    std::vector<std::shared_ptr<Shape> > shapes;
    shapes.emplace_back(std::make_shared<Square>(Point(15, 3), Point(32, 12))); // Шляпа

    // My code for draw oblique cross in dot 6, 7, 8
    int shift = 2;
    // for dot 6
    Point p_6_left = shapes[shapes.size() - 1]->getLeftBottom();
    Point p_6_right = shapes[shapes.size() - 1]->getRightBottom();
    Point p_6 = Point {(p_6_left.getX() + p_6_right.getX()) / 2,  p_6_left.getY()};
    p_6_left.setX(p_6.getX() - shift);
    p_6_left.setY(p_6.getY() + shift);
    p_6_right.setX(p_6.getX() + shift);
    p_6_right.setY(p_6.getY() - shift);



    Point p1 = shapes[shapes.size() - 1]->getLeftBottom();
    p1.setX(p1.getX() - 10);
    p1.setY(p1.getY() + 1);
    Point p2 = shapes[shapes.size() - 1]->getRightBottom();
    p2.setX(p2.getX() + 10);
    p2.setY(p2.getY() + 1);
    shapes.emplace_back(std::make_shared<Line>(p1, p2)); // Линия под шляпой



    // for dot 7
    Point p_7 = shapes[shapes.size() - 1]->getLeftTop();
    Point p_7_left = p_7;
    p_7_left.setX(p_7_left.getX() - shift);
    p_7_left.setY(p_7_left.getY() + shift);
    Point p_7_right = p_7;
    p_7_right.setX(p_7_right.getX() + shift);
    p_7_right.setY(p_7_right.getY() - shift);


    // for dot 8
    Point p_8 = shapes[shapes.size() - 1]->getRightBottom();
    Point p_8_left = p_8;
    p_8_left.setX(p_8_left.getX() - shift);
    p_8_left.setY(p_8_left.getY() + shift);
    Point p_8_right = p_8;
    p_8_right.setX(p_8_right.getX() + shift);
    p_8_right.setY(p_8_right.getY() - shift);





    p1 = shapes[shapes.size() - 1]->getLeftBottom();
    p1.setX(p1.getX() + 1);
    p1.setY(p1.getY() + 1);
    p2 = shapes[shapes.size() - 1]->getRightBottom();
    p2.setX(p2.getX() - 1);
    p2.setY(p2.getY() + 10);
    shapes.emplace_back(std::make_shared<Square>(p1, p2)); // Голова

    Point eyeLeft = shapes[shapes.size() - 1]->getLeftTop();
    eyeLeft.setX(eyeLeft.getX() + 2);
    eyeLeft.setY(eyeLeft.getY() + 2);
    Point eyeRight = Point(eyeLeft.getX() + 2, eyeLeft.getY());
    shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight)); // Левый глаз

    eyeRight = shapes[shapes.size() - 2]->getRightTop();
    eyeRight.setX(eyeRight.getX() - 2);
    eyeRight.setY(eyeRight.getY() + 2);
    eyeLeft = Point(eyeRight.getX() - 2, eyeRight.getY());
    shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight)); // Правый глаз

    std::shared_ptr<Shape> leftEye = shapes[shapes.size() - 2];
    std::shared_ptr<Shape> rightEye = shapes[shapes.size() - 1];
    Point nose = Point(leftEye->getRightTop().getX() +
                       (rightEye->getLeftTop().getX() - leftEye->getRightTop().getX()) / 2,
                       leftEye->getRightTop().getY() + 2);
    shapes.emplace_back(std::make_shared<Line>(nose, nose)); // Нос

    std::shared_ptr<Shape> head = shapes[shapes.size() - 4];
    p1 = head->getLeftBottom();
    p1.setX(p1.getX() + 2);
    p1.setY(p1.getY() - 2);

    p2 = head->getRightBottom();
    p2.setX(p2.getX() - 2);
    p2.setY(p2.getY() - 2);
    shapes.emplace_back(std::make_shared<Line>(p1, p2)); // Рот

    auto costume = std::make_shared<Line>(Point(p1.getX(), p1.getY() + 10),
                                          Point(p2.getX(), p2.getY() + 10));

    shapes.emplace_back(costume); //Линия костюма
    p1 = Point(costume->getLeftBottom().getX(), costume->getLeftBottom().getY() + 1);
    auto leftDot = std::make_shared<Line>(p1, p1);
    shapes.emplace_back(leftDot); //Левая точка

    p1 = Point(costume->getRightBottom().getX(), costume->getRightBottom().getY() + 1);

    auto rightDot = std::make_shared<Line>(p1, p1);

    shapes.emplace_back(rightDot); //Правая точка

    // draw oblique cross
    shapes.emplace_back(std::make_shared<ObliqueCross>(p_6_left, p_6_right));
    shapes.emplace_back(std::make_shared<ObliqueCross>(p_7_left, p_7_right));
    shapes.emplace_back(std::make_shared<ObliqueCross>(p_8_left, p_8_right));

    for (auto shape: shapes)
        shape->draw(screen.get());

    screen->draw();

    std::cin.get();
    return 0;
}
