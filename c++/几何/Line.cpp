//����ֱ��,������߾��Ƕ�Ӧ�İ�ƽ��  
struct Line
{  
	Point p;
	Vector v;
};
Line twopoint(Point a,Point b){return Line{a,b-a};} //����ʽ
 
//ֱ�ߺ͵��λ�ù�ϵ  -1:��  |  1:��  |  0:��ֱ���� 
int LinePointRelation(Line l,Point p)
{
	Point a,b;
	a=l.p;
	b=l.p+l.v;
	return sgn(cross(a-p,b-p));
}

//�㵽ֱ�߾���  
db DisPointToLine(Point p,Line l)
{
	return abs(cross(l.v,p-l.p))/length(l.v);
}

//��p��ֱ�ߵ�ͶӰ  
Point GetLineProjection(Point p,Line l)
{  
	return l.p+l.v*(dot(l.v,p-l.p)/dot(l.v,l.v));
}

//����ֱ�߽��� 
Point PointOfLineInter(Line a,Line b)
{
	return a.p+a.v*(cross(b.v,a.p-b.p)/cross(a.v,b.v));
}

//�ж�ֱ���ཻ 
int JudgeLineInter(Line a,Line b)
{
	if(sgn(cross(a.v,b.v))==0)
	{
		if(sgn(cross(a.p-b.p,b.v))==0) return 0;//�غ� 
		else return 1;//ƽ�� 
	}
	else return 2;//�н��� 
}


