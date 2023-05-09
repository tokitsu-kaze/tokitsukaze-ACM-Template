/*
xa+yb=c
求正整数x最小的一组解 
有解条件 c%gcd(a,b)==0 
*/
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
