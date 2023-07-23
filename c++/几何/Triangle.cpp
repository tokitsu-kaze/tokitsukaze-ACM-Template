//三角形面积
db area(Point c,Point b,Point a){return cross(b-a,c-a)/2;}

//内心
Point incenter(Point a,Point b,Point c)
{
    Line u,v;
    db ta,tb;
    u.a=a;
    ta=atan2(b.y-a.y,b.x-a.x);
    tb=atan2(c.y-a.y,c.x-a.x);
    u.b.x=u.a.x+cos((ta+tb)/2);
    u.b.y=u.a.y+sin((ta+tb)/2);
    v.a=b;
    ta=atan2(a.y-b.y,a.x-b.x);
    tb=atan2(c.y-b.y,c.x-b.x);
    v.b.x=v.a.x+cos((ta+tb)/2);
    v.b.y=v.a.y+sin((ta+tb)/2);
    return PointOfLineInter(u,v);
}

//外心 
Point circumcenter(Point a,Point b,Point c)  
{
	Point res;
    db a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
    db a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
    db d=a1*b2-a2*b1;
    return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}

//垂心
Point orthocenter(Point a,Point b,Point c)
{  
    db c1,c2,d;
    Point p1,p2;
    p1=c-b;
    c1=0;
    p2=c-a;
    c2=dot(b-a,p2);
    d=cross(p1,p2);
    return Point(a.x+(c1*p2.y-c2*p1.y)/d,a.y+(p1.x*c2-p2.x*c1)/d);  
}

//重心->见多边形重心 

