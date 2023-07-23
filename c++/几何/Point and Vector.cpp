typedef double db;
const db eps=1e-6;
namespace Geometry
{
	#define type db
	int sgn(type x)
	{
		if(abs(x)<eps) return 0;
		else return x>0?1:-1;
	}
	struct Point
	{  
		type x,y;
		Point operator +(const Point &a){return {x+a.x,y+a.y};}
		Point operator -(const Point &a){return {x-a.x,y-a.y};}
		Point operator -(){return {-x,-y};}
		Point operator *(const type k){return {x*k,y*k};}
		Point operator /(const type k){return {x/k,y/k};}
		bool operator <(const Point &a){return sgn(x-a.x)==0?sgn(y-a.y)<0:sgn(x-a.x)<0;}
		bool operator ==(const Point &a){return sgn(x-a.x)==0&&sgn(y-a.y)==0;}
	};
	typedef Point Vector;
	
	type dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;} //点积
	type cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;} //叉积
	db length(Vector a){return sqrtl(dot(a,a));} //向量长度
	type length2(Vector a){return dot(a,a);} //向量长度的平方
	db dist(Point a,Point b){return sqrtl(dot(a-b,a-b));} //两点距离
	type dist2(Point a,Point b){return dot(a-b,a-b);} //两点距离的平方
	Vector normal(Vector a){return Point{-a.y,a.x}/length(a);} //垂直法向量
	Vector vecunit(Vector a){return a/length(a);} //单位向量
	db ang(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}//两个向量夹角 
	db ang(Vector v){return atan2(v.y,v.x);}
	Vector rotate(Vector a,db rad) //逆时针旋转 
	{
		return {a.x*cos(rad)-a.y*sin(rad),
				a.x*sin(rad)+a.y*cos(rad)};
	}
	#undef type
}
using namespace Geometry;

/* 
向量叉积 
若 PxQ>0,则P在Q的顺时针方向。 
若 PxQ<0,则P在Q的逆时针方向。 
若 PxQ=0,则P与Q共线,但可能同向也可能反向。 
*/


