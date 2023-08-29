#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
#define ll long long

//Useful define:
typedef complex<double> point;
#define pi 3.14159265358979323846

//Length of the union of segments:
//given n segments on a line, each described by a pair of coordinates 
//we have to find the length of their union

int length_union(const vector<pair<int, int>> &a) {
    int n = a.size();
    vector<pair<int, bool>> x(n*2);
    for (int i = 0; i < n; i++) {
        x[i*2] = {a[i].first, false};
        x[i*2+1] = {a[i].second, true};
    }

    sort(x.begin(), x.end());

    int result = 0;
    int c = 0;
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && x[i].first > x[i-1].first && c > 0)
            result += x[i].first - x[i-1].first;
        if (x[i].second)
            c--;
        else
            c++;
    }
    return result;
}


//Area of triangle:
int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
    return cross(p2 - p1, p3 - p2);
}

double triangle_area(point2d p1, point2d p2, point2d p3) {
    return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}

bool clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) < 0;
}

bool counter_clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) > 0;
}

//or
double triangleArea(double l1 , double l2 , double l3){
    double s =(l1+l2+l3)/2.0;
    double ans = sqrtl(s*(s-l1)*(s-l2)*(s-l3));
    return ans;
} 


//Area of simple polygon
struct point{
    double x, y;
};

double area(const vector<point>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}


//Calc degree of angle from three points:
double calculateAngle(double P1X, double P1Y, double P2X, double P2Y,
    double P3X, double P3Y){

    double numerator = P2Y*(P1X-P3X) + P1Y*(P3X-P2X) + P3Y*(P2X-P1X);
    double denominator = (P2X-P1X)*(P1X-P3X) + (P2Y-P1Y)*(P1Y-P3Y);
    double ratio = numerator/denominator;

    double angleRad = atan(ratio);
    double angleDeg = (angleRad*180)/pi;

    if(angleDeg<0){
        angleDeg = 180+angleDeg;
    }

    return angleDeg;
}   


//find forth point of rectangle:
typedef complex<double> point;
//should be in order     A             B              C
point find_forth(point first , point second , point third){
    point cur = (first + third) / 2.0;
    point target = 2.0 * cur - second;
    return target;
}

//angle of line first-second with X_axis
long double angle_with_x(point first , point second){
    return atan2((second.imag() - first.imag()), (second.real() - first.real()));
}

//rotate p around c by angle
point rotate(point p, point c, long double angle) {
    angle*=-1;
    point rotated = polar(abs(p - c), arg(p - c) + angle);
    return rotated;
}

//Volume of cone
double volumeOfCone(double h ,double r){
    return (1.0/3.0)*(pi*r*r*h);
}

//degree to radian
double toRadian(double degree){
    return degree*(pi/180.0);
}
