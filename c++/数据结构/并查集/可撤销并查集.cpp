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
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra==rb) return 0;
		if(sz[ra]>sz[rb]) swap(ra,rb);
		pre[ra]=rb;
		sz[rb]+=sz[ra];
		st[top++]={ra,rb};
		return 1;
	}
	void roll_back()
	{
		PII now=st[--top];
		pre[now.first]=now.first;
		sz[now.second]-=sz[now.first];
	}
}dsu;
