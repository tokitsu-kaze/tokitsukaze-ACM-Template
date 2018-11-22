//组合数
//1.小范围预处理
ll C[1010][1010];
void init(int n)
{
	int i,j;
	for(i=(C[0][0]=1);i<=n;i++)
	{
		for(j=(C[i][0]=1);j<=n;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	} 
}


//2.大范围 
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return pow2(x,mod-2);}
ll fac[MAX],invfac[MAX];
void init(int n)
{
	ll i;
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
