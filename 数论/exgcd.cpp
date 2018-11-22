/*
解xa+yb=gcd(a,b)
返回值为gcd(a,b)
其中一组解为x y
通解:
	x1=x+b/gcd(a,b)*t
	y1=y-a/gcd(a,b)*t
	(t为任意整数) 
*/
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
//xa+yb=c 有解条件 c%gcd(a,b)==0  
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	ll g,t;
	g=exgcd(a,b,x,y);
	if(!c) x=y=0;
	else if((!a&&!b&&c)||c%g) return -1;//no solution 
	else if(!a&&b) x=1,y=c/b;
	else if(a&&!b) x=c/a,y=-c/a;
	else
	{
		a/=g,b/=g,c/=g;
		x*=c,y*=c;
		t=x;
		x%=b;
		if(x<=0) x+=b;//or x<0
		ll k=(t-x)/b;
		y+=k*a;
	}
	return g;
}
