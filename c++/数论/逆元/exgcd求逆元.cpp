ll inv_exgcd(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x%p+p)%p:-1;
}
/*
gcd(a,p)!=1, no solution, return -1
*/
