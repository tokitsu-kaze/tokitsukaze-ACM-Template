//有向直线,它的左边就是对应的半平面  
struct Line
{  
	Point p;
	Vector v;
};
Line twopoint(Point a,Point b){return Line{a,b-a};} //两点式
 
//直线和点的位置关系  -1:左  |  1:右  |  0:在直线上 
int LinePointRelation(Line l,Point p)
{
	Point a,b;
	a=l.p;
	b=l.p+l.v;
	return sgn(cross(a-p,b-p));
}

//点到直线距离  
db DisPointToLine(Point p,Line l)
{
	return abs(cross(l.v,p-l.p))/length(l.v);
}

//点p在直线的投影  
Point GetLineProjection(Point p,Line l)
{  
	return l.p+l.v*(dot(l.v,p-l.p)/dot(l.v,l.v));
}

//求两直线交点 
Point PointOfLineInter(Line a,Line b)
{
	return a.p+a.v*(cross(b.v,a.p-b.p)/cross(a.v,b.v));
}

//判断直线相交 
int JudgeLineInter(Line a,Line b)
{
	if(sgn(cross(a.v,b.v))==0)
	{
		if(sgn(cross(a.p-b.p,b.v))==0) return 0;//重合 
		else return 1;//平行 
	}
	else return 2;//有交点 
}


