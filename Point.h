//
// Created by DanMagor on 03.09.2017.
//

#ifndef ASSIGNMENT1_POINT_H
#define ASSIGNMENT1_POINT_H


class Point {
private:
    unsigned int x_;
    unsigned int y_;
public:
    Point(unsigned int, unsigned int);
    Point();

    void setX(unsigned int);

    void setY(unsigned int);

    unsigned int X()const;

    unsigned int Y()const;

    bool operator<(Point &);
    bool operator<(const Point &) const;


};


#endif //ASSIGNMENT1_POINT_H
