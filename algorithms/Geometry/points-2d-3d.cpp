#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
#define ll long long

//Useful define:
#define pi 3.14159265358979323846

//Points 2D Operation:
struct point2d {
    double x, y;
    point2d() {}
    point2d(double x, double y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(double t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(double t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(double t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(double t) const {
        return point2d(*this) /= t;
    }
};
point2d operator*(double a, point2d b) {
    return b * a;
}

//dot & cross product
double dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}

double cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}


//Points 3D Operation:
struct point3d {
    double x, y, z;
    point3d() {}
    point3d(double x, double y, double z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(double t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(double t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(double t) const {
        return point3d(*this) /= t;
    }
};
point3d operator*(double a, point3d b) {
    return b * a;
}

//dot & cross product
double dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}