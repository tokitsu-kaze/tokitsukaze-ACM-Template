struct Segment{Point a,b;};

//�߶�ab�е�
Point midseg(Segment seg){return (seg.a+seg.b)/2;}

//��p���߶���
//�߶ΰ����˵�ʱ�ĳ�<=
bool PointOnSeg(Point p,Segment seg)
{
	return sgn(cross(seg.a-p,seg.b-p))==0 &&
		   sgn(dot(seg.a-p,seg.b-p))<0;
}

//��p���߶η�Χ��
bool InRange(Point p,Segment seg)
{
	return dot(p-seg.a,seg.b-seg.a)>0 &&
		   dot(p-seg.b,seg.a-seg.b)>0;
}

//�㵽�߶ξ���
db DisPointToSeg(Point p,Segment seg)
{
	if(seg.a==seg.b) return length(p-seg.a);
	Vector v1,v2,v3;
	v1=seg.b-seg.a;
	v2=p-seg.a;
	v3=p-seg.b;
	if(sgn(dot(v1,v2))<0) return length(v2);
	else if(sgn(dot(v1,v3))>0) return length(v3);
	else return abs(cross(v1,v2))/length(v1);
}

//���߶��������
db DisSegToSeg(Segment x,Segment y)
{
	return min({
		DisPointToSeg(x.a,y),
		DisPointToSeg(x.b,y),
		DisPointToSeg(y.a,x),
		DisPointToSeg(y.b,x)
	});
}

//�߶��ཻ�ж�
bool JudgeSegInter(Segment x,Segment y)
{
	db t1,t2,t3,t4;
	t1=cross(x.b-x.a,y.a-x.a);
	t2=cross(x.b-x.a,y.b-x.a);
	t3=cross(y.b-y.a,x.a-y.a);
	t4=cross(y.b-y.a,x.b-y.a);
	return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
}
