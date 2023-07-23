//���� 
while(r-l>eps)  
{  
	rm=(l+r)/2;  
	lm=(rm+r)/2;
	tl=cal(lm);
	tr=cal(rm);
	if(tr<=tl) r=lm;//���ַ������ֵʱ��Ϊtr>=tl
	else l=rm;
}

//��ʽ


//ŷ�������幫ʽ
double solve(double a,double b,double c,double d,double e,double f)
{
	return sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-e*e)*(b*b+c*c-e*e)-b*b*(c*c+a*a-f*f)*(c*c+a*a-f*f)-c*c*(a*a+b*b-d*d)*(a*a+b*b-d*d)+(a*a+b*b-d*d)*(b*b+c*c-e*e)*(c*c+a*a-f*f)))/12;
}
 






/*************��*************/  
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
//�㶨�� 
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};

typedef Point Vector;

Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}

bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}


double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//���
double length(Vector a){return sqrt(dot(a,a));}//������ģ 
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//��� 
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}//������� 
Point midseg(Point a,Point b){return (a+b)/2;}//�߶�ab�е�
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);} //��ֱ������ 
Vector Rotate(Vector a,double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}
double calarea(Point c,Point b,Point a){return cross(b-a,c-a);}//����������������� 
Vector vecunit(Vector x){return x/length(x);}//��λ����
double TwoVectorAngle(Vector a,Vector b){return acos(dot(a,b)/length(a)/length(b));}//���������н� 
double VectorAngle(Vector v){return atan2(v.y,v.x);}
/* 
������� 
�� PxQ>0,��P��Q��˳ʱ�뷽�� 
�� PxQ<0,��P��Q����ʱ�뷽�� 
�� PxQ=0,��P��Q����,������ͬ��Ҳ���ܷ��� 
*/


/****************ֱ�����߶�**************/ 

