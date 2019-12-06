#include "vector2.h"
#include <cmath>

Vector2::Vector2() : x{0.}, y{0.}
{
}

Vector2::Vector2(double x, double y) : x{x}, y{y}
{
}

Vector2::Vector2(const Vector2& v) : x{v.x}, y{v.y}
{
}

Vector2& Vector2::set(double x, double y)
{
	this->x = x;
	this->y = y;

	return *this;
}

Vector2& Vector2::set(Vector2& v)
{
	this->x = v.x;
	this->y = v.y;

	return *this;
}

Vector2& Vector2::add(double x, double y)
{
    this->x += x;
    this->y += y;

    return *this;
}

Vector2& Vector2::add(const Vector2& v)
{
    this->x += v.x;
    this->y += v.y;

    return *this;
}

Vector2& Vector2::subtract(double x, double y)
{
    this->x -= x;
    this->y -= y;

    return *this;
}

Vector2& Vector2::subtract(const Vector2& v)
{
    this->x -= v.x;
    this->y -= v.y;

    return *this;
}

Vector2& Vector2::multiply(double x, double y)
{
	this->x *= x;
	this->y *= y;

	return *this;
}

Vector2& Vector2::multiply(const Vector2& v)
{
	this->x *= v.x;
	this->y *= v.y;

	return *this;
}

double Vector2::dot(double x, double y)
{
    return this->x * x + this->y * y;
}

double Vector2::dot(const Vector2& v)
{
    return this->x * v.x + this->y * v.y;
}

Vector2& Vector2::scale(double scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

Vector2& Vector2::rotate(double angle)
{
    double temp = x;

    x = x * std::cos(angle) - y * std::sin(angle);
    y = temp * std::sin(angle) + y * std::cos(angle);

    return *this;
}

Vector2& Vector2::normalise()
{
	double magnitude = this->magnitude();

    if(magnitude != 0 && magnitude != 1)
    {
        x /= magnitude;
        y /= magnitude;
    }

    return *this;
}

Vector2 Vector2::perpCW()
{
    return Vector2(y, -x);
}

Vector2 Vector2::perpCCW()
{
    return Vector2(-y, x);
}

double Vector2::magnitude()
{
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::add(const Vector2& v1, const Vector2& v2)
{
    return Vector2(v1.x + v2.x, v1.y + v2.y);
}

Vector2 Vector2::subtract(const Vector2& v1, const Vector2& v2)
{
    return Vector2(v1.x - v2.x, v1.y - v2.y);
}

Vector2 Vector2::multiply(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x * v2.x, v1.y * v2.y);
}

Vector2 Vector2::scale(const Vector2& v, double scalar)
{
	return Vector2(v.x * scalar, v.y * scalar);
}

double Vector2::dot(const Vector2& v1, const Vector2& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double Vector2::distance(const Vector2& v1, const Vector2& v2)
{
    return Vector2::subtract(v1, v2).magnitude();
}
