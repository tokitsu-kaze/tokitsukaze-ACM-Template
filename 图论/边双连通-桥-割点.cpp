namespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	vector<PII > bridge;
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	int cut[MAX],add_block[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(auto to:mp[x])
		{
			if(to==pre&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				son++;
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(x!=pre&&low[to]>=dfn[x])
				{
					cut[x]=1;
					add_block[x]++;
				}
				if(low[to]>dfn[x]) bridge.pb(MP(x,to));
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(x==pre&&son>1)
		{
			cut[x]=1;
			add_block[x]=son-1;
		}
		if(low[x]==dfn[x])
		{
			bcc++;
			do
			{
				tmp=stk[--top];
				belong[tmp]=bcc;
			}while(tmp!=x);
		}
	}
	void work(int _n,vector<int> e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
			cut[i]=add_block[i]=0;
		}
		bcc=top=tot=0;
		bridge.clear();
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
	void rebuild(vector<int> e[]) 
	{
		int i,t;
		for(i=1;i<=n;i++) e[i].clear();
		for(i=1;i<=n;i++)
		{
			t=fa[i];
			if(belong[i]!=belong[t])
			{
				e[belong[i]].pb(belong[t]);
				e[belong[t]].pb(belong[i]);
			}
		}
	}
}
