struct Tree_Diameter
{
	int fa[MAX],rt,mx;
	void dfs(int x,int pre,int h,vector<int> *mp)
	{
		fa[x]=pre;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x,h+1);
		}
		if(h>mx)
		{
			mx=h;
			rt=x;
		}
	}
	vector<int> get_tree_diameter(vector<int> *mp)
	{
		fa[0]=0;
		rt=1;
		mx=0;
		dfs(rt,0,0);
		mx=0;
		dfs(rt,0,0);
		vector<int> res;
		while(rt)
		{
			res.push_back(rt);
			rt=fa[rt];
		}
		return res;
	}
}td;
