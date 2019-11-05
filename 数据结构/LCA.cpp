struct LCA
{
	#define type int
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	type dis[MAX];
	int path[2*MAX],deep[2*MAX],first[MAX],len[MAX],tot,n;
	int dp[2*MAX][22];
	vector<node> mp[MAX];
	void dfs(int x,int pre,int h)
	{
		int i;
		path[++tot]=x;
		first[x]=tot;
		deep[tot]=h;
		for(i=0;i<mp[x].size();i++)
		{
			int to=mp[x][i].to;
			if(to==pre) continue;
			dis[to]=dis[x]+mp[x][i].w;
			len[to]=len[x]+1;
			dfs(to,x,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
	void ST(int n)
	{
		int i,j,x,y;
		for(i=1;i<=n;i++) dp[i][0]=i;
		for(j=1;(1<<j)<=n;j++)
		{
			for(i=1;i+(1<<j)-1<=n;i++)
			{
				x=dp[i][j-1];
				y=dp[i+(1<<(j-1))][j-1];
				dp[i][j]=deep[x]<deep[y]?x:y;
			}
		}
	}
	int query(int l,int r)
	{
		int len,x,y;
		len=(int)log2(r-l+1); 
		x=dp[l][len];
		y=dp[r-(1<<len)+1][len];
		return deep[x]<deep[y]?x:y;
	}
	int lca(int x,int y)
	{
		int l,r,pos;
		l=first[x];
		r=first[y];
		if(l>r) swap(l,r);
		pos=query(l,r);
		return path[pos];
	} 
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	int get_len(int a,int b){return len[a]+len[b]-2*len[lca(a,b)];}
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dis[i]=0;
			len[i]=0;
			mp[i].clear();
		}
	}
	void add_edge(int a,int b,type w=1)
	{
		mp[a].pb(node(b,w));
		mp[b].pb(node(a,w));
	}
	void work(int rt)
	{
		tot=0;
		dfs(rt,0,0);
		ST(2*n-1);
	}
	int lca_root(int rt,int a,int b)
	{
		int fa,fb;
		fa=lca(a,rt);
		fb=lca(b,rt);
		if(fa==fb) return lca(a,b);
		else
		{
			if(get_dis(fa,rt)<get_dis(fb,rt)) return fa;
			else return fb;
		}
	}
	#undef type
}lca;
/*
lca.init(n);
lca.add_edge(a,b,w) undirected edge.
lca.work(rt);
*/



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
