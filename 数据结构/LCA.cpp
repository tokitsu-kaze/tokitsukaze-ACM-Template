//dfs+ST O(nlogn)‘§¥¶¿Ì O(1)≤È—Ø 
struct node{int to;int w;node(){}node(int _to,int _w):to(_to),w(_w){}};
int dis[MAX];
int path[2*MAX],deep[2*MAX],first[MAX],tot;
int dp[2*MAX][26];
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
int LCA(int x,int y)
{
	int l,r,pos;
	l=first[x];
	r=first[y];
	if(l>r) swap(l,r);
	pos=query(l,r);
	return path[pos];
} 
int getdis(int a,int b){return dis[a]+dis[b]-2*dis[LCA(a,b)];}
void work(int n)
{
	for(int i=0;i<=n;i++) dis[i]=0;
	tot=0;
	dfs(1,0,0);
	ST(2*n-1);
}
