struct dsu
{
	unordered_map<int,int> pre;
	void init(){pre.clear();}
	int find(int x)
	{
		if(pre.count(x)) pre[x]=find(pre[x]);
		else return x;
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
