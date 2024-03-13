ll Lucas(ll n,ll m,int p)
{
	if(m==0) return 1;
	return C(n%p,m%p)*Lucas(n/p,m/p,p)%p;
}
/*
p must be a prime number
init(p-1);
*/ 
