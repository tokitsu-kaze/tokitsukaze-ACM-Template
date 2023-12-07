/*
扩展欧几里得求逆元
条件:gcd(a,mod)==1
如果gcd(a,mod)!=1 返回-1 
*/
ll inv(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x+p)%p:-1;
}