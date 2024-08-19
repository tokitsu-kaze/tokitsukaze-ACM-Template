struct gcd_stein
{
	#define type unsigned int
	#define ctz __builtin_ctz
	inline type gcd_stein_impl(type x,type y)
	{
		while(x!=y)
		{
			const type a=y-x;
			const type b=x-y;
			const int n=ctz(b);
			const type s=x<y?a:b;
			const type t=x<y?x:y;
			x=s>>n;
			y=t;
		}
		return x;
	}
	inline type gcd(type x,type y)
	{
		if(x==0||y==0) return x|y;
		const int n=ctz(x);
		const int m=ctz(y);
		return gcd_stein_impl(x>>n,y>>m)<<(n<m?n:m);
	}
	#undef type
	#undef ctz
}stein;
