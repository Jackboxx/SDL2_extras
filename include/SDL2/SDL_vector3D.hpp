#include <math.h>

#ifndef _VECTOR3D_
#define _VECTOR3D_

class Vector3D
{
public:
    float X;
    float Y;
    float Z;
    Vector3D();
    Vector3D(float x, float y, float z);
    Vector3D operator+ (const Vector3D &v);
    Vector3D operator- (const Vector3D &v);
    Vector3D operator* (const float &n);
    Vector3D operator/ (const float &n);
    Vector3D& operator+= (const Vector3D &v);
    Vector3D& operator-= (const Vector3D &v);
    Vector3D& operator*= (const float &n);
    Vector3D& operator/= (const float &n);
    bool operator== (const Vector3D &v);
    bool operator!= (const Vector3D &v);

    Vector3D normalized() {return Vector3D(X / length(), Y / length(), Z / length());}
    void normalize() {X /= length(); Y/= length(); Z /= length();}
    float length() {return sqrt(X * X + Y * Y + Z * Z);}
    float dot(Vector3D vector) {return X * vector.X + Y * vector.Y + Z * vector.Z;}
    Vector3D cross(Vector3D vector) {return Vector3D(Y*vector.Z - Z*vector.Y, Z*vector.X - X*vector.Z, X*vector.Y - Y*vector.X);}
};

Vector3D::Vector3D(){
    X = 0;
    Y = 0;
    Z = 0;
}

Vector3D::Vector3D(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector3D Vector3D::operator+ (const Vector3D &v){
    return Vector3D(X + v.X, Y + v.Y, Z + v.Z);
}

Vector3D Vector3D::operator- (const Vector3D &v){
    return Vector3D(X - v.X, Y - v.Y, Z - v.Z);
}

Vector3D Vector3D::operator* (const float &n){
    return Vector3D(X * n, Y * n, Z * n);
}

Vector3D Vector3D::operator/ (const float &n){
    return Vector3D(X / n, Y / n, Z / n);
}

Vector3D& Vector3D::operator+= (const Vector3D &v){
    X += v.X;
    Y += v.Y;
    Z += v.Z;
    return *this;
}

Vector3D& Vector3D::operator-= (const Vector3D &v){
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
    return *this;
}

Vector3D& Vector3D::operator*= (const float &n){
    X *= n;
    Y *= n;
    Z *= n;
    return *this;
}

Vector3D& Vector3D::operator/= (const float &n){
    X /= n;
    Y /= n;
    Z /= n;
    return *this;
}

bool Vector3D::operator== (const Vector3D &v){
    return X == v.X && Y == v.Y && Z == v.Z;
}

bool Vector3D::operator!= (const Vector3D &v){
    return X != v.X || Y != v.Y || Z != v.Z;
}

#endif