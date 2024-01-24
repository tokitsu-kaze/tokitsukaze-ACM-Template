const int LOG=log2(MAX);
int fa[MAX][LOG+1];
void dfs(int x,int pre)
{
	fa[x][0]=pre;
	for(int i=1;i<=LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
}
int jump(int x,int target)
{
	for(int i=LOG;~i;i--)
	{
		if(fa[x][i]&&w[fa[x][i]]<=target) x=fa[x][i];
	}
	return x;
}
int main()
{
	memset(fa[0],0,sizeof fa[0]);
	return 0;
}
