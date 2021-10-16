struct Maximum_Clique
{
	static const int N=;
	vector<int> sol; // vertex of maximum clique
	int mp[N][N/30+1],s[N][N/30+1];
	int n,ans,dp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dp[i]=0;
			mem(mp[i],0);
		}
	}
	void add_edge(int a,int b) //0~n-1
	{
		if(a>b) swap(a,b);
		if(a==b) return;
		mp[a][b/32]|=(1<<(b%32));
	}
	bool dfs(int x,int k)
	{
		int c=0,d=0;
		for(int i=0;i<(n+31)/32;i++)
		{
			s[k][i]=mp[x][i];
			if(k!=1) s[k][i]&=s[k-1][i];
			c+=__builtin_popcount(s[k][i]);
		}
		if(c==0)
		{
			if(k>ans)
			{
				ans=k;
				sol.clear();
				sol.pb(x);
				return 1;
			}
			return 0;
		}
		for(int i=0;i<(n+31)/32;i++)
		{
			for(int a=s[k][i];a;d++)
			{
				if(k+(c-d)<=ans) return 0;
				int lb=a&(-a),lg=0;
				a^=lb;
				while(lb!=1)
				{
					lb=(unsigned int)(lb)>>1;
					lg++;
				}
				int u=i*32+lg;
				if(k+dp[u]<=ans) return 0;
				if(dfs(u,k+1))
				{
					sol.pb(x);
					return 1;
				}
			}
		}
		return 0;
	}
	int maximum_clique()
	{
		ans=0;
		for(int i=n-1;i>=0;i--)
		{
			dfs(i,1);
			dp[i]=ans;
		}
		return ans;
	}
}mcp;
/*
undirected graph
mcp.init(n);
mcp.add_edge(a,b); a,b: 0~n-1
*/