//����ֱ��,������߾��Ƕ�Ӧ�İ�ƽ��  
struct Line
{  
	Point p;//ֱ��������һ��  
	Vector v; 
	double ang;//����,����x��������ת������v����Ҫ�Ľǣ����ȣ� 
	double a,b,c;//ֱ��һ��ʽ 
	Line(){}
	Line(Point a,Vector b)//��бʽ 
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	void twopoint(Point a,Point b)//����ʽ 
	{
		p=a;
		v=b-a;
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	Point getpoint(double a)
	{  
		return p+(v*a);  
	}
	void LineGeneralEquation()//����һ��ʽ��a,b,c 
	{
		Point p1,p2;
		p1=p;
		p2=p+v;
		a=p2.y-p1.y;  
		b=p1.x-p2.x;  
		c=-a*p1.x-b*p1.y;
	}
};

//��p���߶���
//�߶ΰ����˵�ʱ�ĳ�<=  
bool OnSeg(Point p,Point p1,Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}

//��A������L(p,v)�ϣ������˵�
int onRay(Point a, Line l)
{
	Vector w=a-l.p;
	if(sgn(cross(w,l.v))==0&&sgn(dot(w,l.v))>0) return 1;
	return 0;
}

//��p���߶η�Χ��
bool PointInRange(Point p,Point a,Point b)
{
	return dot(p-a,b-a)>0&&dot(p-b,a-b)>0;//pab<90  pba<90 
}

//�㵽�߶ξ���  
double DisPointToSeg(Point p,Point a,Point b)
{
	if(a==b) return length(p-a);
	Vector v1,v2,v3;
	v1=b-a;
	v2=p-a;
	v3=p-b;
	if(sgn(dot(v1,v2))<0) return length(v2);
	else if(sgn(dot(v1,v3))>0) return length(v3);
	else return fabs(cross(v1,v2))/length(v1);
}

//���߶��������  
double DisSegToSeg(Point a,Point b,Point c,Point d)
{
	return min(min(DisPointToSeg(a,c,d),DisPointToSeg(b,c,d))
	,min(DisPointToSeg(c,a,b),DisPointToSeg(d,a,b)));
}

//�߶��ཻ�ж�  
bool JudgeSegInter(Point a,Point b,Point c,Point d)
{
	double t1,t2,t3,t4;
	t1=cross(b-a,c-a);
	t2=cross(b-a,d-a);
	t3=cross(d-c,a-c);
	t4=cross(d-c,b-c);
	return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
}

//�ж�ֱ��ab���߶�cd�Ƿ��ཻ
bool SegInterLine(Point a,Point b,Point c,Point d)
{
	return sgn(cross((c-b),(a-b)))*sgn(cross((d-b),(a-b)))<=0;
}

//�㵽ֱ�߾���  
double DisPointToLine(Point p, Point a, Point b)
{
	Vector v1,v2;
	v1=b-a;
	v2=p-a; 
	return fabs(cross(v1,v2))/length(v1);//�����ȡ����ֵ,�õ������������  
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
//����ֱ�߽��� 
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}

//�����ֱ��ax+by+c=0�ĶԳƵ�
//1.
Point PointSymmetryLine(Point p,Line l)
{
	Point res;
	double k,a,b,c;
	a=l.a;
	b=l.b;
	c=l.c;
	k=-2*(a*p.x+b*p.y+c)/(a*a+b*b);
	res.x=p.x+k*a;
	res.y=p.y+k*b;
	return res;
}

//2.
Point mirrorPoint(Point a,Line l)
{
	Vector tmp=l.p+l.v*(dot(l.v,a-l.p)/dot(l.v,l.v));
	return tmp+(tmp-a);
}

//��p��ֱ��ab��ͶӰ  
Point GetLineProjection(Point p,Point a,Point b)
{  
	Vector v=b-a;  
	return a+v*(Dot(v,p-a)/dot(v,v));
}

//��ƽ�潻
bool OnLeft(Line l,Point p)
{  
	return cross(l.v,p-l.p)>0; //��p������ֱ��L�����(���ϲ���) 
}
bool hpicmp(Line a,Line b)
{
	return a.ang<b.ang;
}
vector<Point> hpi(vector<Line> l)
{
	int n,i;
	n=l.size();
	sort(l.begin(),l.end(),hpicmp);//����������  
	int first,last;         // ˫�˶��еĵ�һ��Ԫ�غ����һ��Ԫ�ص��±�  
	vector<Point> p(n);      // p[i]Ϊq[i]��q[i+1]�Ľ���  
	vector<Line> q(n);       // ˫�˶���  
	vector<Point> ans;       // ���  
	q[first=last=0]=l[0];  // ˫�˶��г�ʼ��Ϊֻ��һ����ƽ��L[0]  
	for(i=1;i<n;i++)
	{  
	    while(first<last&&!OnLeft(l[i],p[last-1])) last--;  
	    while(first<last&&!OnLeft(l[i],p[first])) first++;  
		q[++last]=l[i];  
		if(fabs(cross(q[last].v,q[last-1].v))<eps)
		{ // ������ƽ����ͬ��ȡ�ڲ��һ��  
			last--;  
			if(OnLeft(q[last],l[i].p)) q[last]=l[i];  
		}  
		if(first<last) p[last-1]=PointOfLineInter(q[last-1],q[last]);  
	}  
	while(first<last&&!OnLeft(q[first],p[last-1])) last--; //ɾ������ƽ��  
	if(last-first<=1) return ans; //�ռ�  
	p[last]=PointOfLineInter(q[last],q[first]); //������β������ƽ��Ľ���  
	for(i=first;i<=last;i++)
	{
		ans.push_back(p[i]);// ��deque���Ƶ������  
	}
	return ans;  
}  


/***************������****************/
//����
Point InCenter(Point a,Point b,Point c)
{
    Line u,v;
    double m,n;
    u.a=a;
    m=atan2(b.y-a.y,b.x-a.x);
    n=atan2(c.y-a.y,c.x-a.x);
    u.b.x=u.a.x+cos((m+n)/2);
    u.b.y=u.a.y+sin((m+n)/2);
    v.a=b;
    m=atan2(a.y-b.y,a.x-b.x);
    n=atan2(c.y-b.y,c.x-b.x);
    v.b.x=v.a.x+cos((m+n)/2);
    v.b.y=v.a.y+sin((m+n)/2);
    return PointOfLineInter(u,v);
}
//���� 
Point CircumCircle(Point a,Point b,Point c)  
{  
	Point res;   
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;  
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;  
    double d=a1*b2-a2*b1;  
    return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}
//����
Point OrthoCenter(Point a,Point b,Point c)
{  
    double c1,c2,d;
    Point p1,p2;
    p1=c-b;
    c1=0;
    p2=c-a;
    c2=dot(b-a,p2);
    d=cross(p1,p2);
    return Point(a.x+(c1*p2.y-c2*p1.y)/d,a.y+(p1.x*c2-p2.x*c1)/d);  
}
//����->����������� 


/***************�����****************/  

// �㼯͹��  
// �����ϣ����͹���ı���������㣬������ <= �ĳ� <  
// ע�⣺����㼯�ᱻ�޸�  
vector<Point> graham(vector<Point> p)
{  
	int n,m,k,i;
	sort(p.begin(),p.end());//Ҫ�õ�operator < 
	p.erase(unique(p.begin(),p.end()),p.end());//Ҫ�õ�operator == 
	n=p.size();
	m=0;
	vector<Point> res(n+1);  
	for(i=0;i<n;i++)
	{  
		while(m>1&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
		res[m++]=p[i];  
	}
	k=m;  
	for(i=n-2;i>=0;i--)
	{  
		while(m>k&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
	    res[m++]=p[i];  
	}  
	if(n>1) m--;  
	res.resize(m);
	return res;
}

//�жϵ��Ƿ��ڶ������  
int JudgePointInPolygon(Point p,vector<Point> poly)
{
	int cnt,n,k,d1,d2;
	cnt=0;
	n=poly.size();
	for(int i=0;i<n;i++)
	{
		if(OnSeg(p,poly[i],poly[(i+1)%n])) return -1;//�ڱ��� 
		k=sgn(cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		d1=sgn(poly[i].y-p.y);
		d2=sgn(poly[(i+1)%n].y-p.y);
		if(k>0&&d1<=0&&d2>0) cnt++;
		if(k<0&&d2<=0&&d1>0) cnt--;
	} 
	if(cnt) return 1;//�ڲ� 
	else return 0;//�ⲿ 
}

//��������� �㼯��ʱ�����  
Point bcenter(vector<Point> p)
{
	int i,j,n;
	Point t,ans;
	double tp,s,tpx,tpy;
	s=t.x=t.y=0;
	n=p.size();
	for(i=0;i<n;i++)
	{
		if(i+1==n) j=0;
		else j=i+1;
		tp=cross(p[i],p[j]);
		s+=tp/2;
		t=t+(p[i]+p[j])*tp;
	}
	ans=t/(6*s);
	return ans;
}

//������
//���ؾ��� 
Point p1[MAX],temp[MAX];
bool cmpxy(Point a,Point b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmpy(Point a,Point b)
{
	return a.y<b.y;
}
double ClosestPair(int l,int r)
{
	int mid,i,j,k;
	double d,d1,d2,d3;
	d=INF;
	if(l==r) return d;
	if(l+1==r) return dist(p1[l],p1[r]);
	mid=(l+r)>>1;
	d1=ClosestPair(l,mid);
	d2=ClosestPair(mid+1,r);
	d=min(d1,d2);
	k=0;
	for(i=l;i<=r;i++)
	{
		if(fabs(p1[mid].x-p1[i].x)<=d) temp[k++]=p1[i];
	}
	sort(temp,temp+k,cmpy);
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k&&temp[j].y-temp[i].y<d;j++)
		{
			d3=dist(temp[i],temp[j]);
			if(d>d3) d=d3;
		}
	}
	return d;
}
int main()
{
	//............................
	sort(p1,p1+n,cmpxy);
	ans=ClosestPair(0,n-1);
	//............................
} 


//ģ���˻�������
double getres(Point t,Point *p,int n)
{
	int i;
	double res=0;
	for(i=0;i<n;i++)
	{
		res+=dist(t,p[i]);
	}
	return res;
}
pair<Point,double> SA(Point *p,int n)
{  
	Point s;  
	double T=100,t,ds,dz,ans;  
	int i,j,k,flag,dir[5][2]={0,0,0,1,0,-1,1,0,-1,0};
	s=Point(0,0);
	for(i=0;i<n;i++)
	{  
		s.x+=p[i].x;  
		s.y+=p[i].y;  
	}
	s.x/=n;  
	s.y/=n;  
	ans=0;
	for(k=1;k<=100000;k++)
	{
		t=T/k;//���ȿ��� 
		for(i=0;i<5;i++)  
		{
			Point z;
			z.x=s.x+dir[i][0]*t;  
			z.y=s.y+dir[i][1]*t;  
			dz=getres(z,p,n);
			if(dz<ans)  
			{  
				ans=dz;
				s=z;
			} 
		}
	}
	pair<Point,double> res;
	res=make_pair(s,ans);
	return res;
}

//��СԲ���� 
double r;
Point center;
void CircumCircle(Point a,Point b,Point c) //���������� 
{  
	Point res;   
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;  
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;  
    double d=a1*b2-a2*b1;  
    res=Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);  
    center=res;  
}
void MinDisWith2Point(Point pi,Point pj,int m,vector<Point> p)  
{  
	int k;
	center=MidSeg(pi,pj);  
	r=dist(pi,pj)/2;  
	for(k=0;k<m;k++)
	{  
		if(dist(center,p[k])<=r) continue; 
        double t=cross((pi-pj),(p[k]-pj));  
        if(t!=0)
		{
			CircumCircle(pi,pj,p[k]);  
			r=dist(center,pi);  
		}  
		else
		{
			double d1,d2,d3;
			d1=dist(pi,pj);
			d2=dist(pi,p[k]);  
			d3=dist(pj,p[k]);
			if(d1>=d2&&d1>=d3)
			{
				center=MidSeg(pi,pj);
				r=dist(pi,pj)/2;
			}
			else if(d2>=d1&&d2>=d3)  
			{
				center=MidSeg(pi,p[k]);  
				r=dist(pi,p[k])/2;  
			}  
			else  
			{  
				center=MidSeg(pj,p[k]);  
				r=dist(pj,p[k])/2;  
			}  
		}  
	}  
}  
void MinDisWithPoint(Point pi,int m,vector<Point> p)  
{
	center=MidSeg(pi,p[0]); 
	r=dist(pi,p[0])/2;  
	for(int j=1;j<m;j++)  
	{  
		if(dist(center, p[j])<=r) continue;  
		else MinDisWith2Point(pi,p[j],j,p);
	}  
}
int main()
{
	//.................
	//n ��ĸ��� 
	vector<Point> p;
	if(n==1)
	{
		printf("%.2lf %.2lf 0.00\n",p[0].x,p[0].y);
		continue;
	}
	r=dist(p[0],p[1])/2;
    center=MidSeg(p[0],p[1]); 
    for(i=2;i<n;i++)
	{  
		if(dist(center,p[i])<=r) continue;  
		else MinDisWithPoint(p[i],i,p);
	}
	printf("%.2lf %.2lf %.2lf\n",center.x,center.y,r);
	//...................
} 

  
/***********��ת����**************/  

//ƽ����Զ���(͹��ֱ��) 
//����͹��
//��Զ��Ծ����ƽ�� 
double dist2(Point a,Point b){return dot(a-b,a-b);}//�����ƽ�� 
double RC_FarthestPair(vector<Point> p)
{  
	int n,i,j,k;
	n=p.size();
	if(n==1) return 0;
	if(n==2) return dist2(p[0],p[1]);
	double temp,res=0;
	k=1;
    for(j=1;j<n;j++)//���� 
	{  
		for(i=0;i<n;i++)//��ת 
		{  
			while(cross(p[i]-p[(i+j)%n],p[(k+1)%n]-p[k])<0) k=(k+1)%n;  
			temp=max(dist2(p[j],p[i]),dist2(p[j],p[k]));  
			res=max(res,temp);  
		}  
	}  
    return res;
}


//�㼯���������
//����͹��
//������������� 
double RC_Triangle(vector<Point> p)
{  
	int n,i,j,k;
	n=p.size();
	if(n<3) return 0;
	double temp,res=0;
	k=1;
    for(j=1;j<n;j++)//����
	{  
		for(i=0;i<n;i++)//��ת
		{  
			while(cross(p[i]-p[(i+j)%n],p[(k+1)%n]-p[k])<0) k=(k+1)%n;  
			temp=max(cross(p[(i+j)%n]-p[i],p[k]-p[i]),cross(p[(i+j)%n]-p[i],p[(k+1)%n]-p[i]));  
			res=max(res,temp);  
		}  
	}  
    return res/2;
}


//��͹���������  
double RC_Dis(vector<Point> p,vector<Point> q)
{  
    int i,j,k,n,m;
    n=p.size();
    m=q.size();
    j=k=0;
    for(i=0;i<n;i++)
    {
        if(p[i].y-p[k].y<-eps) k=i;
    }
    for(i=0;i<m;i++)
    {
        if(q[i].y-q[j].y>eps) j=i;
    }
    double temp,ans=1e9;
    for(i=0;i<n;i++)
    { 
        while((temp=cross(p[(k+1)%n]-p[k],q[(j+1)%m]-p[k])-cross(p[(k+1)%n]-p[k],q[j]-p[k]))>eps) j=(j+1)%m;  
        if(temp<-eps) ans=min(ans,DisPointToSeg(q[j],p[k],p[(k+1)%n])); 
        else ans=min(ans,DisSegToSeg(p[k],p[(k+1)%n],q[j],q[(j+1)%m]));  
        k=(k+1)%n;
    }  
    return ans;  
}  


/************Բ************/  
struct Circle  
{  
    Point c;  
    double r;  
    Circle(){}  
    Circle(Point a,double b)
    {
		c=a;
		r=b;
	}
	Point getpoint(double a) //����Բ�Ľ��������  
	{  
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);  
	}  
}; 

//��P��Բ������ �е����v���� 
int getTangents(Point p, Circle c, Vector* v)  
{  
	Vector u=c.c-p;  
	double d=length(u);  
	if(d<c.r) return 0;  
	else if(sgn(d-c.r)==0)  
	{  
		v[0]=Rotate(u,PI/2);  
		return 1;  
	}  
	else  
	{  
		double ang=asin(c.r/d);  
		v[0]=Rotate(u,-ang);  
		v[1]=Rotate(u,+ang);  
		return 2;  
	}  
}

//��a�㵽b��(��ʱ��)�ڵ�Բ�ϵ�Բ������  
double ArcLen(Circle c,Point a,Point b)  
{  
	double ang1,ang2;  
	Vector v1,v2;  
	v1=a-Point(c.c.x,c.c.y);  
	v2=b-Point(c.c.x,c.c.y);  
	ang1=atan2(v1.y,v1.x);  
	ang2=atan2(v2.y,v2.x);  
	if(ang2<ang1) ang2+=2*PI;  
	return c.r*(ang2-ang1);  
}

//��Բ�Ĺ�����, -1��ʾ����������
//������������ �е㱣����a b���� 
int CommonTangents(Circle c1,Circle c2, Point* a, Point* b)  
{  
	int cnt=0;  
	if(c1.r<c2.r)
	{
		swap(c1,c2);
		swap(a,b);
	}
	int d=(c1.c.x-c2.c.x)*(c1.c.x-c2.c.x)+(c1.c.y-c2.c.y)*(c1.c.y-c2.c.y);  
	int rd=c1.r-c2.r;  
	int rs=c1.r+c2.r;  
	if(d<rd*rd) return 0; //�ں� 
    double base=atan2(c2.c.y-c1.c.y,c2.c.x-c1.c.x);  
	if(d==0&&sgn(c1.r-c2.r)==0) return -1;//���߶�������  
	if(d==rd*rd)//����, 1������  
    {
		a[cnt]=c1.getpoint(base);
		b[cnt]=c2.getpoint(base);
		cnt++;  
		return 1;  
    }  
    //���⹫����  
	double ang=acos((c1.r-c2.r)/sqrt(d));  
	a[cnt]=c1.getpoint(base+ang);
	b[cnt]=c2.getpoint(base+ang);
	cnt++;  
	a[cnt]=c1.getpoint(base-ang);
	b[cnt]=c2.getpoint(base-ang);
	cnt++;  
	if(d==rs*rs)//һ���ڹ�����  
	{  
		a[cnt]=c1.getpoint(base);
		b[cnt]=c2.getpoint(PI+base);
		cnt++;  
	}  
	else if(d>rs*rs)//�����ڹ�����  
	{  
		double ang=acos((c1.r+c2.r)/sqrt(d));  
		a[cnt]=c1.getpoint(base+ang);
		b[cnt]=c2.getpoint(PI+base+ang);
		cnt++;  
		a[cnt]=c1.getpoint(base-ang);
		b[cnt]=c2.getpoint(PI+base-ang);
		cnt++;  
	}
	return cnt;  
}

//���������Բ  
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{  
	double bx=p2.x-p1.x,by=p2.y-p1.y;  
	double cx=p3.x-p1.x,cy=p3.y-p1.y;  
	double d=2*(bx*cy-by*cx);  
	double ex=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;  
	double ey=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;  
	Point p=Point(ex,ey);
	return Circle(p,length(p1-p));
}

//����������Բ  
Circle InscribedCircle(Point p1,Point p2,Point p3)
{  
	double a=length(p2-p3);  
	double b=length(p3-p1);  
	double c=length(p1-p2);  
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);  
	return Circle(p,DisPointToLine(p,p1,p2));  
}

