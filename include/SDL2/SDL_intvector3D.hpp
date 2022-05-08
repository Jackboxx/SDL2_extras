#include <math.h>

#ifndef _INTVECTOR3D_
#define _INTVECTOR3D_

class IntVector3D
{
public:
    int X;
    int Y;
    int Z;
    IntVector3D();
    IntVector3D(int x, int y, int z);
    IntVector3D operator+ (const IntVector3D &v);
    IntVector3D operator- (const IntVector3D &v);
    IntVector3D operator* (const float &n);
    IntVector3D operator/ (const float &n);
    IntVector3D& operator+= (const IntVector3D &v);
    IntVector3D& operator-= (const IntVector3D &v);
    IntVector3D& operator*= (const float &n);
    IntVector3D& operator/= (const float &n);
    bool operator== (const IntVector3D &v);
    bool operator!= (const IntVector3D &v);

    IntVector3D normalized() {return IntVector3D(X / length(), Y / length(), Z / length());}
    void normalize() {X /= length(); Y/= length(); Z /= length();}
    float length() {return sqrt(X * X + Y * Y + Z * Z);}
    float dot(IntVector3D vector) {return X * vector.X + Y * vector.Y + Z * vector.Z;}
    IntVector3D cross(IntVector3D vector) {return IntVector3D(Y*vector.Z - Z*vector.Y, Z*vector.X - X*vector.Z, X*vector.Y - Y*vector.X);}
};

IntVector3D::IntVector3D(){
    X = 0;
    Y = 0;
    Z = 0;
}

IntVector3D::IntVector3D(int x, int y, int z)
{
    X = x;
    Y = y;
    Z = z;
}

IntVector3D IntVector3D::operator+ (const IntVector3D &v){
    return IntVector3D(X + v.X, Y + v.Y, Z + v.Z);
}

IntVector3D IntVector3D::operator- (const IntVector3D &v){
    return IntVector3D(X - v.X, Y - v.Y, Z - v.Z);
}

IntVector3D IntVector3D::operator* (const float &n){
    return IntVector3D(X * n, Y * n, Z * n);
}

IntVector3D IntVector3D::operator/ (const float &n){
    return IntVector3D(X / n, Y / n, Z / n);
}

IntVector3D& IntVector3D::operator+= (const IntVector3D &v){
    X += v.X;
    Y += v.Y;
    Z += v.Z;
    return *this;
}

IntVector3D& IntVector3D::operator-= (const IntVector3D &v){
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
    return *this;
}

IntVector3D& IntVector3D::operator*= (const float &n){
    X *= n;
    Y *= n;
    Z *= n;
    return *this;
}

IntVector3D& IntVector3D::operator/= (const float &n){
    X /= n;
    Y /= n;
    Z /= n;
    return *this;
}

bool IntVector3D::operator== (const IntVector3D &v){
    return X == v.X && Y == v.Y && Z == v.Z;
}

bool IntVector3D::operator!= (const IntVector3D &v){
    return X != v.X || Y != v.Y || Z != v.Z;
}

#endif