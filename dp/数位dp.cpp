const int DIG=20+2;
ll dp[DIG][2];
ll gao(ll x)
{
	const int base=10;
	int p[DIG],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
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
	};
	return dfs(tot-1,1,0,1);
}