//�߶���Բ�Ľ���
int getSegCircleInter(Line l,Circle c,Point *sol)
{  
	Vector nor=Normal(l.v);
	Line l1=Line(c.c,nor);  
	Point p1=PointOfLineInter(l1,l);  
	double d=length(p1-c.c);  
    if(sgn(d-c.r)>0) return 0;
	Point p2=vecunit(l.v)*sqrt(c.r*c.r-d*d);  
	int res=0;  
	sol[res]=p1+p2;  
    if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=p1-p2;
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;  
	return res;  
}

//ֱ����Բ���� ���ظ���  
int getLineCircleInter(Line l,Circle cc,Point *sol)
{ 
	double a,b,c,d,e,f,g,delta,t;
	a=l.v.x;
	b=l.p.x-cc.c.x;
	c=l.v.y;
	d=l.p.y-cc.c.y;
	e=a*a+c*c;
	f=2*(a*b+c*d);
	g=b*b+d*d-cc.r*cc.r;  
	delta=f*f-4*e*g;
	if(sgn(delta)<0) return 0;
	if(sgn(delta)==0)
	{
		t=-f/(2*e);
		sol[0]=l.getpoint(t);
		return 1;
	}  
	else
	{
		t=(-f-sqrt(delta))/(2*e);
		sol[0]=l.getpoint(t);
		t=(-f+sqrt(delta))/(2*e);
		sol[1]=l.getpoint(t);
		return 2;
	}
}

//��Բ���� ���ظ���
int getCircleInter(Circle c1,Circle c2,Point *sol)
{
	double r1,r2,x1,y1,x2,y2,d;
	r1=c1.r;
	r2=c2.r;
	x1=c1.c.x;
	y1=c1.c.y;
	x2=c2.c.x;
	y2=c2.c.y;
	d=length(c1.c-c2.c);
	if(sgn(fabs(r1-r2)-d)>0) return -1;
	if(sgn(r1+r2-d)<0) return 0;
	double a,b,c,p,q,r;
	a=r1*(x1-x2)*2;
	b=r1*(y1-y2)*2;
	c=r2*r2-r1*r1-d*d;
	p=a*a+b*b;
	q=-a*c*2;
	r=c*c-b*b;
    double cosa,sina,cosb,sinb; 
	if(sgn(d-(r1+r2))== 0||sgn(d-fabs(r1-r2))==0)
	{
		cosa=-q/p/2;
		sina=sqrt(1-cosa*cosa);
		Point p(x1+c1.r*cosa,y1+c1.r*sina);
		if(!OnCircle(p,c2)) p.y=y1-c1.r*sina;
		sol[0]=p;
		return 1;
    }
	double delta=sqrt(q*q-p*r*4);
	cosa=(delta-q)/p/2;
	cosb=(-delta-q)/p/2;
	sina=sqrt(1-cosa*cosa);
	sinb=sqrt(1-cosb*cosb);
	Point p1(x1+c1.r*cosa,y1+c1.r*sina);
	Point p2(x1+c1.r*cosb,y1+c1.r*sinb);
	if(!OnCircle(p1,c2)) p1.y=y1-c1.r*sina;
	if(!OnCircle(p2,c2)) p2.y=y1-c1.r*sinb;
	if(p1==p2) p1.y=y1-c1.r*sina;
	sol[0]=p1;
	sol[1]=p2;
	return 2;
}

//����Բ���� �뾶Ϊr������Բ��  
int CircleTangentToTwoDisjointCirclesWithRadius(Circle c1,Circle c2,double r,Point *ans)
{
	Vector v=c2.c-c1.c;  
	double d=length(v);
	if(sgn(d-c1.r-c2.r-r*2)>0) return 0;
	//�������л������� �ܹ�4����� 
	return PointOfCircleCircleInter(Circle(c1.c,r-c1.r),Circle(c2.c,r-c2.r),ans)
/*		  +PointOfCircleCircleInter(Circle(c1.c,r+c1.r),Circle(c2.c,r-c2.r),ans)
		  +PointOfCircleCircleInter(Circle(c1.c,r-c1.r),Circle(c2.c,r+c2.r),ans)
		  +PointOfCircleCircleInter(Circle(c1.c,r+c1.r),Circle(c2.c,r+c2.r),ans)*/;
}




//��n��Բ������Բ sgu414
//�����ڷ���-1 �ж������-2 �𰸴���res 
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int vis[MAX];
Circle cir[MAX];
Point p[MAX];
Line l[MAX];
Line get_line(Circle a,Circle b)//���������
{
	Line AB;
	AB.twopoint(a.c,b.c);
	Point P,Q;
	Vector R;
	double d=length(a.c-b.c);
	double t=(d*d+a.r*a.r-b.r*b.r)/(2*d*d);
	P=AB.getpoint(t);
	R=a.c-b.c;
	Q=Point(-R.y,R.x)+P;
	Line res;
	res.twopoint(P,Q);
	return res;
}
int JudgeLineInter(Line a,Line b)
{
	if(sgn(cross(a.v,b.v))==0)
	{
		if(sgn(cross(a.p-b.p,b.v))==0) return 0;//�غ� 
		else return 1;//ƽ�� 
	}
	else return 2;//�н��� 
}
bool judge(Point P,int n)//�е��Ƿ���Բ��
{
	int i;
	for(i=0;i<n;i++)
		if(sgn(length(cir[i].c-P)-cir[i].r)<=0)return false;
	return true;
}
int cmp(Circle a,Circle b)//����Ƚ�
{
	if(a.c==b.c)return a.r<b.r;
	else if(sgn(a.c.x-b.c.x)==0)return a.c.y<b.c.y;
	else return a.c.x<b.c.x;
}
int Orthogonal_Circle(int n,Circle *cir,Circle &res)
{
	int i,j,k;
	if(n==1) return -2;
	int m=0,t=0;
	sort(cir,cir+n,cmp);//�������ڲ����غ��Լ�ͬ��Բ
	//�ҳ�����������
	for(i=0;i<n-1;i++)
	{
		if(cir[i].c==cir[i+1].c&&sgn(cir[i].r-cir[i+1].r)==0)continue;//�غϵ�Բ��������
		else if(cir[i].c==cir[i+1].c)break;//ͬ��Բ�����غϣ������-1
		l[m++]=get_line(cir[i],cir[i+1]);
	}
	if(i<n-1) return -1;
	//�ҳ����������ߵĽ���
	for(i=0;i<m-1;i++)
	{
		int tmp=JudgeLineInter(l[i],l[i+1]);
		//�غ����ӣ�ƽ���޽�
		if(tmp==0) continue;
		if(tmp==1) return -1;//ƽ�е�ʱ��
		p[t++]=PointOfLineInter(l[i],l[i+1]);
	}
	if(t==0) return -2;//ȫ���غϵ�ʱ��
	int flag=0;
	for(i=0;i<t-1;i++)
	{
		if(p[i]==p[i+1])continue;
		flag=1;//�ཻ�㲻ͬ
	}
	if(flag) return -1;
	if(!flag)
	{
		if(judge(p[0],n)) //�жϵ��Ƿ���Բ�ڣ���Բ���ǲ����ϵĵ�
		{
			res=Circle(p[0],sqrt(pow(length(p[0]-cir[0].c),2)-cir[0].r*cir[0].r));
			return 1;
		}
		else return -1;
	}
}





