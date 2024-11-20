struct LCA
{
	static const int N=MAX;
	static const int LOG=log2(N)+2;
	int fa[LOG][N],dep[N];
	vector<int> *mp;
	void dfs(int x,int pre)
	{
		int i;
		fa[0][x]=pre;
		for(i=1;i<LOG;i++) fa[i][x]=fa[i-1][fa[i-1][x]];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			dfs(to,x);
		}
	}
	void work(int root,vector<int> *_mp)
	{
		mp=_mp;
		for(int j=0;j<LOG;j++) fa[j][0]=0;
		dep[root]=0;
		dfs(root,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<LOG;i++)
		{
			if((d>>i)&1) x=fa[i][x];
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=LOG-1;~i;i--)
		{
			if(fa[i][x]!=fa[i][y])
			{
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return fa[0][x];
	}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
