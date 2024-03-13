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
/*
xa+yb=gcd(a,b)

get x,y
x1=x+b/gcd(a,b)*t
y1=y-a/gcd(a,b)*t
t is any integer
*/