/************�������************/  

//��������  
double PolygonArea(Point *p,int n)
{ 
	double res=0;
	for(int i=0;i<n;i++)
	{
		res+=cross(p[i],p[(i+1)%n]);  
	}
	return fabs(res/2);  
}


//͹���������� ConvexPolygonInterArea
double CPIA(Point *a,Point *b,int na,int nb)
{
    Point p[MAX],q[MAX];
    int tn,sflag,eflag,i,j;
    a[na]=a[0];
	b[nb]=b[0];
	for(i=0;i<=nb;i++)
	{
		p[i]=b[i];
	}
    for(i=0;i<na&&nb>2;i++)
    {
        sflag=sgn(cross(a[i+1]-a[i],p[0]-a[i]));
        for(j=0,tn=0;j<nb;j++)
        {
            if(sflag>=0) q[tn++]=p[j];
            eflag=sgn(cross(a[i+1]-a[i],p[j+1]-a[i]));
            if((sflag^eflag)==-2) q[tn++]=PointOfLineInter(Line(a[i],a[i+1]-a[i]),Line(p[j],p[j+1]-p[j]));
       		sflag=eflag;
		}
        for(j=0;j<tn;j++)
        {
			p[j]=q[j];
		}
        nb=tn;
		p[nb]=p[0];
    }
    if(nb<3) return 0;
    return PolygonArea(p,nb);
}


//����������  SimplePolygonInterArea
double SPIA(Point *a,Point *b,int na,int nb)
{
    int i,j,temp1,temp2;
    Point t1[4],t2[4];
    double res=0;
    a[na]=t1[0]=a[0];
	b[nb]=t2[0]=b[0];
    for(i=2;i<na;i++)
    {
        t1[1]=a[i-1];
		t1[2]=a[i];
        temp1=sgn(cross(t1[1]-t1[0],t1[2]-t1[0]));
        if(temp1<0) swap(t1[1],t1[2]);
        for(j=2;j<nb;j++)
        {
            t2[1]=b[j-1];
			t2[2]=b[j];
            temp2=sgn(cross(t2[1]-t2[0],t2[2]-t2[0]));
            if(temp2<0) swap(t2[1],t2[2]);
            res+=CPIA(t1,t2,3,3)*temp1*temp2;
        }
    }
    return res;
}


//�������Բ�����
Point PointOfLineInter(Line a,Line b)//�߶ν���
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
bool InCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))>=0;}//��Բ��(����Բ��) 
int getSegCircleInter(Line l,Circle c,Point *sol)//�߶���Բ�Ľ���
{  
	Vector nor=Normal(l.v);
	Line l1=Line(c.c,nor);  
	Point p1=PointOfLineInter(l1,l);  
	double d=length(p1-c.c);  
    if(sgn(d-c.r)>0) return 0;
	Point p2=vecunit(l.v)*sqrt(c.r*c.r-d*d);  
	int res=0;  
	sol[res]=p1+p2;  
    if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=p1-p2;
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;  
	return res;  
}  
double VectorAngle(Vector v){return atan2(v.y,v.x);}
double SegCircleArea(Circle c,Point a,Point b) //�߶��и�Բ  
{  
	double a1=VectorAngle(a-c.c);  
	double a2=VectorAngle(b-c.c);  
	double da=fabs(a1-a2);  
	if (sgn(da-PI)>0) da=PI*2.0-da;  
	return sgn(cross(b-c.c,a-c.c))*da*c.r*c.r/2.0;  
}
double PolyCiclrArea(Circle c,Point *p,int n)//�������Բ�����  
{  
	double res=0;  
	Point sol[2];  
	p[n]=p[0];  
	for(int i=0;i<n;i++)
	{
		double t1,t2;  
		int cnt=getSegCircleInter(Line(p[i],p[i+1]-p[i]),c,sol);  
		if(cnt==0)  
		{  
			if(!InCircle(p[i],c)||!InCircle(p[i+1],c)) res+=SegCircleArea(c,p[i],p[i+1]);  
			else res+=cross(p[i+1]-c.c,p[i]-c.c)/2.0;  
		}  
		if(cnt==1)  
		{  
			if(InCircle(p[i],c)&&!InCircle(p[i+1],c))
			{
				res+=cross(sol[0]-c.c,p[i]-c.c)/2.0;
				res+=SegCircleArea(c,sol[0],p[i+1]);  
			}
			else
			{
				res+=SegCircleArea(c,p[i],sol[0]);
				res+=cross(p[i+1]-c.c,sol[0]-c.c)/2.0;  
			}
		}  
		if(cnt==2)  
		{  
			if((p[i]<p[i+1])^(sol[0]<sol[1])) swap(sol[0],sol[1]);  
			res+=SegCircleArea(c,p[i],sol[0]);  
			res+=cross(sol[1]-c.c,sol[0]-c.c)/2.0;  
			res+=SegCircleArea(c,sol[1],p[i+1]);  
		}  
	}  
	return fabs(res);  
} 


//��Բ����� 
double CircleCircleArea(Circle c1,Circle c2)
{
	double d=dist(c1.c,c2.c);//����Բ�ľ�
	if(sgn(d-(c1.r+c2.r))>=0||sgn(c1.r)==0||sgn(c2.r)==0) return 0;//���롢���л���һԲ�뾶Ϊ0
	else if(sgn(d-fabs(c1.r-c2.r))<=0)//���л��ں�
	{  
		double r=min(c1.r,c2.r);
		return r*r*PI;  
	} 
	else//�ཻ
	{
		double a,b,m,n,x,y;
		a=acos((d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r));  
		b=acos((d*d+c2.r*c2.r-c1.r*c1.r)/(2*d*c2.r));  
		m=a*c1.r*c1.r;  
		n=b*c2.r*c2.r;
		x=c1.r*c1.r*sin(a)*cos(a);  
		y=c2.r*c2.r*sin(b)*cos(b);  
		return m+n-(x+y);  
	}
}







////////////////////////////////////////////////////////////////////////////////
  
  

 




  

  
  
//���о�����p �뾶Ϊr ����ֱ��L���е�Բ��  
vector<Point> CircleThroughPointTangentToLineGivenRadius(Point p, Line L, double r) {  
  vector<Point> ans;  
  double t1, t2;  
  getLineCircleIntersection(L.move(-r), Circle(p, r), t1, t2, ans);  
  getLineCircleIntersection(L.move(r), Circle(p, r), t1, t2, ans);  
  return ans;  
}  
  
//�뾶Ϊr ��a b��ֱ�����е�Բ��  
vector<Point> CircleTangentToLinesGivenRadius(Line a, Line b, double r) {  
  vector<Point> ans;  
  Line L1 = a.move(-r), L2 = a.move(r);  
  Line L3 = b.move(-r), L4 = b.move(r);  
  ans.push_back(GetLineIntersection(L1, L3));  
  ans.push_back(GetLineIntersection(L1, L4));  
  ans.push_back(GetLineIntersection(L2, L3));  
  ans.push_back(GetLineIntersection(L2, L4));  
  return ans;  
}  
  

  


/*********����ģ��*********/  
//����ģ���������ϣ���δʹ�ù�  
//pick����  
LL x_mult(cpoint a,cpoint b,cpoint p)  
{  
    return (a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x);  
}  
LL pick()  
{  
    LL s =0, e = 0;  
    for(int i=0;i<n;i++)  
    {  
        s += x_mult(re[i],re[i+1],re[0]);  
        e += gcd(abs(re[i].y-re[i+1].y),abs(re[i].x-re[i+1].x));  
    }e/=2;s/=2;  
    return Abs(s)+1-e;  
}  
  
