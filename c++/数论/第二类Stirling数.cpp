//dp[i][j]表示i个元素划分到k个不可区分的非空盒子里的方案数。
ll dp[MAX][MAX];
void init()
{
	ll i,j;
	mem(dp,0);
	dp[1][1]=1;
	for(i=2;i<MAX;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%mod;
		}
	}
}
