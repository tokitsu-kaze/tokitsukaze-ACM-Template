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