//�����жϵ��Ƿ���͹����  
struct POINT{  
    double x,y;  
    POINT(double _x = 0, double _y = 0):x(_x),y(_y){};  
    void show(){  
        cout<<x<<" "<<y<<endl;  
    }  
};  
POINT p[MAXN],wp[MAXN];  
double multiply(POINT sp,POINT ep,POINT op){ //���  
    return (sp.x-op.x) * (ep.y-op.y) - (ep.x-op.x) * (sp.y-op.y);  
}  
bool onseg(POINT a,POINT s,POINT e){   // �жϵ��Ƿ����߶���  
    if(multiply(a,s,e) == 0 && a.x <= max(s.x,e.x) && a.x >= min(s.x,e.x)  
       && a.y <= max(s.y,e.y) && a.y >= min(s.y,e.y))  
        return true;  
    return false;  
}  
bool inside(POINT pp,POINT sp,POINT ep,POINT op){ //�жϵ�pp�Ƿ�����������(������)  
    if(onseg(pp,sp,ep) || onseg(pp,sp,op) || onseg(pp,ep,op)) //�������������  
        return true;  
    if(multiply(sp,ep,pp) > 0 && multiply(ep,op,pp) > 0  
       && multiply(sp,op,pp) < 0)  //�������������  
           return true;  
    return false;  
}  
bool bsearch(POINT a,int len)  
{    //�����������������  
    int l = 1,r = len,m;  
    while(l < r){  
        m = (l + r) / 2;  
        if(inside(a,p[0],p[m],p[m+1]) == true) return true;  
        if(multiply(p[0],p[m],a) >= 0 && multiply(p[0],p[m+1],a) <= 0  
            && multiply(p[m],p[m+1],a) < 0) return false;  
        if(multiply(p[0],p[m],a) > 0 && multiply(p[0],p[m+1],a) > 0)  
            l = m + 1;  
        else r = m;  
    }  
    return false;  
}  
int main()  
{  
    int n,m,k,tmp = 0,cnt = 0;  
    scanf("%d%d%d",&n,&m,&k);  
    for(int i = 0 ; i < n ; i++)  
        scanf("%lf%lf",&p[i].x,&p[i].y);  
    p[n] = p[0];  
    for(int i = 0 ; i < m ; i++){  
        scanf("%lf%lf",&wp[i].x,&wp[i].y);  
        if(bsearch(wp[i],n-1) == true) cnt++;  
    }  
    if(cnt >= k) printf("YES\n");  
    else printf("NO\n");  
    return 0;  
}  
  
//Բ�������  
//Բ�������  
//  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<algorithm>  
#define sqr(x) ((x)*(x))  
using namespace std;  
  
const int N = 1010;  
const double eps = 1e-8;  
const double pi = acos(-1.0);  
double area[N];  
int n;  
  
int dcmp(double x) {  
    if (x < -eps) return -1; else return x > eps;  
}  
  
struct cp {  
    double x, y, r, angle;  
    int d;  
    cp(){}  
    cp(double xx, double yy, double ang = 0, int t = 0) {  
        x = xx;  y = yy;  angle = ang;  d = t;  
    }  
    void get() {  
        scanf("%lf%lf%lf", &x, &y, &r);  
        d = 1;  
    }  
}cir[N], tp[N * 2];  
  
double dis(cp a, cp b) {  
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));  
}  
  
double cross(cp p0, cp p1, cp p2) {  
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);  
}  
  
int CirCrossCir(cp p1, double r1, cp p2, double r2, cp &cp1, cp &cp2) {  
    double mx = p2.x - p1.x, sx = p2.x + p1.x, mx2 = mx * mx;  
    double my = p2.y - p1.y, sy = p2.y + p1.y, my2 = my * my;  
    double sq = mx2 + my2, d = -(sq - sqr(r1 - r2)) * (sq - sqr(r1 + r2));  
    if (d + eps < 0) return 0; if (d < eps) d = 0; else d = sqrt(d);  
    double x = mx * ((r1 + r2) * (r1 - r2) + mx * sx) + sx * my2;  
    double y = my * ((r1 + r2) * (r1 - r2) + my * sy) + sy * mx2;  
    double dx = mx * d, dy = my * d; sq *= 2;  
    cp1.x = (x - dy) / sq; cp1.y = (y + dx) / sq;  
    cp2.x = (x + dy) / sq; cp2.y = (y - dx) / sq;  
    if (d > eps) return 2; else return 1;  
}  
  
bool circmp(const cp& u, const cp& v) {  
    return dcmp(u.r - v.r) < 0;  
}  
  
bool cmp(const cp& u, const cp& v) {  
    if (dcmp(u.angle - v.angle)) return u.angle < v.angle;  
    return u.d > v.d;  
}  
  
double calc(cp cir, cp cp1, cp cp2) {  
    double ans = (cp2.angle - cp1.angle) * sqr(cir.r)  
        - cross(cir, cp1, cp2) + cross(cp(0, 0), cp1, cp2);  
    return ans / 2;  
}  
  
void CirUnion(cp cir[], int n) {  
    cp cp1, cp2;  
    sort(cir, cir + n, circmp);  
    for (int i = 0; i < n; ++i)  
        for (int j = i + 1; j < n; ++j)  
            if (dcmp(dis(cir[i], cir[j]) + cir[i].r - cir[j].r) <= 0)  
                cir[i].d++;  
    for (int i = 0; i < n; ++i) {  
        int tn = 0, cnt = 0;  
        for (int j = 0; j < n; ++j) {  
            if (i == j) continue;  
            if (CirCrossCir(cir[i], cir[i].r, cir[j], cir[j].r,  
                cp2, cp1) < 2) continue;  
            cp1.angle = atan2(cp1.y - cir[i].y, cp1.x - cir[i].x);  
            cp2.angle = atan2(cp2.y - cir[i].y, cp2.x - cir[i].x);  
            cp1.d = 1;    tp[tn++] = cp1;  
            cp2.d = -1;   tp[tn++] = cp2;  
            if (dcmp(cp1.angle - cp2.angle) > 0) cnt++;  
        }  
        tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, pi, -cnt);  
        tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, -pi, cnt);  
        sort(tp, tp + tn, cmp);  
        int p, s = cir[i].d + tp[0].d;  
        for (int j = 1; j < tn; ++j) {  
            p = s;  s += tp[j].d;  
            area[p] += calc(cir[i], tp[j - 1], tp[j]);  
        }  
    }  
}  
  
void solve()  
{  
    scanf("%d", &n);  
    for (int i = 0; i < n; ++i)  
        cir[i].get();  
    memset(area, 0, sizeof(area));  
    CirUnion(cir, n);  
    //ȥ���ظ������  
    for (int i = 1; i <= n; ++i) {  
        area[i] -= area[i + 1];  
    }  
    //area[i]Ϊ�ص���i�ε����  
    //tot Ϊ�����  
    double tot = 0;  
    for(int i=1; i<=n; i++) tot += area[i];  
    printf("%f\n", tot);  
}  
  

