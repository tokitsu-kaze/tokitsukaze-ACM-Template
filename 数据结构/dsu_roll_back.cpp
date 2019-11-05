struct dsu
{
	PII st[MAX];
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
		st[top++]=MP(ra,rb);
		return 1;
	}
	void roll_back()
	{
		PII now=st[--top];
		pre[now.fi]=now.fi;
		sz[now.se]-=sz[now.fi];
	}
}dsu;
