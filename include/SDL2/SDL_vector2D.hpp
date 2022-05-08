#include <math.h>

#ifndef _VECTOR2D_
#define _VECTOR2D_

class Vector2D
{
public:
    float X;
    float Y;
    Vector2D();
    Vector2D(float x, float y);
    Vector2D operator+ (const Vector2D &v);
    Vector2D operator- (const Vector2D &v);
    Vector2D operator* (const float &n);
    Vector2D operator/ (const float &n);
    Vector2D& operator+= (const Vector2D &v);
    Vector2D& operator-= (const Vector2D &v);
    Vector2D& operator*= (const float &n);
    Vector2D& operator/= (const float &n);
    bool operator== (const Vector2D &v);
    bool operator!= (const Vector2D &v);

    Vector2D normalized() {return Vector2D(X / length(), Y / length());}
    void normalize() {X /= length(); Y/= length();}
    float length() {return sqrt(X * X + Y * Y);}
    float dot(Vector2D vector) {return X * vector.X + Y * vector.Y;}
};

Vector2D::Vector2D(){
    X = 0;
    Y = 0;
}

Vector2D::Vector2D(float x, float y)
{
    X = x;
    Y = y;
}

Vector2D Vector2D::operator+ (const Vector2D &v){
    return Vector2D(X + v.X, Y + v.Y);
}

Vector2D Vector2D::operator- (const Vector2D &v){
    return Vector2D(X - v.X, Y - v.Y);
}

Vector2D Vector2D::operator* (const float &n){
    return Vector2D(X * n, Y * n);
}

Vector2D Vector2D::operator/ (const float &n){
    return Vector2D(X / n, Y / n);
}

Vector2D& Vector2D::operator+= (const Vector2D &v){
    X += v.X;
    Y += v.Y;
    return *this;
}

Vector2D& Vector2D::operator-= (const Vector2D &v){
    X -= v.X;
    Y -= v.Y;
    return *this;
}

Vector2D& Vector2D::operator*= (const float &n){
    X *= n;
    Y *= n;
    return *this;
}

Vector2D& Vector2D::operator/= (const float &n){
    X /= n;
    Y /= n;
    return *this;
}

bool Vector2D::operator== (const Vector2D &v){
    return X == v.X && Y == v.Y;
}

bool Vector2D::operator!= (const Vector2D &v){
    return X != v.X || Y != v.Y;
}

#endif