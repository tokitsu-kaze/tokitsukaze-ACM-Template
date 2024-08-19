struct Tree_Centroid
{
	vector<int> *mp;
	int sz[MAX],mx[MAX],n;
	void dfs(int x,int fa)
	{
		sz[x]=1;
		mx[x]=0;
		for(auto &to:mp[x])
		{
			if(to==fa) continue;
			dfs(to,x);
			sz[x]+=sz[to];
			mx[x]=max(mx[x],sz[to]);
		}
		mx[x]=max(mx[x],n-sz[x]);
	}
	vector<int> get_tree_centroid(int _n,vector<int> *_mp,int root)
	{
		int i,mn;
		n=_n;
		mp=_mp;
		dfs(root,-1);
		vector<int> res;
		mn=n+1;
		for(i=1;i<=n;i++) mn=min(mn,mx[i]);
		for(i=1;i<=n;i++)
		{
			if(mx[i]==mn) res.push_back(i);
		}
		return res;
	}
}trct;
