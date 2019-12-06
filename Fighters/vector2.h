#ifndef VECTOR2_H
#define VECTOR2_H

#include <SFML/Graphics.hpp>

class Vector2
{
public:
    double x, y;

    Vector2();
    Vector2(double x, double y);
    Vector2(const Vector2& v);

	Vector2& set(double x, double y);
	Vector2& set(Vector2& v);
    Vector2& add(double x, double y);
    Vector2& add(const Vector2& v);
    Vector2& subtract(double x, double y);
    Vector2& subtract(const Vector2& v);
	Vector2& multiply(double x, double y);
	Vector2& multiply(const Vector2& v);
    double dot(double x, double y);
    double dot(const Vector2& v);
    Vector2& scale(double scalar);
    Vector2& rotate(double angle);
    Vector2& normalise();
    Vector2 perpCW();
    Vector2 perpCCW();
    double magnitude();

    static Vector2 add(const Vector2& v1, const Vector2& v2);
    static Vector2 subtract(const Vector2& v1, const Vector2& v2);
	static Vector2 multiply(const Vector2& v1, const Vector2& v2);
	static Vector2 scale(const Vector2& v1, double scalar);
    static double dot(const Vector2& v1, const Vector2& v2);
    static double distance(const Vector2& v1, const Vector2& v2);

    operator sf::Vector2f()
    {
        return sf::Vector2f(x, y);
    }
};

#endif // VECTOR2_H
