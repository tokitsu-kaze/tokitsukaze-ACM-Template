//C(n,m) n,m<=1e18 p<=1e5
//p must be a prime number
ll Lucas(ll n,ll m,ll p)
{
	if(m==0) return 1;
	return C(n%p,m%p)*Lucas(n/p,m/p,p)%p;
}
