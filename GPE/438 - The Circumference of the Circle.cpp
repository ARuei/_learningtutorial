#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);

struct Point {

    double x;
    double y;
};

double getDistance(struct Point p1, struct Point p2) {

    return sqrt(pow((p1.x-p2.x), 2)+pow((p1.y-p2.y), 2));
}

double sine_theory(struct Point points []) {

    double cosA, diameter;
    double a, b, c; // The three edges of an triangle

    a = getDistance(points[0], points[1]);
    b = getDistance(points[1], points[2]);
    c = getDistance(points[2], points[0]);

    cosA = (pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c);
    diameter = a / sin(acos(cosA));    

    return diameter*PI;
}

double heron_formula (struct Point points []){

    double a, b, c; // The three edges of an triangle
    double s, r, area;

    a = getDistance(*(points), *(points+1));
    b = getDistance(*(points+1), *(points+2));
    c = getDistance(*(points+2), *(points));

    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    r = a*b*c/(4*area);

    return 2*PI*r;    
}

int main() {

    Point points[3];

    double ret;
    while (cin >> points[0].x >> points[0].y
        >> points[1].x >> points[1].y 
        >> points[2].x >> points[2].y) {
        
        /*
        ret = sine_theory(points);
        printf("%.2lf\n", ret);
        */

        ret = heron_formula(points);
        printf("%.2lf\n", ret);
    }

    return 0;
}