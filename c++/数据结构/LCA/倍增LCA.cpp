//O(nlogn)-O(logn) 
struct LCA
{
	int fa[MAX][22],dep[MAX],n,limt,bin[22];
	VI mp[MAX];
	void init(int _n)
	{
		n=_n;
		for(limt=1;1<<(limt-1)<=n;limt++);
		for(int i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			mem(fa[i],0);
		}
	}
	void add_edge(int a,int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}
	void dfs(int x,int pre)
	{
		for(int i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(int i=0;i<sz(mp[x]);i++)
		{
			int to=mp[x][i];
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			dfs(to,x);
		}
	}
	void work(int rt)
	{
		dep[rt]=0;
		dfs(rt,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				x=fa[x][i];
			}
		}
		return x;
	}
	int lca(int a,int b)
	{
		if(dep[a]<dep[b]) swap(a,b);
		a=go(a,dep[a]-dep[b]);
		if(a==b) return a;
		for(int i=limt;~i;i--)
		{
			if(fa[a][i]!=fa[b][i])
			{
				a=fa[a][i];
				b=fa[b][i];
			}
		}
		return fa[a][0];
	}
}lca;
