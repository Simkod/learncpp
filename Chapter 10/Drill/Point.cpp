#include "Point.h"
#include <limits.h>

Point::Point()
    : m_x(INT_MIN)
    , m_y(INT_MIN)
{
}

Point::Point(int x, int y)
    : m_x(x)
    , m_y(y)
{
}

Point::~Point()
{
}

void Point::setX(int newX)
{
    m_x = newX;
}

int Point::getX() const
{
    return m_x;
}

void Point::setY(int newY)
{
    m_y = newY;
}

int Point::getY() const
{
    return m_y;
}

bool Point::operator==(Point & rhs)
{
    if (m_x == rhs.getX() && m_y == rhs.getY())
    {
        return true;
    }
    return false;
}

bool Point::operator!=(Point & rhs)
{
    if (m_x != rhs.getX() || m_y != rhs.getY())
    {
        return true;
    }
    return false;
}
