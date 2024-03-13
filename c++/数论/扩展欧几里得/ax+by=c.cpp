ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,tmp;
	g=exgcd(b,a%b,x,y);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	
	ll g,dx,dy,t;
	g=exgcd(a,b,x,y);
	if(a==0&&b==0)
	{
		if(c) return -1;
		x=y=0;
		return g;
	}
	if(c%g) return -1; //no solution
	dx=b/g,dy=-a/g;
	x*=c/g,y*=c/g;
	t=(x%dx-x)/dx;
	if(x+dx*t<=0) t++;
	x+=dx*t,y+=dy*t;
	return g;
}
/*
xa+yb=c

get x,y and x>0 is min
have solution: c%gcd(a,b)==0
x=x0+dx*t
y=y0-dy*t
*/

