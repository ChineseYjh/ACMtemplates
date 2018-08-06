//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double dis(Point &x, Point &y){
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
struct Point
{
	double x, y;
} p[100];

Point circumcenter(const Point &a,const Point &b,const Point &c) {//返回三角形的外心
    Point ret;
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    ret.x=a.x+(c1*b2-c2*b1)/d;
    ret.y=a.y+(a1*c2-a2*c1)/d;
    return ret;
}

void min_cover_circle(Point* p, int len, Point& o, double& r){//p为点组，len为点数，o为圆心，r为半径 
	random_shuffle(p, p + len);
	o.x = p[0].x, o.y = p[0].y; r = 0;
	for(int i = 1; i < len; i++){
		if(dis(o, p[i]) > r + eps){
			o.x = p[i].x, o.y = p[j].y, r = 0;
			for(int j = 0; j < i; j++){
				if(dis(o, p[j]) > r + eps){
					o.x = (o.x + p[j].x) / 2, o.y = (o.y + p[j].y) / 2;
					r = dis(o, p[j]) / 2;
					for(int k = 0; k < j; k++){
						if(dis(p[k], o) > r + eps){
							o = circumcenter(p[i], p[j], p[k]);
							r = dis(o, p[i]);
						}
					}
				}
			}
		}
	} 
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}

