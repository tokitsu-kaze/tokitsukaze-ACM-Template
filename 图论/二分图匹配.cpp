//二分图匹配
/*
最小点覆盖的点数=最大匹配数
最小路径覆盖的边数=顶点数n-最大匹配数
最大独立集=最小路径覆盖=顶点数n-最大匹配数
*/
//1.匈牙利算法 求最大匹配 O(n*m)
vector<int> mp[MAX];
int link[MAX],used[MAX];
int dfs(int x)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(!used[to])
		{
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int hungary(int n)//返回最大匹配数 
{
	mem(link,-1);
	int i,res=0;
	for(i=1;i<=n;i++)
	{
		mem(used,0);
		if(dfs(i)) res++;
	}
	return res;
}

