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
int pow2(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int inv(int x){return pow2(x,mod-2);}
int fac[MAX],invfac[MAX];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
