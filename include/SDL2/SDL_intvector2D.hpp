#include <math.h>

#ifndef _INTVECTOR2D_
#define _INTVECTOR2D_


class IntVector2D
{
public:
    int X;
    float Y;
    IntVector2D();
    IntVector2D(int x, int y);
    IntVector2D operator+ (const IntVector2D &v);
    IntVector2D operator- (const IntVector2D &v);
    IntVector2D operator* (const float &n);
    IntVector2D operator/ (const float &n);
    IntVector2D& operator+= (const IntVector2D &v);
    IntVector2D& operator-= (const IntVector2D &v);
    IntVector2D& operator*= (const float &n);
    IntVector2D& operator/= (const float &n);
    bool operator== (const IntVector2D &v);
    bool operator!= (const IntVector2D &v);

    IntVector2D normalized() {return IntVector2D(X / length(), Y / length());}
    void normalize() {X /= length(); Y/= length();}
    float length() {return sqrt(X * X + Y * Y);}
    float dot(IntVector2D vector) {return X * vector.X + Y * vector.Y;}
};

IntVector2D::IntVector2D(int x, int y)
{
    X = x;
    Y = y;
}

IntVector2D IntVector2D::operator+ (const IntVector2D &v){
    return IntVector2D(X + v.X, Y + v.Y);
}

IntVector2D IntVector2D::operator- (const IntVector2D &v){
    return IntVector2D(X - v.X, Y - v.Y);
}

IntVector2D IntVector2D::operator* (const float &n){
    return IntVector2D(X * n, Y * n);
}

IntVector2D IntVector2D::operator/ (const float &n){
    return IntVector2D(X / n, Y / n);
}

IntVector2D& IntVector2D::operator+= (const IntVector2D &v){
    X += v.X;
    Y += v.Y;
    return *this;
}

IntVector2D& IntVector2D::operator-= (const IntVector2D &v){
    X -= v.X;
    Y -= v.Y;
    return *this;
}

IntVector2D& IntVector2D::operator*= (const float &n){
    X *= n;
    Y *= n;
    return *this;
}

IntVector2D& IntVector2D::operator/= (const float &n){
    X /= n;
    Y /= n;
    return *this;
}

bool IntVector2D::operator== (const IntVector2D &v){
    return X == v.X && Y == v.Y;
}

bool IntVector2D::operator!= (const IntVector2D &v){
    return X != v.X || Y != v.Y;
}

#endif