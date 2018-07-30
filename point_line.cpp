//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;

//定义点的类型 
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x) , y(y) { }  //构造函数，方便代码编写 
};
 
typedef Point Vector;
const double eps = 1e-10;

//向量 + 向量 = 向量 ，点 + 向量 = 点
Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
//点 - 点 = 向量
Vector operator - (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
//向量 * 数 = 向量 
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
//向量 / 数 = 向量 
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); } 
bool operator < (const Point& a, const Point& b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
} 
int sgn(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}
bool operator == (const Point& a, const Point& b) {
	return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
//点乘 
double Dot(const Vector &v1, const Vector &v2){
	return v1.x * v2.x + v2.y * v2.y;
}
//长度 
double Length(const Vector &v){
	return sqrt(Dot(v, v));
}
//夹角 
double Angle(const Vector &a, const Vector &b){
	return acos(Dot(a, b) / (Length(a) * Length(b)));
}
//叉乘 
double Cross(const Vector &a, const Vector &b){
	return a.x * b.y - b.x * a.y;
}
//三角形面积的两倍
double Area2(const Point &a, const Point &b, const Point &c){
	return fabs(Cross(b - a, c - a));
} 
//将向量旋转
Vector Rotate(const Vector &v, double rad){
	return Vector(v.x * cos(rad) - v.y * sin(rad), v.y * cos(rad) + v.x * sin(rad));
} 
//单位化
Vector Normal(const Vector &v){
	return v / Length(v); 
} 
//两直线交点(参数方程式) 
Point GetLineIntersection(const Point &P, const Vector &v, const Point &Q, const Vector &w){
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + t * v;
} 
//点到直线距离
double DistanceToLine(const Point &a, const Point &node1, const Point &node2){
	return Area2(a, node1, node2) / Length(node1 - node2);
}
//点到线段的距离
double DistanceToSegment(const Point &a, const Point &node1, const Point &node2){
	if(sgn(Dot(node1 - a, node1 - node2)) == -1) return Length(node1 - a);
	if(sgn(Dot(node2 - a, node2 - node1)) == -1) return Length(node2 - a);
	else return DistanceToLine(a, node1, node2); 
}
//点到直线的投影
Point GetLineProjection(const Point &a, const Point &node1, const Point &node2){
	Vector v = node1 - node2;
	double t = Dot(a - node1, v) / Dot(v, v);
	return node1 + v * t;
} 
//线段规范相交判定
bool JudgeSegmentIntersection_std(const Point &a1, const Point &a2, const Point &b1, const Point &b2){
	//快速排斥实验
	if(min(a1.x, a2.x) > max(b1.x, b2.x) || max(a1.x, a2.x) < min(b1.x, b2.x)
	|| min(a1.y, a2.y) > max(b1.y, b2.y) || max(a1.y, a2.y) < min(b1.y, b2.y))return false;
	//跨立实验
	if(sgn(Cross(a1 - a2, a1 - b1) * Cross(a1 - a2, a1 - b2)) == -1
	&& sgn(Cross(b1 - b2, b1 - a1) * Cross(b1 - b2, b1 - a2)) == -1)return true;
	return false;
} 

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}

