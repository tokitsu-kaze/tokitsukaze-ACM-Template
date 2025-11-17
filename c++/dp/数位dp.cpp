namespace DIGDP
{
	const int base=10;
	const int DIG=20+2;
	int p[DIG],tot;
	ll dp[DIG][2];
	ll dfs(int pos,int lead,int sta,int limt)
	{
		if(pos==-1) return ;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			
			res+=dfs(pos-1,lead&&i==0&&pos,,limt&&i==p[pos]);
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	}
	ll gao(ll x)
	{
		if(x==-1) return 0;
		memset(dp,-1,sizeof dp);
		tot=0;
		while(1)
		{
			p[tot++]=x%base;
			x/=base;
			if(!x) break;
		}
		return dfs(tot-1,1,0,1);
	}
}
	
