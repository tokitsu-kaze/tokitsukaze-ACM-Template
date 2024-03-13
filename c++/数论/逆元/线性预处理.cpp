ll inv[MAX];
void init_inv(int n,ll p)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