//��άƽ��һ��n���ڵ�ļ򵥶���Σ����������һ�����ݣ������������  
const double eps = 1e-8;  
const double pi = acos(-1.);  
using namespace std;  
int dblcmp( double x )  
{  
    if( fabs(x) < eps )    return 0;  
    return x > 0 ? 1 : -1;  
}  
double nowAng;  
struct point  
{  
    double x, y, a;  
    point(){}  
    point( double _x, double _y ) : x(_x), y(_y)  
    {  
        a = atan2(y, x);  
    }  
    bool operator<( const point p )    const  
    {  
        if( dblcmp(a-p.a) == 0 )  
            return x*x+y*y < p.x*p.x+p.y*p.y;  
        return a < p.a;  
    }  
} p[60000], O;  
inline double dis( point a, point b )  
{  
    double dx = a.x-b.x;  
    double dy = a.y-b.y;  
    return sqrt(dx*dx+dy*dy);  
}  
inline double cross( point k, point a, point b )  
{  
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);  
}  
point inter( point a1, point a2, double ang )  
{  
    point b1 = point(0, 0), b2 = point(cos(ang), sin(ang));  
    double u = cross(a1, a2, b1), v = cross(a2, a1, b2);  
    return point((b1.x*v+b2.x*u)/(v+u), (b1.y*v+b2.y*u)/(v+u));  
}  
struct line  
{  
    point a, b;  
    line(){};  
    line( point _a, point _b ) : a(_a), b(_b){};  
    bool operator<( const line p )    const  
    {  
        if( fabs(a.x-p.a.x) < eps && fabs(a.y-p.a.y) < eps )  
            return cross(a, b, p.b) < 0;  
        point d1 = inter(a, b, nowAng);  
        point d2 = inter(p.a, p.b, nowAng);  
        return d1.x*d1.x+d1.y*d1.y < d2.x*d2.x+d2.y*d2.y;  
    }  
};  
struct Event  
{  
    double ang;  
    int id, st;  
    line L;  
    bool operator<( const Event p )    const  
    {  
        if( dblcmp(ang-p.ang) == 0 )  
            return st > p.st;  
        return ang < p.ang;  
    }  
} E[200000];  
int c;  
void add( point a, point b, int k )  
{  
    if( b < a )  
        swap(a, b);  
    E[c].ang = a.a, E[c].st = 1, E[c].L = line(a, b), E[c++].id = k;  
    E[c].ang = b.a, E[c].st = 0, E[c++].id = k;  
}  
multiset<line> S;  
multiset<line>::iterator itArr[100000];  
inline double cal( line L, double d1, double d2 )  
{  
    point a = inter(L.a, L.b, d1);  
    point b = inter(L.a, L.b, d2);  
    return fabs(0.5*cross(O, a, b));  
}  
int main()  
{  
    int i, j, k, n;  
    double d, t, ans, pre;  
    while( scanf("%lf %lf", &O.x, &O.y) != EOF )  
    {  
        c = 0;  
        scanf("%d", &n);  
        for( i = 0; i < n; ++i )  
        {  
            scanf("%lf %lf", &p[i].x, &p[i].y);  
            p[i].x -= O.x, p[i].y -= O.y;  
            p[i].a = atan2(p[i].y, p[i].x);  
        }  
        O.x = O.y = 0;  
        p[n] = p[0];  
        for( i = k = 0; i < n; ++i )  
        {  
            d = fabs(p[i+1].a-p[i].a);  
            if( d < pi )  
                add(p[i], p[i+1], k++);  
            else  
            {  
                point tmp = inter(p[i], p[i+1], pi);  
                tmp.a = pi*dblcmp(p[i].a);  
                add(p[i], tmp, k++);  
                tmp.a = pi*dblcmp(p[i+1].a);  
                add(p[i+1], tmp, k++);  
            }  
        }  
        sort(E, E+c);  
        S.clear();  
        ans = 0;    pre = -pi;  
        for( i = 0; i < c; ++i )  
        {  
            nowAng = E[i].ang;  
            if( E[i].st )  
            {  
                if( S.size() > 0 )  
                    ans += cal(*S.begin(), pre, E[i].ang);  
                itArr[E[i].id] = S.insert(E[i].L);  
            }  
            else  
            {  
                ans += cal(*S.begin(), pre, E[i].ang);  
                S.erase(itArr[E[i].id]);  
            }  
            pre = E[i].ang;  
        }  
        printf("%.10lf\n", ans);  
    }  
    return 0;  
}  
//��άƽ����n(0 < n <= 50000)���߶Σ�Ҫ���ж�n���߶��Ƿ���ڽ��㣬����У�����ཻ�߶εı�š�  
#define MP make_pair  
#define PI pair  
#define FI first  
#define SE second  
#define PB push_back  
#define SZ size()  
const double eps = 1e-10;  
const double pi = acos(-1.);  
const int mod = 1000000007;  
const int maxn = 50100;  
const int INF = 99999999;  
struct point  
{  
    int x, y;  
    bool operator<( const point p )    const  
    {  
        if( x == p.x )    return y < p.y;  
        return x < p.x;  
    }  
} L[maxn][2];  
int tim;  
struct eve  
{  
    int x, id, st;  
    eve(){}  
    eve( int _x, int _id, int _st ) : x(_x), id(_id), st(_st) {}  
    bool operator<( const eve p )     const  
    {  
        if( p.x == x )    return st > p.st;  
        return x < p.x;  
    }  
} E[maxn*2];  
  
void getLine( point x, point y, double& a, double& b, double& c )  
{  
    a = y.y - x.y;  
    b = x.x - y.x;  
    c = y.x*x.y - x.x*y.y;  
}  
struct ele  
{  
    int id;  
    double k, c;  
    ele( int _id )  
    {  
        id = _id;  
        if( L[id][0].x == L[id][1].x )  
            k = 0, c = L[id][0].y;  
        else  
        {  
            double A, B, C;  
            getLine(L[id][0], L[id][1], A, B, C);  
            k = -A/B, c = -C/B;  
        }  
    }  
    bool operator<( const ele p )    const  
    {  
        return tim*k+c < tim*p.k+p.c;  
    }  
};  
set<ele> S;  
set<ele>::iterator itArr[maxn];  
inline set<ele>::iterator preIt( set<ele>::iterator it )  
{  
    return it == S.begin() ? S.end() : --it;  
}  
  
inline set<ele>::iterator nxtIt( set<ele>::iterator it )  
{  
    return it == S.end() ? S.end() : ++it;  
}  
  
int cross( point& k, point& a, point& b )  
{  
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);  
}  
  
int dot( point& k, point& a, point& b )  
{  
    return (a.x-k.x)*(b.x-k.x) + (a.y-k.y)*(b.y-k.y);  
}  
  
inline int sgn( int x )  
{  
    if( x > 0 )    return 1;  
    if( x < 0 )    return -1;  
    return x;  
}  
  
bool inter( int a, int b )  
{  
    int d1 = sgn(cross(L[a][0], L[a][1], L[b][0]));  
    int d2 = sgn(cross(L[a][0], L[a][1], L[b][1]));  
    int d3 = sgn(cross(L[b][0], L[b][1], L[a][0]));  
    int d4 = sgn(cross(L[b][0], L[b][1], L[a][1]));  
    if( (d1^d2)==-2 && (d3^d4)==-2 )    return 1;  
    if( d1 == 0 && dot(L[b][0], L[a][0], L[a][1]) <= 0 )    return 1;  
    if( d2 == 0 && dot(L[b][1], L[a][0], L[a][1]) <= 0 )    return 1;  
    if( d3 == 0 && dot(L[a][0], L[b][0], L[b][1]) <= 0 )    return 1;  
    if( d4 == 0 && dot(L[a][1], L[b][0], L[b][1]) <= 0 )    return 1;  
    return 0;  
}  
  
bool solve( int n )  
{  
    sort(E, E+n);  
    S.clear();  
    for( int i = 0; i < n; ++i )  
    {  
        tim = E[i].x;  
        int id = E[i].id;  
  
        if( E[i].st == 1 )  
        {  
            ele t = ele(id);  
            set<ele>::iterator nxt = S.lower_bound(t), pre = preIt(nxt);  
            if( nxt != S.end() && inter((*nxt).id, id) )  
            {  
                printf("YES\n%d %d\n", (*nxt).id, id);  
                return 1;  
            }  
            if( pre != S.end() && inter((*pre).id, id) )  
            {  
                printf("YES\n%d %d\n", (*pre).id, id);  
                return 1;  
            }  
            itArr[id] = S.insert(nxt, t);  
        }  
        else  
        {  
            set<ele>::iterator pre = preIt( itArr[id] ), nxt = nxtIt( itArr[id] );  
            if( pre != S.end() && nxt != S.end() && inter((*pre).id, (*nxt).id) )  
            {  
                printf("YES\n%d %d\n", (*pre).id, (*nxt).id);  
                return 1;  
            }  
            S.erase(itArr[id]);  
        }  
    }  
  
    return 0;  
}  
  
int main()  
{  
    srand(4);  
    int T, cases = 1;  
    int i, j, k, e;  
    double A, B, C;  
    int N, M;  
    scanf("%d", &N);  
    for( i = 1; i <= N; ++i )  
    {  
        scanf("%d %d %d %d", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);  
        if( L[i][1] < L[i][0] )  
            swap(L[i][0], L[i][1]);  
    }  
    for( i = 1, e = 0; i <= N; ++i )  
    {  
        E[e++] = eve(L[i][0].x, i, +1);  
        E[e++] = eve(L[i][1].x, i, -1);  
    }  
    if( !solve(e) )  
        puts("NO");  
    return 0;  
}
  
  
/*******��ά����*******/  
#include <iostream>    
#include <cstdio>    
#include <cmath>    
#define zero( x ) ( ( ( x ) > 0 ? ( x ) : -( x ) ) < eps )    
const double eps = 1e-8;    
struct point3    
{    
    double x, y, z;    
};    
struct line3    
{    
    point3 a, b;    
};    
struct plane3    
{    
    point3 a, b, c;    
};    
//���� Cross Product U * V    
point3 xmult( point3 u, point3 v )    
{    
    point3 ret;    
    ret.x = u.y * v.z - v.y * u.z;    
    ret.y = u.z * v.x - u.x * v.z;    
    ret.z = u.x * v.y - u.y * v.x;    
    return ret;    
}

