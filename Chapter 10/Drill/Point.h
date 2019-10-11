#pragma once

#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();

public:
    void setX(int newX);
    int getX() const;

    void setY(int newY);
    int getY() const;

    bool operator==(Point& rhs);
    bool operator!=(Point& rhs);

private:
    int m_x;
    int m_y;
};

#endif // POINT_H