struct Tree_Hash
{
	const ull mask=std::chrono::steady_clock::now().time_since_epoch().count();
	ull shift(ull x)
	{
	  x^=mask;
	  x^=x<<13;
	  x^=x>>7;
	  x^=x<<17;
	  x^=mask;
	  return x;
	}
	ull hash[MAX];
	void dfs(VI *mp,int x,int fa)
	{
		hash[x]=1;
		for(auto to:mp[x])
		{
			if(to==fa) continue;
			dfs(mp,to,x);
			hash[x]+=shift(hash[to]);
		}
	}
	void get_tree_hash(VI *mp,int root)
	{
		dfs(mp,root,0);
	}
}trha;