//���� Dot Product U ? V    
double dmult( point3 u, point3 v )    
{    
    return u.x * v.x + u.y * v.y + u.z * v.z;    
}    
//ʸ���� U - V    
point3 subt( point3 u, point3 v )    
{    
    point3 ret;    
    ret.x = u.x - v.x;    
    ret.y = u.y - v.y;    
    ret.z = u.z - v.z;    
    return ret;    
}    
//ȡƽ�淨����    
point3 pvec( plane3 s )    
{    
    return xmult( subt( s.a, s.b ), subt( s.b, s.c ) );    
}    
point3 pvec( point3 s1, point3 s2, point3 s3 )    
{    
    return xmult( subt( s1, s2 ), subt( s2, s3 ) );    
}    
//������룬������ȡ������С    
double distance( point3 p1, point3 p2 )    
{    
    return sqrt( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.x ) * ( p1.y - p2.y ) + ( p1.z - p2.z ) * ( p1.z - p2.z ) );    
}    
//������С    
double vlen( point3 p )    
{    
    return sqrt( p.x * p.x + p.y * p.y + p.z * p.z );    
}    
//�ж����㹲��    
int dots_inline( point3 p1, point3 p2, point3 p3 )    
{    
    return vlen( xmult( subt( p1, p2 ), subt( p2, p3 ) ) ) < eps;    
}    
//�ж��ĵ㹲��    
int dots_onplane( point3 a, point3 b, point3 c, point3 d )    
{    
    return zero( dmult( pvec( a, b, c ), subt( d, a ) ) );    
}    
//�ж����Ƿ����߶��ϣ������˵�͹���    
int dot_online_in( point3 p, line3 l )    
{    
    return zero( vlen( xmult( subt( p, l.a ), subt( p, l.b ) ) ) ) && ( l.a.x - p.x ) * ( l.b.x - p.x ) < eps && ( l.a.y - p.y ) * ( l.b.y - p.y ) < eps && ( l.a.z - p.z ) * ( l.b.z - p.z ) < eps;    
}    
int dot_online_in( point3 p, point3 l1, point3 l2 )    
{    
    return zero( vlen( xmult( subt( p, l1 ), subt( p, l2 ) ) ) ) && ( l1.x - p.x ) * ( l2.x - p.x ) < eps && ( l1.y - p.y ) * ( l2.y - p.y ) < eps && ( l1.z - p.z ) * ( l2.z - p.z ) < eps;    
}    
//�ж����Ƿ����߶��ϣ��������˵�    
int dot_online_ex( point3 p, line3 l )    
{    
    return dot_online_in( p, l ) && ( !zero( p.x - l.a.x ) || ! zero( p.y - l.a.y ) || !zero( p.z - l.a.z ) ) && ( !zero( p.x - l.b.x ) || !zero( p.y - l.b.y ) || !zero( p.z - l.b.z ) );    
}    
int dot_online_ex( point3 p, point3 l1, point3 l2 )    
{    
    return dot_online_in( p, l1, l2 ) && ( !zero( p.x - l1.x ) || !zero( p.y - l1.y ) || !zero( p.z - l1.z ) ) && ( !zero( p.x - l2.x ) || !zero( p.y - l2.y ) || !zero( p.z - l2.z ) );    
}    
//�ж����Ƿ��ڿռ��������ϣ������߽磬���㹲��������    
int dot_inplane_in( point3 p, plane3 s )    
{    
    return zero( vlen( xmult( subt( s.a, s.b ), subt( s.a, s.c ) ) ) - vlen( xmult( subt( p, s.a ), subt( p, s.b ) ) ) - vlen( xmult( subt( p, s.b ), subt( p, s.c ) ) ) - vlen( xmult( subt( p, s.c ), subt( p, s.a ) ) ) );    
}    
int dot_inplane_in( point3 p, point3 s1, point3 s2, point3 s3 )    
{    
    return zero( vlen( xmult( subt( s1, s2 ), subt( s1, s3 ) ) ) - vlen( xmult( subt( p, s1 ), subt( p, s2 ) ) ) - vlen( xmult( subt( p, s2 ), subt( p, s3 ) ) ) - vlen( xmult( subt( p, s3 ), subt( p, s1 ) ) ) );    
}    
//�ж����Ƿ��ڿռ��������ϣ��������߽磬���㹲��������    
int dot_inplane_ex( point3 p, plane3 s )    
{    
    return dot_inplane_in( p, s ) && vlen( xmult( subt( p, s.a ), subt( p, s.b ) ) ) > eps && vlen( xmult( subt( p, s.b ), subt( p, s.c ) ) ) > eps && vlen( xmult( subt( p, s.c ), subt( p, s.a ) ) ) > eps;    
}    
int dot_inplane_ex( point3 p, point3 s1, point3 s2, point3 s3 )    
{    
    return dot_inplane_in( p, s1, s2, s3 ) && vlen( xmult( subt( p, s1 ), subt( p, s2 ) ) ) > eps && vlen( xmult( subt( p, s2 ), subt( p, s3 ) ) ) > eps && vlen( xmult( subt( p, s3 ), subt( p, s1 ) ) ) > eps;    
}    
//�ж��������߶�ͬ�࣬�����߶��Ϸ���0��������������    
int same_side( point3 p1, point3 p2, line3 l )    
{    
    return dmult( xmult( subt( l.a, l.b ), subt( p1, l.b ) ), xmult( subt( l.a, l.b ), subt( p2, l.b ) ) ) > eps;    
}    
int same_side( point3 p1, point3 p2, point3 l1, point3 l2 )    
{    
    return dmult( xmult( subt( l1, l2 ), subt( p1, l2 ) ), xmult( subt( l1, l2 ), subt( p2, l2 ) ) ) > eps;    
}    
//�ж��������߶���࣬����ƽ���Ϸ���0    
int opposite_side( point3 p1, point3 p2, line3 l )    
{    
    return dmult( xmult( subt( l.a, l.b ), subt( p1, l.b ) ), xmult( subt( l.a, l.b ), subt( p2, l.b ) ) ) < -eps;    
  
}  int opposite_side( point3 p1, point3 p2, point3 l1, point3 l2 )    
{    
    return dmult( xmult( subt( l1, l2 ), subt( p1, l2 ) ), xmult( subt( l1, l2 ), subt( p2, l2 ) ) ) < -eps;    
}    
//�ж�������ƽ��ͬ�࣬����ƽ���Ϸ���0    
int same_side( point3 p1, point3 p2, plane3 s )    
{    
    return dmult( pvec( s ), subt( p1, s.a ) ) * dmult( pvec( s ), subt( p2, s.a ) ) > eps;    
}    
int same_side( point3 p1, point3 p2, point3 s1, point3 s2, point3 s3 )    
{    
    return dmult( pvec( s1, s2, s3 ), subt( p1, s1 ) ) * dmult( pvec( s1, s2, s3 ), subt( p2, s1 ) ) > eps;    
}    
//�ж�������ƽ����࣬����ƽ���Ϸ���0    
int opposite_side( point3 p1, point3 p2, plane3 s )    
{    
    return dmult( pvec( s ), subt( p1, s.a ) ) * dmult( pvec( s ), subt( p2, s.a ) ) < -eps;    
}    
int opposite_side( point3 p1, point3 p2, point3 s1, point3 s2, point3 s3 )    
{    
    return dmult( pvec( s1, s2, s3 ), subt( p1, s1 ) ) * dmult( pvec( s1, s2, s3 ), subt( p2, s1 ) ) < eps;    
}    
//�ж���ֱ��ƽ��    
int parallel( line3 u, line3 v )    
{    
    return vlen( xmult( subt( u.a, u.b ), subt( v.a, v.b ) ) ) < eps;    
}    
int parallel( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )    
{    
    return vlen( xmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) ) < eps;    
}    
//�ж�ֱ����ƽ��ƽ��    
int parallel( line3 l, plane3 s )    
{    
    return zero( dmult( subt( l.a, l.b ), pvec( s ) ) );    
}    
int parallel( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
{    
    return zero( dmult( subt( l1, l2 ), pvec( s1, s2, s3 ) ) );    
}    
//�ж���ֱ�ߴ�ֱ    
int perpendicular( line3 u, line3 v )    
{    
    return zero( dmult( subt( u.a, u.b ), subt( v.a, v.b ) ) );    
}    
int perpendicular( point3 u1, point3 u2, point3 v1, point3 v2 )    
{    
    return zero( dmult( subt( u1, u2 ), subt( v1, v2 ) ) );    
}    
//�ж���ƽ�洹ֱ    
int perpendicular( plane3 u, plane3 v )    
{    
    return zero( dmult( pvec( u ), pvec( v ) ) );    
}    
int perpendicular( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )    
{    
    return zero( dmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) );    
}    
//�ж�ֱ����ƽ��ƽ��    
int perpendicular( line l, plane3 s )    
{    
    return vlen( xmult( subt( l.a, l.b ), pvec( s ) ) ) < eps;    
}    
int perpendicular( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
{    
    return vlen( xmult( subt( l1, l2 ), pvec( s1, s2, s3 ) ) ) < eps;    
}    
//�ж���ֱ���ཻ�������˵�Ͳ����غ�    
int intersect_in( line3 u, line3 v )    
{    
    if( !dots_onplane( u.a, u.b, v.a, v.b ) )    
    return 0;    
    if( !dotsinline( u.a, u.b, v.a ) || !dots_inline( u.a, u.b, v.b ) )    
    return !same_side( u.a, u.b, v ) && !same_side( v.a, v.b, u );    
    return dot_online_in( u.a, v ) || dot_online_in( u.b, v ) || dot_online_in( v.a, u ) || dot_online_in( v.b, u );    
}    
int intersect_in( point3 u1, point3 u2, opint3 v1, point3 v2 )    
{    
  
    if( !dots_onplane( u1, u2, v1, v2 ) )    
    return 0;    
    if( !dots_inline( u1, u2, v1 ) || !dots_inline( u1, u2, v2 ) )    
    return !same_side( u1, u2, v1, v2 ) && !same_side( v1, v2, u1, u2 );    
    return dot_online_in( u1, v1, v2 ) || dot_online_in( u2, v1, v2 ) || dot_online_in( v1, u1, u2 ) || dot_online_in( v2, u1, u2 );    
}    
//�ж����߶��ཻ���������˵�Ͳ����غ�    
int intersect_ex( line3 u, line3 v )    
{    
    return dots_onplane( u.a, u.b, v.a, v.b ) && opposite_side( u.a, u.b, v ) && opposite_side( v.a, v.b, u );    
}    
int intersect_ex( point3 u1, point3 u2, point3 v1, point3 v2 )    
{    
    return dots_onplane( u1, u2, v1, v2 ) && opposite_side( u1, u2, v1, v2 ) && opposite_side( v1, v2, u1, u2 );    
}    
//�ж��߶���ռ��������ཻ���������ڱ߽�ͣ����֣�����    
int intersect_in( line3 l, plane3 s )    
{    
    return !same_side( l.a, l.b, s ) && !same_side( s.a, s.b, l.a, l.b, s.c ) && !same_side( s.b, s.c, l.a, l.b, s.a ) && !same_side( s.c, s.a, l.a, l.b, s.b );    
}    
  
int intersect_in( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
  
{    
  
    return !same_side( l1, l2, s1, s2, s3 ) && !same_side( s1, s2, l1, l2, s3 ) && !same_side( s2, s3, l1, l2, s1 ) && !same_side( s3, s1, l1, l2, s2 );    
  
}    
  
//�ж��߶���ռ��������ཻ�����������ڱ߽�ͣ����֣�����    
  
int intersect_ex( line3 l, plane3 s )    
  
{    
  
    return opposite_side( l.a, l.b, s ) && opposite_side( s.a, s.b, l.a, l.b, s.c ) && opposite_side( s.b, s.c, l.a, l.b, s.a ) && opposite_side( s.c, s.a, l.a, l.b, s.b );    
  
}    
  
int intersect_ex( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
  
{    
  
    return opposite_side( l1, l2, s1, s2, s3 ) && opposite_side( s1, s2, l1, l2, s3 ) && opposite_side( s2, s3, l1, l2, s1 ) && opposite_side( s3, s1, l1, l2, s2 );    
  
}    
//������ֱ�߽��㣬ע�������ж�ֱ���Ƿ����ƽ��    
//�߶ν��������ж��߶��ཻ��ͬʱ����Ҫ�ж��Ƿ�ƽ�У�    
point3 intersection( line3 u, line3 v )    
{    
    point3 ret = u.a;    
    double t = ( ( u.a.x - v.a.x ) * ( v.a.y - v.b.y ) - ( u.a.y - v.a.y ) * ( v.a.x - v.b.x ) ) / ( ( u.a.x - u.b.x ) * ( v.a.y - v.b.y ) - ( u.a.y - u.b.y ) * ( v.a.x - v.b.x ) );    
    ret.x += ( u.b.x - u.a.x ) * t;    
    ret.y += ( u.b.y - u.a.y ) * t;    
    ret.z += ( u.b.z - u.a.z ) * t;    
    return ret;    
}    
point3 intersection( point3 u1, point3 u2, point3 v1, point3 v2 )    
{    
    point3 ret = u1;    
    double t = ( ( u1.x - v1.x ) * ( v1.y - v2.y ) - ( u1.y - v1.y ) * ( v1.x - v2.x ) ) / ( ( u1.x - u2.x ) * ( v1.y - v2.y ) - ( u1.y - u2.y ) * ( v1.x - v2.x ) );    
    ret.x += ( u2.x - u1.x ) * t;    
    ret.y += ( u2.y - u1.y ) * t;    
    ret.z += ( u2.z - u1.z ) * t;    
    return ret;    
}    
//����ֱ����ƽ�潻�㣬ע�������ж��Ƿ�ƽ�У�����֤���㲻����    
//�߶κͿռ������ν��������ж�    
point3 intersection( line3 l, plane3 s )    
{    
    point3 ret = pvec( s );    
    double t = ( ret.x * ( s.a.x - l.a.x ) + ret.y * ( s.a.y - l.a.y ) + ret.z * ( s.a.z - l.a.z ) ) / ( ret.x * ( l.b.x - l.a.x ) + ret.y * ( l.b.y - l.a.y ) + ret.z * ( l.b.z - l.a.z ) );    
    ret.x = l.a.x + ( l.b.x - l.a.x ) * t;    
    ret.y = l.a.y + ( l.b.y - l.a.y ) * t;    
    ret.z = l.a.z + ( l.b.z - l.a.z ) * t;    
    return ret;    
}    
point3 intersection( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
{    
    point3 ret = pvec( s1, s2, s3 );    
    double t = ( ret.x * ( s1.x - l1.x ) + ret.y * ( s1.y - l1.y ) + ret.z * ( s1.z - l1.z ) ) / ( ret.x * ( l2.x - l1.x ) + ret.y * ( l2.y - l1.y ) + ret.z * ( l2.z - l1.z ) );    
    ret.x = l1.x + ( l2.x - l1.x ) * t;    
    ret.y = l1.y + ( l2.y - l1.y ) * t;    
    ret.z = l1.z + ( l2.z - l1.z ) * t;    
    return ret;    
}    
//������ƽ�潻�ߣ�ע�������ж��Ƿ�ƽ�У�����֤���㲻����    
line3 intersection( plane3 u, plane3 v )    
{    
    line3 ret;    
    ret.a = parallel( v.a, v.b, u.a, u.b, u.c ) ? intersection( v.b, v.c, u.a, u.b, u.c ) : intersection( v.a, v.b, u.a, u.b, u.c );    
    ret.b = parallel( v.c, v.a, u.a, u.b, u.c ) ? intersection( v.b, v.c, u.a, u.b, u.c ) : intersection( v.c, v.a, u.a, u.b, u.c );    
    return ret;    
}    
line3 intersection( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )    
{    
    line3 ret;    
    ret.a = parallel( v1, v2, u1, u2, u3 ) ? intersection( v2, v3, u1, u2, u3 ) : intersection( v1, v2, u1, u2, u3 );    
    ret.b = parallel( v3, v1, u1, u2, u3 ) ? intersection( v2, v3, u1, u2, u3 ) : intersection( v3, v1, u1, u2, u3 );    
    return ret;    
}    
//�㵽ֱ�߾���    
double ptoline( point3 p, line3 l )    
{    
    return vlen( xmult( subt( p, l.a ), subt( l.b, l.a ) ) ) / distance( l.a, l.b );    
}    
double ptoline( point3 p, point3 l1, point3 l2 )    
{    
    return vlen( xmult( subt( p, l1 ), subt( l2, l1 ) ) ) / distance( l1, l2 );    
}    
//�㵽ƽ�����    
double ptoplane( point3 p, plane3 s )    
{    
    return fabs( dmult( pvec( s ), subt( p, s.a ) ) ) / vlen( pvec( s ) );    
}    
double ptoplane( point3 p, point3 s1, point3 s2, point3 s3 )    
{    
    return fabs( dmult( pvec( s1, s2, s3 ), subt( p, s1 ) ) ) / vlen( pvec( s1, s2, s3 ) );    
}    
//ֱ�ߵ�ֱ�߾���    
double linetoline( lien3 u, line3 v )    
{    
    point3 n = xmult( subt( u.a, u.b ), subt( v.a, v.b ) );    
    return fabs( dmult( subt( u.a, v.a ), n ) ) / vlen( n );    
}    
double linetoline( point3 u1, point3 u2, point3 v1, point3 v2 )    
{    
    point3 n = xmult( subt( u1, u2 ), subt( v1, v2 ) );    
    return fabs( dmult( subt( u1, v1 ), n ) ) / vlen( n );    
}    
//��ֱ�߼н� cos ֵ    
double angle_cos( line3 u, line3 v )    
{    
    return dmult( subt( u.a, u.b ), subt( v.a, v.b ) ) / vlen( subt( u.a, u.b ) ) / vlen( subt( v.a, v.b ) );    
}    
double angle_cos( point3 u1, point3 u2, point3 v1, point3 v2 )    
{    
    return dmult( subt( u1, u2 ), subt( v1, v2 ) ) / vlen( sut( u1, u2 ) ) / vlen( subt( v1, v2 ) );    
}    
//��ƽ��н� cos ֵ    
double angle_cos( plane3 u, plane3 v )    
{    
    return dmult( pvec( u ), pvec( v ) ) / vlen( pvec( u ) ) / vlen( pvec( v ) );    
}    
double angle_cos( point3 u1, point3 u2, point3 v1, point3 v2, point3 v3 )    
{    
    return dmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) / vlen( pvec( u1, u2, u3 ) ) / vlen( pvec( v1, v2, v3 ) );    
}    
//ֱ��ƽ��н� sin ֵ    
double angle_sin( line3 l, plane3 s )    
  
{    
    return dmult( subt( l.a, l.b ), pvec( s ) ) / vlen( subt( l.a, l.b ) ) / vlen( pvec( s ) );    
}    
double angle_sin( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )    
{    
    return dmult( subt( l1, l2 ), pvc( s1, s2, s3 ) ) / vlen( subt( l1, l2 ) ) / vlen( pvec( s1, s2, s3 ) );    
}  
