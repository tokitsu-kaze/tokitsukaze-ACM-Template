struct Disjoint_Set_Union
{
	pair<int,int> st[MAX];
	int pre[MAX],top,sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
		top=0;
	}
	int find(int x)
	{
		while(x!=pre[x]) x=pre[x];
		return x;
	}
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		st[top++]={x,y};
		return 1;
	}
	void roll_back()
	{
		pair<int,int> now=st[--top];
		pre[now.first]=now.first;
		sz[now.second]-=sz[now.first];
	}
}dsu;
