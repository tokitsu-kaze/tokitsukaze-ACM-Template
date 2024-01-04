struct Round_Square_Tree
{
	int tot,n;
	int low[MAX],dfn[MAX];
	int st[MAX],top;
	void dfs(int x,int fa,vector<int> *mp,vector<int> *g)
	{
		int to,i,tmp;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to,x,mp,g);
				low[x]=min(low[x],low[to]);
				if(low[to]==dfn[x])
				{
					n++;
					while(top)
					{
						tmp=st[--top];
						g[tmp].push_back(n);
						g[n].push_back(tmp);
						if(tmp==x)
						{
							top++;
							break;
						}
					}
				}
			}
			else low[x]=min(low[x],dfn[to]);
		}
	}
	int build_tree(int _n,vector<int> *mp,vector<int> *g)
	{
		int i;
		n=_n;
		for(i=1;i<=n;i++) low[i]=dfn[i]=0;
		for(i=1;i<=(n<<1);i++) g[i].clear();
		top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i,mp,g);
		}
		return n;
	}
}rst;
/*
vector<int> mp[MAX],g[MAX<<1];
tot=rst.build_tree(n,mp,g);
*/
