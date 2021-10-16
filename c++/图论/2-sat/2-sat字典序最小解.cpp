//判断是否有解 输出字典序最小的解 O(n*m) 
vector<int> mp[MAX];
bool flag[MAX];
int cnt,s[MAX];
void init(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		mp[i].clear();
	}
	mem(flag,0);
}
bool dfs(int x)
{
	int i;
	if(flag[x^1]) return 0;
	if(flag[x]) return 1;
	s[cnt++]=x;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(!dfs(mp[x][i])) return 0;
	}
	return 1;
}
void twosat(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		if(!flag[i]&&!flag[i^1])
		{
			cnt=0;
			if(!dfs(i))
			{
				while(cnt) flag[s[--cnt]]=0;
				if(!dfs(i^1))//无解 
				{
					puts("NO");
					return;
				}
			}
		}
	}
	for(i=0;i<2*n;i+=2)
	{
		if(flag[i]) printf("%d\n",i+1);
		else printf("%d\n",i+2);
	}
}