void getinv(int n,ll p)
{
	ll i;
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
