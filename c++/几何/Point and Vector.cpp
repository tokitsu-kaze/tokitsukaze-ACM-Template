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
	
	type dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;} //���
	type cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;} //���
	db length(Vector a){return sqrtl(dot(a,a));} //��������
	type length2(Vector a){return dot(a,a);} //�������ȵ�ƽ��
	db dist(Point a,Point b){return sqrtl(dot(a-b,a-b));} //�������
	type dist2(Point a,Point b){return dot(a-b,a-b);} //��������ƽ��
	Vector normal(Vector a){return Point{-a.y,a.x}/length(a);} //��ֱ������
	Vector vecunit(Vector a){return a/length(a);} //��λ����
	db ang(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}//���������н� 
	db ang(Vector v){return atan2(v.y,v.x);}
	Vector rotate(Vector a,db rad) //��ʱ����ת 
	{
		return {a.x*cos(rad)-a.y*sin(rad),
				a.x*sin(rad)+a.y*cos(rad)};
	}
	#undef type
}
using namespace Geometry;

/* 
������� 
�� PxQ>0,��P��Q��˳ʱ�뷽�� 
�� PxQ<0,��P��Q����ʱ�뷽�� 
�� PxQ=0,��P��Q����,������ͬ��Ҳ���ܷ��� 
*/


