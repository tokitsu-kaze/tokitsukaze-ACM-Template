struct Tree_Centroid
{
	VI centroid;
	int sz[MAX],w[MAX],n;
	void dfs(VI *mp,int x,int fa)
	{
		sz[x]=1;
		w[x]=0;
		for(int i=0;i<sz(mp[x]);i++)
		{
			int to=mp[x][i];
			if(to==fa) continue;
			dfs(mp,to,x);
			sz[x]+=sz[to];
			w[x]=max(w[x],sz[to]);
		}
		w[x]=max(w[x],n-sz[x]);
		if(w[x]<=n/2) centroid.pb(x);
	}
	VI get_tree_centroid(int _n,VI *mp,int root)
	{
		n=_n;
		centroid.clear();
		dfs(mp,root,0);
		return centroid;
	}
}trct;
