//二分图匹配
/*
最小点覆盖的点数=最大匹配数
最小路径覆盖的边数=顶点数n-最大匹配数
最大独立集=最小路径覆盖=顶点数n-最大匹配数
*/
//匈牙利算法 O(n*m)
struct Bipartite_Matching
{
	static const int N=;
	int n,m;
	VI mp[N];
	int link[N],s[N];
	bool used[N],flag[N];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].pb(b);}
	bool dfs(int x)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(used[to]) continue;
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		mem(link,-1);
		mem(s,-1);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(!sz(mp[i])) continue;
			mem(used,0);
			if(dfs(i)) res++;
		}
		return res;
	}
	int min_cover(VI &x,VI &y)
	{
		int i,res;
		res=max_match();
		mem(flag,0);
		mem(used,0);
		x.clear();
		y.clear();
		for(i=1;i<=n;i++)
		{
			if(s[i]==-1) dfs(i);
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) x.pb(i);
		}
		for(i=1;i<=m;i++)
		{
			if(used[i]) y.pb(i);
		}
		return res;
	}
}bpm;
