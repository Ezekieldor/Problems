#include<bits/stdc++.h>
using namespace std;

#define point pair<double,double>
#define x first
#define y second
#define EPS 1e-9


struct vec{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}

double cross(vec a, vec b) {
	return a.x*b.y-a.y*b.x;
}

point rotate(point p, double theta){
	double rad = theta*M_PI/180.0;
	return point(p.x*cos(rad)-p.y*sin(rad), p.x*sin(rad)+p.y*cos(rad));
}

point lineIntersectSeg(point p, point q, point A, point B){
	double a = B.y - A.y;
	double b = A.x-B.x;
	double c = B.x*A.y-A.x*B.y;
	double u = fabs(a*p.x+b*p.y+c);
	double v = fabs(a*q.x+b*q.y+c);
	return point ((p.x*v+q.x*u)/(u+v),(p.y*v+q.y*u)/(u+v));
}

vector<point> cutPolygon(point a, point b, vector<point> &Q){
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++){
		double left1 = cross(toVec(a,b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1)
			left2 = cross(toVec(a,b), toVec(a, Q[i+1]));
		if (left1 > -EPS)
			P.push_back(Q[i]);
		if (left1*left2 < -EPS)
			P.push_back(lineIntersectSeg(Q[i],Q[i+1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());
	return P;
}

double area(vector<point> P){
	double result = 0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size(); i++){
		x1 = P[i].x;
		x2 = P[i+1].x;
		y1 = P[i].y;
		y2 = P[i+1].y;
		result += (x1*y2-x2*y1);
	}
	return fabs(result)/2.0;
}

int main (){
	int l, a, xa, ya, xb, yb;
	scanf("%d%d%d%d%d%d", &l, &a, &xa, &ya, &xb, &yb);
	point m = point(double(xa+xb)/2.0, double(ya+yb)/2.0);
	point p1 = rotate(point((double)xa-m.x, (double)ya-m.y), 90);
	point p2 = rotate(point((double)xb-m.x, (double)yb-m.y), 90);
	p1.x += m.x;
	p1.y += m.y;
	p2.x += m.x;
	p2.y += m.y;
	vector<point> P;
	P.push_back(point(0,0));
	P.push_back(point(l,0));
	P.push_back(point(l,a));
	P.push_back(point(0,a));
	P.push_back(point(0,0));
	double a1 = area(cutPolygon(p1,p2,P));
	double a2 = area(cutPolygon(p2,p1,P));
	double a3 = area(P);
	printf ("%.6f %.6f\n", a1/a3, a2/a3);
}
