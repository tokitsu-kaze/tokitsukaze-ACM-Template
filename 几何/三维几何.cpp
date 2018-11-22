

struct Point
{  
	double x,y,z;
	Point(){}
	Point(double a,double b,double c):x(a),y(b),z(c){}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y,a.z+b.z);}
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y,a.z-b.z);}
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p,a.z*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p,a.z/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}


